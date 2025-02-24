#ifdef RECOMMENDATION_H
#define RECOMMENDATION_H

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
    void setAge();
    void setGenre();
    void setDirector();
    int getAge();
    string getGenre();
    string getDirector();
    vector<TVShows> compareData(vector<TVShows>);
    vector<TVShows> createRandReccomendation(vector<TVShows>);

};

#endif