//DISPLAY 10.6 Class with Constructors 
//Program to demonstrate the class SavingAccount.
#include <iostream>
#include "SavingAccount.h"
using namespace std;

// Please write comments here
// Constructor for SavingAccount takes dollars, cents and rate
SavingAccount::SavingAccount(int dollars, int cents, double rate) : BankAccount(dollars, cents), interest_rate(rate)
{
    if (rate < 0)
    {
        cout << "Illegal values for interest rate.\n";
        exit(1); // throw exception;
    }
}

SavingAccount::SavingAccount(int dollars, double rate) : BankAccount(dollars), interest_rate(rate)
{
    if (rate < 0)
    {
        cout << "Illegal value for interest rate.\n";
        exit(1);
    }
}


SavingAccount::SavingAccount( ) : BankAccount(), interest_rate(0.0)
{
   //Body intentionally empty
}


// Update the balance with the interest_rate.
void SavingAccount::update() 
{
    double amount = get_balance();
	amount = amount + fraction(interest_rate)*amount;
	set_balance(amount);
}

// Output the SavingAccount
void SavingAccount::output(ostream& outs) const
{
	BankAccount::output(outs);
    outs << "Interest rate: " << get_rate() << "%" << endl;
}

// Input the balance for the BankAccount
void SavingAccount::input(istream& ins)
{
	BankAccount::input(ins);
    ins >> interest_rate;
}

// Since interest_rate is a double representing percent,
// just return it.
double SavingAccount::get_rate() const
{
    return interest_rate;
}

// Convert the given percent to a fraction: 5.5 to .055
double SavingAccount::fraction(double percent)
{
    return percent/100.0;
}

