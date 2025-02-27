#pragma once

#include "../header/gatherdata.h"
#include "../header/TvShow.h"

#include <string>

using namespace std;

class RecommendationEngine {
    private:
      int age;
      string genre;
      string director;
    public:
    // constructor
    RecommendationEngine();
    RecommendationEngine(int const& userAge);
    RecommendationEngine(string const& userGenre, int const& userAge);
    RecommendationEngine(string const& userDirector);


    // member functions
    void setAge(int const& userAge);
    void setGenre(string const& userGenre);
    void setDirector(string const& userDirector);
    int getAge() const;
    string getGenre() const;
    string getDirector() const;
    vector<TVShow> compareData(const vector<TVShow>) const;
    vector<TVShow> createRandReccomendation(const vector<TVShow>) const;
};

