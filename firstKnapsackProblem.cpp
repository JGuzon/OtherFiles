#include <iostream>     //inclusion of support for doing input & output 
#include <cmath>	    //inclusion of support for doing random number generation 
#include <cctype>	    //inclusion of support for character conversion
#include <vector>
using namespace std;	//declare access to standard stuff like cin, cout



vector<int> binaryCounter;
void resetCounter();
bool increaseCounterByOne(int n);




bool increaseCounterByOne(int n)
{
	bool increase = false;
	for (int i = 0; i < n; i++)
	{
		if (binaryCounter[i] == 0)
			increase = true;
	}
	return increase;
}

void resetCounter(int n)
{
	for (int i = 0; i < n; i++)
	{
		binaryCounter[i] = 0;
	}
}



// Beginning of main function
int main()               
{
	double myRandom;
	int i,j;

	int n;


	//This section is written by Jason Guzon
	cout<< endl << endl << endl
		<< "SOLVING THE KNAPSACK PROBLEM when n=5" << endl;

	while ( true )
	{
		cout<< endl << endl << endl;

		n=5;

		vector<int> value;
		value.resize(5);
		value[0] = 1;
		value[1] = 6;
		value[2] = 18;
		value[3] = 22;
		value[4] = 28;

		vector<int> weight;
		weight.resize(5);
		weight[0] = 1;
		weight[1] = 2;
		weight[2] = 5;
		weight[3] = 6;
		weight[4] = 7;

		int newValue = 0;
		int newWeight = 0;
		bool tooHeavy = false;

		vector<int> solution;
		solution.resize(5);
		int solutionValue = 0;
		int solutionWeight = 0;

		cout<< endl 
			<< "The values and weights have been initialized." << endl;

		binaryCounter.resize(n);
		resetCounter(n);

		int i = 0;

		//FOR 00000
		for(int j = 0; j < n; j++)
		{
			//For the Knapsack Problem
			if (binaryCounter[j] == 1)
			{
				newValue = newValue + value[j];
				newWeight = newWeight + weight[j];
			}
			cout << binaryCounter[j];
		}
		cout << endl;
		if (newWeight > 11)
		{
			cout << "Too heavy!" << endl;
		}
		else
		{
			cout << "Value: " << newValue << endl;
			cout << "Weight: " << newWeight << endl;
		}
		cout << endl;
		newValue = 0;
		newWeight = 0;

		bool doneIncreasing = false;


		while (increaseCounterByOne(n) == true)
		{
			while (doneIncreasing == false)
			{
				if (binaryCounter[i] == 1)//Convert all lower level bits from 1 to 0
				{
					binaryCounter[i] = 0;
					i++;
				}
				else//Convert the first 0 to 1, then end that count
				{
					binaryCounter[i] = 1;
					i = 0;
					doneIncreasing = true;
				}
			}



			for(int j = 0; j < n; j++)
			{
				//For the Knapsack Problem
				if (binaryCounter[j] == 1)
				{
					newValue = newValue + value[j];
					newWeight = newWeight + weight[j];
				}
				cout << binaryCounter[j];
			}
			cout << endl;
			if (newWeight > 11) //Sees if it is too heavy for the knapsack
			{
				tooHeavy = true;
				cout << "Too heavy!" << endl;
			}
			else //Displays the value and weight
			{
				cout << "Value: " << newValue << endl;
				cout << "Weight: " << newWeight << endl;
			}
			cout << endl;

			//Record the solution
			if ((newValue >= solutionValue) && tooHeavy == false)
			{
				solutionValue = newValue;
				solutionWeight = newWeight;
				for(int j = 0; j < n; j++)
				{
					solution[j] = binaryCounter[j];
				}
			}

			newValue = 0;
			newWeight = 0;
			doneIncreasing = false;
			tooHeavy = false;
		}
		cout << endl;
		cout << "The solution is: ";
		for (int j = 0; j < n; j++)
		{
			cout << solution[j];
		}
		cout << endl << "Value: " << solutionValue;
		cout << endl << "Weight: " << solutionWeight;

		char quit;
		cout << endl << endl
			 << "Do you want to quit?(Y or N)";
		cin >> quit;
		if (quit == 'y' || quit == 'Y')
		   break;
	}

	return 0;

}