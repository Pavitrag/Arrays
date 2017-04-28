/*
 * MaxContiguousSubarraySum.cpp
 *
 *  Created on	:	Mar 4, 2016
 *  Author		:	I309980
 */
/**
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest sum.

 For example:

 Given the array [-2,1,-3,4,-1,2,1,-5,4],

 the contiguous subarray [4,-1,2,1] has the largest sum = 6.

 For this problem, return the maximum sum.
 */
#include<iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <cmath>
#include <iterator>
#include <sstream>
#include"Grid.h"

#include "Solution.h"
//#include<pthread.h>
using namespace std;
/*struct Interval {
 int start;
 int end;
 Interval() : start(0), end(0) {}
 Interval(int s, int e) : start(s), end(e) {}
 };

 class Solution {
 public:
 static int maxSubArray(const vector<int> &A);
 static vector<int> maxset(vector<int> &A);
 static vector<int> wave(vector<int> &A);
 static string largestNumber(vector<int> &A);
 static vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);
 void setZeroes(vector<vector<int> > &A)
 };*/

/*
 * Given an array of integers, sort the array into a wave like array and return it,
 In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

 Example

 Given [1, 2, 3, 4]

 One possible answer : [2, 1, 4, 3]
 Another possible answer : [4, 1, 3, 2]
 */

vector<int> Solution::wave(vector<int> &A) {
	sort(A.begin(), A.end());
	for (int i = 1; i < A.size(); i += 2) {
		int temp = A[i];
		A[i] = A[i - 1];
		A[i - 1] = temp;
	}
	return A;
}
#if 0 //has in seperate file: LargestNumber.cpp
int numDigits(int number) {
	int digits = 0;
	if (number == 0)
		return 1;
	while (number) {
		number /= 10;
		digits++;
	}
	return digits;
}

bool compare(string src, string dst) {
	string cat = src + dst;
	string dog = dst + src;
	if (atoi(cat.c_str()) < atoi(dog.c_str()))
		return true;
	return false;
}

char* itoa(int i, char *s/*, int base*/) {
	int d = numDigits(i) + 1;
	int count = 0;
	if (i == 0) {
		s[0] = '0';
		s[1] = '\0';
		return s;
	}
	while (i != 0) {
		int digit = i % 10;
		s[d - 2 - count++] = '0' + digit;
		i /= 10;
	}
	s[d - 1] = '\0';
	return s;
}

template<typename T>
void mySwap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}
string Solution::largestNumber(vector<int> &A) {
	int arr[] = { 3, 30, 34, 5, 9 };
//	int arr[] = 	{ 0, 0, 0, 0, 0};
	vector<int> v;
	v.assign(arr, arr + 5);
	A = v;
	vector<string> sA; // = new vector<string>();
	for (vector<int>::size_type i = 0; i < A.size(); i++) {
		char *ss = new char[numDigits(A[i]) + 1];
		sA.push_back((itoa(A[i], ss/*, 10*/)));
		cout << sA[i] << endl;
	}
	sort(sA.begin(), sA.end(), compare);
	reverse(sA.begin(), sA.end());
	for (vector<int>::size_type i = 0; i < A.size() - 1; i++)
		if (compare(sA[i], sA[i + 1]))
			swap(sA[i], sA[i + 1]);

	//std::ostringstream os;
	std::stringstream os;
	std::copy(sA.begin(), sA.end(), std::ostream_iterator<std::string>(os, " "));
	//std::copy( sA.begin(), sA.end(), ostream_iterator<string>( os ) );
	/*for (vector<int>::size_type i = 0; i < sA.size(); i++)
		str = str + sA[i];
	if (0 == atoi(str.c_str())) {
		str = "0";
	}
	*/
	//cout << str << endl;
	return  os.str();
}
#endif
/**
 * Question:
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

 You may assume that the intervals were initially sorted according to their start times.

 Example 1:

 Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

 Example 2:

 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

 Make sure the returned intervals are also sorted.
 */
