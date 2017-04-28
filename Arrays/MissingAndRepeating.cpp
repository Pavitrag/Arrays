/*
 * MissingAndRepeating.cpp
 *
 *  Created on	:	Jul 1, 2016
 *  Author		:	Pavi.
 *
 *  Source : http://www.practice.geeksforgeeks.org/problem-page.php?pid=108
 *
 *  QUESTION=====================
 *  Given an unsorted array of size n. Array elements are in range from 1 to n. One number 'A' from set {1, 2, …n} is missing and one number 'B' occurs twice in array. Find these two numbers.

Input:

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:

Print B, the repeating number followed by A which is missing in a single line.


Constraints:

1 ≤ T ≤ 40
1 ≤ N ≤ 100
1 ≤ A[i] ≤ N


Example:

Input
2
2
2 2
3
1 3 3
Output
2 1
3 2
 */
#if 0
	#include "Utils.h"
	#include "Grid.h"
	using namespace Utils;
	using namespace com_pavitra_learning;
#endif

#include<vector>
#include<iostream>

using namespace std;

void missingAndRepeating(vector<int>& v, int &repeated, int& missing){
	vector<int> count(v.size(), 0);
	for(size_t i = 0; i<v.size(); i++){
		count[v[i] - 1]++;
	}
	for(size_t i = 0; i<v.size(); i++){
		if (count[i] > 1)
			repeated = i+1;
		if (count[i] == 0)
			missing = i+1;
	}
}

int missingAndRepeatingDriver(){
	int repeated, missing;
	int arr[] = {2, 2};
	vector<int> v(arr, arr+2);
	missingAndRepeating(v, repeated, missing);
	cout << "repeating = " << repeated << "; missing = " << missing << endl;
	cout << "--------------------------------" << endl;
	int arr1[] = {1, 3, 3};
	vector<int> v1(arr1, arr1+3);
	missingAndRepeating(v1, repeated, missing);
	cout << "repeating = " << repeated << "; missing = " << missing << endl;
	cout << "--------------------------------" << endl;
	return 0;
}
