//Homework #6 by Jason Guzon

#include <iostream>     //inclusion of support for doing input & output 
#include <cmath>	    //inclusion of support for doing random number generation 
#include <cctype>	    //inclusion of support for character conversion
#include <vector>
using namespace std;	//declare access to standard stuff like cin, cout

vector< vector<int> > table; //table[items][max weight (capacity limit)]
vector<bool> solution; //Records which items are used for the solution

void setUpTable(int numItems, int capLim, vector<int> val, vector<int> wei)
{
	solution.resize(numItems);
	table.resize(numItems+1);//Adjusts rows to number of items
	for (int i = 0; i < numItems+1; i++) //Adjust colums to size
	{
		table[i].resize(capLim+1);
	}
	for (int j = 0; j < capLim+1; j++) //When there are no items, the answer is always 0
	{
		table[0][j] = 0;
	}
	for (int i = 0; i < numItems+1; i++) //When there is no capacity in the knapsack, the answer is always 0
	{
		table[i][0] = 0;
	}
	for (int i = 1; i < numItems+1; i++) //Set the rest of the table to -1
	{
		for (int j = 1; j < capLim+1; j++)
		{
			table[i][j] = -1;
		}
	}
}

int opt(int i, int w, vector<int> weight, vector<int> value)
{
	if (i == 0 || w == 0) //There are no items or there is no capacity
	{
		return 0;
	}
	if (table[i][w] != -1) //The solution is already in the table
	{
		solution[i-1] = true;
		return table[i][w];
	}
	int result1, result2, result;
	if (weight[i-1] > w) //The item is too big for the knapsack
	{
		solution[i-1] = false;
		return result = opt(i-1, w, weight, value);
	}
	else
	{
		result1 = opt(i-1, w, weight, value); //Item i is not included
		result2 = value[i-1] + opt(i-1, w-weight[i-1], weight, value); //Item i is included
		if (result1 > result2)
		{
			solution[i-1] = false;
			return result1;
		}
		else
		{
			solution[i-1] = true; //Use this item
			return result2;
		}
	}
}



// Beginning of main function
int main()               
{
	int capacityLimit = 0;
	int numberOfItems = 0;
	
	cout << "KNAPSACK PROBLEM" << endl;
	cout << "What is the capacity limit?" << endl;
	cin >> capacityLimit;
	cout << "How many items are there to choose from?" << endl;
	cin >> numberOfItems;

	vector<int> values;
	values.resize(numberOfItems);
	vector<int> weights;
	weights.resize(numberOfItems);

	cout << "What are their values?" << endl;
	for (int i = 0; i < numberOfItems; i++)
	{
		cout << "Item " << i + 1 << ": ";
		cin >> values[i];
	}
	cout << "What are their weights?" << endl;
	for (int i = 0; i < numberOfItems; i++)
	{
		cout << "Item " << i + 1 << ": ";
		cin >> weights[i];
	}

	cout << "Now calculating the ideal solution..." << endl;

	setUpTable(numberOfItems, capacityLimit, values, weights);
	int optValue = opt(numberOfItems, capacityLimit, weights, values);

	cout << endl << "The optimal value is the following: " << optValue << endl;
	cout << "One possible combination of items to achieve this value is the following: " << endl;
	for (int x = 0; x < numberOfItems; x++)
	{
		if (solution[x] == true)
		{
			cout << "Item " << x+1 << endl;
		}
	}

	cout << "Enter any character to exit the program." << endl;
	char exit;
	cin >> exit;

	return 0;

}