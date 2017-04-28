/*
 * SurpasserCount.cpp
 *
 *  Created on	:	Sep 25, 2016
 *  Author		:	I309980
 * 
 *  === SOURCE === 
 *	http://www.practice.geeksforgeeks.org/problem-page.php?pid=1152
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
//Binary search tree based solution.
class SurpasserNode {
public:
	SurpasserNode* left;
	SurpasserNode* right;
	int index;
	int rightCount;
	int value;

	SurpasserNode(int v) :
			left(NULL), right(NULL), index(-1), rightCount(0), value(v) {
	}
};

SurpasserNode* insert(SurpasserNode* node, int v, int idx, int rightSubtreeCount, vector<int>& c) {
	if (!node) {
		node = new SurpasserNode(v);
		node->index = idx;
		return node;
	}
	if (node->value <= v) { //insert right
		node->rightCount++;
		if (node->right)
			return insert(node->right, v, idx, rightSubtreeCount, c);
		else {
			node->right = new SurpasserNode(v);
			node->right->index = idx;
			c[idx] = rightSubtreeCount;
			return node;
		}
	} else if (node->value > v) { //insert left
		if (node->left)
			return insert(node->left, v, idx, rightSubtreeCount + node->rightCount + 1, c);
		else {
			node->left = new SurpasserNode(v);
			node->left->index = idx;
			c[idx] = rightSubtreeCount + node->rightCount + 1;
			return node;
		}
	}
	return NULL;
}

void goCount(vector<int>& v) {
	int n = v.size();
	vector<int> count(n, 0);
	SurpasserNode* root = NULL;
	for (int i = n - 1; i >= 0; i--) {
		if (!root)
			root = insert(root, v[i], i, 0, count);
		else
			insert(root, v[i], i, 0, count);
	}
	for (int i = 0; i < n; i++)
		cout << count[i] << " ";
	cout << endl;
}

//------------------ End: Binary search tree based solution ------------------
/* ...........................N.O. M.A.N'S. L.A.N.D........................... */
//------------------ Merge sort based solution ------------------
#include<unordered_map>
static void mergeModified(vector<int>& arr, vector<int>& aux, std::unordered_map<int, int>& inverts, int lo, int mid, int hi){
	int i = lo; int j = mid+1;
	for(int k=lo; k <= hi; k++){
		if(i > mid) arr[k++] = aux[j++];
		else if(j > hi) arr[k++] = aux[i++];
		else if(arr[i] <= arr[j])	arr[k++] = aux[i++];
		else{
			inverts[arr[i]]++;
			arr[k++] = aux[j++];
		}
	}
	return;
}
static void mergeSortModified(vector<int>& arr, vector<int>& aux, std::unordered_map<int, int>& inverts, int lo, int hi){
	if(lo >= hi) return;
	int mid = lo + (hi-lo)/2;
	mergeSortModified(aux, arr, inverts, lo, mid);
	mergeSortModified(aux, arr, inverts, mid+1, hi);
	if(aux[mid] < aux[mid+1])	return;
	mergeModified(arr, aux, inverts, lo, mid, hi);
}
void surpassersPerElement(vector<int>& arr){
	vector<int> aux(arr.begin(), arr.end());
	std::unordered_map<int, int> inversionCount;
	mergeSortModified(arr, aux, inversionCount, 0, arr.size()-1);
	for(int i =0; i < arr.size(); i++){
		inversionCount[arr[i]] = arr.size() - i - 1 - inversionCount[arr[i]];
	}
	for(std::unordered_map<int, int>::iterator p = inversionCount.begin(); p != inversionCount.end(); p++){
		cout << (*p).second << " ";
	}
	cout << endl;
}
//------------------ End : Merge sort based solution ------------------
void surpasserCountDriver() {
	vector<int> v = { 4, 5, 1, 2, 3 };
	goCount(v);
	cout << "surpassersPerElement : " << endl;
	surpassersPerElement(v);
	//---------------------
	vector<int> v1 = { 1, 7, 9, 3, 2, 8, 6, 5};
	goCount(v1);
	cout << "surpassersPerElement : " << endl;
	surpassersPerElement(v1);

	vector<int> v2 = { 468, 335, 501, 170, 725, 479, 359, 963, 465, 706, 146, 282, 828, 962, 492, 996, 943, 828, 437,
			392, 605, 903, 154, 293, 383, 422, 717, 719, 896, 448, 727, 772, 539, 870, 913, 668, 300, 36, 895, 704, 812,
			323 };
	cout << "surpassersPerElement : " << endl;
	goCount(v2);
	surpassersPerElement(v2);
}
#include<iostream>
using namespace std;
int kMarsh_new() {
	int m, n, k;
	    std::cin >> m >> n;
	    vector<vector<char> > l(m, vector<char>(n, '.'));
	    for(int i = 0; i < m; i++)
	        for(int j = 0; j < n; j++)
	            cin >> l[i][j];

	    int minr =0, maxr = m-1, minc = 0, maxc = n-1;
	    for(int i =0; i < m; i++){
	        for(k = 0; k < n; k++)
	            if(l[i][k] == 'x') break;
	        if(k == n){
	            minr = i;
	            break;
	        }
	    }

	    for(int i =m-1; i >=0 ; i--){
	        for(k = 0; k < n; k++)
	            if(l[i][k] == 'x') break;
	        if(k == n){
	            maxr = i;
	            break;
	        }
	    }

	    for(int i =0; i < n; i++){
	        for(k = 0; k < m; k++)
	            if(l[k][i] == 'x') break;
	        if(k == m){
	            minc = i;
	            break;
	        }
	    }

	    for(int i =n-1; i >=0; i--){
	        for(k = 0; k < m; k++)
	            if(l[k][i] == 'x') break;
	        if(k == m){
	            maxc = i;
	            break;
	        }
	    }

	    if(minr >= maxr || minc >= maxc) {
	        cout << "impossible";
	        return 0;
	    }
	    cout << 2*(maxr-minr) + 2*(maxc-minc);
	    return 0;
}
