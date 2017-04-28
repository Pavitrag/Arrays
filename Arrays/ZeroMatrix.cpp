/*
 * ZeroMatrix.cpp
 *
 *  Created on	:	Jun 27, 2016
 *  Author		:	I309980
 *  Book: Cracking the coding interview - 6th Ed.
		Chapter # 1
		QUESTION: 1.8
			ZERO MATRIX: Write and algorithm such that if an element in an MxN matrix is zero, its entire
			row and column are set to 0.
 */
#if 1
#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;
#endif
#include<vector>
using namespace std;

void set(vector<vector<int> >& v, int r, int c, int value) {
	if (r == -1)
		for (int i = 0; i < v.size(); i++)
			v[i][c] = 0;
	else
		for (int i = 0; i < v[0].size(); i++)
			v[r][i] = 0;
}
void makeZero(vector<vector<int> >& v) {
	int r0 = -1, c0 = -1;
	//check if first column has zero.
	for (int i = 0; i < v.size(); i++)
		if (v[i][0] == 0)
			c0 = 1;

	//check if first row has zero.
	for (int i = 0; i < v[0].size(); i++)
		if (v[0][i] == 0)
			r0 = 1;

	//check for zeros in rest of the array.
	for (int i = 1; i < v.size(); i++)
		for (int j = 1; j < v[0].size(); j++)
			if (v[i][j] == 0) {
				v[0][j] = 0;
				v[i][0] = 0;
			}
	//setting phase;
	for (int i = 1; i < v[0].size(); i++)
		if (v[0][i] == 0)
			set(v, -1, i, 0);//set corresponding column vector zero
	for (int i = 1; i < v.size(); i++)
		if (v[i][0] == 0)
			set(v, i, -1, 0);//set corresponding row vector zero

	//set the first row zero
	if (r0 == 1) {
		//v[0][0] = 0;
		set(v, 0, -1, 0);
	}

	//set the first column zero
	if (c0 == 1) {
		//v[0][0] = 0;
		set(v, -1, 0, 0);
	}
}

void makeZeroDriver() {
	vector<vector<int> > v(2, vector<int>(2));
	v[0][0] = 1;
	v[0][1] = 0;
	v[1][0] = 0;
	v[1][1] = 0;
	makeZero(v);
	print2DVector(v);
	cout << "---------" << endl;

	vector<vector<int> > v1(3, vector<int>(4));
	v1[0][0] = 1; 	v1[0][1] = 0;	v1[0][2] = 1;	v1[0][3] = 1;
	v1[1][0] = 0; 	v1[1][1] = 0;	v1[1][2] = 1;	v1[1][3] = 0;
	v1[2][0] = 1;	v1[2][1] = 1;	v1[2][2] = 1;	v1[2][3] = 1;
	makeZero(v1);
	print2DVector(v1);
	cout << "---------" << endl;
}
#if 0
int main(){
	int T;
	while(T-- >0){
		int r, c;
		cin >> r >> c;
		vector<vector<int> > v(r, vector(c));
		for(int i =0; i<r; i++)
			for(int j =0; j<c; j++)
				cin >> v[i][j];
		makeZero(v);

	}
}
#endif
