#include <iostream>     //inclusion of support for doing input & output 
#include <cmath>	    //inclusion of support for doing random number generation 
#include <cctype>	    //inclusion of support for character conversion
#include <vector>
#include <algorithm>	//for random_shuffle
using namespace std;	//declare access to standard stuff like cin, cout



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

//1. Implement a function that can determine the number of inversions given two preference lists of n items
int inversionCount(vector<int> & list1, vector<int> & list2)
{
	int inversions = 0;
	int n = 0;
	int m = 0; //should be the same as n but just in case
	
	//Initialize n to the size of the lists
	if (list1.size() == list2.size())
	{
		n = list1.size();
		m = list2.size();
	}
	else if (list1.size() < list2.size()) //Just in case the lists are not the same size, the program will not crash
	{
		n = list1.size();
		m = list2.size();
	}
	else
	{
		n = list2.size();
		m = list1.size();
	}

	//Order one of the lists in ascending order (changing the other as well to compliment it)
	//because I do not know how to count inverses with both of them in random orders
	vector<int> temp1;
	temp1.resize(m);
	vector<int> temp2;
	temp2.resize(m);

	for (int x = 0; x < n; x++)
	{
		temp1[list1[x]-1] = list1[x];
		temp2[list1[x]-1] = list2[x];
	}

	/*cout << "Re-ordered lists." << endl;
	for (int x = 0; x < n; x++)
	{
		cout << temp1[x];
	}

	cout << endl;

	for (int x = 0; x < n; x++)
	{
		cout << temp2[x];
	}

	cout << endl;*/

	//Count the number of inversions by looking at what values are greater than later values
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (temp1[i] > temp2[j])
			{
				inversions++;
			}
		}
	}

	return inversions;
}


// Beginning of main function
int main()               
{
	//A random preference list
	vector<  vector<int> > preferenceDB;

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

	for (int y = 0; y < m; y++) //Initialize the database of random vectors
	{
		randomPreference(n, preferenceDB[y]);
	}

	//Find the number of inversions for each pair
	int numInversions = 0; //To store the amount returned by inversionCount
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
				numInversions = inversionCount(preferenceDB[y], preferenceDB[z]); //Get the number of inversions
				if (leastInversions[y] > numInversions) //If there are less inversions
				{
					leastInversions[y] = numInversions; //Store that number of inversions
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