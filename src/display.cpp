#include "../header/display.h"
#include <iostream>

Display::Display(const RecommendationEngine& engine, const std::vector<TVShow>& allShows)
    : engine(engine), allShows(allShows) {}

void Display::Menu() {
 
}

void Display::displayRecommendationsDev() {
    std::cout << "Motunrayo's Recommendations: Abbott Elementary, Criminal Minds, The Next Step\n";
    std::cout << "Celina's Recommendations: The Office, Brooklyn Nine-Nine, Bridgerton\n";
    std::cout << "Megan's Recommendations: What We Do in the Shadows, The Good Place, Killing Eve\n";
    std::cout << "Nam's Recommendations: House of Cards, Euphoria, Sex and the City\n";
}

void Display::displayRecommendationsRand() {
    // Get 1 random recommendation from the engine
    std::vector<TVShow> randomShows = engine.createRandReccomendation(allShows);

    std::cout << "===== Random Recommendation =====" << std::endl;
    if (!randomShows.empty()) {
        std::cout << "We recommend: " << randomShows[0].getTitle() << std::endl;
    } else {
        std::cout << "No recommendations available." << std::endl;
    }
}

void Display::displayRecommendationsCust() {

}

void Display::displayRecommendations(const vector<TVShow>) {

}