/*
 * PalindromePermutation.cpp
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

#include<iostream>
#include<string>

using namespace std;

/*BOOK: Cracking the coding interview; Ed. 6th
 * QUESTION : 1.4 Chapter 1 - Arrays & Strings
 */
/*Given a string, check if its a palindrome permutation of itself*/
//Naive method:

bool palinPerm(string str){
	int count[128]{0,}; //ascii char set.
	for(int i =0; i<str.length(); i++){
		if(str[i] != 0)	count[str[i]]++;
	}
	int howmany=0;
	for(int i =0; i<128; i++){
		if(count[i]%2 == 1)
			howmany++;
		if(howmany > 1)	return false;
	}
	return true;
}

void toggleBit(int &n, int index){
	n = (n ^ (1 << index));
}
//Case insensitive and non-alphabet chars are ignored.
bool isPalindromePermutation(string s) {
	int counter = 0; //assuming 4 byte integer, gives 32 bits with each bit position represent character as index.
	//implies => 'a' -> 0, z -> '25'
	for (int i = 0; i < s.length(); i++) {
		if('a'<=s[i] && 'z' >= s[i])
			toggleBit(counter, s[i]-'a');
	}
	if((counter & (counter-1)) != 0)
		return false;
	return true;
}

void palindromePermutationDriver(){
	string s = "taco cat";
	cout << "\"" << s.c_str() << "\" is " << (isPalindromePermutation(s) ? "palindrome" : "not palindrome") << endl;
	string ss = "taco o cat";
	cout << "\"" << ss.c_str() << "\" is " << (isPalindromePermutation(ss) ? "palindrome" : "not palindrome") << endl;
	string s2 = "Pav i t r a";
	cout << "\"" << s2.c_str() << "\" is " << (isPalindromePermutation(s2) ? "palindrome" : "not palindrome") << endl;
}
