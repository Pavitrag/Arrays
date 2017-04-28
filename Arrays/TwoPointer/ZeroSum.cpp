/*
 * ZeroSum.cpp
 *
 *  Created on	:	Jul 10, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
#include<algorithm>
using namespace std;
using namespace Utils;
using namespace com_pavitra_learning;

vector<vector<int> > threeSum(vector<int> &copy) {
	vector<int> A;
	vector<vector<int> > v;
	sort(copy.begin(), copy.end());
	A.push_back(copy[0]);
	for (int i = 1; i < copy.size(); i++)
		if ((copy[i] != 0) && (copy[i - 1] != copy[i]))
			A.push_back(copy[i]);
	printVector(A.begin(), A.end());
	for (int i = 0; i < A.size() - 2; i++) {
		int j = i + 1;
		int k = A.size() - 1;
		while (j < k) {
			int sum = A[i] + A[j] + A[k];
			if (sum > 0) {
				k--;
				//while((k-1 > j) && (A[k-1] == A[k])) k--;
			} else if (sum < 0) {
				j++;
				//while((j+1 < k) && (A[j+1] == A[j])) j++;
			} else if (sum == 0) {
				vector<int> v1;
				v1.push_back(A[i]);
				v1.push_back(A[j]);
				v1.push_back(A[k]);
				v.push_back(v1);
				j++;
				k--;
				//	while((j < k) && (A[j] == A[j-1])) j++;
				//while((k > j) && (A[k] == A[k+1])) k--;
			}
		}
	}
	return v;
}


void threeSumDriver(){
	int arr[] = {1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3 };
	vector<int> v(arr, arr+19);
	vector<vector<int> > ret = threeSum(v);
	print2DVector(ret);
}
