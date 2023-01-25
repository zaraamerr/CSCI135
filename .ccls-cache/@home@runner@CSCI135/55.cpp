//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date:  January 2023
//Write a C++ program that converts Celsius to Fahrenheit. Your program should prompt the user for the temperature (may contain decimal part) in Celsius and then print out the corresponding degree in Fahrenheit.
#include <iostream>
using namespace std;

int main(){
    cout << "Enter the degree in Celsius: "; //asks the user to input a degree in celsius.
    int celsius; //creates a var called celsius which will be used to store the user's input
    cin >> celsius; //stores the user's input into the var celsius
    int fahrenheit; //creates a var called fahrenheit which will be used to store the fahrenheit conversion of the user's celsius degree input.
    fahrenheit = 9/5 * celsius + 32; //the conversion formula for celsius to fahrenheit is assigned to the var fahrenheit
    cout << "The degree in Farenheit will be :" << farenheit << ".\n"; //outputs the integer result of the conversion formula to the terminal, showing the user the conversion from celsius to fahrenheit
    return 0; //ends function


}
