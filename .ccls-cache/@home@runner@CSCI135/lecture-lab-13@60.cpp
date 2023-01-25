//Name: Zara Amer
//Date: January 2023
//Email: zara.amer22@myhunter.cuny.edu
//Write a C++ program that asks the user for a whole number between -128 and 127 and prints out the number in "two's complement" notation.
#include <iostream>
using namespace std;

int main(){
    int n; //creates a var that will store an integer value
    cout << "Give a whole number between -128 and 127: " << endl; // asks the user for a whole number btwn a defined range
    cin >> n; //assigns the user's input into the var n
    int num = n; //let num = n
    if (num < 0){ // checks if num is negative
        num = -num-1; // if true, make num negative and subtract 1
    }
    string result; //creates a var that stores a string value, in other words, the binary representation of num
    int rem; //creates var that stores the remainder as an int value
    while (num > 0){ // as long as num is greater than 0
        rem = num%2; // set remainder as num divided by 2
        result = to_string(rem) + result; //to string converts int into a string
        num /=2; // let num = num/2
    }
    int size = 8; //creates a var called size that is set to 8 to make it an 8-letter string
    int len = result.length(); //creates a var called len to which it returns the number of letters in the string result
    for (int i=0; i < size-len; i++){ //determines size minus len to figure out how many zeroes to pad into the string
        result = "0" + result; //pads the zeroes
    }
    if (n<0){ //checks if num is negative or not
        for (int i = 0; i < result.length(); i++){ //iterates
            if (result[i] == '0'){ //checks if the character in 'i'th position of the string is '0'
                result[i] = '1'; //if true the character is replaced with 1
            }
            else if (result[i] == '1'){ //if the character in the 'i'th position does not end in 0, the if-statement checks instead if it ends in 1
            result[i] = '0'; //if true, the character is replaced with 0
            }
        }
    }
    cout << "Binary string: " << result << endl; //outputs the binary representation of the num the user inputted
  return 0;
}
