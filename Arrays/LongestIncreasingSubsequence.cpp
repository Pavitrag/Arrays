/*Problem:
 * http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 * LongestIncreasingSubsequence.cpp
 *
 *  Created on	:	Jun 12, 2016
 *  Author		:	Pavitra
 */
//O(N.log(N)) implementation.
//space = O(N)
#ifndef ALGO_ARRAYS_LONGESTINCREASINGSUBSEQUENCE_CPP_
#define ALGO_ARRAYS_LONGESTINCREASINGSUBSEQUENCE_CPP_
#include "Utils.h"
using namespace Utils;
#include<vector>
#include<iostream>

using namespace std;
int ceil(vector<int>& v, const vector<int>& T, int key) {
	int l = 0;
	int r = T.size() - 1;
	int m = 0;
	while (r - l > 1) {
		m = l + (r - l) / 2;
		if (v[T[m]] >= key)
			r = m;
		else
			l = m;
	}
	return r;
}

int ceil_Length(const vector<int>& T, int key) {
	int l = 0;
	int r = T.size() - 1;
	int m = 0;
	while (r - l > 1) {
		m = l + (r - l) / 2;
		if (T[m] >= key)
			r = m;
		else
			l = m;
	}
	return r;
}
/*T[] stores: index of the min. of the last value of an inc. subseq of a particular length*/
/*Logic:
 * 1. Note that the T[] stores the end elements of the the inc. subsequences sorted in
 * increasing order of their length.
 * 2. If the new element v[i] is smallest of all then push it at the begining of the list.
 * Literally overwriting end element of list of size 1.
 * 3. If the new element v[i] is largest of all the end elements of all the active subsequences,
 * then extend the largest list by this element.
 * 4. If the new element v[i] is in-between then find the end-element (Ceiling) which is greater than
 * v[i] and replace it with v[i]
 * 5. Keep track of length of the longest list.*/
