//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date:  January 2023
//Write a C++ program  that asks the user for a number and a character other than space, draw a triangle of that height and width using 'character graphics'.

#include <iostream>
using namespace std;

int main(){
    int num; //creates a var that will store an int value called num
    char symbol; //creates a var that will store a char value called symbol
    cout << "Enter an int: " << endl; //asks the user for an integer
    cin >> num; //stores the user's input into the var num
    cout << "Enter a symbol other than space: " << endl; //asks the user for a symbol
    cin >> symbol; //stores the user's input into the var symbol 
    
    for (int i = 0; i < num + 1; i++){ //starts at 0, iterates thru the loop until it reaches the value of num which is basically how many rows are in the triangle
        for (int blank = num - i; blank > 0; blank--) //for each row
            cout << " "; //adds a blank space before each row to create a right-aligned triangle
        
        for(int sym = 0; sym < i; sym++){ //starts at 0, adds symbols for each row corresponding to the value of i
            cout << symbol; //outputs symbols in row form
        }
        cout << endl; //adds newline to terminal
    }
  return 0;  //ends function
}
