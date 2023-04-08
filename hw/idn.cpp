//Name: Zara Amer
//Course Name: CSCI 135
//Date: 2/6/23
//Assignment: HW E3.5-- Increasing, Decreasing or Neither
//Write a program that reads three numbers and prints “increasing” 
//if they are in increasing order, “decreasing” if they are in decreasing
//order, and “neither” other-wise. Here, “increasing” means “strictly
//increasing”, with each value larger than its predecessor. 

#include <iostream>
using namespace std;

int main(){
    int first; //creates var that will store first num as int
    int second; //creates var that will store second num as int
    int third; //creates var that will store third num as int
    cout << "Enter the first number: " << endl; //asks user for first num
    cin >> first; //stores user input into int first
    cout << "Enter the second number: " << endl; //asks user for second num
    cin >> second; //stores user input into int second
    cout << "Enter the third number: " << endl; //asks user for third num
    cin >> third; //stores user input into int third
    if (first > second && second > third){ //checks if nums are in descending order
        cout << "Decreasing" << endl; //if true, prints this msg to terminal      
    }
    else if (first < second && second < third){ //checks if nums are in ascending order
        cout << "Increasing" << endl; //if true, prints this msg to terminal
    }
    else{
        cout << "Neither" << endl; //if neither strictly increasing nor strictly decreasing, prints this msg to terminal
    }
    return 0; //ends
}