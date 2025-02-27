#include "../header/display.h"
#include <iostream>
#include <limits>
#include <vector>

Display::Display(const RecommendationEngine& engine, const std::vector<TVShow>& allShows)
    : engine(engine), allShows(allShows) {}

void Display::Menu() {

    int input;
    cout << "Welcome to Ctrl+ALt+Binge!" << endl;
    cout << "1. Enter Preferences" << endl;
    cout << "2. Random Recommendation" << endl;
    cout << "3. Developers' Favorites" << endl;
    cout << "4. Exit" << endl;
    cout << "Please select an option (1-4): " << endl;
    cin >> input;
    cout << endl;

    // if user chooses enter preferences
    if (input == 1) {
        
        int choice;
        
        while (true) {
            cout << "Choose your Recommendation Based off of: " << endl;
            cout << "1. Age" << endl;
            cout << "2. Favorite Genre" << endl;
            cout << "3. Favorite Director" << endl;
            cout << "Please select an option (1-3): " << endl;

            cin >> choice;
            cout << endl;

            if (choice == 1) {
                int userAge;
                cout << "Enter Your Age: (a number please!)" << endl;
                cin >> userAge;
                cout << endl;

                if (cin.fail()) {
                    cin.clear(); // clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ok maybe there was some disconnect.. a number (i.e 7 NOT seven or some other words/characters)\n" << endl;
                    continue;
                }
                RecommendationEngine ageRecommend(userAge);
                break;
            } else if (choice == 2) {
                string userGenre;
                cout << "Enter Your Favorite Genre: " << endl;
                cin >> userGenre;
                RecommendationEngine genreRecommend(userGenre, -1);
                break;
                
            } else if (choice == 3) {
                string userDirector;
                cout << "Enter Your Favorite Director: " << endl;
                cin >> userDirector;
                RecommendationEngine directorRecommend(userDirector);
                break;

            } else {
                cout << "Now you know that wasn't an option, input again.\n" << endl;
            }
        }
        displayRecommendationsCust();
    }
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