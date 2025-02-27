#include "recommendation.h"
#include "gatherdata.h"
#include "TvShow.h"

#include <iostream>
#include <string>

using namespace std;

// constructor if user didn't choose set preference
RecommendationEngine::RecommendationEngine() 
: age(-1), genre("none"), director("none") {}

// constructor if user chooses age as their preference
RecommendationEngine::RecommendationEngine(int userAge) 
: age(userAge), genre("none"), director("none") {}

// constructor if user chooses genre as their preference
RecommendationEngine::RecommendationEngine(string userGenre, int userAge) 
: age(userAge), genre(userGenre), director("none") {}

// constructor if user chooses director as their preference
RecommendationEngine::RecommendationEngine(string userDirector) 
: age(-1), genre("none"), director(userDirector){}

void RecommendationEngine::setAge(const int age) const {
    this->age = age;
}

void RecommendationEngine::setGenre(const string genre) const{
    this->genre = genre;
}

void RecommendationEngine::setDirector(const string director) const{
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

vector<TVShow> RecommendationEngine::compareData(const vector<TVShow>) const {

}

vector<TVShow> RecommendationEngine::createRandReccomendation(const vector<TVShow>) const {

}