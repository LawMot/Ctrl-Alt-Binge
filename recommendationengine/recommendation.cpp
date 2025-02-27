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
    this->age = age;
}

void RecommendationEngine::setGenre(string const& userGenre) {
    this->genre = genre;
}

void RecommendationEngine::setDirector(string const& userDirector) {
    this->director = director;
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

// vector<TVShow> RecommendationEngine::compareData(const vector<TVShow>) const {

// }

// vector<TVShow> RecommendationEngine::createRandReccomendation(const vector<TVShow>) const {

// }