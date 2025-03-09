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

    void displayRecommendationsCust(RecommendationEngine userRec);

    void ChooseMenuOrExit();

    RecommendationEngine SetPreferences();

    Display(const std::vector<TVShow>& allShows);
private:
    const std::vector<TVShow>& allShows;
};

#endif // DISPLAY_H