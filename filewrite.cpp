//Zara Amer
//CSCI 135
//Professor Maryash
//assignment e 8.1: Write a program that carries out the following tasks: Open a file with the name
//hello.txt. Store the message “Hello, World!” in the file. Close the file. Open the same file again.
//Read the message into a string variable and print it.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Open the file for writing
    std::ofstream outfile("hello.txt");
    if (!outfile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    outfile << "Hello, World!";
    outfile.close();

    // Open the file for reading
    std::ifstream infile("hello.txt");
    if (!infile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    std::string message;
    std::getline(infile, message);
    infile.close();

    // Print the message
    std::cout << message;

    return 0;
}

