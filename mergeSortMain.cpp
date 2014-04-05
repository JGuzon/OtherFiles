#include <iostream>
#include <cmath>	    //inclusion of support for doing random number generation 
#include <cctype>	    //inclusion of support for character conversion
using namespace std;
#include <vector>
#include <algorithm>	//for random_shuffle
#include "mergeSort.h"




//2. Implement a function that can generate random preference lists of n items
void randomPreference(int n, vector<int> & list)
{
	list.resize(n);
	for (int counter = 0; counter < n; counter++)
	{
		list[counter] = counter + 1;//Enters numbers 1 to n
	}
	std::random_shuffle ( list.begin(), list.end() );//Shuffles the entries
}
	
	


// Beginning of main function
int main()               
{
	//A random preference list
	vector<  vector<int> > preferenceDB;
	vector<int> newVector;

	int n = 0; //Number of items
	int m = 0; //Number of people

	cout << "Hello! How many items are in the list?";
	cout << endl;
	cin >> n;
	while (n < 1)
	{
		cout << endl;
		cout << "Error: n must be at least 1";
		cout << endl;
	}
	cout << endl;
	cout << "Thank you. And how many people have a list?";
	cout << endl;
	cin >> m;
	while (m < 2)
	{
		cout << endl;
		cout << "Error: m must be at least 2";
		cout << endl;
	}
	cout << endl;

	preferenceDB.resize(m);

	cout << "Now initializing the database of random vectors..." << endl;
	for (int y = 0; y < m; y++) //Initialize the database of random vectors
	{
		randomPreference(n, preferenceDB[y]);
	}

	cout << "Now searching for optimal partners by finding least inversions..." << endl;
	//Find the number of inversions for each pair
	int inversionz = 0; //To store the amount returned by inversionCount
	vector<int> partners; //To store the optimal partner of persons 0 to n
	partners.resize(m);
	vector<int> leastInversions; //To store the number of versions with the optimal partner
	leastInversions.resize(m);
	for (int k = 0; k < m; k++) //Initialize the leastInversions vector with the most inversions possible
	{
		leastInversions[k] = (n * (n - 1)) / 2;
	}

	for (int y = 0; y < m; y++)
	{
		for (int z = 0; z < m; z++)
		{
			if (y != z) //Do not check a person with himself/herself
			{
				inversionz = inversionCount(preferenceDB[y], preferenceDB[z], newVector); //Get the number of inversions
				if (leastInversions[y] > inversionz) //If there are less inversions
				{
					leastInversions[y] = inversionz; //Store that number of inversions
					partners[y] = z; //Store the person who is their partner
				}
			}
		}
	}

	cout << endl;
	for (int a = 0; a < m; a++)
	{
		cout << "The optimal partner for person " << a << " is:" << endl;
		cout << "Person " << partners[a] << endl;
		cout << "Number of inversions: " << leastInversions[a] << endl;
		cout << endl;
	}

	cout << endl << endl;

	cout << endl << endl << "Enter any character to quit." << endl;
	cin >> n;
	return 0;

}