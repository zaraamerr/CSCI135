//Name: Zara Amer
//Course Name: CSCI 135
//Date: January 25 2023
//Description: Write a program smaller.cpp that asks the user to
//input two integer numbers and prints out the smaller of the two.

#include <iostream>
using namespace std;

int main(){
    int first; //var that will store the first int that the user inputs
    int second; //var that will store the second int that the user inputs
    cout << "Enter the first number: "; //asks user for first int
    cin >> first; //stores user input into first
    cout << "Enter the second number: "; //asks user for second int
    cin >> second; //stores user input into second
    if (first < second){ //if-statement checks if first int is less than second int
        cout << "The smaller of the two is " << first << endl; //if true, it prints this message
    }
    else if (second < first){ //if the previous if-statement is false, it goes on to check if the second int is less than the first int
        cout << "The smaller of the two is " << second << endl; //if true, it prints this message
    }
    return 0;
}
