#include "GrocerTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor initializes filenames and automatically loads data / creates backup
GrocerTracker::GrocerTracker(string inputFile, string backupFile) {
    inputFilename = inputFile;
    backupFilename = backupFile;
    loadDataFile();
    createBackupFile();
}

// Reads the input file and tallies item frequencies using a map
void GrocerTracker::loadDataFile() {
    ifstream inFS;
    string item;

    inFS.open(inputFilename);
    
    // Check if file opened successfully
    if (!inFS.is_open()) {
        cout << "Error: Could not open input file " << inputFilename << endl;
        return;
    }

    // Read each item and increment its count in the map
    while (inFS >> item) {
        itemFrequencyMap[item]++;
    }

    inFS.close();
}

// Creates the frequency.dat backup file automatically at startup
void GrocerTracker::createBackupFile() {
    ofstream outFS;

    outFS.open(backupFilename);

    // Check if backup file opened successfully
    if (!outFS.is_open()) {
        cout << "Error: Could not create backup file " << backupFilename << endl;
        return;
    }

    // Write each item and its frequency to the backup file
    for (auto const& [item, frequency] : itemFrequencyMap) {
        outFS << item << " " << frequency << endl;
    }

    outFS.close();
}

// Menu Option 1: Look up frequency of a specific user-entered item
void GrocerTracker::searchItemFrequency() const {
    string searchItem;
    cout << "Enter the item you wish to look for: ";
    cin >> searchItem;

    // Search map for the item
    auto it = itemFrequencyMap.find(searchItem);
    if (it != itemFrequencyMap.end()) {
        cout << endl << it->first << " was purchased " << it->second << " time(s)." << endl;
    } else {
        cout << endl << searchItem << " not found in the records." << endl;
    }
}

// Menu Option 2: Print all items and their numerical frequencies
void GrocerTracker::printFrequencyList() const {
    cout << "\n--- Item Purchase Frequencies ---" << endl;
    for (auto const& [item, frequency] : itemFrequencyMap) {
        cout << item << " " << frequency << endl;
    }
    cout << "----------------------------------" << endl;
}

// Menu Option 3: Print a text-based histogram representing frequencies with asterisks
void GrocerTracker::printHistogram() const {
    cout << "\n--- Purchase Frequency Histogram ---" << endl;
    for (auto const& [item, frequency] : itemFrequencyMap) {
        cout << left << setw(12) << item << " ";
        for (int i = 0; i < frequency; ++i) {
            cout << "*";
        }
        cout << endl;
    }
    cout << "------------------------------------" << endl;
}