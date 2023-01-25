//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date:  January 2023
//Write a C++ program that converts Celsius to Farenheit. Your program should prompt the user for the temperature (may contain decimal part) in Celsius and then print out the corresponding degree in Farenheit.
#include <iostream>
using namespace std;

int main(){
    cout << "Enter the degree in Celsius: ";
    int celsius;
    cin >> celsius;
    int farenheit;
    farenheit = 9/5 * celsius + 32;
    cout << "The degree in Farenheit will be :" << farenheit << ".\n";
    return 0;


}
