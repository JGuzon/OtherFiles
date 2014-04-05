#include <iostream>     //inclusion of support for doing input & output 
#include <cmath>	    
#include <cctype>	    
#include <vector>		//For vectors. Ended up using arrays instead
#include <sstream>
using namespace std;	//declare access to standard stuff like cin, cout

//char array storing this problem's RNA sequence
char rna[10] = {'a', 'a', 'g', 'c', 'g', 'a', 'c', 'g', 'u', 'u'};

int opt(int i, int j) //opt function finds the highest number of pairs
{
	int max1 = 0; //for storing the maximum number of pairs between i and j-1
	int max2 = 0; //for storing the maximum number of pairs between i and j
	int i2 = i;
	int j2 = j;
	int t = 0; //for checking for other pairs in between

	if (i2>=j2-4) //There is not enough room between i and j, aka it is a "sharp corner." Zero pairs.
	{
		return 0;
	}

	char iChar = rna[i2-1]; //stores the i letter
	char jChar = rna[j2-1]; //stores the j letter

	//Stores the maximum amount of pairs between i and j-1
	max1 = opt(i2, j2 - 1);

	//If i and j are a pair
	if ((iChar == 'a' && jChar == 'u') || (iChar == 'u' && jChar == 'a') || (iChar == 'c' && jChar == 'g') || (iChar == 'g' && jChar == 'c'))
	{
		max2 = max2 + 1; //There is at least one pair
		//Iterate through t's to find the maximum number of pairs between
		for (int k = 5; k < j2; k++)
		{
			for (int i3 = i2 + 1; i3 <= j2 - k; i3++)
			{
				t = i3 + k;
				max2 = max2 + opt(i3,t-1) + opt(t+1,j2-1);
			}
		}
	}
	
	//Return the bigger result
	if (max1 > max2)
	{
		return max1;
	}
	else
	{
		return max2;
	}
}

// Beginning of main function
int main()
{
	int solutions[5][5];

	//The side and bottom represent the corresponding rna array iterators
	//The coordinates represent the corresponding solutions array of arrays iterators

	//[4]5 4,0  4,1  4,2  4.3  4,4

	//[3]4 3,0  3,1  3,2  3.3  3,4

	//[2]3 2,0  2,1  2,2  2.3  2,4

	//[1]2 1,0  1,1  1,2  1.3  1,4

	//[0]1 0,0  0,1  0,2  0.3  0,4

	//    [5]6 [6]7 [7]8 [8]9 [9]10

	//Initialize opt(i,j)=0 whenever i>=j-4
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			if (x >= y-4)
			{
				solutions[x][y] = 0;
			}
		}
	}

	int j = 0;
	for (int k = 5; k < 10; k++) //The difference between i and j
	{
		for (int i = 1; i <= 10 - k; i++) //The lower number
		{
			j = i + k; //The higher number
			solutions[i-1][j-6] = opt(i, j); //Stores the maximum number of pairs between i and j
		}
	}

	//Outputs the solution table
	for (int x = 4; x > -1; x--)
	{
		for (int y = 0; y < 5; y++)
		{
			cout << solutions[x][y];
		}
		cout << endl;
	}

	char exit;
	cin >>exit;
	return 0;
}