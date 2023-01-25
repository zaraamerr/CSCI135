//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date:  January 2023
//Write a C++ program that will print "10" 6 times in one row, for 10 rows.

#include <iostream>
using namespace std;

//Prints "10" 6 times in one row for 10 rows.
int main(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 6; j++){
            cout << "10";
        }
        cout << "\n";
    }

    return 0;
}
