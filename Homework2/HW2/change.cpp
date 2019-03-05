//# File: change.cpp

//Code calculates change for a give amount using dollars, quarters, dimes, 
//and pennies; using highest denomiations first.
//
//------------------------------------------------------------------------------
//Class: CS 215                                    Instructor: Dr. Deborah Hwang
//Assignment: 2                                    Date Assigned:1/20/17
//Programmer: Jacob Darabaris                      Date Completed:1/23/17

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

void ComputeChange(int cents, int *Dollars, int *Quarters, 
		   int *Dimes, int *Pennies);
int main(int argc, char **argv)
{  
	using namespace std;
	if(argc!=3)
    	{      
		cerr << "Usage error"<< endl;
      		return 1;
    	}
  	ifstream in(argv[1]);
  	ofstream out(argv[2]);

	out << setw(10) << "Amount" 
	    << setw(10) << "Dollars" 
	    << setw(10) << "Quarters" 
	    << setw(10) << "Dimes" 
	    << setw(10) << "Pennies" 
	    << endl << endl;

	int mCents, mDollars, mQuarters, mDimes, mPennies;
    	while (in >> mCents)
      	{
		ComputeChange(mCents, &mDollars, &mQuarters, &mDimes,&mPennies);
		out << setw(10) << mCents 
		    << setw(10) << mDollars 
		    << setw(10) << mQuarters 
		    << setw(10) << mDimes 
		    << setw(10) << mPennies 
		    << endl;
      	}
	in.close();
	out.close();
  	return 0;
}
void ComputeChange(int cents, int *Dollars, int *Quarters, 
		   int *Dimes, int *Pennies)
{
	*Dollars = cents/100;
	int DollarRemainder = cents%100;	
	*Quarters = DollarRemainder/25;
	int QuarterRemainder = DollarRemainder%25;	
	*Dimes = QuarterRemainder/10;	
	int DimeRemainder = QuarterRemainder%10;
	*Pennies = DimeRemainder;
}
