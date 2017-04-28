/*
 * UglyNumbers.cpp
 *
 *  Created on	:	Jul 2, 2016
 *  Author		:	pavi.8081@gmail.com
 *
 *  SOURCE : http://www.practice.geeksforgeeks.org/problem-page.php?pid=553
 *
 *  QUESTION ==========
 *  Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
 *  The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers.
 *  By convention, 1 is included. Write a program to find Nth Ugly Number.

	Input:

	The first line of input contains an integer T denoting the number of test cases.
	The first line of each test case is N.

	Output:

	Print the Nth Ugly Number.

	Constraints:

	1 ≤ T ≤ 100
	1 ≤ N ≤ 500

	Example:

	Input:
	2
	10
	4

	Output:
	12
	4
 */
#include <iostream>
#include<vector>
#include<utils.h>
using namespace std;
using namespace Utils;

#define MIN(x, y, z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))
int ugly235(vector<int>& uglies, int n, int& i2, int& i3, int& i5){
    if(uglies.size() > n)
        return uglies[n-1];

    for(int i = uglies.size()-1; i < n; i++){
        int next_2 = uglies[i2]*2;
        int next_3 = uglies[i3]*3;
        int next_5 = uglies[i5]*5;
        int nextUgly = MIN(next_2, next_3, next_5);
        if(nextUgly == next_2)
            i2++;
        if(nextUgly == next_3)
            i3++;
        if(nextUgly == next_5)
            i5++;
        uglies.push_back(nextUgly);
    }
    return uglies[n-1];
}

int ugly357(vector<int>& uglies, int n, int& i3, int& i5, int& i7){
    if(uglies.size() > n)
        return uglies[n-1];

    for(int i = uglies.size()-1; i < n; i++){
        int next_3 = uglies[i3]*3;
        int next_5 = uglies[i5]*5;
        int next_7 = uglies[i7]*7;
        int nextUgly = MIN(next_3, next_5, next_7);
        if(nextUgly == next_3)
            i3++;
        if(nextUgly == next_5)
            i5++;
        if(nextUgly == next_7)
            i7++;
        uglies.push_back(nextUgly);
    }
    return uglies[n-1];
}
int uglyDriver() {
	vector<int> uglies235;
	uglies235.push_back(1);
	int i2, i3, i5;
	i2 = i3 = i5 = 0;
	cout << ugly235(uglies235, 68, i2, i3, i5) << endl;
	printVector(uglies235.begin(), uglies235.end());
	cout << "-------------------------------------------------"<< endl;
	//-------------------------------------------------
	vector<int> uglies357;
	int i23, i25, i27;
	i23 = i25 = i27 = 0;
	uglies357.push_back(1);
	cout << ugly357(uglies357, 68, i23, i25, i27) << endl;
	printVector(uglies357.begin(), uglies357.end());
#if 0

    int T;
    cin >>  T;
    while(T-- > 0){
        int N;
        cin >> N;

        cout << ugly235(uglies, N, i2, i3, i5) << endl;
    }
#endif
	return 0;
}



