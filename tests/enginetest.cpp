#include "../recommendationengine/recommendation.h"
#include "../header/gatherdata.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST(FilterAgeSuite, invalidchoice) {
    GatherData data;
    data.setFilePath("tests/age_datatest.csv");
    data.loadData();
    vector<TVShow> allShows = data.getInfo();

    RecommendationEngine ageChoice(-2);
    vector<TVShow> recommended5 = ageChoice.compareAge(allShows);

    ASSERT_TRUE(recommended5.empty());
}

TEST(FilterAgeSuite, under7) {
    GatherData data;
    data.setFilePath("tests/age_datatest.csv");
    data.loadData();
    vector<TVShow> allShows = data.getInfo();

    RecommendationEngine ageChoice(5);
    vector<TVShow> recommended5 = ageChoice.compareAge(allShows);
    EXPECT_EQ(recommended5[0].getRating(), "TV-Y7");
    EXPECT_EQ(recommended5[1].getRating(), "TV-Y7");
}

TEST(FilterAgeSuite, between7And10) {
    GatherData data;
    data.setFilePath("tests/age_datatest.csv");
    data.loadData();
    vector<TVShow> allShows = data.getInfo();

    RecommendationEngine ageChoice(9);
    vector<TVShow> recommended5 = ageChoice.compareAge(allShows);

    EXPECT_EQ(recommended5[0].getRating(), "TV-Y7");
    EXPECT_EQ(recommended5[1].getRating(), "TV-Y7");
}

TEST(FilterAgeSuite, between10And13) {
    GatherData data;
    data.setFilePath("tests/age_datatest.csv");
    data.loadData();
    vector<TVShow> allShows = data.getInfo();

    RecommendationEngine ageChoice(12);
    vector<TVShow> recommended5 = ageChoice.compareAge(allShows);

    EXPECT_EQ(recommended5[0].getRating(), "TV-PG");
    EXPECT_EQ(recommended5[1].getRating(), "TV-PG");
}

TEST(FilterAgeSuite, between14And16) {
    GatherData data;
    data.setFilePath("tests/age_datatest.csv");
    data.loadData();
    vector<TVShow> allShows = data.getInfo();

    RecommendationEngine ageChoice(15);
    vector<TVShow> recommended5 = ageChoice.compareAge(allShows);

    EXPECT_EQ(recommended5[0].getTitle(), "Love on the Spectrum");
    EXPECT_EQ(recommended5[1].getTitle(), "Dharmakshetra");
    EXPECT_EQ(recommended5[0].getRating(), "TV-14");
    EXPECT_EQ(recommended5[1].getRating(), "TV-PG");
}

TEST(FilterAgeSuite, above17) {
    GatherData data;
    data.setFilePath("tests/age_datatest.csv");
    data.loadData();
    vector<TVShow> allShows = data.getInfo();

    RecommendationEngine ageChoice(20);
    vector<TVShow> recommended5 = ageChoice.compareAge(allShows);

    EXPECT_EQ(recommended5[0].getRating(), "TV-14");
    EXPECT_EQ(recommended5[1].getRating(), "TV-MA");
}