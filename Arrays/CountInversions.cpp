/*
 * CountInversions.cpp
 *
 *  Created on	:	Aug 23, 2016
 *  Author		:	I309980
 * 
 *  === SOURCE === 
 *	https://www.interviewbit.com/problems/inversions/
 *
 *  === QUESTION ===
 *	Given an array A, count the number of inversions in the array.

	 Formally speaking, two elements A[i] and A[j] form an inversion if A[i] > A[j] and i < j

	 Example:

	 A : [2, 4, 1, 3, 5]
	 Output : 3
	 as the 3 inversions are (2, 1), (4, 1), (4, 3).
 *
 *	=== SOLUTION APPROACH ===
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

class CountInversionsType {
public:
//Implementation based on mergeSort in Book - Algorithms by Sedgewick
	int mergeAndCountInversions(vector<int> &A, int *arr, int b, int m, int e) {
		if (!arr)
			return 0;
		int inverts = 0;
		int lo = b, hi = m + 1;
		for (int k = b; k <= e; k++) {
			if (lo > m)
				arr[k] = A[hi++];
			else if (hi > e)
				arr[k] = A[lo++];
			else if (A[lo] > A[hi]) {
				inverts += (m - lo + 1);
				arr[k] = A[hi++];
			} else
				arr[k] = A[lo++];
		}
		for (int k = b; k <= e; k++)
			A[k] = arr[k];
		return inverts;
	}
#if 0 //Ist try.
	int mergeAndCountInversions(vector<int> &A, int *arr, int b, int m, int e) {
	    if(!arr) return 0;
		int inverts = 0;
		int i, j;
		int k = 0;
		for(i = b, j = m+1; i<=m && j<= e;){
			if(A[j] < A[i]){
				inverts+=(m-i+1);
				arr[k++] = A[j];
				j++;
			}
			else if(A[i] <= A[j]){
				arr[k++] = A[i];
				i++;
			}
		}
		if(i <= m)
			for(int t = i; t<=m; t++)
				arr[k++] = A[t];
		else if (j <= e)
			for (int t = j; t <= e; t++)
				arr[k++] = A[t];
		for(int l = b; l <= e; l++)
			A[l] = arr[l-b];
		return inverts;
	}
#endif
	int inversions(vector<int> &A, int *arr, int b, int e) {
		if (e <= b)
			return 0;
		int mid = (b + e) / 2;
		int left = inversions(A, arr, b, mid);
		int right = inversions(A, arr, mid+1, e);
		return left + right + mergeAndCountInversions(A, arr, b, mid, e);

	}
	int countInversions(vector<int> &A) {
		int*arr = new int[A.size()];
		return inversions(A, arr, 0, A.size() - 1);
	}
};

void countInversionsDriver(){
	int arr[] = { 84, 2, 37, 3, 67, 82, 19, 97, 91, 63, 27, 6, 13, 90, 63, 89, 100, 60, 47, 96, 54, 26, 64, 50, 71, 16,
			6, 40, 84, 93, 67, 85, 16, 22, 60 };
	vector<int> a(arr, arr+sizeof(arr)/sizeof(int));
	CountInversionsType ct;
	cout << ct.countInversions(a) << endl;
}
