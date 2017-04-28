/*
 * RemoveDuplicatesFromSortedArray.cpp
 *
 *  Created on	:	Jul 10, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;


/* === QUESTION ==
 *
 * Remove duplicates from Sorted Array
	Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

	Note that even though we want you to return the new length, make sure to change the original array as well in place

	Do not allocate extra space for another array, you must do this in place with constant memory.

	 Example:
	Given input array A = [1,1,2],
	Your function should return length = 2, and A is now [1,2].
	===========================================================

	=== SOLUTION APPROACH ===
	Notice that the array is sorted.
	This implies that all repetitions for an element are clustered together in the array.

	**Try maintaining 2 pointers in the array: **

	One pointer iterates over the array and
	Other pointer only moves per occurrence of a value in the array.
	Now you need to make sure we choose only one occurrence per cluster of repetition in the array, we could probably just check if A[i] != A[i+1].
	So, the second pointer only moves when A[i] != A[i+1]
*/

//My solution:
int removeDuplicates(vector<int> &A) {
    if(A.size() <= 1) return A.size();
    int len = A.size();
    int nlen = len;
    for(int i = len-1; i>=0; i--){
        if((i-1 >=0) &&(A[i-1] == A[i])){
            A.erase(A.begin()+i);
            nlen--;
        }
    }
    return nlen;
}
//InterviewBit solution...
int removeDuplicatesInterviewBit(vector<int> &A) {
	int count = 0, n = A.size();
	for (int i = 0; i < n; i++) {
		if (i < n - 1 && A[i] == A[i + 1])
			continue;
		else {
			A[count] = A[i];
			count++;
		}
	}
	return count;
}

int removeDuplicatesInterviewBit2(vector<int> &A) {
	int count = 0, n = A.size();
	int atmost2 = 1;
	for (int i = 0; i < n; i++) {
		if (i < n - 1 && A[i] == A[i + 1]){
			atmost2++;
			if(atmost2 > 2){
				while(i < n-1 && A[i] == A[i+1]){
					A[atmost2-1] = A[atmost2];
					atmost2++;
				}
			}
			else{
				count = atmost2-1;
			}
		}
		else {
			A[count] = A[i];
			count++;
			atmost2 = 1;
		}
	}
	return count;
}
