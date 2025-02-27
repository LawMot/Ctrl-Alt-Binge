#pragma once
#include <string>

class TVShow {
private:
    std::string title;
    std::string genre;
    std::string director;
    std::string rating;
public:
<<<<<<< HEAD
    const void setPreferences(std::string title, std::string genre, std::string director, std::string rating);
};

=======
    const void setPreferences(std::string title, std::string director, std::string rating, std::string genre);

    std::string getTitle() const { return title; }
    std::string getGenre() const { return genre; }
    std::string getDirector() const { return director; }
    std::string getRating() const { return rating; }
};
>>>>>>> 2804415 (save file changes)
