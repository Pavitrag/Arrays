/*
 * IncreaseOrDecrease.cpp
 *
 *  Created on	:	Jun 8, 2016
 *  Author		:	I309980
 */
/*	Q U E S T I O N:
 * Given an array of N integers. At each step it is allowed to
 * increase the value of any number by 1 or decrease it by 1,
 * what is the minimum number of steps required to make the sequence non-decreasing.
 * */
#if 0
#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

int makeNonDecreasing(vector<int>& array, int begin, int end){
	int steps = 0;
	if(begin > end) return 0;

	if(begin > 0 && array[begin-1] > array[begin]){
		int diff = array[begin-1] - array[begin];
		array[begin] += diff;
		steps = diff + makeNonDecreasing(array, begin + 1, end);
	}
	else if(begin > 0 && array[begin-1] == array[begin]){

	}

}
#endif
