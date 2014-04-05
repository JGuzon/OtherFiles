//*************************************************************************
//Given two preference vectors pref1 and pref2, 
//preferenceTransform below can derive a signle transformed vector "transformed".
//The transformed vector "transformed" is derived by
//(i) sorting the elements in the first preference vector into ascending order and
//(ii) move the elements in the second preference vecto based on the way the elements.
//
//Note that the
//the number of inversions between pairs of elelments in pref1 and pref2 is the same as
//the number of inversions between the elements in "transformed".
//
//Note that 
//(i) transformed is a reference parameter and
//    thus the caller need to provide the storage for the third parameter
//(ii) pref1 and pref2 are value parameters and the
//    the contents of the original vector arguments will not be altered.
//*************************************************************************
void preferenceTransform(vector<int>  pref1, vector<int>  pref2, vector<int>& transformed);


void mergeTwoSortedVectors(vector<int> & vecA, vector<int> & vecB, vector<int> & vecC); 

void mergeSort(vector<int> & vecToSort);

void testMergeSortImplementation();

int inversionCount(vector<int>  pref1, vector<int>  pref2, vector<int>& transformed);