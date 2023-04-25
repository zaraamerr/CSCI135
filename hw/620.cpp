//ZARA AMER
//PROF MARYASH
//CS 135
//4/24/23
//HW 6.20: Write a function vector <int> merge_sorted (vector <int> a, vector <int> b)
//that merges two vectors, producing a new sorted vector. Keep an index into each vector
//indicating how much of it has been processed already. Each time, append the smallest unprocessed element
//from either vector, then advance the index. For example, if a is 1 4 9 16 and b is 4 7 9 9 11,
//the merge_sorted returns the vector 1 4 4 7 9 9 9 11 16

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <int> merge_sorted (vector <int> a, vector <int> b) {
    vector <int> c;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        c.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        c.push_back(b[j]);
        j++;
    }
    return c;
}

int main() {
    vector <int> a;
    vector <int> b;
    a.push_back(1);
    a.push_back(4);
    a.push_back(9);
    a.push_back(16);
    b.push_back(4);
    b.push_back(7);
    b.push_back(9);
    b.push_back(9);
    b.push_back(11);
    vector <int> c = merge_sorted(a, b);
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}