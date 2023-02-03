//Name: Zara Amer
//Course Name: CSCI 135
//Date: 2/3/23
//Assignment E3.1
//Write a program that reads an int and prints whether it is 
//negative. positive, or zero

#include <iostream>
using namespace std;

int main (){
    int number;
    cout << "Enter an integer: " << endl;
    cin >> number;
    if (number < 0){
        cout << "This integer is negative." << endl;
    }
    else if (number > 0){
        cout << "This integer is positive." << endl;
    }
    else{
        cout << "This integer is zero." << endl;
    }
}

