//Name: Zara Amer
//Course Name: CSCI 135
//Date: January 26 2023
//Description: Write a program smaller3.cpp that asks the user 
//to input three integer numbers, and prints out the smallest of the three.

#include <iostream>
using namespace std;

int main(){
    int first; //var that will store the first int that the user inputs
    int second; //var that will store the second int that the user inputs
    int third; //var that will store the third int that the user inputs
    int smallest; //var that will store the smallest value
    cout << "Enter the first number: "; //asks user for first int
    cin >> first; //stores user input into first
    cout << "Enter the second number: "; //asks user for second int
    cin >> second; //stores user input into second
    cout << "Enter the third number: "; //asks user for third int
    cin >> third; //stores user input into third
    smallest= first;
    if (second < smallest){ //if-statement checks if second int is less than the current smallest value
        smallest= second; //if true, smallest is set to the value of the second int
        
    }
    if (third < smallest){ //if-statement checks if the third int is less than the current smallest value
        smallest= third; //if true, smallest is set to the value of the third int
    }
    return 0;
}
