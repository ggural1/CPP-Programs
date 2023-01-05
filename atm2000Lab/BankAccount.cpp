//DISPLAY 10.6 Class with Constructors 
//Program to demonstrate the class BankAccount.
#include <iostream>
#include "BankAccount.h"
using namespace std;

// Please write comments here
// Constructor for BankAccount takes dollars, cents and rate
BankAccount::BankAccount(int dollars, int cents)
{
    if ((dollars < 0) || (cents < 0))
    {
        cout << "Illegal values for money.\n";
        exit(1); // throw exception;
    }
    balance = dollars + 0.01*cents;
}

BankAccount::BankAccount(int dollars)
{
    if (dollars < 0) 
    {
        cout << "Illegal values for money.\n";
        exit(1);
    }
    balance = dollars;
}


BankAccount::BankAccount( ) : balance(0)
{
   //Body intentionally empty
}


// Precondition: dollars and cents must be greater or equal to 0.
// Postcondition: increase the balance by the dollars and cents
void BankAccount::deposit(int dollars, int cents)
{
    if (dollars >= 0 && cents >= 0)
    {
        balance += dollars + 0.01*cents;
    }
    else {
        cout << "Illegal values for money must be greater than or equal 0\n";
    }
}

// Precondition: dollars and cents must be greater or equal to 0.
// Dollars and cents be less than or equal to balance.
// Postcondition: increase the balance by the dollars and cents
void BankAccount::withdraw(int dollars, int cents)
{
    double amount = dollars + .01*cents;
    if (dollars >= 0 && cents >= 0 && amount <= get_balance())
    {
        balance -= amount;
    }
    else {
        cout << "Illegal values for money must be greater than or equal 0 ";
        cout << "and less than or equal to the balance.\n";
    }
}

// Output the BankAccount
void BankAccount::output(ostream& outs) const
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account Balance: $" << get_balance() << endl;
}

// Input the balance for the BankAccount
void BankAccount::input(istream& ins)
{
	ins >> balance;
}

// Since balance is a double, just return it.
double BankAccount::get_balance() const
{
    return balance;
}

// Since balance is a double, just set it.
void BankAccount::set_balance(double amount)
{
    balance = amount;
}

