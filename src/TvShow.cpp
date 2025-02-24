#include "TvShow.h"
#include <string>

const void TVShow::setPreferences(std::string newTitle, std::string newGenre, std::string newDirector, std::string newRating) const {
    title = newTitle;
    genre = newGenre;
    director = newDirector;
    rating = newRating;
}