vector<Solution::Interval> Solution::insert(
		vector<Solution::Interval> &intervals, Solution::Interval newInterval) {
	if (newInterval.start > newInterval.end) {
		int tmp = newInterval.start;
		newInterval.start = newInterval.end;
		newInterval.end = tmp;
	}
	vector<Interval> result;
	//first insert the interval into this sorted interval
	vector<Interval>::iterator it;
	for (it = intervals.begin(); it != intervals.end(); it++) {
		if (newInterval.start < (*it).start) {
			intervals.insert(it, newInterval);
			break;
		}
	}
	if (it == intervals.end()) {
		intervals.insert(it, newInterval);
	}

	if (intervals.empty())
		return result;

	//merge intervals accordingly.
	result.push_back(*intervals.begin());
	for (vector<Interval>::iterator it = intervals.begin() + 1;
			it != intervals.end(); it++) {
		if ((*it).start > result.back().end)
			result.push_back(*it);
		else {
			result.back().end = (
					result.back().end > (*it).end ?
							result.back().end : (*it).end);
		}
	}
	return result;
}

/*
 Small explanation :

 We use the first row and column in the matrix to store what we need to store in step 2. The trick is in using the first row and column to store the information.
 Then we need to know whether or not to set the first row and column to zeroes. So, we use two boolean to store that information.

 Detailed explanation :

 So, you have 2 additional variables ( lets say R and C ). Firstly convince yourself that if in the original array, if any of the value in the first row was 0, the whole row will be 0. So R stores just that information ( whether any of the value in the row was 0 ). Now, if R = 0, your job is simple. In the end, mark every element in the first row as 0. If R = 1, then leave the row as it is ( with each cell storing whether their corresponding column has any zeroes ).
 Things work very similarily for columns.

 Let me demonstrate using an example.
 Lets say the array was

 [
 1 1 1
 0 1 1
 1 0 1
 ]
 Now, R = 1 as everything in row 1 = 1. C = 0, as second element in first column is 0.
 Now, using first row and first column to store value about their respective columns and rows ( For the first row, column i stores if all the value in column i are 1. For the first column, row i stores if all the values in row i are 1. We leave 0,0 unassigned )

 [
 X 0 1
 0 . .
 0 . .
 ]
 is what you get.

 Now, for any entry which is not in first row or first column, entry (r,c) is 1, if its corresponding column entry in first row is 1 and corresponding row entry in first column is 1.

 [
 0 0 1
 0 0 0
 0 0 0
 ]*/
void setZeroes(vector<vector<int> > &A) {
	int R = 1, C = 1;
	for (unsigned int i = 0; i < A[0].size(); i++)
		if (A[0][i] == 0) {
			R = 0; //marker to set first Row as 0
			break;
		}

	for (unsigned int i = 0; i < A.size(); i++)
		if (A[i][0] == 0) {
			C = 0; //marker to set first Col as 0
			break;
		}
	/*:::::::::::::::::::::::Assignments:::::::::::::::::::::::::::::::::*/
	for (unsigned int i = 1; i < A.size(); i++) {
		for (unsigned int j = 1; j < A[i].size(); j++) {
			if (A[i][j] == 0) {
				A[0][j] = 0;
				A[i][0] = 0;
			}
		}
	}

	vector<int> &v = A[0]; //take first row vector and mark corresponding columns zero
	for (unsigned int i = 1; i < v.size(); i++) {
		if (v[i] == 0) {
			for (unsigned int k = 1; k < A.size(); k++)
				A[k][i] = 0;
		}
	}

	for (unsigned int i = 1; i < A.size(); i++) {
		if (A[i][0] == 0) {
			vector<int> &v = A[i];
			for (unsigned int k = 1; k < v.size(); k++)
				v[k] = 0;
		}
	}

	if (R == 0) {
		vector<int> &ii = A[0];
		ii.assign(ii.size(), 0);
	}

	if (C == 0) {
		for (unsigned int k = 0; k < A.size(); k++)
			A[k][0] = 0;
	}
}
//---------------------------

