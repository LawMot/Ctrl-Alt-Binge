#ifndef GATHERDATA_H
#define GATHERDATA_H

#include <vector>
#include <string> 
#include "TvShow.h"

using namespace std; 

class GatherData {
    private:   
        vector<TVShow> allData; 
        string filePath; 
    public:
        ~GatherData(); 
        void loadData();
        const vector<TVShow> & getInfo();
        string getFilePath() const;
        void setFilePath(const string & path); 
};

#endif 