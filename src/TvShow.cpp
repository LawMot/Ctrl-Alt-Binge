#include "../header/TvShow.h"
#include <string>

const void TVShow::setPreferences(std::string newTitle, std::string newDirector, std::string newRating, std::string newGenre) {
    title = newTitle;
    genre = newGenre;
    director = newDirector;
    rating = newRating;
}
