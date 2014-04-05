#include <iostream>
using namespace std;
#include <vector>
#include "mergeSort.h"

int numInversions = 0;

void testMergeSortImplementation()
{

	int n1,n2;

	vector<int> vecA; // Declaring the vectors and integers
	vector<int> vecB;
	vector<int> vecC;

	cout << endl << endl 
		 << "*****************************************************" << endl
		 << "**   Test the implementation for getting a single  **" << endl
		 << "**   preference list for inversion counting based  **" << endl
		 << "**   on two original preference lists.             **" << endl
		 << "*****************************************************" << endl;


	cout << endl << endl 
		<< "//*************************************************************************" << endl
		<< "//Given two preference vectors pref1 and pref2, " << endl
		<< "//preferenceTransform below can derive a signle transformed vector." << endl
		<< "//" << endl
		<< "//Note that the" << endl
		<< "//the number of inversions between pairs of elelments in pref1 and pref2" << endl
		<< "//is the same as" << endl
		<< "//the number of inversions between the elements in transformed." << endl
		<< "//" << endl
		<< "//Note that " << endl
		<< "//(i) transformed is a reference parameter and thus" << endl
		<< "//    the caller need to provide the storage for the third parameter" << endl
		<< "//(ii) pref1 and pref2 are value parameters and the" << endl
		<< "//    the contents of the original vector arguments will not be altered." << endl
		<< "//*************************************************************************" << endl
		<< endl << endl;

	while (true)
	{
		cout << "Please enter size of the two preference lists.\n";
		cout << "enter 0 to quit this part of testing:\n";
		cin >> n1;

		if (n1 <= 0)
			break;

		vecA.resize(n1); // Resizing the vectors
		vecB.resize(n1);

		cout << "Please enter the values in the first vector.\n";
		for(int i=0; i<n1; i++)		// Retrieve the first vector info
		{
				cout << "Element #" << i+1 << ": ";
				cin >> vecA[i];
		}

		cout << "\nPlease enter the values in the second vector.\n";
		for(int i=0; i<n1; i++)		// Retrieve the second vector info
		{
				cout << "Element #" << i+1 << ": ";
				cin >> vecB[i];
		}

		vecC.resize(n1); // Resize the vector to contain the two merged vectors
		numInversions = 0;
		preferenceTransform(vecA,vecB,vecC);

		cout << "\n**The transformed preferece list is ** \n";
		for (int i=0; i<n1; i++)	// Display vecC
		{
			cout << "Element #" << i+1 << ": " << vecC[i] << endl;
		}
		cout << endl << "The number of inversions is: " << numInversions << endl;
	
		cout << "\n";
	} 




	
	cout << endl << endl 
		 << "************************************************" << endl
		 << "**   Test the implementation for mergeing     **" << endl
		 << "**   two sort vectors into one sorted vector  **" << endl
		 << "************************************************" << endl << endl;

	cout << "Please enter sizes of the two sorted vectors\n\n" // Retrieve the vector sizes
		 << "Vector 1 size: ";
	cin >> n1;

	cout << "Vector 2 size: ";
	cin  >> n2;

	vecA.resize(n1); // Resizing the vectors
	vecB.resize(n2);

	cout << "Please enter the values in the first vector.\n";
	for(int i=0; i<n1; i++)		// Retrieve the first vector info
	{
			cout << "Element #" << i+1 << ": ";
			cin >> vecA[i];
	}

	cout << "\nPlease enter the values in the second vector.\n";
	for(int i=0; i<n2; i++)		// Retrieve the second vector info
	{
			cout << "Element #" << i+1 << ": ";
			cin >> vecB[i];
	}

	vecC.resize(n1+n2); // Resize the vector to contain the two merged vectors
	numInversions = 0;
	mergeTwoSortedVectors(vecA,vecB,vecC);

	cout << "\n**The merged vector contains ** \n";
	for (int i=0; i<(n1+n2); i++)	// Display vecC
	{
		cout << "Element #" << i+1 << ": " << vecC[i] << endl;
	}
	
	cout << endl << "The number of inversions is: " << numInversions << endl;

	cout << "\n";


	cout << endl << endl 
		 << "************************************************" << endl
		 << "**   Test the implementation of merge sort    **" << endl
		 << "************************************************" << endl;

	vector<int> vecD;	// Initializing variables for series sorting
	int n3;
	
	cout << "Please enter sizes of the vector to be sorted\n\n" // Retrieve the vector sizes
		<< "Vector size: ";
	cin >> n3;
	vecD.resize(n3);

	cout << "Please enter the values in vector.\n";
	for(int i=0; i<n3; i++)		// Retrieve the first vector info
	{
			cout << "Element #" << i+1 << ": ";
			cin >> vecD[i];
	}
	numInversions = 0;
	mergeSort(vecD);


	cout << "\n\n**The sorted vector contains **\n";
	for(int i=0; i<n3; i++)		// Retrieve the first vector info
	{
			cout << "\nElement #" << i+1 << ": ";
			cout << vecD[i];
	}
	cout << endl << "The number of inversions is: " << numInversions << endl;
 
	cout << "\n\n";
	cout << endl << endl 
		 << "************************************************" << endl << endl;
	cin >> numInversions;

}



