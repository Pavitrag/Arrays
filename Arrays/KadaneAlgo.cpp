/*
 * KadaneAlgo.cpp
 *
 *  Created on	:	Jun 29, 2016
 *  Author		:	I309980
 *  QUestion:
 *  Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=106
 *  Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.

Constraints:
1 ≤ T ≤ 40
1 ≤ N ≤ 100
-100 ≤ A[i] <= 100

Example:
Input
2
3
1 2 3
4
-1 -2 -3 -4

Output
6
-1

**For More Examples Use Expected Output**
 */

#include <iostream>
#include<vector>

using namespace std;

int maxSubArraySum(vector<int>&v, int &gbegin, int &gend){
	int begin=0;
	int end=0;
	gbegin = 0, gend = 0;
	int max_so_far = v[0];
	int max_ending_here = v[0];
	for(int i =1; i<v.size(); i++){
		if(max_ending_here+v[i] >= v[i]){
			max_ending_here +=v[i];
			end = i;
		}
		else{
			max_ending_here = v[i];
			begin = end = i;
		}

		if(max_so_far <= max_ending_here){
			max_so_far = max_ending_here;
			gbegin = begin;
			gend = end;
		}
	}
	return max_so_far;
}
int maxSubArraySumDriver() {
	int T;
	cin >> T;
	while(T-- > 0){
	    int N;
	    cin >> N;
	    vector<int> v(N);
	    for(int i =0; i < N; i++){
	        cin >> v[i];
	    }
	    int b, e;
	    int sum = maxSubArraySum(v, b, e);
	    /*for(int i = b; i<= e; i++){
	        cout << v[i] << " ";
	    }*/
	    cout << sum << endl;
	}
	return 0;
}
//--------------------------------------------
/**
 * Find out the maximum sub-array of non negative numbers from an array.
 The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

 Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

 Example:

 A : [1, 2, 5, -7, 2, 3]
 The two sub-arrays are [1, 2, 5] [2, 3].
 The answer is [1, 2, 5] as its sum is larger than [2, 3]
 NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
 NOTE 2: If there is still a tie, then return the segment with minimum starting index
 */
class Solution{
public:
	vector<int> maxset(vector<int> &A);
	int maxSubArraySum(const vector<int> &A);
	//This algo is to find the sum of the max sub array which also contains -ive numbers.
	int maxSubArray(const vector<int> &A, int &gb, int &ge);
};
//This algo is to find the sum of the max sub array which also contains -ive numbers.
int Solution::maxSubArraySum(const vector<int> &A) {
	int max, currMax;
	if (A.size() > 0)
		max = currMax = A[0];
	for (size_t i = 1; i < A.size(); i++) {
		currMax = std::max(A[i], currMax + A[i]);
		max = std::max(currMax, max);
	}
	return max;

}

//This algo is to find the sum of the max sub array which also contains -ive numbers.
	int Solution::maxSubArray(const vector<int> &A, int &gb, int &ge) {
		int max, currMax;
		int b = 0, e = 0;
		gb = ge = 0;
		if (A.size() > 0)
			max = currMax = A[0];
		for (size_t i = 1; i < A.size(); i++) {
			if(currMax + A[i] >= A[i]){
				e =  i;
			}
			else{
				b = e = i;
				currMax = A[i];
			}
			if(max > currMax){
				gb = b;
				ge = e;
				max = currMax;
			}
		}
		return max;

	}

//This algo is to find the max sub array which does not contain -ive numbers.
vector<int> Solution::maxset(vector<int> &A) {
	int arr[] = { 1, 2, 5, -7, 2, 5 };
	//int arr[] = {-1,-1,-1,-1,-1};
	//int arr[] = {0, 0, -1, 0};
	//int arr[] = {  756898537, -1973594324, -2038664370, -184803526, 1424268980 };
	vector<int> v;
	v.assign(arr, arr + 6);
	A = v;
	long long currMax = 0, max = 0;
	long lb = 0,/*le,*/b, e;
	/*lb=le=*/b = e = -1;
	for (int le = 0; le < A.size(); le++) {
		if (A[le] < 0) {
			lb = le + 1;
			currMax = 0;
		} else {
			currMax += A[le];
			if (max < currMax) {
				max = currMax;
				b = lb;
				e = le;
			} else if ((max == currMax) && (e - b < le - lb)) {
				b = lb;
				e = le;
			}
		}
	}
	std::vector<int> *iv;
	if ((e != -1) && (e - b >= 0))
		return *(iv = new vector<int>(A.begin() + b, A.begin() + e + 1));
	else {
		std::vector<int> iv(0);
		return iv;
	}
}
