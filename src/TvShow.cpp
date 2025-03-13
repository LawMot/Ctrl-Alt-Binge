#include "../header/TvShow.h"
#include <string>
#include <iostream>

const void TVShow::setPreferences(std::string newTitle, std::string newDirector, std::string newRating, std::string newGenre) {
    title = newTitle;
    genre = newGenre;
    director = newDirector;
    rating = newRating;
}

std::ostream& operator<<(std::ostream& os, const TVShow& show) {
    os << "Title: " << show.title
       << ", Genre: " << show.genre
       << ", Director: " << show.director
       << ", Rating: " << show.rating;
    return os;
}   