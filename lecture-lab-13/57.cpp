//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date: January 2023
//Write a C++ program that asks the user for the current number of credit hours and prints

#include <iostream>
using namespace std;

int main(){
    int credits; //creates a var for credits that will store int values
    cout << "Enter credit hours: "; //asks the user to enter number of credit hours earned
    cin >> credits; //stores user's input into var credits
    if (credits > 94){ //if statement checks if credits are greater than 94
        cout << "senior"; //if true, the program outputs senior into the terminal
    }
    else if (credits < 94 && credits >= 61){ //if the credits are not greater than 94, the if-statement goes on to check if the credits are less than 94 and greater than or equal to 61
        cout << "junior"; //if true, the program outputs junior into the terminal
    }
    else if (credits < 61 && credits >= 28){ //if the credits are not within the junior range, the if-statement goes on to check if the credits are less than 61 and greater than or equal to 28
        cout << "sophomore"; //if true, the program outputs sophomore into the terminal
    }
    else if (credits < 28){ //if the credits are not within the sophomore range, the if-statement goes on to check if the credits are less than 28
        cout << "freshman"; //if true, the program outputs freshman into the terminal
    }
  return 0; //ends the function

}
