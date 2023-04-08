//Zara Amer
//Professor Maryash
//CSCI 135
//assignment: homework e6.8

//Write a function bool equals(int a[], int a_size, int b[], int b_size)
//that checks whether two arrays have the same elements in the same order.

#include <iostream>
using namespace std;

//@param: two arrays, int a and int b, and their sizes.
//return: bool value that determines whether 2 arrays have the same elements in the same order.

bool equals(int a[], int a_size, int b[], int b_size) {
    if(a_size == b_size) { //check if same size arrays
        for(int i = 0; i < a_size; i++) { //if so, check order of each array
            if(a[i] != b[i]) { //if an element in the first array doesn't match with an element in the second array
                return false; //false
            }
        }
        return true; //true if same size and all elements are same
    } else {
        return false; //immediately returns false if the arrays aren't the same size
    }
}
