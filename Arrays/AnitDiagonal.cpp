/*
 * AnitDiagonal.cpp
 *
 *  Created on	:	Jul 2, 2016
 *  Author		:	I309980
 */
/*
 source: : https://www.interviewbit.com/problems/anti-diagonals/
 Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

 Example:


 Input:

 1 2 3
 4 5 6
 7 8 9

 Return the following :

 [
 [1],
 [2, 4],
 [3, 5, 7],
 [6, 8],
 [9]
 ]


 Input :
 1 2
 3 4

 Return the following  :

 [
 [1],
 [2, 3],
 [4]
 ]
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;
#include<iostream>
#include<vector>

using namespace std;

#if 0 //=======This is my try and its correct!
void antiDiagonal(vector<vector<int> >&v, vector<vector<int> >& ret) {
	if(v.size() == 1) {
		ret.push_back(vector<int>(v.size(), v[0][0]));
		return;
	}
	for(int sum =0; sum<=2*(v.size()-1); sum++) { //indexes the new vector.
		ret.push_back(vector<int>());
		int i = (sum < v.size() ? sum : v.size()-1);
		int j = (sum-i < v.size() ? sum-i : v.size()-1);
		int maxj = i;
		int mini = j;
		for(; i >= mini && j <=maxj; i--, j++) {
			ret[sum].push_back(v[j][i]);
		}
	}
}
#endif
//========this one is based on the hint @ interviewbit.com
void antiDiagonal(vector<vector<int> >&v, vector<vector<int> >& ret) {
	for(int counter = 0; counter < v[0].size(); counter++){
		int r = 0, c = counter;
		vector<int> v1;
		while(r <= counter && c >= 0){
			v1.push_back(v[r][c]);
			r++;
			c--;
		}
		ret.push_back(v1);
	}
}
void antiDiagonalDriver() {
	int arr[] = { 1 };
	vector<vector<int> > v(1, vector<int>(arr, arr + 1));
	vector<vector<int> > ret;
	antiDiagonal(v, ret);
	print2DVector(ret);
	cout << "------------------------" << endl;
	int arr1[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	vector<vector<int> > v1;
	v1.push_back(vector<int>(arr1[0], arr1[0] + 3));
	v1.push_back(vector<int>(arr1[1], arr1[1] + 3));
	v1.push_back(vector<int>(arr1[2], arr1[2] + 3));
	vector<vector<int> > ret1;
	antiDiagonal(v1, ret1);
	print2DVector(ret1);
	cout << "------------------------" << endl;
}

//interviewbit solution:

/*
 ===HINT :====================================
 Lets look at how the co-ordinates change when you move from one element to the other in the anti-diagonal.
 With every movement, row increases by one, and the column decreases by one ( or in other words (1, -1)
 gets added to the current co-ordinates ).
 Now, all we need to know is the start ( or the first element ) in each diagonal.
 Can you figure out which elements qualify as the first elements in each diagonal ?

 ===SOLUTION APPROACH:==========================

 Continuing from hint 1, lets try to figure out the first element in each diagonal.

 Lets look at an example matrix.
 1 2 3
 4 5 6
 7 8 9

 The corresponding diagonals are :
 1
 2 4
 3 5 7
 6 8
 9
 If you look at the first elements in each diagonal, they seem to be the elements in the first row and then the
 last column in order 1 2 3 6 9
 So, you iterate over these positions in order, and keep adding (1, -1) to them till their co-ordinate is valid.
 */

class AntiDiagonalClass {
public:
	vector<vector<int> > diagonal(vector<vector<int> > Vec) {
		int N = Vec.size();
		if (N == 1)
			return Vec;

		vector<pair<int, int> > search_space;
		for (int i = 0; i < N; ++i) {
			search_space.push_back(make_pair(0, i));
		}
		for (int i = 1; i < N; ++i) {
			search_space.push_back(make_pair(i, N - 1));
		}

		vector<vector<int> > Ans;
		for (int i = 0; i < search_space.size(); ++i) {
			vector<int> Temp;
			int x = search_space[i].first;
			int y = search_space[i].second;
			while (x < N && y >= 0) {
				Temp.push_back(Vec[x][y]);
				x += 1;
				y -= 1;
			}
			Ans.push_back(Temp);
		}

		return Ans;
	}
};
