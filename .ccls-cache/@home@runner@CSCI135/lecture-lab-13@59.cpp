//Name:  Zara Amer
//Email:  zara.amer22@myhunter.cuny.edu
//Date:  January 2023
//Write a C++ program that asks the user for their annual budget for a task (for example, foods, movie) and estimated monthly expense.


#include <iostream>
using namespace std;

int main(){
    float annual; //creates a var that will be used to store the annual budget as a floating-point number
    float monthly; //creates a var that will be used to store the monthly expenses as a floating-point number
    cout << "Input your annual budget: "; //asks the user to input a number for the annual budget
    cin >> annual; //stores the user's input into the var annual
    cout << "Input your month expense: "; //asks the user to input a number for the monthly expenses
    cin >> monthly; //stores the user's input into the var monthly
    float inflation; //creates a var that will be used to store the inflation as a floating-point number
    inflation = monthly * 0.15 + monthly; //defines the var with a formula to calculate the monthly expenses after inflation hits
    printf("month  expense	 remaining balance of budget\n"); //outputs headers into the terminal
    for (int i = 1; i <= 12; i++){ //starts at 1, iterates through the loop 12 times (1 year)
        if (i<=6){ //checks if the months are january-june
            printf("%5d\t%7.2f\t%27.2f\n",i, monthly, annual-monthly * i); //if true, it prints out the current month, the monthly expense, and the remaining annual budget (annual minus monthly) at the end of that month in float
    
        }
        else if (i>6){ //checks if the months are july to december
            printf("%5d\t%7.2f\t%27.2f\n", i, inflation, annual-inflation * i); //if true, it prints out the current month, the monthly expense adjusted with inflation, and the remaining budget (annual minus monthly) at the end of that month in float
            
        }
        if (i==12 && annual-inflation*i >= 0){ //checks if the month is December and if the remaining budget is greater than $0
            cout << "You're on track"; //outputs this message into the terminal
        }
        else if (i==12 && annual-inflation*i < 0){ //checks if the month is December and if the remaining budget is less than 0
            cout << "You need a higher budget"; // outputs this message into the terminal
        }
            
        
    }
    cout << endl; //adds newline to terminal
  return 0; //ends the function
}
