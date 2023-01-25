//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date:  January 2023
//Write a C++ program that will print "10" 6 times in one row, for 10 rows.

#include <iostream>
using namespace std;

//Prints "10" 6 times in one row for 10 rows.
int main(){
    for (int i = 0; i < 10; i++){ //starts at 0, checks if rows are < 10, if true it executes the loop until there are 10 rows. if false it does not execute the loop.
        for (int j = 0; j < 6; j++){ //starts at 0, checks if "10" is printed < 6 times, if true it keeps printing "10" within the row until there are 6 "10"s. if false, it does not print "10" in the same row again.
            cout << "10"; //output is 10
        }
        cout << "\n"; //creates a new line after each row
    }

    return 0; //ends the function
}
