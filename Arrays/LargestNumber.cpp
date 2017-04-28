/*
 * LargestNumber.cpp
 *
 *  Created on	:	Jul 3, 2016
 *  Author		:	I309980
 */
/*QUESTION:======================
		Given a list of non negative integers, arrange them such that they form the largest number.

		For example:

		Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

		Note: The result may be very large, so you need to return a string instead of an integer.
SOURCE: https://www.interviewbit.com/problems/largest-number/
*/

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;


//#include "Solution.h"
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include <iterator>
#include <sstream>
#include<cmath>
using namespace std;

bool compare(string a, string b){
	string first = a.append(b);
	string second = b.append(a);

	return (first.compare(second)>0 ? true : false);
}

string numberToString(int a){
	string s(0, '0');
	if(a == 0){
		s.insert(s.begin(), '0');
		return s;
	}
	while(a>0){
		int rem = a%10;
		a = a/10;
		s.insert(s.begin(), rem+'0');
	}
	return s;
}
vector<string> toString(const vector<int>& a, int& all0s){
	vector<string> s;
	for(size_t i =0; i<a.size(); i++){
		s.push_back(numberToString(a[i]));
		if(s[i] != "0")
			all0s = 0;
	}
	return s;
}

string largestNumber(const vector<int> &A) {
	int all0s = 1;
    vector<string> s = toString(A, all0s);
	if(all0s)
		return "0";
	sort(s.begin(), s.end(), compare);
	string ss;
	for(int i =0; i<s.size(); i++)
		ss.append(s[i]);
	return ss;
}

void largestNumberDriver(){
	int arr[] = {3, 30, 34, 5, 9};
	vector<int> v(arr, arr+5);
	cout << "largestNumber = " << largestNumber(v) << "\n" << "----------" << endl;
	int arr1[] = {0, 0, 0, 0, 0,  0};
	vector<int> v1(arr1, arr1 + 6);
	cout << "largestNumber = " << largestNumber(v1) << "\n" << "----------" << endl;
}
