//Name: Zara Amer
//Course Name: CSCI 135
//Date: 2/8/23
//Assignment: Task A of Lab 3
//Write a program east-storage.cpp that asks the user to input
//a string representing the date (in MM/DD/YYYY format), and 
//prints out the East basin storage on that day.

#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

int main() {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    // Get rid of the first header line
    std::string junk;
    getline(fin, junk);

    // Asks for user date input
    std::string user_date;
    std::cout << "Enter date: ";
    std::cin >> user_date;

    std::string date;
    double east_storage = 0.0;

    // Compare date and user_date until they're the same
    do {
        fin >> date;
    }
    while (date.compare(user_date) != 0);

    // Retrieve the next value (which happens to be east storage) and store in variable
    fin >> east_storage;

    std::cout << "East basin storage: " << east_storage << " billion gallons." << std::endl;

    fin.close();

    return 0;
}

