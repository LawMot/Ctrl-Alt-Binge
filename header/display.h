#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include <vector>

class Display {
public:
    void Menu();

    void displayRecommendationsDev();

    void displayRecommendationsRand();

    void displayRecommendationsCust();

private:

    void displayRecommendations(const std::vector<std::string>& recommendations);
};

#endif // DISPLAY_H