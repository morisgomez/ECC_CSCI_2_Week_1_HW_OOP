/*
 Program Name: MortgagePayment.cpp
 Programmer: Moris
 Date: Saturday 02/15/2024
 Version Control: 1.0
 About: Week 1, CSCI 2, Homework.
 Description:
 Design a class that will determine the monthly payment on a home
 mortgage.The monthly payment with interest compounded monthly can
 be calculated as follows: monthlyPayment = (principal  x rate)/[1-(rate+1)^-term]
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//create class:
class MonthlyMortgagePayment
{
//create private variables:
private:
    double principal; //loan amount.
    double rate; //yearly interest rate.
    double term; //years to pay off loan.

//create public member functions:
public:
    //constructors:
    MonthlyMortgagePayment() //default constructor.
    {
        principal = 0;
        rate = 0;
        term = 0;
    }
    MonthlyMortgagePayment(double prin, double rat, double ter) //3 variable constructor.
    {
        principal = prin;
        rate = rat;
        term = ter;
    }
    
    //getters:
    double getPrincipal()
    {
        return principal;
    }
    
    double getRate()
    {
        return rate;
    }
    
    double getTerm()
    {
        return term;
    }
    
    //setters:
    void setPrincipal(double p)
    {
        principal = p;
    }
    
    void setRate(double r)
    {
        rate = r;
    }
    
    void setTerm(double t)
    {
        term = t;
    }
    
    //create functions for calculations:
    double calculateMonthlyRate()
    {
        return getRate() / 1200.0;
    }
    
    double calculateTotalMonths()
    {
        return getTerm() * 12.0;
    }
    
    double calculateMonthlyPayment()
    {
        return getPrincipal() * calculateMonthlyRate() / (1.0 - pow(calculateMonthlyRate() + 1, - calculateTotalMonths()));
        //using getters for calculations instead of
        //directly accessing private variables.
    }
    
    //create display function:
    void display()
    {
        cout << "your mortgage loan amount is: $" << getPrincipal() << endl;
        cout << "your yearly interest rate is: " << getRate() << "%" << endl;
        cout << "your years given to repay loan is: " << getTerm() << endl;
        
        cout << endl << "----------CALCULATIONS-------------" << endl;
        cout << "your monthly interest rate is: " << calculateMonthlyRate() << "%" << endl;
        cout << "your total months to repay loan is: " << calculateTotalMonths() << endl;
        
        //fixed << setprecision(2) makes sure there are 2 values to right of decimal.
        cout << "your monthly payment on your loan is: $" << fixed << setprecision(2) << calculateMonthlyPayment() << endl;
    }
}; //end of class MonthlyMortgagePayment.

int main()
{
    double mortgage;
    double yearlyRate;
    double yearsToPay;
    
    cout << "enter mortgage loan amount (DO NOT INCLUDE COMMAS):";
    cin >> mortgage;
    cout << "enter annual interest rate:";
    cin >> yearlyRate;
    cout << "enter loan term:";
    cin >> yearsToPay;
    
    //input validation: no negative inputs from user for values:
    if(mortgage < 0)
    {
        cout << "ERROR: all inputs need to be positive. try again." << endl;
    }
    else if(yearlyRate < 0)
    {
        cout << "ERROR: all inputs need to be positive. try again." << endl;
    }
    else if(yearsToPay < 0)
    {
        cout << "ERROR: all inputs need to be positive. try again." << endl;
    }
    else
    {
        MonthlyMortgagePayment userLoan(mortgage, yearlyRate, yearsToPay);
        userLoan.display();
    }
    return 0;
} //end of main function.

//case studies:
//1) MonthlyMortgagePayment loanOne(240000, 7.62, 30); ---> PASSED.
//correct amount: $1,698
//program amount: $1697.88


//2) MonthlyMortgagePayment loanTwo(500000, 10.34, 20); ---> PASSED.
//correct amount: $4,938
//program amount: $4938.28

//3) MonthlyMortgagePayment loanThree(360000, 5.69, 15); ---> PASSED.
//correct amount: $2,978
//program amount: $2977.92
