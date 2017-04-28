/*
 * Solution.h
 *
 *  Created on	:	Mar 4, 2016
 *  Author		:	I309980
 */

#ifndef ALGO_ARRAYS_SOLUTION_H_
#define ALGO_ARRAYS_SOLUTION_H_
#include<vector>
#include <string>
using std::vector;
class Solution{
public:
	static int maxSubArray(const std::vector<int> &A);
	static std::vector<int> maxset(std::vector<int> &A);
	static std::vector<int> wave(std::vector<int> &A);
	static std::string largestNumber(std::vector<int> &A);
	struct Interval {
	      int start;
	      int end;
	      Interval() : start(0), end(0) {}
	      Interval(int s, int e) : start(s), end(e) {}
	  };
	static std::vector<Solution::Interval> insert(std::vector<Solution::Interval> &intervals, Solution::Interval newInterval);
	static void setZeroes(std::vector<std::vector<int> > &);
	static std::vector<std::vector<int> > prettyPrint(int);
	static std::vector<int> plusOne(std::vector<int> &A);
	static int firstMissingPositive(std::vector<int> &A);
	static std::vector<int> repeatedNumber(const std::vector<int> &A);
	static std::vector<int> flip(std::string A);
	static int repeatedNumber2(const vector<int> &A);
	//BinarySearch.cpp
	static int findMinRecursive(const vector<int> &A, int, int);
	static int findMin(const vector<int> &A, int);
	static int sqrt(int A);
	static int searchMatrix(vector<vector<int> > &A, int B);
	static int pow(int x, int n, int d);
	static vector<int> searchRange(const vector<int> &A, int B);
	static int searchInsert(vector<int> &A, int B);
	static double findMedianSortedArrays(const vector<int> &A, const vector<int> &B);
};



#endif /* ALGO_ARRAYS_SOLUTION_H_ */
