//Name: Zara Amer
//CSCI135
//Date: 2/25/23
//Assignment E5.15: Write a function void sort3(int&a, int&b, int&c) 
//that swaps the 3 values to arrange them in sorted order.

#include <iostream>
using namespace std;

void sort3(int& a, int& b, int&c) {
    if (a > b){ //sort a and b first, if a is greater than b
        swap(a,b); //swap the values of a and b to ensure a is less than b
    }
    if (b > c){ //sort b and c next, if b is greater than c
        swap (b,c); //swap the values of b and c to ensure b is less than c
    }
}