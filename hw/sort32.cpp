#include <iostream>
using namespace std;

void sort2(int& a, int& b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}

void sort3(int& a, int& b, int&c) {
    sort2(a,b);
    sort2(a,c);
    sort2(b,c);
}

int main(){
    int a= 5;
    int b= 3;
    int c= 1;
    sort3(a,b,c);
    cout << a << b << c << endl;
}
