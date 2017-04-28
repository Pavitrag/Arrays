/*
 * RemoveElements.cpp
 *
 *  Created on	:	Jul 10, 2016
 *  Author		:	Pavi
 *
 *  === QUESTION ===
 *  Remove Element

	Given an array and a value, remove all the instances of that value in the array.
	Also return the number of elements left in the array after the operation.
	It does not matter what is left beyond the expected length.

	 Example:
	If array A is [4, 1, 1, 2, 1, 3]
	and value elem is 1,
	then new length is 3, and A is now [4, 2, 3]
	Try to do it in less than linear additional space complexity.
	-------------------------------------------------------------

 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;


int removeElement(vector<int> &A, int B) {
    int count = 0;
    for(int i =0; i<A.size(); i++)
    {
        if(A[i] != B){
            A[count++] = A[i];
        }
    }
    return count;
}

