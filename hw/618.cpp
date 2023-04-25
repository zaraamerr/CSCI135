//ZARA AMER
//CS 135
//PROF MARYASH
//4/24
//HW 6.18: Write a function vector <int> append (vector <int> a, vector <int> b) that
//appends one vector after another. E.G. if a is 1 4 9 16 and b is 9 7 4 9 11, then append
//returns 1 4 9 16 9 7 4 9 11

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <int> append (vector <int> a, vector <int> b) {
    vector <int> c;
    for (int i = 0; i < a.size(); i++) {
        c.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        c.push_back(b[i]);
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
    b.push_back(9);
    b.push_back(7);
    b.push_back(4);
    b.push_back(9);
    b.push_back(11);
    vector <int> c = append(a, b);
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}