//*************************************************************************
//Given two iterators itr1 and itr 2 to the beginning of
//two segments of a given size in a vector, 
//rearrange the contents of the two segments by
//(i) sorting the elements in the first segment into ascending order and
//(ii) move the elements in the second segment based on the way the elements.
//*************************************************************************
void preferenceTransform
( int size, vector<int>::iterator itr1, vector<int>::iterator itr2)
{

	if (size<=1) //If  the size is 1 or less, it is already sorted just return true.
		return;
 
	if (size==2) //If size is 2, sort the two elements, and then return true.
	{
			if ( *itr1 > *(itr1+1) )
				{	int temp;

					temp=*itr1;
					*itr1=*(itr1+1);
					*(itr1+1)=temp;

					temp=*itr2;
					*itr2=*(itr2+1);
					*(itr2+1)=temp;
				}
			
			return;
	}


	int sizeA = size/2;			// Size of the first half  ==> A
	int sizeB = size- sizeA;	// Size of the second half ==> B

	preferenceTransform(sizeA, itr1, itr2);
	preferenceTransform(sizeB, itr1+sizeA, itr2+sizeA);

	vector<int> buffer1, buffer2;
	buffer1.resize(size);
	buffer2.resize(size);
	
	int countA=0,countB=0,countC=0; // Count variables

	while(countA<sizeA && countB<sizeB)	
	{
		if(  *(itr1+  countA) < *(itr1+sizeA+  countB)	)
		// If the current element in first half, i.e. A, is smaller, 
		// it becomes the next value to go into the buffer.
		{
			buffer1[countC]=*(itr1+  countA);
			buffer2[countC]=*(itr2+  countA);

			countC++;
			countA++;

		}
		else	
		// If the current element in the second half, i.e. B, is smaller, 
		// it becomes the next value to go into the buffer.
		{
			buffer1[countC]=*(itr1+sizeA+  countB);
			buffer2[countC]=*(itr2+sizeA+  countB);

			countC++;
			countB++;
		}
	}

	while(countA<sizeA)	// If vecB is all used up, place rest of vecA in vec C
	{
			buffer1[countC]=*(itr1+  countA);
			buffer2[countC]=*(itr2+  countA);

			countC++;
			countA++;
	}
	while(countB<sizeB)	// If vecA is all used up, place rest of vecB in vec C
	{
			buffer1[countC]=*(itr1+sizeA+  countB);
			buffer2[countC]=*(itr2+sizeA+  countB);

			countC++;
			countB++;
	}

	for (int i=0; i< size; i++)
	{
		*(itr1+i) = buffer1[i];
		*(itr2+i) = buffer2[i];
	}
}


