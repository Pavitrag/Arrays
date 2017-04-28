/*
 * MergeOverlappingIntervals.cpp
 *
 *  Created on	:	Jul 3, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include<vector>
#include<algorithm>
using namespace std;

/*source : https://www.interviewbit.com/problems/merge-overlapping-intervals/
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
*/


// Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

 bool merge_compare(Interval a, Interval b){
	 Interval tmpa;
	 tmpa.start = (a.start < a.end ? a.start : a.end);
	 tmpa.end = (a.start > a.end ? a.start : a.end);
	Interval tmpb;
	tmpb.start = (b.start < b.end ? b.start : b.end);
	tmpb.end = (b.start > b.end ? b.start : b.end);
	if(tmpa.start < tmpb.start)
		return true;
	return false;
 }
vector<Interval> merge(vector<Interval> &A) {
	sort(A.begin(), A.end(), merge_compare);
	vector<Interval> result;
	result.push_back(A[0]);
	for(int i = 1; i < A.size(); i++){
		if(A[i].start <= result.back().end){
			result.back().end = (result.back().end > A[i].end ? result.back().end : A[i].end);
		}
		else
			result.push_back(A[i]);
	}
	return result;
}

void geeksforgeeksOutput(vector<Interval> &A){
	for(int i = 0; i < A.size(); i++){
		cout << A[i].start << " " << A[i].end ;
	}
	cout << endl;
}
void printIntervals(vector<Interval> &A){
	for(int i = 0; i < A.size(); i++){
		cout << "[" << A[i].start << ", " << A[i].end << "], ";
	}
	cout << endl;
}

void mergeOverlappingIntervalsDriver(){
	Interval arr[] = {{1,3},{2,6},{8,10},{15,18}};
	vector<Interval> A(arr, arr+4);
	printIntervals(A);
	vector<Interval> ret = merge(A);
	printIntervals(ret);
	cout << "------------------------" << endl;
}