int longestIncSubseqLength(vector<int>& v) {
	vector<int> T;
	if (v.empty())	return 0;
	T.push_back(v[0]);
	int len = 1;
	for (std::size_t i = 0; i < v.size(); i++) {
		if (v[i] <= T[0]) //same smallest element if encountered again will not be counted.
			T[0] = v[i];
		else if (v[i] > T[T.size() - 1]) {
			T.push_back(v[i]);
			len++;
		} else
			T[ceil_Length(T, v[i])] = v[i];
	}
	cout << "T.size() : " << T.size() << endl;
	return len;
}
#if 1
void printRecursiveLongestSubstring(vector<int>& v, vector<int>& R, vector<int>& T, int lastIndex){
	if(lastIndex != -1){
		printRecursiveLongestSubstring(v, R, T, R[lastIndex]);
		cout << "v[" << lastIndex << "] : " << v[lastIndex] << ", " ;
	}
}
//R[] is T[] as per Tushar Roy's algo.
int longestIncSubseq(vector<int>& v) {
	vector<int> R(v.size(), -1);
	vector<int> T;
	if (v.empty())	return 0;
	T.push_back(0); //Storing the index.
	int len = 0;
	for (std::size_t i = 1; i < v.size(); i++) {
		if (v[i] < v[T[0]]) {
			T[0] = i; //R[i] is already initialized to -1.
		}else if (v[i] > v[T[T.size() - 1]]) {
			R[i] = T[T.size() - 1];
			T.push_back(i);
			len++;
		} else{
			int c = ceil(v, T, v[i]);
			T[c] = i;
			R[T[c]] = T[c-1];
		}
	}
	cout << "R vector : " << endl;
	printVector(R.begin(), R.end());
	cout << "T[] vector : " << endl;
	printVector(T.begin(), T.end());
	cout << "A Longest increasing sub-sequence is :" << endl;
	printRecursiveLongestSubstring(v, R, T, T[len]);
	cout << endl;
	return len+1;
}
#endif
int longestIncSubseqMain() {
	int narr[] = {157, 73, 151, 24, 86, 157, 17, 27, 158, 127, 158, 138, 72, 70, 162, 97, 23, 18, 113, 118, 97, 186, 42, 24, 130, 30, 166, 160, 133, 97, 56, 54, 163, 185, 135, 55, 173, 58, 170, 133, 164, 8, 84, 112, 36, 68, 49, 76, 139, 24, 143, 155, 112, 142, 176, 60, 26, 22, 71, 27, 135, 6, 184, 51, 199, 80, 102, 194, 135, 38, 135, 157, 194, 177, 106, 163, 149, 82, 101, 14, 42, 56, 56, 143, 63, 12, 78, 25, 79, 153, 44, 97, 74, 41, 114, 76, 73, 19, 11, 18, 133, 113, 96, 170, 32, 41, 89, 86, 91, 98, 190, 191, 146, 154, 115, 52, 141, 45, 59, 136, 160, 193, 6, 65, 182, 104, 30, 176, 9, 93, 198, 150, 157, 162, 28, 68, 142, 130, 41, 14, 175, 2, 78, 16, 84, 14, 193, 25, 2, 193, 160, 71, 29, 28, 85, 76, 187, 99, 171, 88, 48, 5, 104, 22, 64, 107, 164, 11, 172, 90, 41, 165, 143, 20, 114, 192, 105, 19, 33, 151, 6, 176, 140, 104, 23, 99, 48, 185, 49, 172, 65, 114, 76, 146, 113, 147, 79, 170, 63, 120, 186, 90, 145, 66, 141, 46, 109, 119, 71, 2, 124, 133, 73, 153, 88, 171, 164, 102, 104, 24, 128, 1, 170, 16, 166, 29, 144, 148, 89, 144, 38, 10, 64, 50, 82, 189, 143, 9, 61, 22, 159, 155, 89, 147, 91, 150, 44, 31, 21, 149, 68, 137, 184, 36, 27, 186, 39, 54, 30, 25, 149, 124, 160, 58, 167, 145, 156, 119, 127, 12, 26, 156, 2, 150, 97, 185, 116, 165, 143, 76, 114, 143, 197, 149, 73, 27, 7, 174, 30, 5, 106, 27, 13, 176, 94, 166, 37, 137, 142, 15, 195, 57, 53, 137, 39, 83, 156, 16, 132, 31, 42, 26, 12, 38, 187, 91, 51, 63, 35, 94, 154, 17, 53, 9, 63, 34, 55, 104, 35, 104, 57, 149, 125, 118, 14, 110, 29, 1, 81, 119, 59, 51, 156, 162, 65, 104, 77, 44, 110, 103, 162, 90, 149, 83, 54, 75, 21, 3, 124, 32, 170, 79, 60, 9, 20, 172, 4, 146, 182, 105, 193, 86, 114, 99, 190, 123, 139, 38, 11, 62, 35, 109, 162, 160, 94, 116, 70, 138, 70, 59, 101, 172, 65, 118, 16, 156, 16, 131, 40, 13, 89, 83, 155, 86, 111, 85, 175, 181, 16, 152, 142, 116, 80, 111, 99, 74, 189, 178, 133, 157, 90, 114, 9, 142, 191, 124, 164, 29, 185, 179, 1, 72, 86, 175, 72, 134, 68, 154, 96, 169, 26, 77, 30, 51, 199, 110, 94, 87, 81, 117, 50, 68, 129, 80, 65, 22, 6, 27, 17, 117, 127, 67, 88, 82, 165, 141, 87, 22, 63, 122, 65, 110, 16, 103, 74, 125, 142, 146, 163, 24, 132, 7, 69, 119, 3, 108, 108, 82, 13, 137, 31, 115, 10, 85, 157, 91, 94, 197, 153, 55, 146, 109, 49, 92, 113, 132, 115, 40, 159, 123, 105, 196, 53, 70, 80, 39, 24, 119, 67, 60, 99, 87, 197, 63, 34, 159, 23, 147, 193, 38, 126, 48, 59, 3, 8, 99, 31, 93, 1, 79, 200, 153, 49, 83, 141, 116, 176, 163, 168, 137, 198, 19, 98, 29, 52, 17, 31, 50, 126, 59, 30, 121, 141, 161, 148, 163, 56, 76, 193, 162, 155, 199, 147, 115, 147, 189, 170, 39, 64, 76, 116, 122, 76, 16, 129, 35, 171, 106, 65, 158, 163, 162, 125, 150, 70, 131, 124, 151, 134, 126, 111, 138, 137, 138, 79, 194, 37, 115, 165, 192, 150, 136, 106, 138, 5, 138, 24, 65, 171, 9, 169, 82, 86, 153, 174, 53, 195, 77, 27, 197, 173, 50, 41, 175, 20, 144, 12, 142, 90, 20, 166, 6, 186, 17, 51, 16, 10, 65, 167, 94, 75, 110, 101, 96, 174, 190, 162, 173, 169, 159, 32, 69, 27, 111, 23, 175, 180, 111, 153, 183, 192, 96, 165, 75, 165, 103, 56, 61, 75, 173, 22, 123, 148, 178, 190, 6, 196, 195, 151, 144, 155, 82, 13, 73, 40, 29, 113, 163, 168, 9, 16, 109, 24, 160, 35, 5, 87, 120, 159, 146, 7, 167, 101, 168, 93, 188, 133, 157, 175, 48, 22, 84, 23, 132, 177, 184, 149, 124, 183, 19, 177, 21, 112, 183, 57, 91, 126, 125, 87, 78, 170, 44, 135, 78, 69, 69, 192, 197, 184, 29, 128, 27, 72, 98, 13, 104, 28, 9, 146, 109, 186, 39, 38, 44, 114, 102, 51, 129, 112, 51, 150, 193, 55, 70, 82, 66, 68, 114, 194, 35, 73, 173, 31, 102, 43, 178, 78, 171, 103, 165, 182, 191, 24, 38, 24, 180, 196, 170, 128, 43, 111, 183, 59, 127, 88, 71, 129, 52, 59, 14, 61, 184, 87, 143, 11, 73, 129, 35, 42, 119, 104, 68, 66, 139, 82, 58, 151, 15, 199, 59, 62, 64, 157, 8, 79, 90};

	vector<int> v4(narr, narr + 836);
	printVector(v4.begin(), v4.end());
	cout << longestIncSubseqLength(v4) << endl;
	cout << "---------------" <<endl;
	cout << longestIncSubseq(v4) << endl;
	cout << "Test case 1" << endl;
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	vector<int> seq(arr, arr + 16);
	printVector(seq.begin(), seq.end());
	cout << longestIncSubseq(seq) << endl;
	cout << "Test case 2" << endl;
	int array1[] = { 68, 35 ,1 ,70 ,25 ,79 ,59 ,63 ,65 ,6 ,46 ,82};
	vector<int> v1(array1, array1 + 12);
	printVector(v1.begin(), v1.end());
	cout << longestIncSubseq(v1) << endl;
	cout << "Test case 3" << endl;
	int array2[] = { 62, 92,96 ,43 ,28 ,37 ,92 ,5 ,3 ,54 ,93 ,83 ,22 };
	vector<int> v2(array2, array2 + 13);
	printVector(v2.begin(), v2.end());
	cout << longestIncSubseq(v2) << endl;
}
#endif /* ALGO_ARRAYS_LONGESTINCREASINGSUBSEQUENCE_CPP_ */
