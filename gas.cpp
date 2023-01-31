// Name: Zara Amer
// Course Name: CSCI 135
// Date: January 31, 2023
// Write a program that asks the user to input the
// number of gallons of gas in the tank, the fuel efficiency in miles
// per gallon and the price of gas per gallon. Then print the cost 
// per 100 miles and how far the car can go with the gas in the tank.

#include <iostream>
using namespace std;

int main (){
    int num_of_gallons;
    int miles_per_gallon;
    int price;
    int cost_per_100_miles;
    int distance;
    cout << "Enter a number of gallons: " << endl;
    cin >> num_of_gallons;
    cout << "Enter how many miles can be driven with one gallon of fuel: " << endl;
    cin >> miles_per_gallon;
    cout << "Enter the price of gas per gallon: " << endl;
    cin >> price;
    cost_per_100_miles= (price * 100 / miles_per_gallon);
    distance= (num_of_gallons*miles_per_gallon);
    cout << "The cost to travel 100 miles is " << cost_per_100_miles << " dollars and with " << num_of_gallons << " gallons of gas, the car can travel " << distance << " miles." << endl;
    return 0;

}