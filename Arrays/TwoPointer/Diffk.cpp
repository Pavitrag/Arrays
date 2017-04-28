/*
 * Diffk.cpp
 *
 *  Created on	:	Jul 10, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
#include<Cmath>
using namespace std;
using namespace Utils;
using namespace com_pavitra_learning;

/* source : https://www.interviewbit.com/problems/diffk/
 * === QUESTION ===
 * Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input :
 A : [1 3 5]
 k : 4
 Output : YES as 5 - 1 = 4
 Return 0 / 1 ( 0 for false, 1 for true ) for this problem

 Try doing this in less than linear space complexity.

 * === SOLUTION APPROACH ===
 * Let us first look at why 2 pointer approach works here.
	A naive 2 loop approach would be:

	for (int i = 0; i < len; i++) {
	  for (int j = i + 1; j < len; j++) {
		if (A[j] - A[i] > diff) break; // No need going forward as the difference is going to increase even further.
		if (A[j] - A[i] == diff) return true;
	  }
	}
	Now, let us say that for i = I, we we exploring j.

	At j = J - 1, our difference D1 was less than diff
	At j = J, our difference D2 exceeded diff.
	When i = I + 1, our A[i] increases ( as the array is sorted ).
	So, for j = J - 1, the differece will be smaller than D1
	(which is even more smaller to diff.)
	Which means we do not need to explore j <= J - 1
	and we can begin exploring directly from j = J.
	So, j only keeps moving in forward direction and never needs to come back as i increases.

	Let us use that in a solution now:

	int j = 0;
	for (int i = 0; i < len; i++) {
	  j = max(j, i+1);
	  while (arr[j] - arr[i] < diff) j += 1;
	  if (arr[j] - arr[i] == diff) return true;
	}
 */

int diffPossible(vector<int> &A, int B) {
	if (A.size() <= 1)
		return 0;
	int len = A.size();
	int diff;
	for (int i = 0, j = i + 1; j < len;) {
		diff = A[j] - A[i];
		if (A[j] - A[i] > B)
			i++;
		else if (A[j] - A[i] < B)
			j++;
		else if (A[j] - A[i] == B)
			return 1;
		if (i == j)
			j++;
	}
	return 0;
}

bool diffPossibleInterviewBit(vector<int> &num, int diff) {
	if (num.size() < 2 || diff < 0)
		return false;
	int j = 0, len = num.size();
	for (int i = 0; i < len - 1; i++) {
		j = max(j, i + 1);
		while (j < len && num[j] - num[i] < diff)
			j += 1;
		if (j < len && num[j] - num[i] == diff)
			return true;
	}
	return false;
}

void diffPossibleDriver() {
	int arr[] = { 1, 3, 5 };
	vector<int> v(arr, arr + 3);
	cout << "Diff possible = " << diffPossible(v, 4) << endl;

	int arr1[] = { 0, 1, 9, 10, 13, 17, 17, 17, 23, 25, 29, 30, 37, 38, 39, 39, 40, 41, 42, 60, 64, 70, 70, 70, 72, 75,
			85, 85, 90, 91, 91, 93, 95 };
	vector<int> v1(arr1, arr1 + 33);
	cout << "Diff possible = " << diffPossible(v1, 83) << endl;

	int arr2[] = { 1, 2, 3 };
	vector<int> v2(arr2, arr2 + 3);
	cout << "Diff possible = " << diffPossible(v2, 0) << endl;
}

