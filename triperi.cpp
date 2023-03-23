//Zara Amer
//CSCI 135
//Professor Maryash
//ASSIGNMENT E 7.16: Define a structure Triangle that contains three Point members. Write a function that
//computes the perimeter of a Triangle. Write a program that reads the coordinates of
//the points, calls your function, and displays the result.

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x; //x coord
    double y; //y coord
};

//triangle struct
struct Triangle {
    Point p1;
    Point p2;
    Point p3;
};

//compute perimeter
double perimeter(Triangle tri) {
    //calculate distance between the points
    double distOne = sqrt(pow(tri.p1.x - tri.p2.x, 2) + pow(tri.p1.y - tri.p2.y, 2));
    double distTwo = sqrt(pow(tri.p2.x - tri.p3.x, 2) + pow(tri.p2.y - tri.p3.y, 2));
    double distThree = sqrt(pow(tri.p1.x - tri.p3.x, 2) + pow(tri.p1.y - tri.p3.y, 2));
    
    return (distOne+ distTwo + distThree); //perimeter
}

//program to test
int main() {
    Triangle tri;

    cout << "Coordinates of first point: ";
    cin >> tri.p1.x >> tri.p1.y;
    cout << "Coordinates of second point: ";
    cin >> tri.p2.x >> tri.p2.y;
    cout << "Coordinates of third point: ";
    cin >> tri.p3.x >> tri.p3.y;

    cout << "Perimeter of the triangle is " << perimeter(tri) << endl;
    
    return 0;
}