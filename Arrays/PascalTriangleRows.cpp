/*
 * PascalTriangleRows.cpp
 *
 *  Created on	:	Jul 4, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include<vector>
#include<iostream>

using namespace std;

vector<vector<int> > pascalTriangleRows(int A){
	vector<vector<int> > v;
	v.push_back(vector<int>(1, 1));
	for(int i = 1; i< A; i++){
		vector<int> vv;
		for(int j=0; j<=i; j++){
			if(j == 0)
				vv.push_back(v[i-1][j]);
			else if(j==i)
				vv.push_back(v[i-1][j-1]);
			else
				vv.push_back(v[i-1][j-1] + v[i-1][j]);
		}
		v.push_back(vv);
	}
	return v;
}


void pascalTriangleRowsDriver(){
	int i = 10;
	vector<vector<int> >v = pascalTriangleRows(i);
	print2DVector(v);
}
