/*
 * SpiralPrint2DVector.cpp
 *
 *  Created on	:	Jul 2, 2016
 *  Author		:	pavi.8081
 *
 *  QUESTION ===========
 *  source: https://www.interviewbit.com/problems/spiral-order-matrix-i/
 *  Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include<iostream>
#include<vector>

using namespace std;

void spiralPrintMyTry(vector<vector<int> >&v){
	int m = v.size();
	int n = v[0].size();
	int i = 0, j = 0;
	for (int layer = 0; layer < (m + 1) / 2; layer++) {
		i = layer;
		for (j = layer; j < n - 1 - layer; j++)
			cout << v[i][j] << " ";
//		j=n - 1 - layer;
		for (i = layer+1; i < m - 1 - layer; i++)
			cout << v[i][j] << " ";
		for (j = (n - 1) - layer; j > layer; j--)
			cout << v[i][j] << " ";
		for (i = m - 1 - layer; i > layer; i--)
			cout << v[i][j] << " ";
	}
	cout << endl;
}
#if 1
void spiralPrint(vector<vector<int> >&v) {
	int top, bottom, left, right;
	top = 0, bottom = v.size() - 1, left = 0, right = v[0].size() - 1;
	int direction = 0; //0 => left->right; 1 => top->down; 2 -> right->left; 3 => down->top
	while (top <= bottom && left <= right) {
		if (direction == 0) {
			for (int i = left; i <= right; i++)
				cout << v[top][i] << " ";
			direction = 1;
			top++;
		} else if (direction == 1) {
			for (int i = top; i <= bottom; i++)
				cout << v[i][right] << " ";
			direction = 2;
			right--;
		} else if (direction == 2) {
			for (int i = right; i >= left; i--)
				cout << v[bottom][i] << " ";
			direction = 3;
			bottom--;
		} else if (direction == 3) {
			for (int i = bottom; i >= top; i--)
				cout << v[i][left] << " ";
			direction = 0;
			left++;
		}
	}
	cout << endl;
}
#endif
#if 0
void spiralPrint(vector<vector<int> >&v){
	int top, bottom, left, right;
	top = 0, bottom = v.size() - 1, left = 0, right = v[0].size() - 1;
	while (top <= bottom && left <= right) {
		for (int i = left; i <= right; i++)
			cout << v[top][i] << " ";
		top++;

		for (int i = top; i <= bottom; i++)
			cout << v[i][right] << " ";
		right--;

		for (int i = right; i >= left; i--)
			cout << v[bottom][i] << " ";
		bottom--;

		for (int i = bottom; i >= top; i--)
			cout << v[i][left] << " ";
		left++;
	}
	cout << endl;
}
#endif

void spiralPrintDriver(){
	int arr0[] = {1, 2, 3, 4};
	int arr1[] = {5, 6, 7, 8};
	int arr2[] = {9, 10, 11, 12};
	int arr3[] = {13, 14, 15, 16};
	vector<vector<int> > v;
	v.push_back(vector<int>(arr0, arr0+3));
	v.push_back(vector<int>(arr1, arr1+3));
	v.push_back(vector<int>(arr2, arr2+3));
//	v.push_back(vector<int>(arr3, arr3+4));
	spiralPrint(v);
	cout << "------------------" << endl;
	vector<vector<int> > v1;
	v1.push_back(vector<int>(arr0, arr0+4));
	v1.push_back(vector<int>(arr1, arr1+4));
	v1.push_back(vector<int>(arr2, arr2+4));
	v1.push_back(vector<int>(arr3, arr3+4));
	spiralPrint(v1);
	cout << "------------------" << endl;
	vector<vector<int> > v2;
	v2.push_back(vector<int>(arr0, arr0+1));
	v2.push_back(vector<int>(arr1, arr1+1));
	v2.push_back(vector<int>(arr2, arr2+1));
	spiralPrint(v2);

}
