//Implementation of the class CheckingAccount.
#include <iostream>
#include <cmath>
using namespace std;

// To Do: include necessary header files
#include "CheckingAccount.h"

// To Do: Please write comments and code to implement CheckingAccount here
// Constructor for SavingAccount takes dollars, cents and rate

CheckingAccount::CheckingAccount(int dollars, int cents, double fee) : BankAccount(dollars, cents), check_fee(fee)
{
	if (fee < 0)
	{
		cout << "Illegal value for check fee.\n";
		exit(1);
	}
}

CheckingAccount::CheckingAccount(int dollars, double fee) : BankAccount(dollars), check_fee(fee)
{
	if (fee < 0)
	{
		cout << "Illegal value for check fee.\n";
		exit(1);
	}
}

CheckingAccount::CheckingAccount() : BankAccount(), check_fee(0.0)
{
	// Body intentionally empty
}

double CheckingAccount::getFee() const
{
	return check_fee;
}

// Output the CheckingAccount
void CheckingAccount::output(ostream& outs) const
{
	BankAccount::output(outs);
	outs << "Check fee: $" << getFee() << endl;
}

// Input the balance for the BankAccount
void CheckingAccount::input(istream& ins)
{
	BankAccount::input(ins);
	ins >> check_fee;
}

void CheckingAccount::check(int dollars, int cents)
{
	double amount = dollars + .01*cents;
	double balance = get_balance();
    	if (dollars >= 0 && cents >= 0 && amount <= get_balance())
    	{
        	balance -= (amount + check_fee);
    	}
    	else 
	{
        	cout << "Illegal values for money must be greater than or equal 0 ";
        	cout << "and less than or equal to the balance.\n";
    	}
}	

double CheckingAccount::fraction(double percent)
{
	return percent/100.0;
}
