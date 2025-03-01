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

    void displayRecommendationsCust();

    Display(const RecommendationEngine& engine, const std::vector<TVShow>& allShows);
private:
    const RecommendationEngine& engine;
    const std::vector<TVShow>& allShows;
    void displayRecommendations(const vector<TVShow>);
};

#endif // DISPLAY_H