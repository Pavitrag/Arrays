/*
 * ThreeSum.cpp
 *
 *  Created on	:	Jul 10, 2016
 *  Author		:	Pavi
 *
 *  === QUESTION ===
 *  Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
	Return the sum of the three integers.
	You may assume that each input would have exactly one solution.

	Example:
	given array S = {-1 2 1 -4},
	and target = 1.

	The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
 *  === SOLUTION APPROACH ===
 *  When the array is sorted, try to fix the least integer by looping over it.

	Lets say the least integer in the solution is arr[i].

	Now we need to find a pair of integers j and k, such that arr[j] + arr[k] is closest to (target - arr[i]).

	To do that, let us try the 2 pointer approach.

	If we fix the two pointers at the end ( that is, i+1 and end of array ), we look at the sum.

	If the sum is smaller than the sum we need to get to, we increase the first pointer.
	If the sum is bigger, we decrease the end pointer to reduce the sum.
 */

#include "Utils.h"
#include "Grid.h"
#include<climits>
#include<algorithm>

using namespace Utils;
using namespace com_pavitra_learning;

int threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int mind;
    int diff=INT_MAX;
    for(int i =0; i<A.size(); i++){
        int j = i+1;
        int k = A.size()-1;
        while(j<k){
        	int sum = A[i]+A[j]+A[k];
        	cout << sum << endl;
			if(sum > B){
				if(abs(diff) > abs(sum-B)){
					diff = abs(sum-B);
					mind = sum;
				}
				k--;
			}
			else if(sum < B){
				if (abs(diff) > abs(sum - B)) {
					diff = abs(B - sum);
					mind = sum;
				}
				j++;
			}
			else if(sum == B)
				return sum;
        }
    }
    return mind;
}

//InterviewBit solution:
int threeSumClosestInterviewBit(vector<int> &num, int target) {
	sort(num.begin(), num.end());
	int bestSum = 1000000000, sum = 0;
	// Fix the smallest number in the three integers
	for (int i = 0; i < num.size() - 2; i++) {
		// Now num[i] is the smallest number in the three integers in the solution
		int ptr1 = i + 1, ptr2 = num.size() - 1;
		while (ptr1 < ptr2) {
			sum = num[i] + num[ptr1] + num[ptr2];
			if (abs(target - sum) < abs(target - bestSum)) {
				bestSum = sum;
			}
			if (sum > target) {
				ptr2--;
			} else {
				ptr1++;
			}
		}
	}
	return bestSum;
}

void threeSumClosestDriver(){
	int arr[] = { -5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3};
	vector<int>A(arr, arr+56);
	cout << "threeSumClosest = " << threeSumClosest(A, -1)<< endl;

	int arr1[] = { 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
	vector<int>A1(arr1, arr1+31);
	cout << "threeSumClosest = " << threeSumClosest(A1, -3) << endl;

	int arr2[] = { 5, -2, -1, -10, 10};
	vector<int>A2(arr2, arr2+5);
	cout << "threeSumClosest = " << threeSumClosest(A2, 5) << endl;

	int arr3[] = { -10, -10, -10 };
	vector<int> A3(arr3, arr3 + 3);
	cout << "threeSumClosest = " << threeSumClosest(A3, -5) << endl;
}