//*************************************************************************
//Given two preference vectors pref1 and pref2, 
//preferenceTransform below can derive a signle transformed vector "transformed".
//The transformed vector "transformed" is derived by
//(i) sorting the elements in the first preference vector into ascending order and
//(ii) move the elements in the second preference vecto based on the way the elements.such that
//
//Note that the
//the number of inversions between pairs of elelments in pref1 and pref2 is the same as
//the number of inversions between the elements in "transformed".
//
//Note that 
//(i) transformedand is a reference parameter and
//    thus the caller need to provide the storage for vector<int>& 
//(ii) pref1 and pref2 are value parameters and the
//    the contents of the original vector arguments will not be altered.
//*************************************************************************
void preferenceTransform(vector<int>  pref1, vector<int>  pref2, vector<int>& transformed)
{
	if (pref1.size() != pref2.size() )
		return;
	int size = pref1.size();

	preferenceTransform(size,  pref1.begin(), pref2.begin());
	transformed.resize(size);
	for (int i=0; i< size; i++)
	{	//cout << pref1[i] << " , " << pref2[i] << endl;
		transformed[i] = pref2[i];
	}
}



//*************************************************************************

//
// Merge two sorted vectors function
//
void mergeTwoSortedVectors(vector<int> & vecA, vector<int> & vecB, vector<int> & vecC)
{

	//	Preconditions: (checking if the vectors are in ascending order)

	int size1 = vecA.size(), size2 = vecB.size();

	//for(int i=0; i<(size1-1); i++)	// Checking Vector A is in order
	//{
	//		if(vecA[i]>vecA[i+1])
	//		{	cout << "ERROR: The first vector is not in ascending order.\n";
	//			return;
	//		}
	//}
	//
	//for(int i=0; i<(size2-1); i++)// Checking Vector B is in order
	//{
	//		if(vecB[i]>vecB[i+1])
	//		{
	//			cout << "ERROR: The second vector is not in ascending order.\n";
	//			return;
	//		}
	//}

//
// Placing elements in vecC
	int countA=0,countB=0,countC=0; // Count variables


	while(countA<size1 && countB<size2)	
	{
		if(vecA[countA]<vecB[countB])	// If the vecA element is smaller, it becomes the next vecC element
		{
			vecC[countC]=vecA[countA];
			countC++;
			countA++;
		}
		else	// If the vecB element is smaller, it becomes the next vecC element
		{
			vecC[countC]=vecB[countB];
			countC++;
			countB++;
			numInversions = numInversions + (size1 - countA);
		}
	}

	while(countA<size1)	// If vecB is all used up, place rest of vecA in vec C
	{
			vecC[countC]=vecA[countA];
			countC++;
			countA++;
	}
	while(countB<size2)	// If vecA is all used up, place rest of vecB in vec C
	{
			vecC[countC]=vecB[countB];
			countC++;
			countB++;
	}

}

	
//
// Merge sort function
//
void mergeSort(vector<int> & vecToSort)
{
	int temp; // Initialize temporary variables
	vector<int> vec1,vec2;
	
	// First: check if vectors are already sorted
	if (vecToSort.size()<=1) //If  the size of  vecToSort is 1 or less, it is already sorted just return true.
		return;
 
	if (vecToSort.size()==2) //If size of  vecToSort  is 2, sort the two elements, and then return true.
	{
			if (vecToSort[0]>vecToSort[1])
				{
					temp=vecToSort[1];
					vecToSort[1]=vecToSort[0];
					vecToSort[0]=temp;
					numInversions++;
				}
			return;
	}

	int size1 = vecToSort.size()/2;	// Initialize size of new vectors
	int size2 = vecToSort.size()- size1;

	vec1.resize(size1);	// Resizing the temporary vectors
	vec2.resize(size2);

	for(int i=0;i<size1;i++)	// Placing variables in two new vectors
		vec1[i]=vecToSort[i];
	for(int i=0;i<size2;i++)
		vec2[i]=vecToSort[i+size1];

	mergeSort(vec1); //Call mergeSort(vec1)  to sort the first vector.
	mergeSort(vec2); //Call mergeSort(vec2) to sort the second vector.

	mergeTwoSortedVectors(vec1,vec2,vecToSort); // Merge the two sorted vectors
}

int inversionCount(vector<int>  pref1, vector<int>  pref2, vector<int>& transformed)
{
	numInversions = 0;
	preferenceTransform(pref1, pref2, transformed);
	mergeSort(transformed);
	return numInversions;
}