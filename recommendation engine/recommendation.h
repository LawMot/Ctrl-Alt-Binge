#pragma once

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

    // member functions
    void setAge() const;
    void setGenre(const string genre) const;
    void setDirector(const string director) const;
    int getAge() const;
    string getGenre() const;
    string getDirector() const;
    vector<TVShow> compareData(const vector<TVShow>) const;
    vector<TVShow> createRandReccomendation(const vector<TVShow>) const;

};

