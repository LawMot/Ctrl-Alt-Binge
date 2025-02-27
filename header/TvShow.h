#pragma once
#include <string>

class TVShow {
private:
    std::string title;
    std::string genre;
    std::string director;
    std::string rating;
public:
    const void setPreferences(std::string title, std::string genre, std::string director, std::string rating);
};

