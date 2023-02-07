// Name: Zara Amer
// Course Name: CSCI 135
// Date: 2/6/23
// Assignment: HW E4.8 - 1 character per line
// Write a program that reads a word and prints each character of
// the word on a separate line.

#include <iostream>
#include <string>
using namespace std;

int main(){
    string word; //creates var that will store word as str value
    cout << "Enter a word: " << endl; //asks user for word
    cin >> word; //stores user input into str word
    for (int i = 0; i < word.length(); i++){ //for every character in the word
        cout << word[i] << endl; //print the character and create newline
    }
    return 0; //ends
}