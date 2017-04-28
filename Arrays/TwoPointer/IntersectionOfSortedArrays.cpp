/*
 * IntersectionOfSortedArrays.cpp
 *
 *  Created on	:	Jul 11, 2016
 *  Author		:	Pavi.
 *
 *  source: https://www.interviewbit.com/problems/intersection-of-sorted-arrays/
 *
 *  === QUESTION ===
 *  Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input :
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input :
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]
 NOTE : For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more
 than once in both arrays should be included multiple times in the final output.
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;
#include<vector>
//My Solution:
vector<int> intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> c;
    int a = 0;
    int b = 0;
    while(a < A.size()  && b < B.size()){
        if(A[a] < B[b])
            a++;
        else if(A[a] > B[b])
            b++;
        else{
            c.push_back(A[a]);
            a++;
            b++;
        }
    }
    return c;
}


