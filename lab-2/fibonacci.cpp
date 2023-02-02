// Name: Zara Amer
// Course Name: CSCI 135
// Date: February 2, 2023
// Assignment: Task D for Lab 2
//Write a program fibonacci.cpp, which uses an array of ints
//to compute and print all Fibonacci numbers from F(0) to F(59).

#include <iostream>
using namespace std;

int main(){
    int fib[60]; //creates an array that will store all fibonacci numbers from 0-59
    //first two terms are given
    fib[0]= 0;
    fib[1]= 1;
    for (int i = 0; i < 60; i++){
        fib[i] = fib[i-1] + fib[i-2]; //compute the rest of the fibonacci numbers iteratively
        cout << fib[i] << endl; //output the fibonacci numbers to the terminal
    }
    return 0;
}

//As the numbers approach the two billions, I noticed that some of the
//numbers are negative. I believe that this is happening because the
//integer data type can only store 32-bits worth of information. This means
//that the maximum value an int can hold is 2,147,483,647. When the
//Fibonacci number exceeds that value, the variable overflows, resulting in
//negative numbers. To resolve this, I think I'd have to use a data type
//that can store larger values, such as 'double'.