/*
 Print concentric rectangular pattern in a 2d matrix.
 Let us show you some examples to clarify what we mean.

 Example 1:

 Input: A = 4.
 Output:

 4 4 4 4 4 4 4
 4 3 3 3 3 3 4
 4 3 2 2 2 3 4
 4 3 2 1 2 3 4
 4 3 2 2 2 3 4
 4 3 3 3 3 3 4
 4 4 4 4 4 4 4
 Example 2:

 Input: A = 3.
 Output:

 3 3 3 3 3
 3 2 2 2 3
 3 2 1 2 3
 3 2 2 2 3
 3 3 3 3 3
 The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

 You will be given A as an argument to the function you need to implement, and you need to return a 2D array.
 */

void copyToCol(int col, int value, vector<vector<int> >&A) {
	for (int i = col; i < A.size() - col; i++) {
		A[i][col] = value;
	}
}

void copyToRow(int row, int value, vector<vector<int> >&A) {
	vector<int> &v = A[row];
	for (int i = row; i < v.size() - row; i++) {
		v[i] = value;
	}
}

void copyAlongMinorDiagonal(vector<vector<int> >&A) {
	int rows = A.size() - 1;
	int cols = A[0].size() - 1;
	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols - i; j++) {
			A[rows - i][cols - j] = A[i][j];
		}
	}
}
vector<vector<int> > Solution::prettyPrint(int A) {
	long vsize = 2 * (A - 1) + 1;

	vector<int> oned(vsize);
	vector<vector<int> > pretty(vsize, oned);
	for (int i = A; i >= 1; i--) {
		int row = A - i;
		copyToRow(row, i, pretty);
		//--
		copyToCol(row, i, pretty);
	}
	copyAlongMinorDiagonal(pretty);
	print2DVector(pretty);
	return pretty;
}

vector<int> Solution::plusOne(vector<int> &A) {
	//-----------test code------
	A.clear();
	A.push_back(0);
	A.push_back(3);
	A.push_back(7);
	A.push_back(6);
	A.push_back(5);
	/////////////////////////////
	int carry = 0;
	if (A.size() > 0) {
		if (A[0] == 0) {
			cout << A.size() << endl;
			A.assign(A.begin() + 1, A.end());
			cout << A.size() << endl;
		}
		A[A.size() - 1] += 1;
	} else
		return A;
	carry = A[A.size() - 1] / 10;
	A[A.size() - 1] %= 10;
	for (int i = A.size() - 2; i >= 0; i--) {
		if (carry == 0)
			break;
		A[i] = A[i] + carry;
		carry = A[i] / 10;
		A[i] %= 10;
	}

	if (carry != 0) {
		vector<int> newA;
		newA.push_back(carry);
		newA.insert(newA.begin() + 1, A.begin(), A.end());
		return newA;
	}
	return A;
}

int segregate(std::vector<int>& A) {
	// 2, 3, -7, 6, 8, 1, -10, 15
	//after seg : -7, -10, 2, 6, 8, 1, 3, 15
	int ncount = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] <= 0) {
			int temp = A[ncount];
			A[ncount] = A[i];
			A[i] = temp;
			ncount++;
		}
	}
	return ncount;
}

int findMissing(vector<int>::iterator begin, vector<int>::iterator end) {
	//printVector(begin, end);
	int i = 0;
	for (i = 0; i < end - begin; i++) {
		//cout << "(begin[" << i << "]=" << begin[i] << " - 1) < " << (end - begin) << ") && ((begin[" << i << "]-1) >=0)" << endl;
		if (((begin[i] - 1) < (end - begin)) && ((begin[i] - 1) >= 0)) {
			//cout << "begin[" << i << "] = " << begin[i] <<endl;
			begin[begin[i] - 1] *= -1;
		}
	}
	//cout << "end - begin = " << end - begin << endl;
	//printVector(begin, end);
	for (i = 0; i < end - begin; i++) {
		if (begin[i] > 0)
			return i + 1;
	}
	return i;
}
int Solution::firstMissingPositive(std::vector<int>& A) {
	int ppos = segregate(A); //position in A from where +ive nos. start after segregation.
	//printVector(A.begin(), A.end());
	return findMissing(A.begin() + ppos, A.end());
}

//---------------

