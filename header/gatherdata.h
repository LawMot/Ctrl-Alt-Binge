#ifndef GATHERDATA_H
#define GATHERDATA_H

#include <vector>
#include <string> 
#include "TVShow.h"

using namespace std; 

class GatherData {
    private:
        vector<TVShows> allData; 
        string filePath; 
    public:
        ~GatherData(); 
        void loadData();
        const vector<TVShows> & getInfo();
        string getFilePath() const;
        void setFilePath(const string & path); 
};

#endif 