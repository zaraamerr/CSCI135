// Name: Zara Amer
// Course Name: CSCI 135
// Date: February 1, 2023
// Assignment: Task C for Lab 2
//Write a program edit-array.cpp that creates an array of 10 integers, 
//and provides the user with an interface to edit any of its elements. 

#include <iostream>
using namespace std;

int main(){
    const int SIZE= 10; //creates a const that will store the size of the array
    int myData[SIZE]; //creates an array of 10 ints 
    for (int i= 0; i < SIZE; i++){ //for every int in the array
        myData[i]= 1; // each cell stores the value 1 as a placeholder
    }
    int index; //creates a var that will store the user's input for index when they start editing the array
    int v; //creates a var that will store the user's input for the new value they want to substitute into the index of their choice
    do {
        cout << "Array elements: " << endl;
        for (int i = 0; i < SIZE; i++){ //for every int in the array
            cout << myData[i] << " "; //print it out to the terminal
        }
        cout << endl;
        cout << "Input index: " << endl; //asks user to input an index
        cin >> index; //stores user input into index
        if (index < 0 || index >= SIZE){ //checks if the index the user inputted is not within the appropriate range of the array
            cout << "Index out of range. Exit program" << endl; //if true, prints out this message
            return 0; //ends
        }
        cout << "Input new value: " << endl; //if the index is all good, ask user to input a new value to be put into that index
        cin >> v; //store user input into v
        myData[index]= v; //sets the value of the element at the user's index to the user's new value
    } while (index >= 0 && index < SIZE); //the loop will keep running if the user enters indexes within the appropriate range of the array. if the user does not enter an appropriate index, the while will be false and the loop will stop iterating.
    return 0;
}