vector<int> Solution::repeatedNumber(const vector<int> &A) {
	vector<int> ret;
	bool flag = false;
	long long diffSum = 0, diffSqSum = 0;
	for (vector<int>::size_type i = 0; i < A.size(); i++) {
		diffSum = diffSum + (A[i] - (i + 1));
		diffSqSum = diffSqSum + ((long long) A[i] * A[i] - (i + 1) * (i + 1));
	}
	if (diffSum < 0)
		flag = true; // repeated one is smaller than missing one.
	diffSum = abs(diffSum);
	diffSqSum = abs(diffSqSum);
	int a = abs(((diffSqSum / diffSum) + diffSum) / 2);
	int b = abs(((diffSqSum / diffSum) - diffSum) / 2);
	if (flag) {
		if (a < b) {
			ret.push_back(a); // repeated
			ret.push_back(b); // missing
		} else {
			ret.push_back(b); // repeated
			ret.push_back(a); // missing
		}
	} else {
		if (a > b) {
			ret.push_back(a); // repeated
			ret.push_back(b); // missing
		} else {
			ret.push_back(b); // repeated
			ret.push_back(a); // missing
		}
	}
	return ret;
}

/*
 * You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R  N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

 You aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

 Notes:
 - Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == b, then b < d.

 For example,

 S = 010

 Pair of [L, R] | Final string
 _______________|_____________
 [1 1]          | 110
 [1 2]          | 100
 [1 3]          | 101
 [2 2]          | 000
 [2 3]          | 001

 We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
 Another example,

 If S = 111

 No operation can give us more than three 1s in final string. So, we return empty array [].
 */

vector<int> Solution::flip(string A) {
#if 0
		struct maxes {
			int L;
			int R;
			int maxOnes;
			maxes() :
					L(0), R(0), maxOnes(0) {
			}
		};
		vector<int> v;
		int totalCount = 0;
		size_t dim = A.length();
		for (int i = 0; i < dim; i++) {
			if (A[i] == '1')
				totalCount++;
		}
		if (totalCount == dim)
			return v;

		/*vector<int> oned(dim, 0);
		 vector<vector<int> > flips(dim, oned);*/
		vector<int> vflips(dim, 0);
		maxes m_max;
		long flips = 0, prevFlip = 0;
		for (int i = 0; i < dim; i++) {
			vflips[i]/*[i][i]*/= totalCount + ((A[i] == '1') ? -1 : 1);
			if (m_max.maxOnes < vflips[i]/*[i][i]*/) {
				m_max.maxOnes = vflips[i]/*[i][i]*/;
				m_max.L = m_max.R = i;
			}
		}
		for (int i = 0; i < dim; i++) {
			prevFlip = vflips[i];
			for (int j = i + 1; j < dim; j++) {
				flips/*[i][j]*/= prevFlip + ((A[j] == '1') ? -1 : 1);
				if (m_max.maxOnes < flips/*[i][j]*/) {
					m_max.maxOnes = flips/*[i][j]*/;
					m_max.L = i;
					m_max.R = j;
				}
				prevFlip = flips;
			}
		}
		v.push_back(m_max.L + 1);
		v.push_back(m_max.R + 1);
		return v;
#endif
	//int arr[] = { 1, 2, 5, -7, 2, 5 };
	vector<int> v;
	long best_ending_here = 0, best_till_now = 0;
	size_t dim = A.length();
	for (int i = 0; i < dim; i++) {
		if(A[i] == '1'){
			v.push_back(-1);
		}
		else
			v.push_back(1);
	}
	best_till_now = best_ending_here;
	long lb = 0, b, e;
	b = e = -1;
	for (int le = 0; le < dim; le++) {

		if (best_ending_here + v[le] < 0) {
			best_ending_here = 0;
			lb = le + 1;
		} else {
			best_ending_here += v[le];
			if (best_till_now < best_ending_here) {
				best_till_now = best_ending_here;
				b = lb;
				e = le;
			}
		}
	}
	std::vector<int> iv;
	if ((e != -1) && (e - b >= 0)){
		iv.push_back(b+1);
		iv.push_back(e+1);
	}
	return iv;
}

/**
 * Find Duplicate in ArrayBookmark
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less then O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.
 */

/*int Solution::repeatedNumber2(const vector<int> &A){
	int n = A.size()-1;
	int sqn = (int) sqrtl(n);
	for(int i=0; i<)

}*/
