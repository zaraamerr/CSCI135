//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date:  January 2023
//Write a C++ program  that asks the user for a number and a character other than space, draw a triangle of that height and width using 'character graphics'.

#include <iostream>
using namespace std;

int main(){
    int num;
    char symbol;
    cout << "Enter an int: " << endl;
    cin >> num;
    cout << "Enter a symbol other than space: " << endl;
    cin >> symbol;
    
    for (int i = 0; i < num; i++){
        for (int blank = num - i; blank > 0; blank--)
            cout << " ";
        
        for(int sym = 0; sym < i; sym++){
            cout << symbol;
        }
        cout << endl;
    }
    
}
