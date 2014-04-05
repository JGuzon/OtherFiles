#include <iostream>     //inclusion of support for doing input & output 
#include <cmath>	    //inclusion of support for doing random number generation 
#include <cctype>	    //inclusion of support for character conversion
#include <vector>
using namespace std;	//declare access to standard stuff like cin, cout


// Beginning of main function
int main()               
{
	int n = 0; //Variable for the total that is trying to be reached
	int numFives = 0; //Variable for the number of 5 cent stamps needed
	int numFours = 0; //Variable for the number of 4 cent stamps needed
	int numOnes = 0; //Variable for the number of 1 cent stamps needed
	int remainder = 0; //Variable to store n % 15

	cout << "Please enter the value of N:" << endl;
	cin >> n;
	remainder = n%15;
	numFives = (n-remainder)/5;
	if (remainder == 1)
	{
		numOnes = numOnes + 1;
	}
	else if (remainder == 2)
	{
		numOnes = numOnes + 2;
	}
	else if (remainder == 3)
	{
		numOnes = numOnes + 3;
	}
	else if (remainder == 4)
	{
		numFours = numFours + 1;
	}
	else if (remainder == 5)
	{
		numFives = numFives + 1;
	}
	else if (remainder == 6)
	{
		numFives = numFives + 1;
		numOnes = numOnes + 1;
	}
	else if (remainder == 7)
	{
		numFives = numFives + 1;
		numOnes = numOnes + 2;
	}
	else if (remainder == 8)
	{
		numFours = numFours + 2;
	}
	else if (remainder == 9)
	{
		numFives = numFives + 1;
		numFours = numFours + 1;
	}
	else if (remainder == 10)
	{
		numFives = numFives + 2;
	}
	else if (remainder == 11)
	{
		numFives = numFives + 2;
		numOnes = numOnes + 1;
	}
	else if (remainder == 12)
	{
		numFours = numFours + 3;
	}
	else if (remainder == 13)
	{
		numFours = numFours + 3;
		numOnes = numOnes + 1;
	}
	else if (remainder == 14)
	{
		numFours = numFours + 3;
		numOnes = numOnes + 2;
	}
	cout << "You will need the following amount of each stamp" << endl;
	cout << "5 cent stamps: " << numFives << endl;
	cout << "4 cent stamps: " << numFours << endl;
	cout << "1 cent stamps: " << numOnes << endl;

	cout << endl << "Enter any number to quit." << endl;
	cin >> n;
	
	return 0;
}