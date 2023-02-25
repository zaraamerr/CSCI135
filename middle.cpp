//Name: Zara Amer
//Date: 2/25/23
//csci135
//HW e5.6: Write a function string  middle (string str) that returns
//the middle character in a str if the length of the string is odd
//or the 2 middle characters if the string is even.

#include <iostream>
#include <string>
using namespace std;

string middle (string str){
    int length = str.length(); //create an int var that will store length of str
    if (length % 2 == 0){ //if the str len is even
        return str.substr(length/2-1, 2); //return the middle 2 letters of str by extracting a substr of len 2
    } else{
        return str.substr(length/2, 1); //else if the str len is odd, return the single middle letter by extracting a substr of len 2
    }
}

//test middle func in main
int main(){
    cout << middle ("treat") << endl; //odd
    cout << middle ("superb") << endl; //even
}