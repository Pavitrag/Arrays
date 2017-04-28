/*
 * TicTacToe.cpp
 *
 *  Created on	:	Jul 17, 2016
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

/*Tic tac toe
Given the end position of a variation of a game of tic-tac-toe for two players X and O on an N by N board where 9 > N > 3, enumerate the score. For every three consecutive x marks in a horizontal, vertical or diagonal row, X scores a point; likewise the same for O. Note that four consecutive xs would net X two points; 5 consecutive xs would net three points and so on.

Input: The first line in the input is the number of test cases t. The second line consists of n where n is the board size. The next n rows is the final board position for first test case. This is followed by the next test case in the same format.

Output: The next t lines would be the game score for each of the test cases t. X's followed by O's score.

Sample input is below:    C:\Users\i309980\Documents\personal\learning\test_cases\itc-tac_toe\p_2_t_sample_in.txt

2
6
o o x x o o
o o x o x x
x o x o x o
x o o x x x
x o o o x x
o x x o x o
9
x x o x x o o x x
x x o o x o x o x
o o x x o x o o x
o x o o x o x x x
x o x x x x o x x
x o x o x x o o x
o x x x x x o o o
o o o o o x o o o
x o x o o x o o o

Sample output is below:    C:\Users\i309980\Documents\personal\learning\test_cases\itc-tac_toe\p_2_t_sample_out.txt

8 9
31 24
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

void horizontal(vector<vector<char> >&mat, int& x_score, int& o_score) {
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j + 2 < mat[0].size(); j++) {
			if((mat[i][j] == mat[i][j+1]) &&(mat[i][j + 1] == mat[i][j + 2]))
			{
				if (tolower(mat[i][j]) == 'x')
					x_score++;
				else
					o_score++;
			}
		}
	}
}

void vertical(vector<vector<char> >&mat, int& x_score, int& o_score) {
	for (int j = 0; j < mat[0].size(); j++) {
		for (int i = 0; i + 2 < mat.size(); i++) {
			if((mat[i][j] == mat[i+1][j]) &&(mat[i+1][j] == mat[i+2][j]))
			{
				if (tolower(mat[i][j]) == 'x')
					x_score++;
				else
					o_score++;
			}
		}
	}
}
//To Do : Correct Me
void diagonalNE_SW(vector<vector<char> >&mat, int& x_score, int& o_score){
	for (int offset = 0; offset < mat.size() - 2; offset++) {
		for (int i = offset, j = mat.size() - 1; i + 2 < mat.size() && j - 2 >= 0; i++, j--) {
			if ((mat[i][j] == mat[i + 1][j - 1]) && (mat[i + 1][j - 1] == mat[i + 2][j - 2])) {
				if (tolower(mat[i][j]) == 'x')
					x_score++;
				else
					o_score++;
			}
		}
	}
	//Upper
	for (int offset = 0; offset < mat.size() - 2; offset++) {
		for (int i = 0, j = (mat.size() - 1) - (offset + 1); /*i + 2 < mat.size() && */(j - 2 >= 0); i++, j--) {
			if ((mat[i][j] == mat[i + 1][j - 1]) && (mat[i + 1][j - 1] == mat[i + 2][j - 2])) {
				if (tolower(mat[i][j]) == 'x')
					x_score++;
				else
					o_score++;
			}
		}
	}
}
void diagonalNW_SE(vector<vector<char> >&mat, int& x_score, int& o_score){
	for(int offset = 0; offset<mat.size()-2; offset++){
		for(int i = 0, j = offset; i+2<mat.size() && j+2<mat.size(); i++, j++){
			if ((mat[i][j] == mat[i + 1][j+1]) && (mat[i + 1][j+1] == mat[i + 2][j+2])) {
				if (tolower(mat[i][j]) == 'x')
					x_score++;
				else
					o_score++;
			}
		}
	}
	//lower
	for (int offset = 1; offset < mat.size() - 2; offset++) {
		for (int i = offset, j = 0; i + 2 < mat.size() && j + 2 < mat.size(); i++, j++) {
			if ((mat[i][j] == mat[i + 1][j + 1]) && (mat[i + 1][j + 1] == mat[i + 2][j + 2])) {
				if (tolower(mat[i][j]) == 'x')
					x_score++;
				else
					o_score++;
			}
		}
	}
}

void solve(vector<vector<char> >&mat, int& x_score, int& o_score){
	diagonalNW_SE(mat, x_score, o_score);
	diagonalNE_SW(mat, x_score, o_score);//this needs correction
	horizontal(mat, x_score, o_score);
	vertical(mat, x_score, o_score);

}
int solveTic() {
	freopen("C:\\Users\\i309980\\Documents\\personal\\learning\\test_cases\\itc-tac_toe\\p_2_t_sample_in.txt", "r", stdin);
	int T;
	cin >> T;
	while (T-- > 0) {
		int idim;
		cin >> idim;
		vector<vector<char> >v(idim, vector<char>(idim, 0));
		for(int i =0; i < idim; i++)
			for(int j =0; j < idim; j++)
					cin >> v[i][j];
		int x_score = 0, o_score = 0;
		solve(v, x_score, o_score);
		cout << x_score << " " << o_score << endl;
	}
	return 0;
}

