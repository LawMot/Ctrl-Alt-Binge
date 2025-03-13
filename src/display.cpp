#include "../header/display.h"
#include <iostream>
#include <limits>
#include <vector>

Display::Display(const std::vector<TVShow>& allShows)
    : allShows(allShows), engine(*static_cast<RecommendationEngine*>(nullptr)) {}

Display::Display(const RecommendationEngine& engine, const std::vector<TVShow>& allShows)
    : engine(engine), allShows(allShows) {}

void Display::Menu() {

    int input;
    bool run = true; 

    while (run) {
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
            SetPreferences();
          //  displayRecommendationsCust(custEngine);

        } else if (input == 2) {
           displayRecommendationsRand();
            ChooseMenuOrExit();

        } else if (input == 3) {
            displayRecommendationsDev();
            ChooseMenuOrExit();

        } else if (input == 4) {
            cout << "Bye! Hope you come around soon!" << endl;
            run = false;
            break; 
        } else {
            cout << "Now you know that wasn't an option, input again.\n" << endl;
        }
    }
    return; 
}

void Display::SetPreferences() {
    int choice;
        
    while (true) {
        cout << "Choose your Recommendation Based off of: " << endl;
        cout << "1. Age" << endl;
        cout << "2. Favorite Genre" << endl;
        cout << "3. Favorite Director" << endl;
        cout << "4. Back to Menu" << endl;
        cout << "5. Exit" << endl;
        cout << "Please select an option (1-5): " << endl;

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
            cin.ignore(); 
            cin >> userAge;
            cout << endl;

            // if user types in the wrong data type
            if (cin.fail()) {
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "A number... PLEASE I BEG a number. Try again... \n" << endl;
                continue;
            }
         //   displayRecommendationsCust(custEngine);
          //  return RecommendationEngine(userAge);
              displayAgeRec(userAge); 

        } else if (choice == 2) {
            vector<string> genres = {"Anime Series", "British TV Shows", "Classic & Cult TV", "Crime TV Shows", "Docuseries", "International TV Shows", "Kids' TV", "Reality TV", "Romantic TV Shows", "Spanish-Language TV Shows", "Stand-Up Comedy & Talk Shows", "TV Action & Advanture", "TV Comedies", "TV Dramas", "TV Horror", "TV Sci-Fi & Fantasy", "TV Shows"};

            cout << "\nAvailable Genres:" << endl;
            for(size_t i = 0; i < genres.size(); ++i) {
                cout << i+1 << ". " << genres[i] << endl;
            }

            int genreChoice;
            cout << "Select genre (1-" << genres.size() << "): ";
            cin.ignore(); 
            cin >> genreChoice;

            if(genreChoice > 0 && genreChoice <= genres.size()) {
               displayGenreRec(genres[genreChoice-1]);
            } else {
                cout << "Invalid genre selection!" << endl;
            }
            
        } else if (choice == 3) {
            string userDirector;
            cin.ignore(); // Avoids getline issues from previous cin
            cout << "Enter Your Favorite Director: ";
            getline(cin, userDirector);

            if (userDirector.empty()) {
                cout << "No director entered. Cannot generate recommendations.\n" << endl;
                continue;
            }

            displayDirectorsRec(userDirector);
   //         return RecommendationEngine();

        } else if (choice == 4) {
            cout << "Returning to Menu... \n" << endl;
            Menu();
        //    return RecommendationEngine();  // Not sure how this will loop back to Menu (needs testing for sure)
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

void Display::displayRecommendationsRand() {
    GatherData loader; 
    loader.setFilePath("TV Show Dataset.csv"); 
    loader.loadData(); 

    vector <TVShow> allShows = loader.getInfo(); 

    RecommendationEngine engine; 
    vector <TVShow> recs = engine.createRandReccomendation(allShows); 

    cout << "===== Random Recommendations =====" << endl;
    if (!recs.empty()) {
        cout << "Here are your random picks:" << endl;
        for (size_t i = 0; i < recs.size(); ++i) {
            cout << "- " << recs[i].getTitle() << endl;
        }
    } else {
        cout << "No shows available." << endl;
    }
}


void Display::displayDirectorsRec(string userDirector) {
    vector<TVShow> recommendedShows;
    RecommendationEngine engine;
    
    engine.setDirector(userDirector); 
    
    if (userDirector.empty()) {
        cout << "No director entered. Cannot generate recommendations." << endl;
        return;
    }
    
    // Get recommendations based on similar directors
    recommendedShows = engine.compareDirectors(recommendedShows, engine);
    
    // Display results
    if (recommendedShows.empty()) {
        cout << "No recommendations found for director: " << userDirector << endl;
    } else {
        cout << "Recommended TV Shows with similar directors:" << endl;
        for (const auto& show : recommendedShows) {
            cout << endl; 
            cout << "Title: " << show.getTitle() << endl;
            cout << "Director: " << show.getDirector() << endl;
            cout << "Rating: " << show.getRating() << endl;
            cout << "Genre: " << show.getGenre() << endl << endl;
        }
    }
}

void Display::displayAgeRec(int userAge) {
   vector<TVShow> recommendedShows;
   RecommendationEngine engine;
   
   engine.setAge(userAge);
   
   // Get recommendations based on similar directors
   recommendedShows = engine.compareAge(allShows);

    std::cout << "===== Your Custom Recommendation =====" << std::endl;
    if (!recommendedShows.empty()) {
        int count = 1;
        for(const auto& show : recommendedShows) {
            if (count >= 11) break;
            cout << count << ". ";
            cout << "Title: " << show.getTitle() << endl;
            cout << "Director: " << show.getDirector() << endl;
            cout << "Rating: " << show.getRating() << endl;
            cout << "Genre: " << show.getGenre() << endl << endl;
            count++;
        }
    } else {
        std::cout << "No recommendations available." << std::endl;
    }
    cout << endl;
}

void Display::displayGenreRec(string userGenre) {
    vector<TVShow> recommendedShows;
    RecommendationEngine engine;
    
    engine.setGenre(userGenre);
    
    // Get recommendations based on similar directors
    recommendedShows = engine.compareGenre(allShows);
 
     std::cout << "===== Your Custom Recommendation =====" << std::endl;
     if (!recommendedShows.empty()) {
         int count = 1;
         for(const auto& show : recommendedShows) {
             if (count >= 11) break;
             cout << count << ". ";
             cout << "Title: " << show.getTitle() << endl;
             cout << "Director: " << show.getDirector() << endl;
             cout << "Rating: " << show.getRating() << endl;
             cout << "Genre: " << show.getGenre() << endl << endl;
             count++;   
         }
     } else {
         std::cout << "No recommendations available." << std::endl;
     }
     cout << endl;
 }
 
   