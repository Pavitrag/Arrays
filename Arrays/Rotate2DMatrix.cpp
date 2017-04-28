/*
 * Rotate2DMatrix.cpp
 *
 *  Created on	:	Jun 27, 2016
 *  Author		:	I309980
 */
/*Book: Cracking the coding interview - 6th Ed.
	Chapter # 1
	QUESTION: 1.7
	*/

#if 1
	#include "Utils.h"
	#include "Grid.h"
	using namespace Utils;
	using namespace com_pavitra_learning;
#endif

#include<iostream>
#include<vector>

using namespace std;

void rotateVectorBasedMatrix(vector<vector<int> >& img) {
	int rows = img.size();
	for (int i = 0; i < rows/2; i++) {
		int temp;
		for (int j = i; j < rows-(i+1); j++) {
			temp = img[i][j];
			img[i][j] = img[rows - 1 - j][i];
			img[rows - 1 - j][i] = img[rows - 1 - i][rows - 1 - j];
			img[rows - 1 - i][rows - 1 - j] = img[j][rows - 1 - i];
			img[j][rows - 1 - i] = temp;
		}
	}
}

//Cracking coding interview solution - 6th Ed sol. Mixed with my rediscovery.
void rotateMatrix90v2(vector<vector<int> >&v){
	cout << "----------VERSION 2--------------" << endl;
	int row = v.size();
	for (int layer = 0; layer < row / 2; layer++) {
		int first = layer;
		int last = row - 1 - layer;
		for (int i = first; i < last; i++) {
			int offset = i-first;
			int temp = v[first][i];
			v[first][i] = v[last-offset][first];
			v[last - offset][first] = v[last][last - offset];
			v[last][last - offset] = v[first + offset][last];
			v[first + offset][last] = temp;
		}
	}
}
//l = layer; o = offset
void rotateMatrix90v1(vector<vector<int> >&v){
	cout << "----------VERSION 1--------------" << endl;
	int row = v.size();
	for(int l=0; l<row/2; l++){
		for(int o=0; o<row-1-2*l; o++){
			int temp = v[l][l+o];
			v[l][l+o] = v[row-1-(l+o)][l];
			v[row-1-(l+o)][l] = v[row-1-l][row-1-(l+o)];
			v[row-1-l][row-1-(l+o)] = v[l+o][row-1-l];
			v[l+o][row-1-l] = temp;
		}
	}
}

void rotateVectorBasedMatrixDriver(){
	 int image[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13, 14, 15, 16}};
//	 int image[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	 vector<vector<int> > v(4, vector<int>(4));
	 for(int i=0;i<4;i++){
		 for(int j=0;j<4; j++){
			 v[i][j] = image[i][j];
		 }
	 }
	 print2DVector(v);
	 cout << "------------------------" << endl;
	 rotateMatrix90v1(v);
	// rotateVectorBasedMatrix(v);
	 print2DVector(v);
	 cout << "------------------------" << endl;
	 int img1[][14] = {
			  {27, 35, 36, 47, 94, 133, 163, 164, 235, 253, 280, 310, 339, 352},
			  {46, 72, 77, 95, 144, 149, 158, 174, 242, 243, 317, 371, 378, 386},
			  {13, 14, 80, 83, 121, 157, 158, 163, 215, 220, 308, 325, 388, 397},
			  {11, 38, 45, 84, 105, 132, 134, 145, 184, 219, 282, 298, 380, 381},
			  {23, 27, 42, 118, 120, 139, 168, 225, 243, 271, 274, 349, 393, 395},
			  {22, 27, 49, 85, 103, 167, 175, 234, 241, 258, 283, 296, 352, 385},
			  {24, 78, 117, 119, 137, 147, 173, 189, 193, 216, 281, 304, 332, 358},
			  {27, 71, 108, 109, 112, 133, 137, 145, 150, 171, 195, 225, 260, 336},
			  {5, 56, 65, 114, 123, 200, 220, 222, 248, 264, 285, 317, 350, 367},
			  {2, 20, 60, 72, 75, 130, 136, 149, 189, 254, 264, 295, 315, 349},
			  {23, 35, 68, 77, 104, 129, 153, 165, 248, 253, 290, 316, 321, 394},
			  {34, 127, 129, 154, 186, 202, 203, 210, 235, 269, 331, 344, 376, 387},
			  {11, 98, 99, 118, 119, 183, 250, 252, 277, 280, 291, 307, 360, 368},
			  {42, 74, 93, 119, 178, 186, 198, 221, 234, 295, 296, 319, 322, 335}
			};
	 vector<vector<int> >v1;
	 v1.push_back(vector<int>(img1[0], img1[0]+14));
	 v1.push_back(vector<int>(img1[1], img1[1]+14));
	 v1.push_back(vector<int>(img1[2], img1[2]+14));
	 v1.push_back(vector<int>(img1[3], img1[3]+14));
	 v1.push_back(vector<int>(img1[4], img1[4]+14));
	 v1.push_back(vector<int>(img1[5], img1[5]+14));
	 v1.push_back(vector<int>(img1[6], img1[6]+14));
	 v1.push_back(vector<int>(img1[7], img1[7]+14));
	 v1.push_back(vector<int>(img1[8], img1[8]+14));
	 v1.push_back(vector<int>(img1[9], img1[9]+14));
	 v1.push_back(vector<int>(img1[10], img1[10]+14));
	 v1.push_back(vector<int>(img1[11], img1[11]+14));
	 v1.push_back(vector<int>(img1[12], img1[12]+14));
	 v1.push_back(vector<int>(img1[13], img1[13]+14));
	rotateMatrix90v2(v1);
	print2DVector(v1);
	cout << "------------------------" << endl;


}

