/*
 * PascalTriangleKthRow.cpp
 *
 *  Created on	:	Jul 3, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include<iostream>
#include<vector>

using namespace std;
typedef unsigned long long ull;

vector<ull> getRow(int A){
	if(A < 0) return vector<ull>(1, 0);
	if(A==0) return vector<ull>(1, 1);
	vector<ull> recur = getRow(A-1);
	vector<ull> v(A+1, 0);
	for(ull i = 0; i<v.size();i++){
		if(i ==0)
			v[0] = recur[0];
		else if(i == v.size()-1)
			v[i] = recur[i-1];
		else
			v[i] = recur[i-1]+recur[i];
	}
	return v;
}

void retRowDriver(){
	int i=100;
	vector<ull> v= getRow(i);
	printVector(v.begin(), v.end());
	cout << "------------------------" << endl;
}
