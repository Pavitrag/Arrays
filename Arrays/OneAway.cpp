/* * OneAway.cpp
 *
 *  Created on	:	Jun 25, 2016
 *  Author		:	Pavi
 *
 *
	Book: Cracking the coding interview - 6th Ed.
	Chapter # 1
	QUESTION: 1.5
	There are 3 types of edits that can be performed on strings :
	insert a character, remove a character, replace a character.
	Given 2 strings, write a function to check if they are one edit (or zero edit) away
	EXAMPLE:
	pale, ple 	-> true
	pales, pale -> true
	pale, bale 	-> true
	pale, bake 	-> false
	*/
#include<iostream>
#include<string>

using namespace std;

bool oneAway(string s, string t) {
	const string &first = (s.length() > t.length() ? s : t);
	const string &second = (s.length() < t.length() ? s : t);
	bool foundDiff = 0;
	int indexf = 0, indexs = 0;
	if (first.length() - second.length() > 1)
		return false;
	while (indexs < second.length()) {
		if (first[indexf] != second[indexs]) {
			if (true == foundDiff)
				return false;
			foundDiff = true;
			if (first.length() == second.length())
				indexs++;
		} else{
			indexs++;
		}
		indexf++;
	}
	return true;
}
