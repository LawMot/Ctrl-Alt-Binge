#include "../header/gatherdata.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

GatherData::~GatherData() {}

void GatherData::loadData()
{
    ifstream file(filePath); 
    
    if (!file.is_open())   
    {
        throw runtime_error("Error: Could not open file"); 
    }

    string oneshow; 

    while(getline(file, oneshow))
    {
        stringstream ss(oneshow); 
        string fields[4]; // Array to store exactly 4 fields

        for (int i = 0; i < 4; i++)
        {
            if (!getline(ss, fields[i], ',')) {
                fields[i] = "Unknown"; // Handle missing fields properly
            }
            if (fields[i].empty()) {
                fields[i] = "Unknown"; // Convert empty fields to "Unknown"
            }
        }

        TVShow show; 
        show.setPreferences(fields[0], fields[1], fields[2], fields[3]); 
        allData.push_back(show); 
    }
    file.close(); 
}

const vector<TVShow> & GatherData::getInfo()
{
    return allData; 
}

string GatherData::getFilePath() const
{
    return filePath; 
}

void GatherData::setFilePath(const string & path)
{
    filePath = path; 
}