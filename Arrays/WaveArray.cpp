/*
 * WaveArray.cpp
 *
 *  Created on	:	Jul 1, 2016
 *  Author		:	Pavi.
 *
 *  source : http://www.practice.geeksforgeeks.org/problem-page.php?pid=125
 *
 *  QUESTION===========
 *  Given an array of integers, sort the array into a wave like array and return it.
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
 NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.



Input:

The first line contains an integer T, depicting total number of test cases.
Then following T lines contains an integer N depicting the size of square matrix and next line followed by the value of array.


Output:

Print the array into wave like array.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100

Example:

Input
1
5
5 7 3 2 8
Output
3 2 7 5 8
 */
#if 0
#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;
#endif

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void _swap(vector<int>& v, int i, int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
//O(N.LogN)
void waved(vector<int>& v){
	sort(v.begin(), v.end());
	for(size_t i=0;i<v.size();i+=2){
		if(i+1 < v.size())
			_swap(v, i, i+1);
	}
}

//O(N)

void waveUnsorted(vector<int>& v){
	for (size_t i = 0; i < v.size(); i+=2) {

	}
}
void wavedDriver(){
	int arr[] = { 5, 7, 3, 2, 8 };
	vector<int> v(arr, arr+5);
	waved (v);
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
