/*
 * KthSmallestElementInArray.cpp
 *
 *  Created on	:	Jul 13, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include<vector>
using namespace std;

#if 0
void  swapForKthSmallest(vector<int>& h, int i, int j){
    int temp = h[i];
    h[i]=h[j];
    h[j] = temp;
}
void maxHeapify(vector<int>& h, int e, int k){
	if (h.size() < k) {
		h.push_back(e);
		int idx = h.size() - 1;
		int p = (idx - 1) / 2;
		while ((idx >= 0) && (h[idx] < h[p])) {
			swapForKthSmallest(h, idx, p);
			idx = p;
			p = (idx - 1) / 2;
		}
		if (h.size() > k) {
			h.pop_back();
		}
	}
	else{
		if(e < h[0]){
			h[0] = e;
			maxHeapify(h, )
		}
	}
}

int sink(vector<int>& h, int idx){
    h[0] = h[h.size()-1];
    h.pop_back();
    int p = 0;
    int min = p;
    while(p < h.size()){
        if((2*p+1 < h.size()) && (h[min] > h[2*p+1])){
            min = 2*p+1;

        }
        if((2*p+2 < h.size()) && (h[min] > h[2*p+2])){
            min = 2*p+2;
        }

        if(min != p){
            swapForKthSmallest(h, min, p);
            p = min;
        }
        else
            return;
    }
    return;
}
void formMinHeap(const vector<int> &A, vector<int>& h, int k){
    for(int i = 0; i< A.size(); i++){
        minHeapify(h, A[i], k);
    }
}

int kthsmallest(const vector<int> &A, int k) {
    vector<int>h;
    formMinHeap(A, h, k);
    int r;
    printVector(h.begin(), h.end());
    for(int i = 0; i<k; i++){
        r = sink(h);
    }
    return r;
}

void kthsmallestDriver(){
	int arr[] = {8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92};
	vector<int> v(arr, arr+46);
	printVector(v.begin(), v.end());
	cout << "Kth smallest element in array is = " << kthsmallest(v, 9) << endl;
}
#endif

void  kthsmallestMySwap(vector<int>& h, int i, int j){
    int temp = h[i];
    h[i]=h[j];
    h[j] = temp;
}

void swim(vector<int> & h, int e){
	h.push_back(e);
	int idx = h.size()-1;
	int p = (idx-1)/2;
	while((p >= 0) && (h[p] < h[idx])){
		kthsmallestMySwap(h, p, idx);
		idx = p;
		p = (idx-1)/2;
	}
}

void sink(vector<int> & h, int e){ //maxHeapify()
	if(e > h[0])
		return;
	h[0] = e;
	int p = 0;
	int l = 1, r = 2;
	int max = p;
	while(p < h.size()){
		l = 2*p + 1;
		r = 2*p + 2;
		if(l < h.size() && h[l] > h[max])
			max  = l;
		if(r < h.size() && h[r]  > h[max])
			max = r;

		if(max != p){
			kthsmallestMySwap(h, max, p);
			p = max;
		}
		else
			return;
	}
}

int MaxHeapify(vector<int> &v, int k){
	vector<int> h;
	for(int i = 0; i < k; i++)
		swim(h, v[i]);
	for(int i = k; i < v.size(); i++)
		sink(h, v[i]);
	return h[0];

}

void kthsmallestDriver(){
	int arr[] = {8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92};
	vector<int> v(arr, arr+46);
	printVector(v.begin(), v.end());
	cout << "Kth smallest element in array is = " << MaxHeapify(v, 9) << endl;
}
