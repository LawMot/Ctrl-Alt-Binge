#ifndef DISPLAY_H
#define DISPLAY_H

#include "../recommendationengine/recommendation.h"
#include "../header/TvShow.h"

#include <iostream>
#include <string>
#include <vector>

class Display {
public:
    void Menu();

    void displayRecommendationsDev();

    void displayRecommendationsRand();

    void displayDirectorsRec(string director); 

    void displayAgeRec(int userAge);

    void displayGenreRec(string userGenre);

    void ChooseMenuOrExit();

    void SetPreferences();

    Display(const std::vector<TVShow>& allShows);

    Display(const RecommendationEngine& engine, const std::vector<TVShow>& allShows);
private:
    const RecommendationEngine& engine;
    const std::vector<TVShow>& allShows;
    bool agePreference = false;
    bool genrePreference = false;
    bool directorPreference = false;
};

#endif // DISPLAY_H