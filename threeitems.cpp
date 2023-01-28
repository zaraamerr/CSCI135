// Name: Zara Amer
// Course Name: CSCI 135
// Date: January 27, 2023
// Write a program that asks the user for 3 items, such as the name of your
// three best friends or three favorite movies, and prints them on
// three separate lines.

#include <iostream>
using namespace std;

int main (){
    string first; //create a var that will store user's first icecream flavor as a string
    string second; //create a var that will store user's second icecream flavor as a string
    string third; //create a var that will store user's third icecream flavor as a string
    cout << "Enter your first ice cream flavor of choice: "; //ask user to input first flavor
    cin >> first; //store user input into first var
    cout << "Enter your second ice cream flavor of choice: "; //ask user to input second flavor
    cin >> second; //store user input into second var
    cout << "Enter your third ice cream flavor of choice: "; //ask user to input third flavor
    cin >> third; //store user input into third var

    cout << first << "\n" << second << "\n" << third << endl; //print all three flavors on separate lines

    return 0; //end

}