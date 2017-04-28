/*
 * UnionIntersection.cpp
 *
 *  Created on	:	Jun 22, 2016
 *  Author		:	I309980
 */
#if 0
#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;
#endif

//UNION of two given un-sorted arrays
//Complexity : Time : O(Nlog(N) + Mlog(M))
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void _union(vector<int>& A, vector<int>& B){
	int i = 0;
	int j =0;
	while((i <A.size()) && (j < B.size())){
		if(A[i] < B[j]){
			cout << A[i] << " ";
			i++;
		}
		else if(A[i] > B[j]){
			cout << B[j] << " ";
			j++;
		}
		else if(A[i] == B[j]){
			cout << A[i] << " ";
			i++;
			j++;
		}
	}
	if(i >= A.size()){
		while(j < B.size()){
			cout << B[j] << " "; j++;
		}
	}
	else if(j >= B.size()){
		while(i < A.size()){
			cout << A[i] << " "; i++;
		}
	}
}
int unionDriver(){
	int T;
	cin >> T;
	while(T-- > 0){
		int N, M;
		cin >> N >> M;
		vector<int> A(N, 0);
		vector<int> B(M, 0);
		int i =0;
		while( i < N){
			cin >> A[i];
			i++;
		}
		i=0;
		while( i < M){
			cin >> B[i];
			i++;
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		_union(A, B);
		cout << endl;
	}
}

//Intersection of two unsorted arrays.
void intersection(const vector<int>& A, const vector<int>& B){
	//assumption - 1. input A and B are sorted
	//			   2. no duplicate elements.
	size_t i = 0;
	size_t j = 0;
	while ((i < A.size()) && (j < B.size())) {
		if (A[i] < B[j])		i++;
		else if (A[i] > B[j])	j++;
		else if (A[i] == B[j]) {
			cout << A[i] << " ";
			i++;
			j++;
		}
	}
}
