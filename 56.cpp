//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date:  January 2023
//Write a C++ program program that asks the user for two integers, the first variable reprsents the start of an range and the second variable represents the end. The program prints all even integers in [start, end], where both ends are inclued in the range.

#include <iostream>
using namespace std;

int main(){
    int start;
    int end;
    cout << "Type in the starting number: ";
    cin >> start;
    cout << "Type in the ending number: ";
    cin >> end;
    for (int i = start; i < end; i++){
        if (i%2 == 0){
            cout << i << "\n";
        }

    }

}
