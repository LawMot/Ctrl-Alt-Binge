#include "recommendation.h"
#include "../header/gatherdata.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 
#include <set> 
#include <vector> 
#include <algorithm> 

using namespace std;

// constructor if user didn't choose set preference
RecommendationEngine::RecommendationEngine() 
: age(-1), genre("none"), director("none") {}

// constructor if user chooses age as their preference
RecommendationEngine::RecommendationEngine(int const& userAge) 
: age(userAge), genre("none"), director("none") {}

// constructor if user chooses genre as their preference
RecommendationEngine::RecommendationEngine(string const& userGenre, int const& userAge) 
: age(userAge), genre(userGenre), director("none") {}

// constructor if user chooses director as their preference
RecommendationEngine::RecommendationEngine(string const& userDirector) 
: age(-1), genre("none"), director(userDirector) {}

void RecommendationEngine::setAge(int const& userAge) {
    age = userAge;
}

void RecommendationEngine::setGenre(string const& userGenre) {
    genre = userGenre;
}

void RecommendationEngine::setDirector(string const& userDirector) {
    director = userDirector;
}

int RecommendationEngine::getAge() const {
    return age;
}

string RecommendationEngine::getGenre() const {
    return genre;
}

string RecommendationEngine::getDirector() const {
    return director;
}

vector<TVShow> RecommendationEngine::compareDirectors(vector<TVShow>& inputVector, RecommendationEngine userDirector) {
    GatherData loader;
    loader.setFilePath("TV Show Dataset.csv");
    loader.loadData();
    vector<TVShow> allShows = loader.getInfo();  // allShows holds every show in the csv file
    
    for(int i = 0; i < allShows.size(); ++i) {
        int distance = levenshteinDistance(userDirector.getDirector(), allShows.at(i).getDirector());
        if(distance < 4) {  // if director in the csv file is similar to userDirector add to inputVector 
            inputVector.push_back(allShows.at(i));
        }
    }

    return inputVector;
}

const int RecommendationEngine::levenshteinDistance(string userDirector, string compareDirector) {
    int iterator;

    int length1 = userDirector.length();
    int length2 = compareDirector.length();

    if(compareDirector == "") return length1;

    // matrix to store distances   (rows)        (columns)
    vector<vector<int>> distances(length1 + 1, vector<int>(length2 + 1));

    //fill in rows and columns with each letter from both strings
    for(iterator = 0; iterator <= length1; ++iterator) {
        distances[iterator][0] = static_cast<int>(iterator);
    }
    
    for(iterator = 0; iterator <= length2; ++iterator) {
        distances[0][iterator] = static_cast<int>(iterator);
    }

    //fill matrix using levenshtein's formula
    for(iterator = 1; iterator <= length1; ++iterator) {
        for(int j = 1; j <= length2; ++j) {
            if(userDirector[iterator - 1] == compareDirector[j - 1]) {
                distances[iterator][j] = distances[iterator - 1][j - 1];
            } else {
                distances[iterator][j] = 1+ min({distances[iterator - 1][j], distances[iterator][j - 1], distances[iterator - 1][j - 1]});
            }
        }
    }
    return distances[length1][length2];
}


vector<TVShow> RecommendationEngine::compareAge(const vector<TVShow>& allShows) const {
    vector<TVShow> filteredShows;

    // if age is not valid return nothing
    if (age < 0) {
        cout << "No shows available, that's not even a valid age :/" << endl;
        return filteredShows;
    }
    // interates through the whole dataset (allShows vector)
        for (int i = 0; i < allShows.size(); i++) {
            TVShow show = allShows[i];
            string showRating = show.getRating();
            // if age is 17 or older, push shows with TV-MA or TV-14 to filteredShows vector
            if (age >= 17) {
                if (showRating == "TV-MA" || showRating == "TV-14") {
                    filteredShows.push_back(show);
                }
            // if age is between 14-16 pushback shows with TV-14 & TV-PG ratings to filteredShows vector
            } else if (age < 17 && age >= 14) { 
                if (showRating == "TV-14" || showRating == "TV-PG") {
                    filteredShows.push_back(show);
                }
            // if age is between 10-13 pushback shows with TV-G & TV-PG ratings to filteredShows vector
            } else if (age >= 10 && age <= 13) {
                // up to TV-PG and TV-G
                if (showRating == "TV-G" || showRating == "TV-PG") {
                    filteredShows.push_back(show);
                }
            // if age is between 8-9 pushback shows with TV-Y7 & TV-G ratings to filteredShows vector
            } else if (age > 7 && age < 10) {
                if (showRating == "TV-Y7" || showRating == "TV-G") {
                    filteredShows.push_back(show);
                }
            // if age is 7 and under pushback shows with TV-Y7 & TV-Y ratings to filteredShows vector
            } else if (age <= 7) {
                if (showRating == "TV-Y7" || showRating == "TV-Y") {
                    filteredShows.push_back(show);
                }
            }
    }

    return filteredShows;
}

vector<TVShow> RecommendationEngine::compareGenre(const vector<TVShow>& allShows) const {
    vector<TVShow> genreMatches;

    for(int i = 0; i < allShows.size(); ++i) {
        if(allShows[i].getGenre() == genre) {  // Direct genre match
            genreMatches.push_back(allShows[i]);
        }    
    }
    return genreMatches;
}

vector<TVShow> RecommendationEngine::createRandReccomendation(const vector<TVShow>& allShows) const {
    vector<TVShow> randomShows; // Store the random rec

    if (allShows.empty()) return randomShows;

    srand(time(0));  
    
    set<int> usedIndices;  // Track used shows
    
    // 5 rec or run out of shows
    while (randomShows.size() < 5 && randomShows.size() < allShows.size()) {
        int randomIndex = rand() % allShows.size();  // Get random index
        
        // Check if we haven't used this index before
        if (usedIndices.find(randomIndex) == usedIndices.end()) {
            randomShows.push_back(allShows[randomIndex]);
            usedIndices.insert(randomIndex); // Marked as used 
        }
    }
    
    return randomShows;
}