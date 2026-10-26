#ifndef GROCERTRACKER_H
#define GROCERTRACKER_H

#include <string>
#include <map>

using namespace std;

class GrocerTracker {
private:
    // Private data member to store item names and their frequency counts
    map<string, int> itemFrequencyMap;

    string inputFilename;
    string backupFilename;

public:
    // Constructor
    GrocerTracker(string inputFile, string backupFile);

    // Core file processing functions
    void loadDataFile();
    void createBackupFile();

    // Menu option functions
    void searchItemFrequency() const;
    void printFrequencyList() const;
    void printHistogram() const;
};

#endif // GROCERTRACKER_H