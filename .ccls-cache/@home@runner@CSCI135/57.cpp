//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date: January 2023
//Write a C++ program that asks the user for the current number of credit hours and prints

#include <iostream>
using namespace std;

int main(){
    int credits;
    cout << "Enter credit hours: ";
    cin >> credits;
    if (credits > 94){
        cout << "senior";
    }
    else if (credits < 94 && credits > 61){ 
        cout << "junior";
    }
    else if (credits < 61 && credits > 28){
        cout << "sophmore";
    }
    else if (credits < 28){
        cout << "freshman";
    }


}
