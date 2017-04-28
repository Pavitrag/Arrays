/*
 * SpiralOrderMatrix2.cpp
 *
 *  Created on	:	Jul 4, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

/*

source : https://www.interviewbit.com/problems/spiral-order-matrix-ii/
QUESTION:
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:
 [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]

*/

vector<vector<int> > generate_Matrix(int A){
	vector<vector<int> > v(A, vector<int>(A, 0));
	int T=0, B=A-1;
	int L=0, R=A-1;
	int direction = 0;
	int count = 1;
	while(T<=B && L <= R){
		if(direction == 0){
			for(int i = L; i<=R; i++){
				v[T][i] = count++;
//				count++;
			}
			T++;
			direction++;
		}
		else if(1 == direction){
			for(int i = T; i<=B; i++) {
				v[i][R] = count++;
//				count++;
			}
			R--;
			direction++;
		}
		else if (2 == direction) {
			for (int i = R; i >= L; i--) {
				v[B][i] = count++;
//				count++;
			}
			B--;
			direction++;
		}
		else if (3 == direction) {
			for (int i = B; i >= T; i--) {
				v[i][L] = count++;
//				count++;
			}
			L++;
			direction = 0;
		}
	}
	return v;
}

void printSpiralSquaredDriver(){
	int i =5;
	vector<vector<int> > v = generate_Matrix(i);
	print2DVector(v);
}
