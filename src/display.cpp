#include "../header/display.h"
#include <iostream>


void Display::Menu() {
 
}

void Display::displayRecommendationsDev() {
    std::cout << "Motunrayo's Recommendations: Abbott Elementary, Criminal Minds, The Next Step\n";
    std::cout << "Celina's Recommendations: The Office, Brooklyn Nine-Nine, Bridgerton\n";
    std::cout << "Megan's Recommendations: What We Do in the Shadows, The Good Place, Killing Eve\n";
    std::cout << "Nam's Recommendations: House of Cards, Euphoria, Sex and the City\n";
}

void Display::displayRecommendationsRand() {

}

void Display::displayRecommendationsCust() {

}

void Display::displayRecommendations(const std::vector<std::string>& recommendations) {

}