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
    int num_of_gallons; //creates a var that will store the num of gallons
    int miles_per_gallon; //creates a var that will store the fuel efficiency in miles per gallon
    int price; //creates a var that will store the price of gas per gallon
    double cost_per_100_miles; //creates a var that will store the calculation of how much it costs to travel 100 miles
    int distance; //creates a var that will store the calculation of how far the car can go with the current amt of gas in the tank
    cout << "Enter a number of gallons: " << endl; //asks user to input # of gallons
    cin >> num_of_gallons; //stores user input into var num_of_gallons
    cout << "Enter how many miles can be driven with one gallon of fuel: " << endl; //asks user to input how many miles can be traveled w/ 1 gallon
    cin >> miles_per_gallon; //stores user input into var miles_per_gallon
    cout << "Enter the price of gas per gallon: " << endl; //asks user to input price of gas per gallon
    cin >> price; //stores user input into var price
    cost_per_100_miles= (100.0 / miles_per_gallon * price); //set var cost_per_100 miles to a calculation that multiplies the price by 100 and divides it by how many miles can be traveled per gallon to determine what the cost is to travel 100 miles
    distance= (num_of_gallons*miles_per_gallon); //set var distance to a calculation that multiplies num_of_gallons by miles_per_gallon to determine how many miles the car can travel with the current amt of gas in its tank.
    cout << "The cost to travel 100 miles is " << cost_per_100_miles << " dollars and with " << num_of_gallons << " gallons of gas, the car can travel " << distance << " miles." << endl; //print output into terminal
    return 0; //end

}