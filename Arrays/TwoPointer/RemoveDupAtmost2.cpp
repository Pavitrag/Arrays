/*
 * RemoveDupAtmost2.cpp
 *
 *  Created on	:	Jul 10, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;
/*
 * === QUESTION ===
 * Remove Duplicates from Sorted Array

	Given a sorted array, remove the duplicates in place such that each element appear atmost twice and return the new
	length.

	Do not allocate extra space for another array, you must do this in place with constant memory.

	Note that even though we want you to return the new length, make sure to change the original array as well in place

	For example,
	Given input array A = [1,1,1,2],

	Your function should return length = 3, and A is now [1,1,2].
 === SOLUTION APPROACH ===
	 Notice that the array is sorted. This implies that all repetitions for an element are clustered together
	 in the array.

	 Try maintaining 2 pointers in the array:

	 One pointer iterates over the array
	 Other pointer only moves per occurrence of a value in the array.
	 Now you need to make sure we choose atmost 2 occurrences per cluster of repetition in the array,
	 We could probably just check **if A[i] != A[i+1] || A[i] != A[i+2] **
	 So, the second pointer only moves when A[i] != A[i+1] || A[i] != A[i+2]
 */

int remove3ndDuplicates(vector<int> &A) {
	int len = A.size();
	if (len <= 3)
		return len;
	int count=1, j=1;
	for(int i =1; i<len; i++){
		if(A[i-1] == A[i] && count < 2){
			count++;
			A[j++] = A[i];
		}
		else if (A[i-1] != A[i]){
			A[j++] = A[i];
			count =1;
		}
	}
	return j;
}
void remove3ndDuplicatesDriver() {
	int arr[] = { 1, 1, 1, 2 };
	vector<int> v(arr, arr + 4);
	int len0 = remove3ndDuplicates(v);
	cout << "new length = " << len0 << endl;
	printVector(v.begin(), v.begin()+len0);
	int arr1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3  };
	vector<int> v1(arr1, arr1 + 70);
	int len = remove3ndDuplicates(v1);
	cout << "new length = " << len << endl;
	printVector(v1.begin(), v1.begin()+len);

	int arr2[] = { 1, 2, 3 };
	vector<int> v2(arr2, arr2 + 3);
	int len3 = remove3ndDuplicates(v2);
	cout << "new length = " << remove3ndDuplicates(v2) << endl;
	printVector(v2.begin(), v2.begin()+len3);

	int arr3[] = {0, 1, 1, 2, 2, 3, 3, 3, 3};
	vector<int> v3(arr3, arr3 + 9);
	int len1 = remove3ndDuplicates(v3);
	cout << "new length = " << len1 << endl;
	printVector(v3.begin(), v3.begin()+len1);

	int arr4[] = { 0, 1, 1, 2, 2, 3, 4, 5, 5, 6, 6, 6, 7 };
	vector<int> v4(arr4, arr4 + 13);
	int len2 = remove3ndDuplicates(v4);
	cout << "new length = " << len2 << endl;
	printVector(v4.begin(), v4.begin() + len2);

	int arr5[] = {0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 3};
	vector<int> v5(arr5, arr5 + 11);
	int len4 = remove3ndDuplicates(v5);
	cout << "new length = " << len4 << endl;
	printVector(v5.begin(), v5.begin() + len4);
}

//InterviewBit Approach
int removeDuplicatesAtmost2InterviewBit(int A[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (i < n - 2 && A[i] == A[i + 1] && A[i] == A[i + 2])
			continue;
		else {
			A[count] = A[i];
			count++;
		}
	}
	return count;
}
