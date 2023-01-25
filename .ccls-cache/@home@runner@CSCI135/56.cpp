//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date:  January 2023
//Write a C++ program that asks the user for two integers. The program prints all even integers in [start, end], where both ends are included in the range.

#include <iostream>
using namespace std;

int main(){
    int start; //this var represents the start of the range
    int end; // this var represents the end of the range
    cout << "Type in the starting number: "; //asks the user to input a starting number for the range
    cin >> start; //sets var start as the starting number the user inputted
    cout << "Type in the ending number: "; //asks the user to input an ending number for the range
    cin >> end; //sets the var end as the ending number for the range
    for (int i = start; i < end; i++){ //initial value is whatever value the var start is, loop iterates until it reaches the end value for the range
        if (i%2 == 0){ //argues that if the int is divisble by 2 (even)
            cout << i << "\n"; //then output the value into the terminal followed by a newline.
        }
    }
    return 0; //ends the function
}
