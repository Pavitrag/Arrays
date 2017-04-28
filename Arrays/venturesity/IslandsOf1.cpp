#if 0/*
 * IslandsOf1.cpp
 *
 *  Created on	:	Jul 20, 2016
 *  Author		:	I309980
 * 
 *  === SOURCE === 
 *	http://amzscr.venturesity.com/problem
 *  === QUESTION ===
 *	Islands of 1's
	Given a 2D matrix filled with 0's and 1's, find the number of islands of 1's in the matrix. An element with value 1 surrounded by all zeros vertically, horizontally or diagonally adjacent is an island of 1. A group of 1's can also form an island if they are vertically, horizontally and diagonally surrounded by 0’s.

	input format: First line of input consists of number of test case . T
	Next T lines followed by
	First line consists of number of rows and columns in the test case, say m and n. Next m rows are the matrix of size m X n.

	output format: Output should have T integer which represents the number of islands in each test case.

	Sample input:    C:\Users\i309980\Documents\personal\learning\test_cases\island_of_1s\p_1_t_sample_in.txt

	1
	5 5
	1 1 0 0 0
	0 1 0 0 1
	1 0 0 1 1
	0 0 0 0 0
	1 0 1 0 1
	Sample output:    C:\Users\i309980\Documents\personal\learning\test_cases\island_of_1s\p_1_t_sample_out.txt

	5
 *
 *	=== SOLUTION APPROACH ===
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

struct Adjacents{
	int r;
	int c;
	Adjacents(int i, int j) : r(i), c(j){}
};

Adjacents adj[] = {
		Adjacents(-1, -1),
		Adjacents(-1, 0),
		Adjacents(-1, 1),
		Adjacents(0, 1),
		Adjacents(1, 1),
		Adjacents(1, 0),
		Adjacents(1, -1),
		Adjacents(0, -1)
};

bool isValid(int r, int c, int m, int n) {
	if (r < 0 || r >= m)
		return false;
	if (c < 0 || c >= n)
		return false;
	return true;
}

void dfs(vector<vector<int> >& v, vector<vector<bool> >& visited, int i, int j, int m, int n) {
	if (isValid(i, j, m, n) && (v[i][j] == 1) && !visited[i][j] ) {
		visited[i][j] = true;
		for (int k = 0; k < 8; k++) {
			int v_i = i + adj[k].r;
			int v_j = j + adj[k].c;
			dfs(v, visited, v_i, v_j, m, n);
		}
	}
}

int islandsOf1V2(vector<vector<int> >& v) {
	int count = 0;
	int m = v.size();
	int n = v[0].size();
	bool isolated = true;
	vector<vector<bool> > visited(v.size(), vector<bool>(v[0].size(), false));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if ((v[i][j] == 1) && !visited[i][j]) { //dfs failed
				dfs(v, visited, i, j, m, n);
				count++;
			}
		}
	return count;
}
#endif
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Adj{
	int r;
	int c;
	Adj(int i, int j) : r(i), c(j){}
};

Adj adj[] = {
		Adj(-1, -1),
		Adj(-1, 0),
		Adj(-1, 1),
		Adj(0, 1),
		Adj(1, 1),
		Adj(1, 0),
		Adj(1, -1),
		Adj(0, -1)
};

bool valid(int r, int c, int m, int n) {
	if (r < 0 || r >= m)
		return false;
	if (c < 0 || c >= n)
		return false;
	return true;
}

bool dfs(vector<vector<int> >& v, vector<vector<bool> >& visited, int i, int j, int m, int n) {
	if (valid(i, j, m, n) && v[i][j] && !visited[i][j] ) {
		visited[i][j] = true;
		for (int k = 0; k < 8; k++) {
			int v_i = i + adj[k].r;
			int v_j = j + adj[k].c;
			dfs(v, visited, v_i, v_j, m, n);
		}
	}
	return true;
}

int go(vector<vector<int> >& v){
	int count = 0;
	int m = v.size();
	int n = v[0].size();
	vector<vector<bool> > visited(m, vector<bool>(n, false));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (v[i][j]&& !visited[i][j]){
				dfs(v, visited, i, j, m, n);
					count++;
			}
	return count;
}

/*int main(){
	int T;
	cin >> T;
	while (T-- > 0) {
		int rows, cols;
		cin >> rows >> cols;
		vector<vector<int> > v(rows, vector<int>(cols, 0));
		for(int i = 0; i< rows; i++)
			for(int j = 0 ; j < cols; j++)
				cin >> v[i][j];
		cout << go(v) << endl;
	}
	return 0;
}*/
int islandsOfOneDriver(){
	freopen("C:\\Users\\i309980\\Documents\\personal\\learning\\test_cases\\island_of_1s\\p_1_t_sample_in.txt",
			"r", stdin);
	int T;
	cin >> T;
	while (T-- > 0) {
		int rows, cols;
		cin >> rows >> cols;
		vector<vector<int> > v(rows, vector<int>(cols, 0));
		for(int i = 0; i< rows; i++)
			for(int j = 0 ; j < cols; j++){
				cin >> v[i][j];
			}
//		cout << islandsOf1(v) << endl;
//		cout << islandsOf1V2(v) << endl;
		cout << go(v) << endl;
	}
}


