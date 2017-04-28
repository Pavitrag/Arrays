/*
 * CheckUnique.cpp
 *
 *  Created on	:	Jun 25, 2016
 *  Author		:	I309980
 */
#if 0
#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;
#endif
/* Cracking coding interview Ed. 6 Chapter 1; Q - 1.2
 * Question : Given 2 strings, write a method to decide if one is a permutation of other*/
#include<iostream>
using namespace std;
/* Time complexity : O(N)
 * Space complexity : O(1) - constant because letters[] is not dependent on input size.*/

//assumption : character set is ASCII. Not even extended in which case had to take letters[256]
bool checkPermutation(char* s, int slen, char* t, int tlen) {
	if (!s || !t)
		return false;
	if (slen != tlen)
		return false;
	int *letters = new int[128]{0,};
	for(int i=0 ; i<slen; i++){
		letters[s[i]]++;
	}
	for(int i=0 ; i<tlen; i++){
		letters[t[i]]--;
		/* Since t and s are of same length, assume t has less frequency of a char than that char's freq in s.
		 * To compensate for this difference, the gap in length has to be filled with a new char or existing
		 * other char of s. In either case letters[t[i]] will become less than zero and hence algo will return
		 * correct result.*/
		if(letters[t[i]] < 0)
			return false;
	}
	delete[] letters;
	return true;
}
