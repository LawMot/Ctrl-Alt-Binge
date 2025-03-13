#include "../header/gatherdata.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST(getDataTests, badDataTest) 
{
    GatherData data;
    data.setFilePath("nonreal.csv"); 
    ASSERT_THROW(data.loadData(), runtime_error);
}

   
TEST(getDataTests, goodDataTest) 
{
    GatherData data;
    data.setFilePath("TV Show Dataset.csv");
    ASSERT_NO_THROW(data.loadData());
}


TEST(getDataTests, testGetInfo) 
{
    GatherData data;
    data.setFilePath("tests/datatest.csv");
    data.loadData();
    const auto& shows = data.getInfo();

    EXPECT_EQ(shows[0].getTitle(), "Blood & Water");
    EXPECT_EQ(shows[0].getDirector(), "Unknown"); // No director provided in CSV
    EXPECT_EQ(shows[0].getRating(), "TV-MA");
    EXPECT_EQ(shows[0].getGenre(), "International TV Shows");

    EXPECT_EQ(shows[1].getTitle(), "Unknown"); // No title provided
    EXPECT_EQ(shows[1].getDirector(), "Julien Leclercq");
    EXPECT_EQ(shows[1].getRating(), "TV-MA");
    EXPECT_EQ(shows[1].getGenre(), "Crime TV Shows");

    EXPECT_EQ(shows[2].getTitle(), "Jailbirds New Orleans");
    EXPECT_EQ(shows[2].getDirector(), "Julien Leclercq");
    EXPECT_EQ(shows[2].getRating(), "Unknown"); // No rating provided
    EXPECT_EQ(shows[2].getGenre(), "Docuseries");

    EXPECT_EQ(shows[3].getTitle(), "Kota Factory");
    EXPECT_EQ(shows[3].getDirector(), "Julien Leclercq");
    EXPECT_EQ(shows[3].getRating(), "TV-MA");
    EXPECT_EQ(shows[3].getGenre(), "Unknown"); // No genre provided
}


TEST(getDataTests, testSetGetFilePath) 
{
    GatherData data;
    data.setFilePath("TV Show Dataset.csv");
    EXPECT_EQ (data.getFilePath(),"TV Show Dataset.csv");
}
