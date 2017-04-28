/*
 * TripletSum.cpp
 *
 *  Created on	:	Jun 24, 2016
 *  Author		:	I309980
 */
#if 0
	#include "Utils.h"
	#include "Grid.h"
	using namespace Utils;
	using namespace com_pavitra_learning;
#endif


#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int findTriplet(vector<int>& v, int sum) {
	for (int i = 0; i < v.size(); i++) {
		int pivot = v[i];
		int lo = i + 1;
		int hi = v.size() - 1;
		while (lo < hi) {
			if ((v[lo] + v[hi] + pivot) == sum)
				return 1;
			else if ((v[lo] + v[hi] + pivot) < sum)
				lo++;
			else
				hi--;
		}
	}
	return 0;
}
int findTripletDriver() {
	int t = 0;
	cin >> t;
	while (t-- > 0) {
		int n, x;
		cin >> n >> x;
		vector<int> v(n);
		int itr = 0;
		while (itr < n) {
			cin >> v[itr++];
		}
		sort(v.begin(), v.end());
		cout << findTriplet(v, x) << endl;
	}
	return 0;
}
