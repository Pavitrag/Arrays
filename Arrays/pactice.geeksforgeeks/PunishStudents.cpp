/*
 * PunishStudents.cpp
 *
 *  Created on	:	Sep 17, 2016
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
using namespace std;

static void bubbleSort(vector<int>& v, vector<int>& marks) {
	int n = v.size();
	bool swapped = true;
	for (int upperlimit = n; (upperlimit >= 0) && (swapped == true); upperlimit--) {
		swapped = false;
		for (int j = 1; j < upperlimit; j++) {
			if (v[j - 1] > v[j]) {
				swapped = true;
				int temp = v[j - 1];
				v[j - 1] = v[j];
				v[j] = temp;
				//--------
				marks[j - 1]--;
				marks[j]--;

				temp = marks[j - 1];
				marks[j - 1] = marks[j];
				marks[j] = temp;
			}
		}
	}
}

static bool solve(vector<int>& roll, vector<int>& marks, int m) {
	long t_marks = 0;
	bubbleSort(roll, marks);
	for (int i = 0; i < marks.size(); i++)
		t_marks += marks[i];
	t_marks /= marks.size();
	return t_marks >= m;
}

int punishStudents() {
	vector<int> roll = { 3, 2, 4, 1, 5 };
	vector<int> marks = { 50, 67, 89, 79, 58 };
	cout << solve(roll, marks, 68) << endl;
	//--------------------------------------
	vector<int> roll1 = { 5, 4, 1, 3, 2, 6 };
	vector<int> marks1 = { 78, 98, 86, 67, 78, 79 };
	cout << solve(roll1, marks1, 67.5) << endl;
#if 0
	int T=0;
	cin >> T;
	while(T-- > 0) {
		int n, m;
		cin >> n;
		cin >> m;
		vector<int> roll(n, 0);
		vector<int> marks(n, 0);
		for(int i = 0; i < n; i++)
		cin >> roll[i];
		for(int i = 0; i < n; i++)
		cin >> marks[i];
		cout << solve(roll, marks, m) << endl;
	}
#endif
	return 0;
}
