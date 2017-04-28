/*
 * NumRange.cpp
 *
 *  Created on	:	Jul 14, 2016
 *  Author		:	I309980
 * 
 *  === SOURCE === 
 *	https://www.interviewbit.com/problems/numrange/
 *
 *  === QUESTION ===
 *	Given an array of non negative integers A, and a range (B, C),
	find the number of continuous subsequences in the array which have sum S in the range [B, C] or B <= S <= C

	Continuous subsequence is defined as all the numbers A[i], A[i + 1], .... A[j]
	where 0 <= i <= j < size(A)

	Example :

	A : [10, 5, 1, 0, 2]
	(B, C) : (6, 8)
	ans = 3
	as [5, 1], [5, 1, 0], [5, 1, 0, 2] are the only 3 continuous subsequence with their sum in the range [6, 8]

	 NOTE : The answer is guranteed to fit in a 32 bit signed integer.
 *
 *	=== SOLUTION APPROACH ===
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;



int numRange(vector<int> &A, int B, int C) {
    int sum = 0;
    int count = 0;
    int begin = -1;
    int i =0;
    while(A[i] > C)
        i++;
    while(i < A.size()){
        if(sum + A[i] < B){
            if(sum == 0){
                begin = i;
            }
            sum += A[i];
            i++;
        }
        else if((B <= sum + A[i]) && (sum + A[i] <= C)){
            sum += A[i];
            count++;
            i++;
        }
        else if(sum + A[i] > C){
            if(B <= sum-A[begin]+A[i] && sum-A[begin]+A[i] <= C){
                count++;
                sum += A[i] - A[begin];
                i++;
            }
            else{
            	sum -= A[begin];
            }
			begin++;
        }
    }
    return count;
}

//Correct algo.
int numRangeV2(vector<int> &A, int B, int C) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < A.size(); i++) {
		sum = 0;
		for (int j = i; j >= 0; j--) {
			if (sum + A[j] >= B && sum + A[j] <= C) {
				sum += A[j];
				count++;
			} else if (sum + A[j] < B)
				sum += A[j];
			else
				//sum + A[j] > C
				break;
		}
	}
	return count;
}

void numRangeDriver(){
	int arr[] = {80, 97, 78, 45, 23, 38, 38, 93, 83, 16, 91, 69, 18, 82, 60, 50, 61, 70, 15, 6, 52, 90};
	vector<int> a(arr, arr+22);
	cout << "Num Range between [99, 269] = " << numRangeV2(a, 99, 269) << endl;
}
