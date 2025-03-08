#include "gtest/gtest.h"
#include "../header/display.h"
#include "../recommendationengine/recommendation.h"
#include "../header/TvShow.h"
#include <iostream> 
#include <sstream> 

//Display menu 
TEST(displayTests, testInvalidInputType) 
{
    // Simulate invalid input first
    istringstream input("four\n4\n"); // Invalid input followed by "4"
    cin.rdbuf(input.rdbuf()); // Redirect cin

    ostringstream output;
    cout.rdbuf(output.rdbuf()); // Redirect cout

    Display display({}); 
    display.Menu(); 

    // Expect to see the error message for invalid input
    EXPECT_TRUE(output.str().find("Huh I gave u numbers to choose from?!?! Try Again -_-") != string::npos);

    // Expect to see the menu again after invalid input
    EXPECT_TRUE(output.str().find("Please select an option (1-4): ") != string::npos);

    // Expect that the "4" option will trigger the exit message
    EXPECT_TRUE(output.str().find("Bye! Hope you come around soon!") != string::npos);
}

TEST(displayTests, testInvalidInputInt) 
{
    // Simulate invalid input first
    istringstream input("5\n4\n"); // Invalid input followed by "4"
    cin.rdbuf(input.rdbuf()); // Redirect cin

    ostringstream output;
    cout.rdbuf(output.rdbuf()); // Redirect cout

    Display display({}); 
    display.Menu(); 

    // Expect to see the error message for invalid input
    EXPECT_TRUE(output.str().find("Now you know that wasn't an option, input again.\n") != string::npos);

    // Expect to see the menu again after invalid input
    EXPECT_TRUE(output.str().find("Please select an option (1-4): ") != string::npos);

    // Expect that the "4" option will trigger the exit message
    EXPECT_TRUE(output.str().find("Bye! Hope you come around soon!") != string::npos);
}

//Display dev recs 
TEST(displayTests, devRecs) 
{
    // Redirect input if needed, here we don't need any specific input
    istringstream input(""); 
    cin.rdbuf(input.rdbuf()); // Redirect cin

    // Redirect cout to capture the output
    ostringstream output;
    cout.rdbuf(output.rdbuf()); // Redirect cout

    // Create the Display object
    Display display({});

    // Call the method you're testing
    display.displayRecommendationsDev(); 

    // Define the expected output
    string expectedOutput = 
        "Motunrayo's Recommendations: Abbott Elementary, Criminal Minds, The Next Step\n"
        "Celina's Recommendations: The Office, Brooklyn Nine-Nine, Bridgerton\n"
        "Megan's Recommendations: What We Do in the Shadows, The Good Place, Killing Eve\n"
        "Nam's Recommendations: House of Cards, Euphoria, Sex and the City\n";

    // Compare the captured output with the expected output
    EXPECT_EQ(output.str(), expectedOutput);
}

//Display rand recs 
TEST(displayTests, randRecs) 
{
    
}

//Display custom recs 
TEST(displayTests, custRecs) 
{
    
}