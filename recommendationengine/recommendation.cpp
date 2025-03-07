#include "recommendation.h"

#include <iostream>
#include <string>

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

 vector<TVShow> RecommendationEngine::compareData(const vector<TVShow>) const {

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