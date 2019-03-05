// File: cipher.cpp
//Contains code for for performing a Caeser Shift using external text files.
//
//-----------------------------------------------------------------------------------------------------------------------------------
//Class: CS 215						Instructor: Dr. Deborah Hwang
//Assignment: Homework 1				Date Assigned: 1/13/17
//Programmer: Jacob Darabaris				Date Completed: 1/18/17
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
	if(argc!=4) //number of arguments in the commandline
  	{
        	cerr << "Usage error"<< endl;
        	return 1;
  	}
	//argv = array of arguments
        ifstream in(argv[1]);
        ofstream out(argv[2]);

	int shift = atoi (argv[3]);
        char ch;

        while(in >> noskipws >> ch)
        {
        	if (ch>='a' and ch<='z')
	 	{
	    		ch = (((ch - 'a')+ shift)%26)+'a';
	  		out << ch;
		}
		else if (ch>='A' and ch<='Z')
	   	{
			ch =(((ch - 'A')+ shift)%26)+'A';
			out << ch;
		}
		else
			out << ch;	
	}
        return 0;
}

