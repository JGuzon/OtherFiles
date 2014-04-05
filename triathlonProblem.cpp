//Jason Guzon
//CSCI 400 Test 1
//For Problem Instance #II
//There is a separate .cpp file for Problem Instance #I


#include <iostream>     //inclusion of support for doing input & output 
#include <cmath>	    //inclusion of support for doing random number generation 
#include <cctype>	    //inclusion of support for character conversion
#include <vector>
#include <algorithm>	//for next_permutation
using namespace std;	//declare access to standard stuff like cin, cout



//The number of people
int n = 10;
//n!
int nFactorial = 3628800;



//Finds the shortest completion time
int findCompletionTime(vector<int> & list, vector<int> & swimList, vector<int> & bikeAndRunList)
{
	int completionTime = 0; //The time it takes for ALL of the people to pass the finish line
	//Taken from the person with the latest completion time

	int startTime = 0; //What time each person starts
	//For the first person, it is 0.
	//For each following person, it is right after their previous person finishes swimming

	int personNumber = 0; //Determines which person is going now

	int personTime = 0; //The amount of time it takes for the current person to finish

	for (int w = 0; w<n; w++)
	{
		personNumber = list[w] - 1;
		personTime = startTime + swimList[personNumber] + bikeAndRunList[personNumber];
		if (personTime > completionTime)
		{
			completionTime = personTime;
		}
		startTime = startTime + swimList[personNumber];
	}

	return completionTime;
}


// Beginning of main function
int main()               
{
	cout << "Now initializing people, swimming times, biking times, and running times..." << endl << endl;

	//Vector of numbers 1 to n, to represent the people
	vector<int> numbers;
	numbers.resize(n);
	for(int i=0; i<n; i++)
	{
		numbers[i] = i + 1;
	}

	//Vector of swimming times
	vector<int> swimTime;
	swimTime.resize(n);
	swimTime[0] = 20; //Person #1's swimming time
	swimTime[1] = 35; //Person #2's swimming time
	swimTime[2] = 40; //Person #3's swimming time
	swimTime[3] = 25;
	swimTime[4] = 22;
	swimTime[5] = 37;
	swimTime[6] = 42;
	swimTime[7] = 27;
	swimTime[8] = 31;
	swimTime[9] = 36;

	//Vector of combined biking and running times
	vector<int> bikeAndRunTime;
	bikeAndRunTime.resize(n);
	bikeAndRunTime[0] = 45; //Person #1's combined biking and running time
	bikeAndRunTime[1] = 35; //Person #2's combined biking and running time
	bikeAndRunTime[2] = 50; //Person #3's combined biking and running time
	bikeAndRunTime[3] = 55;
	bikeAndRunTime[4] = 45;
	bikeAndRunTime[5] = 35;
	bikeAndRunTime[6] = 50;
	bikeAndRunTime[7] = 56;
	bikeAndRunTime[8] = 34;
	bikeAndRunTime[9] = 50;

	cout << endl << "Now generating all the different permutations..." << endl << endl;

	int permCounter = 0; //Counts what permutation we are on
	//Vector to store all the permutations
	vector<  vector<int> > permutations;
	permutations.resize(nFactorial);
	do {
		for (int x = 0; x<n; x++)
		{
			permutations[permCounter].resize(n);
			permutations[permCounter][x] = numbers[x];
		}
		permCounter++;
	} while (next_permutation(numbers.begin(),numbers.end()));

	////Display all the permutations
	//for (int x = 0; x<nFactorial; x++)
	//{
	//	for (int y = 0; y<n; y++)
	//	{
	//		cout << permutations[x][y];
	//	}
	//	cout << endl << endl;
	//}

	cout << endl << "Now finding all the completion times and finding the ideal order..." << endl << endl;

	//Store all the weight sums in a vector
	vector<int> completionTimes;
	completionTimes.resize(nFactorial);
	int shortestTime = 9999999999; //Arbitrarily large number
	vector<int> shortestTimeIndexes;
	shortestTimeIndexes.resize(1);

	for (int j = 0; j<nFactorial; j++)
	{
		completionTimes[j] = findCompletionTime(permutations[j], swimTime, bikeAndRunTime);
		if (shortestTime > completionTimes[j])
		{
			shortestTime = completionTimes[j];
			shortestTimeIndexes.clear();
			shortestTimeIndexes.push_back(j);
			cout << "New shortest time: " << shortestTime << endl;
		}
		else if (shortestTime == completionTimes[j])
		{
			shortestTimeIndexes.push_back(j);
		}
	}
	int numSolutions = shortestTimeIndexes.size();

	//Display the results
	cout << endl << "The shortest completion time is " << shortestTime << "." << endl;
	cout << endl << "The number of solutions is " << numSolutions << "." << endl;

	cout << endl << "ONE ideal order of people is as follows: " << endl;

	//Displays the person # in order
	for (int k = 0; k < n; k++)
	{
		//Takes the order from "permutations"
		//Chooses the order from "shortestTimeIndexes"
		//nextSolution iterates through "shortestTimeIndexes"
		//k iterates through "permutations"
		cout << "Person #" << permutations[shortestTimeIndexes[0]][k];
		if (k < (n-1))
		{
			cout << ", ";
		}
		else
		{
			cout << endl;
		}
	}



	////This next section displays ALL the ideal orders
	//for (int nextSolution = 0; nextSolution < numSolutions; nextSolution++)
	//{
	//	//Displays an "Or" if it is not the first solution
	//	if(nextSolution > 0)
	//	{
	//		cout << "Or ";
	//	}

	//	//Displays the person # in order
	//	for (int k = 0; k < n; k++)
	//	{
	//		//Takes the order from "permutations"
	//		//Chooses the order from "shortestTimeIndexes"
	//		//nextSolution iterates through "shortestTimeIndexes"
	//		//k iterates through "permutations"
	//		cout << "Person #" << permutations[shortestTimeIndexes[nextSolution]][k];
	//		if (k < (n-1))
	//		{
	//			cout << ", ";
	//		}
	//		else
	//		{
	//			cout << endl;
	//		}
	//	}
	//}


	char exit;
	cout << endl << endl << "Enter any character to quit." << endl;
	cin >> exit;
	return 0;

}