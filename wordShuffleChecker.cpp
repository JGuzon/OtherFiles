#include <iostream>     //inclusion of support for doing input & output 
#include <cmath>	    //Not needed
#include <cctype>	    
#include <vector>		//For vector of chars
#include <string>		//For strings
#include <sstream>
using namespace std;	//declare access to standard stuff like cin, cout


// Beginning of main function
int main()               
{
	string word1 = ""; //String for the first word
	string word2 = ""; //String for the second word
	string combinedWord = ""; //String for the combined word

	char end; //Just to end the program

	//Get the words from the user (and make sure that they are between 1 and 100 characters;
	cout << "Please enter the two words then the combibned word." << endl;
	cout << "Word 1: ";
	getline(cin, word1);
	while (word1.length() < 1 || word1.length() > 100)
	{
		cout << "Please enter a word that is between 1 and 100 characters." << endl;
		cout << "Word 1: ";
		getline(cin, word1);
	}
	cout << "Word 2: ";
	getline(cin, word2);
	while (word2.length() < 1 || word2.length() > 100)
	{
		cout << "Please enter a word that is between 1 and 100 characters." << endl;
		cout << "Word 2: ";
		getline(cin, word2);
	}
	cout << "Combined word: ";
	getline(cin, combinedWord);
	while (combinedWord.length() < 1 || combinedWord.length() > 100)
	{
		cout << "Please enter a word that is between 1 and 100 characters." << endl;
		cout << "Combined Word: ";
		getline(cin, combinedWord);
	}

	//Test to see if the combined word's length is different than the two words put together
	//If so, the program tells the user that the combined word is not a proper shuffle and ends the program
	const int length1 = word1.length();
	const int length2 = word2.length();
	int combinedLength = length1 + length2;

	if (combinedWord.length() != combinedLength)
	{
		cout << endl << "The two words do not have the same amount of characters as the combined word." << endl;
		cout << "Therefore, the combined word is not a shuffle of the two words." << endl;
		cout << "Enter any character to end the program." << endl;
		cin >> end;
		return 0;
	}

	//Converts the strings to constant vectors of chars
	const vector<char> wordx(word1.begin(), word1.end());
	const vector<char> wordy(word2.begin(), word2.end());
	const vector<char> wordz(combinedWord.begin(), combinedWord.end());

	int x = 0; //Iterator for the first word, wordx
	int y = 0; //Iterator for the second word, wordy
	int z = 0; //Iterator for the combined word, wordz
	bool sameLetter = false; //Records if at any time all three letters were the same
	int xRemember = -1; //Records the location of wordx where the first time in this sequence all three letters were the same
	int yRemember = -1; //Does the same for wordy

	while (x < length1 && y < length2) //While both iterators have not reached the end of their vector
	{
		if (wordz[z] == wordx[x] && wordz[z] == wordx[y]) //If ALL 3 characters are the same
		{
			if (sameLetter == false) //If there were no previously shared letters
			{
				xRemember = x; //Remember where x was when the first shared letter appeared
				yRemember = y; //Remember where y was when the first shared letter appeared
				sameLetter = true; //Know that there have previously been shared letters
			}

			//Iterate all the iterators
			x = x++;
			y = y++;
			z = z++;
		}
		else if (wordz[z] == wordx[x] && wordz[z] != wordy[y]) //If only x and z's letters are the same
		{
			if (sameLetter == true) //If they all previously shared a character
			{
				y = yRemember; //Return y to the place where they first shared a character
				xRemember = -1; //Set xRemember, yRemember, and sameLetter back to their original values
				yRemember = -1;
				sameLetter = false;
			}
			//Iterate only x and z
			x = x++;
			z = z++;
		}
		else if (wordz[z] == wordy[y] && wordz[z] != wordx[x]) //If only y and z's letters are the same
		{
			if (sameLetter == true);
			{
				x = xRemember;
				xRemember = -1;
				yRemember = -1;
				sameLetter = false;
			}
			//Iterate only y and z
			y = y++;
			z = z++;
		}
		else //If z does not match either
		{
			if (sameLetter == false)
			{
			cout << endl << "The combined word is not a shuffle of the two words." << endl;
			cout << "Enter any character to end the program." << endl;
			cin >> end;
			return 0;
			}
			else //sameLetter == true
			{
				//Both letters at xRemember and yRemember have been used, so iterate them both
				//Such as if the words are "chocolate" and "chocolate"
				//And the combined word is "cchhooccoollaattee"
				if (wordz[z] == wordx[xRemember]) //Only need to check one, since the letters at xRemember and yRemember are the same
				{
					xRemember = xRemember++;
					yRemember = yRemember++;
					z = z++;
				}
				else
				{
					cout << endl << "The combined word is not a shuffle of the two words." << endl;
					cout << "Enter any character to end the program." << endl;
					cin >> end;
					return 0;
				}
			}
		}
	}

	//If either x and/or y has iterated through the whole word and they shared the same letters
	//(like if they are the same word, such as "chocolate" and "chocolate"
	//and the combined word is something like "chocolatechocolate"
	//or if they are the same word but one is longer, such as "chocolate" and "chocolates"
	// and the combined word is something like "chcolatechocolates")
	if (sameLetter == true)
	{
		if (length1 > length2) //wordx is longer, so set x back to where the similarities first happened.
		{
			x = xRemember;
			xRemember = -1;
			yRemember = -1;
			sameLetter = false;
		}
		else //Otherwise, wordy is longer (or the exact same word), so set y back to where the similarities first happened.
		{
			y = yRemember;
			xRemember = -1;
			yRemember = -1;
			sameLetter = false;
		}
	}

	//While wordx has not been completely iterated through but wordy has
	//Such as if the words were "choco" and "late"
	//And the combined word was "chocolate"
	while (x < length1)
	{
		if (wordz[z] == wordx[x])
		{
			x = x++;
			z = z++;
		}
		else
		{
			cout << endl << "The combined word is not a shuffle of the two words." << endl;
			cout << "Enter any character to end the program." << endl;
			cin >> end;
			return 0;
		}
	}

	while (y < length2) //While wordy has not been completely iterated through but wrodx has
	{
		if (wordz[z] == wordy[y])
		{
			y = y++;
			z = z++;
		}
		else
		{
			cout << endl << "The combined word is not a shuffle of the two words." << endl;
			cout << "Enter any character to end the program." << endl;
			cin >> end;
			return 0;
		}
	}

	//If all those above conditions were met, the word is a shuffle
	cout << endl << "Congratulations! The combined word is a shuffle of the two words!" << endl;
	cout << "Enter any character to end the program." << endl;
	cin >> end;

	return 0;
}