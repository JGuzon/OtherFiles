#include <ctime>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>	
#include <cmath>

using namespace std;


/************************************************************************/
/************************************************************************/
void main()
{
	int n = 0; //Variable for nickels
	int d = 0; //Variable for dimes
	int q = 0; //Variable for quarters
	int take = 0; //Variable for the player to take coins
	bool gameStillGoing = true;
	bool optimalMoveFound = false;

	//Creates the utility table for the optimal moves
	int table[100][100][100];
	table[0][0][0] = 0;
	int i = 1, j = 1, k = 1; //Variables for the table

	//If there is only one pile, optimal move, set to 1
	for (i = 1; i < 100; i++)
	{
		table[i][0][0] = 1;
	}
	for (j = 1; j < 100; j++)
	{
		table[0][j][0] = 1;
	}
	for (k = 1; k < 100; k++)
	{
		table[0][0][k] = 1;
	}

	//If there are only two piles and they are not equal, optimal move, set to 1
	//But if there only two piles and they are equal, no optimal move, set to 0
	for (i = 1; i < 100; i++)
	{
		for (j = 1; j < 100; j++)
		{
			if (j != i)
				table[i][j][0] = 1;
			else
				table[i][j][0] = 0;
		}
	}
	for (i = 1; i < 100; i++)
	{
		for (k = 1; k < 100; k++)
		{
			if (k != i)
				table[i][0][k] = 1;
			else
				table[i][0][k] = 0;
		}
	}
	for (j = 1; j < 100; j++)
	{
		for (k = 1; k < 100; k++)
		{
			if (k != j)
				table[0][j][k] = 1;
			else
				table[0][j][k] = 0;
		}
	}

	//If there are three piles and at least two of them are equal, optimal move, set to 1
	//Also, if one pile is greater than another by only 1, optimal move, set to 1
	//Otherwise, no optimal move, set to 0
	for (i = 1; i < 100; i++)
	{
		for (j = 1; j < 100; j++)
		{
			for (k = 1; k < 100; k++)
			{
				if (i == j || i == k || j == k)
					table[i][j][k] = 1;
				else if ( (i-j)==1 || (j-i)==1 || (i-k)==1 || (k-i)==1 || (j-k)==1 || (k-j)==1 )
					table[i][j][k] = 1;
				else
					table[i][j][k] = 0;
			}
		}
	}

	

	cout << "Welcome to the Nim Game!" << endl;
	cout << "We will have 3 stacks of coins." << endl;
	cout << "One of nickels, one of dimes, and one of pennies." << endl;
	cout << "Whoever gets the last coin wins." << endl << endl;
	cout << "How many nickels will there be?" << endl;
	cin >> n;
	while (n < 0 || n > 100)
	{
		cout << "Please enter a number between 0 and 100.";
		cin >> n;
	}
	cout << "How many dimes will there be?" << endl;
	cin >> d;
	while (d < 0 || d > 100)
	{
		cout << "Please enter a number between 0 and 100.";
		cin >> d;
	}
	cout << "How many qaurters will there be?" << endl;
	cin >> q;
	while (q < 0 || q > 100)
	{
		cout << "Please enter a number between 0 and 100.";
		cin >> q;
	}

	//Loop for if all coin stacks are 0
	while (n == 0 && d == 0 && q == 0)
	{
		cout << "How many nickels will there be?" << endl;
		cin >> n;
		while (n < 0 || n > 100)
		{
			cout << "Please enter a number between 0 and 100.";
			cin >> n;
		}
		cout << "How many dimes will there be?" << endl;
		cin >> d;
		while (d < 0 || d > 100)
		{
			cout << "Please enter a number between 0 and 100.";
			cin >> d;
		}
		cout << "How many qaurters will there be?" << endl;
		cin >> q;
		while (q < 0 || q > 100)
		{
			cout << "Please enter a number between 0 and 100.";
			cin >> q;
		}
	}
	
	char option;
	bool playerturn;
	bool playerwins;
	cout << endl << "Would you like to go first?" << endl;
	cout << "Please enter 'Y' for Yes and 'N' for No." << endl;
	cin >> option;
	while (option != 'n' && option != 'N' && option != 'y' && option != 'Y')
	{
		cout << "Sorry, " << option << " is not an option." << endl;
		cout << "Please enter 'Y' for Yes and 'N' for No." << endl;
		cin >> option;
	}
	if (option == 'Y' || option == 'y')
		playerturn = true;
	else
		playerturn = false;

	while (gameStillGoing == true)
	{
		cout << endl;
		cout << "Nickels: " << n << endl;
		cout << "Dimes: " << d << endl;
		cout << "Quarters: " << q << endl;

		if (playerturn == true) //Player's Turn
		{
			cout << endl << "From which stack would you like to take?" << endl;
			cin >> option;
			while (option!='n' && option!='N' && option!='d' && option!='D' && option!='q' && option!='Q')
			{
				cout << "Please enter N, D, or Q for nickels, dimes, or quarters respectively." << endl;
				cin >> option;
			}
			while ( ((option=='n'||option=='N')&&n==0) || ((option=='d'||option=='D')&&d==0) || ((option=='q'||option=='Q')&&q==0) )
			{
				cout << "That stack is empty. Please choose another stack." << endl;
				cin >> option;
				while (option!='n' && option!='N' && option!='d' && option!='D' && option!='q' && option!='Q')
				{
					cout << "Please enter N, D, or Q for nickels, dimes, or quarters respectively." << endl;
					cin >> option;
				}
			}

			cout << endl << "How many coins would you like to take?" << endl;
			cin >> take;
			while ( take <= 0 || ((option=='n'||option=='N')&&take>n) || ((option=='d'||option=='D')&&take>d) || ((option=='q'||option=='Q')&&take>q) )
			{
				cout << "Please enter a correct amount of coins." << endl;
				cin >> take;
			}
			if (option=='n'||option=='N')
				n = n - take;
			else if (option=='d'||option=='D')
				d = d - take;
			else
				q = q - take;

			playerwins = true;
		} //End of player's turn

		else //Computer's Turn
		{
			i = 0;
			j = 0;
			k = 0;
			optimalMoveFound = false;
			if (table[n][d][q] == 0) //If there is no optimal move, just take 1 from n. If n is empty, takes from d, or q if d is empty as well.
			{
				if (n != 0)
					n = n - 1;
				else if (d != 0)
					d = d - 1;
				else
					q = q - 1;
			}
			else
			{
				while (optimalMoveFound == false)
				{
					if (table[i][d][q] == 1)
					{
						n = i;
						optimalMoveFound = true;
					}
					else if (table[n][j][q] == 1)
					{
						d = j;
						optimalMoveFound = true;
					}
					else if (table[n][d][k] == 1)
					{
						q = k;
						optimalMoveFound = true;
					}
					else
					{
						i++;
						j++;
						k++;
					}
				}
			}
				
			playerwins = false;
		} //End of computer's turn


		if (n == 0 && d == 0 && q == 0)
			gameStillGoing = false;
	} //End of gameStillGoing loop
	


	if (playerwins == true)
		cout << endl << "Congratulations! You won!" << endl;
	else
		cout << endl << "Sorry! You lost." << endl;

	cout << endl << "Enter any character to quit." << endl;
	cin >> option;
	return;
}
