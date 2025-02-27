#include "../header/display.h"
#include <iostream>


void Display::Menu() {
    // if user chooses enter preferences
    int input;
    cout << "Welcome to Ctrl+ALt+Binge!" << endl;
    cout << "1. Enter Preferences" << endl;
    cout << "2. Random Recommendation" << endl;
    cout << "3. Developers' Favorites" << endl;
    cout << "4. Exit"
    cout << "Please select an option (1-4): " << endl;

    if (input == 1) {
        
        int choice;
        
        while (true) {
            cout << "Choose your Recommendation Based off of: " << endl;
            cout << "1. Age" << endl;
            cout << "2. Favorite Genre" << endl;
            cout << "3. Favorite Director" << endl;
            cout << "Please select an option (1-3): " << endl;
            cin >> choice;

            if (choice == 1) {
                int userAge;
                cout << "Enter Your Age: (a number please!)" << endl;
                cin >> userAge;
                while (true) {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Ok maybe there was some disconnect.. a number (i.e 7 NOT seven or some other words/characters)";
                    } else {
                        break;
                    }
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
                cout << "Now you know that wasn't an option, input again." << endl;
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

}

void Display::displayRecommendationsCust() {

}

void Display::displayRecommendations(const std::vector<std::string>& recommendations) {

}