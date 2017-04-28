/*
 * NextPermutation.cpp
 *
 *  Created on	:	Jul 6, 2016
 *  Author		:	I309980
 */
/*Source: http://www.programcreek.com/2014/06/leetcode-next-permutation-java/
interviewBit:https://www.interviewbit.com/problems/next-permutation/
	==================QUESTION===============
	Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
=========================================

Solution Analysis:

	The steps to solve this problem:
	1) scan from right to left, find the first element that is less than its previous one.

	4 5 6 3 2 1
	  |
	  p
	2) scan from right to left, find the first element that is greater than p.

	4 5 6 3 2 1
		|
		q
	3) swap p and q

	4 5 6 3 2 1
	swap
	4 6 5 3 2 1
	4) reverse elements [p+1, nums.length]

	4 6 1 2 3 5
*/
#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include<vector>
#include<algorithm>
using namespace std;

void swap(vector<int>&v, int l, int h){
	if ((l < 0) || (l >= v.size()) || (h < 0) || (h >= v.size()))
		return;
	int temp = v[l];
	v[l] = v[h];
	v[h] = temp;
}
void reverse(vector<int>&v, int l, int h){
	while(l<h){
		int temp = v[l];
		v[l] = v[h];
		v[h] = temp;
		l++; h--;
	}
}
void nextPermutation(vector<int>& v){
	if(v.size() == 0) return;
	int p=0;
	for(int i =v.size()-2; i>=0; i--){
		if(v[i]<v[i+1]){
			p = i;
			break;
		}
	}
	int q = 0;
	for(int i =v.size()-1; i>p; i--){
		if(v[i] > v[p]){
			q = i; //first greater number than v[p] from right
			break;
		}
	}
	if((p==0) && (q==0)){//numbers are reverse sorted, so reverse
		reverse(v, 0, v.size()-1);
		return;
	}
	swap(v, p, q);
	if(p+1<v.size()-1)
		reverse(v, p+1, v.size()-1);
}

void nextPermutationDriver(){
	cout << "Next Permutation === Test case # 1" << endl;
	int palin_arr[] = { 1, 2, 3, 4 };
	vector<int> palin_v(palin_arr, palin_arr + 4);
	cout << "next permutation larger than : ";
	printVector(palin_v.begin(), palin_v.end());
	cout << " is : ";
	nextPermutation(palin_v);
	printVector(palin_v.begin(), palin_v.end());

	cout << "===Test case # 2" << endl;
	int palin_arr1[] = { 0 };
	vector<int> palin_v1(palin_arr1, palin_arr1 + 1);
	cout << "next permutation larger than : ";
	printVector(palin_v1.begin(), palin_v1.end());
	cout << " is : ";
	nextPermutation(palin_v1);
	printVector(palin_v1.begin(), palin_v1.end());

	cout << "===Test case # 3" << endl;
	int palin_arr2[] = { 1, 9, 9, 1 };
	vector<int> palin_v2(palin_arr2, palin_arr2 + 4);
	cout << "next permutation larger than : ";
	printVector(palin_v2.begin(), palin_v2.end());
	cout << " is : ";
	nextPermutation(palin_v2);
	printVector(palin_v2.begin(), palin_v2.end());

	cout << "===Test case # 4" << endl;
	int palin_arr3[] = { 9 };
	vector<int> palin_v3(palin_arr3, palin_arr3 + 1);
	cout << "next permutation larger than : ";
	printVector(palin_v3.begin(), palin_v3.end());
	cout << " is : ";
	nextPermutation(palin_v3);
	printVector(palin_v3.begin(), palin_v3.end());

	cout << "Test case # 5" << endl;
	int palin_arr4[] = { 9, 9, 9, 9, 8 };
	vector<int> palin_v4(palin_arr4, palin_arr4 + 5);
	printVector(palin_v4.begin(), palin_v4.end());
	cout << " is : ";
	nextPermutation(palin_v4);
	printVector(palin_v4.begin(), palin_v4.end());
}
