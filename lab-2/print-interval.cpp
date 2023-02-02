// Name: Zara Amer
// Course Name: CSCI 135
// Date: February 1, 2023
// Assignment: Task B for Lab 2
//Write a program print-interval.cpp that asks the user to input two
//integers L and U (representing the lower and upper limits of the 
//interval), and print out all integers in the range L ≤ i < U separated
//by spaces. Include the lower limit, but exclude the upper limit.

#include <iostream>
using namespace std;

int main (){
    int L; //create a var that will store the user's input for the lower limit of the interval
    int U; //creates a var that will store the user's input for the higher limit of the interval
    cout << "Enter L: " << endl; //ask user to input int L
    cin >> L; //store user input into L
    cout << "Enter U: " << endl; //ask user to input int U
    cin >> U; //store user input into U
    for (int i= L; i < U; i++){ //for every int in the range btwn U and L, starting at L
        cout << i << " " << endl; //output the ints within the range
    }
    return 0;
}