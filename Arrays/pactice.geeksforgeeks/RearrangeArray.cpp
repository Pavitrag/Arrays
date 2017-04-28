/*
 * RearrangeArray.cpp
 *
 *  Created on	:	Sep 15, 2016
 *  Author		:	I309980
 * 
 *  === SOURCE === 
 *
 *  === QUESTION ===
 *
 *
 *	=== SOLUTION APPROACH ===
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
static void _printVector(const T& a, const T& b) {
	for (T t = a; t != b; t++)
		cout << *t;
	cout << endl;
}

static bool __compare(int a, int b) {
	return a > b;
}
void solve(vector<int>& v) {
	bool reverse = false;
	for (int i = 0; i < v.size() - 1; i++) {
		if (reverse)
			sort(v.begin() + i, v.end(), __compare);
		else
			sort(v.begin() + i, v.end());
		reverse = !reverse;
	}
}
int rearrangArrayG4GPractice() {
#if 0
	int T;
	cin >> T;
	while (T-- > 0) {
		int N;
		cin >> N;
		vector<int> v(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		solve(v);
		printVector(v.begin(), v.end());
	}
#endif
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };
	solve(v);
	_printVector(v.begin(), v.end());
	return 0;
}
