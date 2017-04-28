/*
 * MaxContiguousSeriesOf1.cpp
 *
 *  Created on	:	Jul 11, 2016
 *  Author		:	Pavi.

  SOURCE : https://www.interviewbit.com/problems/max-continuous-series-of-1s/
  === QUESTION ===
  You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
	Find the position of zeros which when flipped will produce maximum continuous series of 1s.

	For this problem, return the indices of maximum continuous series of 1s in order.

	Example:

	Input :
	Array = {1 1 0 1 1 0 0 1 1 1 }
	M = 1

	Output :
	[0, 1, 2, 3, 4]

	If there are multiple possible solutions, return the sequence which has the minimum start index.

	=== SOLUTION APPROACH ===
	N : 4
	lis : 1 0 1 0
	M : 2

	pointer i and j
	i = j = 0
	iterate till i < N:
			if(Number_of_Zeros_in_Current_range > M) :
					increment j and reduce range till Number_of_Zeros_in_current_range > M
			else :
					add element in range and update all variables
  */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;


vector<int> handle0(vector<int> &A){
	int maxW = 0;
	int i = 0, j = 0;
	int begin, end;
	for (int k = 0; k < A.size(); k++) {
		if (A[k] == 0) {
			continue;
		} else {
			i = j = k;
			while (A[j] == 1)
				j++;
			if (j - i > maxW) {
				maxW = j - i;
				begin = i;
				end = j - 1;
			}
			j--;
			k = j;
		}
	}
	vector<int> v;
	for (int i = begin; i <= end; i++)
		v.push_back(i);
	return v;
}

//copied from internet
vector<int> maxone(vector<int> &A, int m) {
	if (m == 0)
		return handle0(A);
	int countZeros = 0;
	for (int i = 0; i < A.size(); i++)
		if (A[i] == 0)
			countZeros++;
	if (countZeros < m) {
		vector<int> ret;
		for (int i = 0; i < A.size(); i++)
			ret.push_back(i);
		return ret;
	}
	int wL = 0, wR = 0;
	int nZero = 0;
	int bestWindowWidth = -1;
	int bestWL = 0, bestWR = 0;
	while (wR < A.size()) {
		//expand to the right, update '0' count:
		if (nZero <= m) {
			if (A[wR] == 0)
				nZero++;
			wR++;
		}

		//shrink from left, update '0' count:
		if (nZero > m) {
			if (A[wL] == 0)
				nZero--;
			wL++;
		}

		//update best window:
		if (wR - wL > bestWindowWidth) {
			bestWindowWidth = wR - wL;
			bestWR = wR;
			bestWL = wL;
		}
	}
	vector<int> idx;
	for (int i = 0; i < bestWindowWidth; i++)
		idx.push_back(bestWL + i);
	return idx;
}

//My developed solution
vector<int> maxoneMyTake(vector<int>& A, int m){
	if (m == 0)
		return handle0(A);
	int left = 0, right = 0;
	int mleft = -1, mright = -1;
	int maxContiguousOnes = 0;
	int nZeros = 0;
	for (; right < A.size(); right++) {
		if (nZeros < m) {
			if (A[right] == 0) {
				/*if (nZeros == 0) //got the first Zero.
				 left = right;*/
				nZeros++;
			}
		} else { //nZeros is m now.
			if (A[right] == 0) {
				while (A[left] != 0) {
					left++;
				}
				left++;
			}
		}

		if (nZeros == m) {
			if (maxContiguousOnes < right - left + 1) {
				maxContiguousOnes = right - left + 1;
				mright = right;
				mleft = left;
			}
		}
	} //for(;;)
	vector<int> v;
	if (nZeros == m) {
		//handle case when no. of zeros in vector less than 'm'.
		for (int i = mleft; i <= mright; i++) {
			v.push_back(i);
		}
	} else if (nZeros < m) {
		for (int i = 0; i <= A.size(); i++) {
			v.push_back(i);
		}
	}
	return v;
}

//Interview suggested solution
//----------------------------
void maxoneDriver(){
	int arr[] = { 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0};
	vector<int> v(arr, arr+17);
	int m = 4;
	vector<int> ret = maxone(v, m);
	printVector(ret.begin(), ret.end());

	vector<int> ret1 = maxoneMyTake(v, m);
	printVector(ret.begin(), ret.end());
}

