//Name: Zara Amer
//CSCI135
//Date: 2/23/23
//Assignment E5.14: Write a function void sort2(int&a, int&b) that swaps the values of a and b
// if a is greater than b. otherwise, it leaves a and b unchanged.

#include <iostream>
using namespace std;

void sort2(int& a, int& b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}