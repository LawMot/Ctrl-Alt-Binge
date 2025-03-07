#include "../header/display.h"
#include <iostream>
#include <limits>
#include <vector>

Display::Display(const std::vector<TVShow>& allShows)
    : allShows(allShows) {}

void Display::Menu() {

    int input;

    while (true) {
        cout << "Welcome to Ctrl+ALt+Binge!" << endl;
        cout << "1. Enter Preferences" << endl;
        cout << "2. Random Recommendation" << endl;
        cout << "3. Developers' Favorites" << endl;
        cout << "4. Exit" << endl;
        cout << "Please select an option (1-4): " << endl;

        cin >> input;
        cout << endl;

        // if user types in the wrong data type
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Huh I gave u numbers to choose from?!?! Try Again -_-" << endl;
            continue;
        }

        // if user chooses enter preferences
        if (input == 1) {
            RecommendationEngine custEngine = SetPreferences();
            displayRecommendationsCust(custEngine);

        } else if (input == 2) {
           //displayRecommendationsRand();
            ChooseMenuOrExit();

        } else if (input == 3) {
            displayRecommendationsDev();
            ChooseMenuOrExit();

        } else if (input == 4) {
            cout << "Bye! Hope you come around soon!" << endl;
            break;
        } else {
            cout << "Now you know that wasn't an option, input again.\n" << endl;
        }
    }
}

RecommendationEngine Display::SetPreferences() {
    int choice;
        
    while (true) {
        cout << "Choose your Recommendation Based off of: " << endl;
        cout << "1. Age" << endl;
        cout << "2. Favorite Genre" << endl;
        cout << "3. Favorite Director" << endl;
        cout << "4. Back to Menu" << endl;
        cout << "5. Exit" << endl;
        cout << "Please select an option (1-3): " << endl;

        cin >> choice;
        cout << endl;

        // if user types in the wrong data type
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ok maybe there was some disconnect.. a number (i.e 7 NOT seven or some other words/characters)\n" << endl;
            continue;
        }

        if (choice == 1) {
            int userAge;
            cout << "Enter Your Age: (a number please!)" << endl;
            cin >> userAge;
            cout << endl;

            // if user types in the wrong data type
            if (cin.fail()) {
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "A number... PLEASE I BEG a number. Try again... \n" << endl;
                continue;
            }
            return RecommendationEngine(userAge);;
        } else if (choice == 2) {
            string userGenre;
            cout << "Enter Your Favorite Genre: " << endl;
            cin >> userGenre;
            return RecommendationEngine(userGenre, -1);
            
        } else if (choice == 3) {
            string userDirector;
            cout << "Enter Your Favorite Director: " << endl;
            cin >> userDirector;
            return RecommendationEngine(userDirector);

        } else if (choice == 4) {
            cout << "Returning to Menu... \n" << endl;
            Menu();
            return RecommendationEngine();  // Not sure how this will loop back to Menu (needs testing for sure)
        } else if (choice == 5) {
            cout << "Exiting..." << endl;
            cout << "Bye! Hope you come around soon!" << endl;
            exit(0);
        } else {
            cout << "Now you know that wasn't an option, input again.\n" << endl;
        }
    }
}

void Display::ChooseMenuOrExit() {
    int nextChoice;
        
    cout << "\n Would you like to go back to menu or exit?" << endl;
    cout << "Input 1 for menu OR input 2 to exit" << endl;
    cin >> nextChoice;

    if (nextChoice == 1) {
        Menu();
    } else if (nextChoice == 2) {
        cout << "Bye! Hope you come around soon!" << endl;
        exit(0);
    } else {
        cout << "Invalid option. Returning to the menu..." << endl;
        Menu();
    }
}

void Display::displayRecommendationsDev() {
    std::cout << "Motunrayo's Recommendations: Abbott Elementary, Criminal Minds, The Next Step\n";
    std::cout << "Celina's Recommendations: The Office, Brooklyn Nine-Nine, Bridgerton\n";
    std::cout << "Megan's Recommendations: What We Do in the Shadows, The Good Place, Killing Eve\n";
    std::cout << "Nam's Recommendations: House of Cards, Euphoria, Sex and the City\n";
}

// void Display::displayRecommendationsRand() {
//     // Get 1 random recommendation from the engine
//     std::vector<TVShow> randomShows = engine.createRandReccomendation(allShows);

//     std::cout << "===== Random Recommendation =====" << std::endl;
//     if (!randomShows.empty()) {
//         std::cout << "We recommend: " << randomShows[0].getTitle() << std::endl;
//     } else {
//         std::cout << "No recommendations available." << std::endl;
//     }
// }

void Display::displayRecommendationsCust(RecommendationEngine userRec) {
    int num = 1;

    std::vector<TVShow> userVector;

    std::vector<TVShow> userCustShows = userRec.compareData(userVector);

    std::cout << "===== Your Custom Recommendation =====" << std::endl;
    if (!userCustShows.empty()) {
        for(int i = 0; i < userCustShows.size(); ++i) {
            std::cout << num << ". " << userCustShows.at(i) << std::endl;
            ++num;
        }
    } else {
        std::cout << "No recommendations available." << std::endl;
    }
}
