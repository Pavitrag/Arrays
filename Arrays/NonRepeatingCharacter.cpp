/*
 * NonRepeatingCharacter.cpp
 *
 *  Created on	:	Jun 28, 2016
 *  Author		:	I309980
 *  QUESTION:
 *  Given a string s consisting of lowercase Latin Letters, find the first non repeating character in s.

Input:

The first line contains T denoting the number of testcases. Then follows description of testcases.
Each case begins with a single integer N denoting the length of string. The next line contains the string s.

Output:


 For each testcase, print the first non repeating character present in string.

 Print -1 if there is no non repeating character.

Constraints:


 1<=T<=30
 1<=N<=100


Example:


Input :

3
5
hello
12
zxvczbtxyzvy
6
xxyyzz



Output :

h
c
-1

**For More Examples Use Expected Output**
 */
#if 0
	#include "Utils.h"
	#include "Grid.h"
	using namespace Utils;
	using namespace com_pavitra_learning;
#endif
#include <iostream>
#include<string>
#include<climits>
using namespace std;

class CountIndex {
public:
	CountIndex():index(-1), count(0){}
	int index;
	int count;
};
int nonRepeatingChar(string s) {
	CountIndex ci[26];
	for (int i = 0; i < s.length(); i++) {
		if (ci[s[i] - 'a'].count == 0)
			ci[s[i] - 'a'].index = i;
		ci[s[i] - 'a'].count++;
	}
	int gindex = INT_MAX;
	for (int i = 0; i < 26; i++) {
		if (ci[i].count == 1) {
			if (gindex > ci[i].index)
				gindex = ci[i].index;
		}
	}
	if (gindex == INT_MAX)
		return -1;
	return s[gindex];
}
int nonRepeatingCharDriver() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int len;
		cin >> len;
		string s;
		cin >> len >> s;
		char ch = nonRepeatingChar(s);
		if ((int) ch != -1)
			cout << ch << endl;
		else
			cout << -1 << endl;
	}/*
	string s = "zxvczbtxyzvy";
	char ch = nonRepeatingChar(s);
	if((int)ch != -1)
		cout <<  ch << endl;
	else
		cout <<  -1 << endl;*/
	return 0;
}
