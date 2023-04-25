//ZARA AMER
//PROF MARYASH
//4/24/23
//HW 9.5: implement a class Rectangle. Provide a constructor to construct
//to construct a rectangle of a given width and height, member functions
//float get_perimeter() and float get_area() that compute the perimeter and area
//and a member function void resize(double factor) that resizes the rectangle
//by multiplying the width and height by the given float factor.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Rectangle {
public:
    double width;
    double height;
    Rectangle(double w, double h);
    double get_perimeter();
    double get_area();
    void resize(double factor);
};

Rectangle::Rectangle(double w, double h) {
    width = w;
    height = h;
}

double Rectangle::get_perimeter() {
    return 2 * (width + height);
}

double Rectangle::get_area() {
    return width * height;
}

void Rectangle::resize(double factor) {
    width = width * factor;
    height = height * factor;
}

// int main() {
//     Rectangle r(2, 4);
//     cout << "Perimeter: " << r.get_perimeter() << endl;
//     cout << "Area: " << r.get_area() << endl;
//     r.resize(2);
//     cout << "Perimeter: " << r.get_perimeter() << endl;
//     cout << "Area: " << r.get_area() << endl;
//     return 0;
// }