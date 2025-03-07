#include "../header/display.h"
#include "../header/gatherdata.h"
#include "../header/TvShow.h"

int main () {
    // Create an instance of GatherData to load TV shows from the CSV file
    GatherData gatherData;
    
    // Set the path to the CSV file
    gatherData.setFilePath("TV Show Dataset.csv");

    // Load data from the CSV file
    gatherData.loadData();

    // Get the vector of TVShow objects
    std::vector<TVShow> allShows = gatherData.getInfo();

    // Create an instance of Display and pass the vector of TV shows
    Display display(allShows);

    // Start the menu interaction
    display.Menu();

    return 0;
}
