//Name: Zara Amer
//Course Name: CSCI 135
//Date: 2/8/23
//Assignment: Task A of Lab 3
//Write a program east-storage.cpp that asks the user to input
//a string representing the date (in MM/DD/YYYY format), and 
//prints out the East basin storage on that day.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;

int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    // Get rid of the first header line
    string junk;
    getline(fin, junk);

    // Asks for target date input
    string target_date;
    cout << "Enter date: ";
    cin >> target_date;

    string date;
    double east_storage = 0.0;

    // Compare date and target_date until they're the same
    do {
        fin >> date;
    }
    while (date.compare(target_date) != 0 && !fin.eof());

    // Retrieve the next value (which happens to be east storage) and store in variable
    if (!fin.eof()) {
        fin >> east_storage;
        cout << "East basin storage: " << east_storage << endl;
    } else {
        cout << "" << endl;
    }

    fin.close();

    return 0;
}
