#include <gtest/gtest.h>
#include "display.h"
#include "recommendation.h"
#include "TvShow.h"

// Test case for displayRecommendationsRand
TEST(DisplayTest, DisplaysRandomRecommendation) {
    // Create some test TV shows
    std::vector<TVShow> testShows;
    testShows.push_back(TVShow("Breaking Bad"));
    testShows.push_back(TVShow("Stranger Things"));

    // Create a RecommendationEngine and Display object
    RecommendationEngine engine;        
    Display display(engine, testShows);

    // Redirect stdout to capture output
    testing::internal::CaptureStdout();
    display.displayRecommendationsRand();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the output contains "===== Random Recommendation ====="
    EXPECT_TRUE(output.find("===== Random Recommendation =====") != std::string::npos);
}

// Test case for empty recommendation list
TEST(DisplayTest, DisplaysNoRecommendationMessage) {
    // Create an empty list of TV shows
    std::vector<TVShow> testShows;

    // Create a RecommendationEngine and Display object
    RecommendationEngine engine;
    Display display(engine, testShows);

    // Redirect stdout to capture output
    testing::internal::CaptureStdout();
    display.displayRecommendationsRand();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the output contains "No recommendations available."
    EXPECT_TRUE(output.find("No recommendations available.") != std::string::npos);
}
