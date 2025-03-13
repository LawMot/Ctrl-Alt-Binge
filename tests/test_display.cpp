#include "gtest/gtest.h"
#include "../header/display.h"
#include "../recommendationengine/recommendation.h"
#include "../header/TvShow.h"
#include <iostream> 
#include <sstream> 

TEST(FilterDirectorsTest, levenshteinTest) {
    RecommendationEngine engine; 
    EXPECT_EQ(engine.levenshteinDistance("director", "director"), 0);

    EXPECT_EQ(engine.levenshteinDistance("director", ""), 8);  // "director" length is 8
    EXPECT_EQ(engine.levenshteinDistance("", "director"), 8);

    EXPECT_EQ(engine.levenshteinDistance("director", "directir"), 1);  // One character change
    EXPECT_EQ(engine.levenshteinDistance("directir", "director"), 1);

    EXPECT_EQ(engine.levenshteinDistance("director", "producor"), 6); 
    EXPECT_EQ(engine.levenshteinDistance("director oh", "producor oj"), 7); 

    EXPECT_EQ(engine.levenshteinDistance("", ""), 0);
}

TEST(FilterDirectorsTest, testDirectorRec) {
    vector<TVShow> recommendedShows;
    RecommendationEngine engine;

    engine.setDirector("Gary Sing"); 

    recommendedShows = engine.compareDirectors(recommendedShows, engine);

    EXPECT_EQ(recommendedShows[0].getTitle(), "Word of Honor");
    EXPECT_EQ(recommendedShows[0].getDirector(), "Gary Sing");
    EXPECT_EQ(recommendedShows[0].getRating(), "TV-14");
    EXPECT_EQ(recommendedShows[0].getGenre(), "International TV Shows");
}

TEST(FilterGenresTest, testGenreRec) {
    GatherData data;
    data.setFilePath("TV Show Dataset.csv");
    data.loadData();
    vector<TVShow> allShows = data.getInfo();

    vector<TVShow> recommendedShows;
    RecommendationEngine engine;

    engine.setGenre("Crime TV Shows"); 

    recommendedShows = engine.compareGenre(allShows);

    EXPECT_FALSE(recommendedShows.empty()) << "No genre matches found.";  // Ensure the vector is not empty
    if (!recommendedShows.empty()) {
        EXPECT_EQ(recommendedShows[0].getGenre(), "Crime TV Shows");
    }
}


