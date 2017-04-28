/*
 * RearrangeArray.cpp
 *
 *  Created on	:	Jun 28, 2016
 *  Author		:	Pavi
 *  Given an array arr[] of size n where every element is in range from 0 to n-1.
 *  Rearrange the given array so that arr[i] becomes arr[arr[i]]. This should be done with O(1) extra space.


 Input:

 First line contains an integer denoting the test cases 'T'.
 Every test case contains an integer value depicting size of array 'N'
 and N integer elements are to be inserted in the next line with spaces between them.


 Output:

 Print all elements of the array after rearranging, each separated by a space, in separate line for each test case.


 Constraints:

 1 <= T <= 70
 1 <= N<= 100
 1 <= Arr[i] <= 100
 Arr[i]<=N


 Example:

 Input:

 3
 2
 1 0
 5
 4 0 2 1 3
 4
 3 2 0 1

 Output:

 0 1
 3 4 2 0 1
 1 0 3 2

 **For More Examples Use Expected Output**
 **
 **Explained here: https://www.quora.com/How-can-I-rearrange-a-given-array-so-that-Arr-I-becomes-Arr-Arr-I-with-O-1-extra-space
 */
#if 0
#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;
#endif

#include <iostream>
#include<vector>
#include<string>
using namespace std;

void rearrange(vector<int>& v) {
	int N = v.size();
	for (int i = 0; i < N; i++) {
		int t = (v[v[i]] % N) * N + (v[i] % N);
		v[i] = t;
	}
	for (int i = 0; i < N; i++) {
		v[i] = v[i] / N;
	}
}

int rearrangeDriver() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];
		rearrange(v);
		for (int i = 0; i < N; i++)
			cout << v[i] << " ";
		cout << endl;
	}
	return 0;
}
