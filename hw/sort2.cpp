//Zara Amer
//CSCI 135
//Professor Maryash
//ASSIGNMENT E 7.1: Write a function void sort2(double* p, double* q) that receives two pointers 
//and sorts the values to which they point. If you call sort2(&x, &y) then x <= y after the call.

#include <iostream>
using namespace std;

//PARAM: two double pointers p and q
//FUNC: sort the values to which they point

void sort2(double* p, double* q) {
    if(*p > *q) {
        double swap = *q;
        *q = *p;
        *p = swap;
    } 
}