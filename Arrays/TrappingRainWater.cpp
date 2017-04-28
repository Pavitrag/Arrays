/*
 * TrappingRainWater.cpp

 *
 *  Created on	:	Jun 9, 2016
 *  Author		:	I309980
 *
 *  ***Solution Approach***
 *  instead of calculating area by height*width, we can think it in a cumulative way.
 *  In other words, sum water amount of each bin(width=1).
 *  Search from left to right and maintain a max height of left and right separately,
 *  which is like a one-side wall of partial container.
 *  Fix the higher one and flow water from the lower part.
 *  For example, if current height of left is lower, we fill water in the left bin.
 *  Until left meets right, we filled the whole container.
 */
//http://ideone.com/MJ17X1

#if 1
#include "Utils.h"
#include "Grid.h"
#include<vector>
#include<algorithm>
using namespace std;
using namespace Utils;
using namespace com_pavitra_learning;

/*https://leetcode.com/problems/trapping-rain-water/
 * QUESTION:
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.

 	 For example,
 	 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

 	 Time complexity : O(N)
 	 Space complexity : O(N)
 */

//InterviewBit Solution
class TrappingRainWaterSolution_InterviewBit {
public:
	int trap(int A[], int n) {
		int left = 0;
		int right = n - 1;
		int res = 0;
		int maxleft = 0, maxright = 0;
		while (left <= right) {
			if (A[left] <= A[right]) {
				if (A[left] >= maxleft)
					maxleft = A[left];
				else
					res += maxleft - A[left];
				left++;
			} else {
				if (A[right] >= maxright)
					maxright = A[right];
				else
					res += maxright - A[right];
				right--;
			}
		}
		return res;
	}
};

class TrappingRainWater {
public:
	int trap(vector<int>& height);
private:
	void maxFromLeft(vector<int>& input, vector<int>& lmax);
	void maxFromRight(vector<int>& input, vector<int>& rmax);
};

void TrappingRainWater::maxFromLeft(vector<int>& input, vector<int>& lmax) {
	int max_so_far = 0;
	for (std::size_t i = 0; i < input.size(); i++) {
		if (max_so_far < input[i])
			max_so_far = input[i];
		lmax.push_back(max_so_far);
	}
	cout << "max from left :" << endl;
	printVector(lmax.begin(), lmax.end());
}
void TrappingRainWater::maxFromRight(vector<int>& input, vector<int>& rmax) {
	int max_so_far = 0;

	for (int i = input.size() - 1; i >= 0; i--) {
			if (max_so_far < input[i])
				max_so_far = input[i];
		rmax[i] = max_so_far;
	}
	cout << "max from right :" << endl;
	printVector(rmax.begin(), rmax.end());
}
int TrappingRainWater::trap(vector<int>& height) {
	int trappedWater = 0;
	vector<int> lmax;
	vector<int> rmax(height.size());
	maxFromLeft(height, lmax);
	maxFromRight(height, rmax);
	for (std::size_t i = 0; i < height.size(); i++) {
		int min = (lmax[i] < rmax[i] ? lmax[i] : rmax[i]);
		trappedWater += (min - height[i]);
	}
	return trappedWater;
}

void tapRainWaterDriver(){
	int array[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	vector<int> v(array, array+12);
	TrappingRainWater t;
	printVector(v.begin(), v.end());
	cout << "total Units of water = " << t.trap(v) << endl;
	cout << "Test case # 2." << endl;
	int arrayV2[] = { 3, 8, 12, 6, 1, 0, 5, 20, 11, 4, 3, 0 };
	vector<int> v2(arrayV2, arrayV2 + 12);
	printVector(v2.begin(), v2.end());
	cout << "total Units of water = " << t.trap(v2) << endl;
	cout << "Test case # 3." << endl;
	int arrayV3[] = { 5, 4, 1, 2 };
	vector<int> v3(arrayV3, arrayV3 + 4);
	printVector(v3.begin(), v3.end());
	cout << "total Units of water = " << t.trap(v3) << endl;
	cout << "Test case # 4." << endl;
	int arrayV4[] = { 5, 2, 1, 2, 1, 5 };
	vector<int> v4(arrayV4, arrayV4 + 6);
	printVector(v4.begin(), v4.end());
	cout << "total Units of water = " << t.trap(v4) << endl;
}

#else

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height);
private:
	void maxFromLeft(vector<int>& input, vector<int>& lmax);
	void maxFromRight(vector<int>& input, vector<int>& rmax);
};

void Solution::maxFromLeft(vector<int>& input, vector<int>& lmax) {
	int max_so_far = 0;
	for (size_t i = 0; i < input.size(); i++) {
		if (max_so_far < input[i])
			max_so_far = input[i];
		lmax.push_back(max_so_far);
	}
}
void Solution::maxFromRight(vector<int>& input, vector<int>& rmax) {
	int max_so_far = 0;
	for (int i = input.size() - 1; i >= 0; i--) {
		if (max_so_far < input[i])
			max_so_far = input[i];
		rmax[i] = max_so_far;
	}
}

int Solution::trap(vector<int>& height) {
	int trappedWater = 0;
	vector<int> lmax;
	vector<int> rmax(height.size());
	maxFromLeft(height, lmax);
	maxFromRight(height, rmax);
	for (size_t i = 0; i < height.size(); i++) {
		int min = (lmax[i] < rmax[i] ? lmax[i] : rmax[i]);
		trappedWater += (min - height[i]);
	}
	return trappedWater;
}

int __main() {
	int T = 0;
	cin >> T;
	while(T-- > 0){
	    int N;
	    cin >>N;
	    vector<int> v(N);
		while (N-- > 0){
	        cin >> v[N];
	    }
	    Solution s;
	    cout << s.trap(v) << endl;
	}
	return 0;
}
#endif

