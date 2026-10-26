#include <iostream>
#include "GrocerTracker.h"

using namespace std;

// Function to display the main user menu
void displayMenu() {
    cout << "\n===============================" << endl;
    cout << "    CORNER GROCER ITEM TRACKER" << endl;
    cout << "===============================" << endl;
    cout << "1. Look up item frequency" << endl;
    cout << "2. Print frequency of all items" << endl;
    cout << "3. Print histogram of frequencies" << endl;
    cout << "4. Exit program" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    // Instantiate the tracker object. 
    //  automatically triggers loading the input file and creating frequency.dat.
    GrocerTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    int choice = 0;

    // Main menu loop
    do {
        displayMenu();
        
        // Basic input validation for menu selection
        if (!(cin >> choice)) {
            cout << "\nInvalid input. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        // Handle menu options
        switch (choice) {
            case 1:
                tracker.searchItemFrequency();
                break;
            case 2:
                tracker.printFrequencyList();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                cout << "\nExiting program. Have a great day!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please select an option from 1 to 4." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}