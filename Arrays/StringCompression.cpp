/*
 * StringCompression.cpp
 *
 *  Created on	:	Jun 26, 2016
 *  Author		:	Pavi
 */
/*
 * Book: Cracking the coding interview - 6th Ed.
	Chapter # 1 - Arrays and Strings
	QUESTION: 1.6
	Implement a method to perform basic string compression using the counts of repeated characters.
	ex - aabcccccaaa would become a2b1c5a3.
	If "compressed" string would not become smaller than the original string, your method should return the
	original string. You can assume the string has only uppercase and lowercase letters (a - z)*/
#if 0
	#include "Utils.h"
	#include "Grid.h"
	using namespace Utils;
	using namespace com_pavitra_learning;
#endif
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#if 0 //initial try. But wrong logic : when count of a char is two or 3 digits long, then this code fails.
//Run length encoding ?
string* compressed(string& s){
	string *news = new string();
	int j=0; //j indexes news
	int count = 1; //for s[0]
	news->append(&s[0], 1);
	for(int i =0; i< s.length(); i++){
		if((i+1 < s.length()) && (s[i] == s[i+1])){
			count++;
		}
		else /*if((i+1 < s.length()) && (s[i+1] != s[i]))*/{
			if(count > 0){
				char c = count+'0';
				news->append(&c, 1);
				if(i+1 < s.length())
					news->append(&s[i+1], 1);
			}
			count=1;//reset count for next char.
		}
	}
	if((*news).length() >= s.length()){
		delete news;
		return &s;
	}
	return news;
}
#endif
int countIntChars(int l){
	int ret=0;
	while(l != 0){
		ret++;
		l=l/10;
	}
	return ret;
}
int countCompressed(string& s) {
	//finding length of compressed String. If its greater than str length then we dont
	//return new compressed string but return the original string.
	int countCompressedStrLen = 0;
	int currentLength = 0;
	for (int i = 0; i < s.length(); i++) {
		currentLength++;
		if ((i + 1 >= s.length()) || (s[i] != s[i + 1])) {
			countCompressedStrLen += 1 + countIntChars(currentLength);
			currentLength = 0;
		}
	}
	return countCompressedStrLen;
}
string* compressBad(string& s){
	int compressedLen = countCompressed(s);
	if (compressedLen >= s.length())
		return &s;
	string* news  = new string();//(compressedLen);
	int count=0, j=0;
	for (int i = 0; i < s.length(); i++) {
		count++;
		if ((i + 1 >= s.length()) || (s[i] != s[i + 1])) {
			news->append(&s[i], 1);
			stringstream ss;
			ss << count;
			news->append(ss.str());
			count = 0;
		}
	}
	return news;
}

void compressedDriver(){
	string s("aabcccccccccccccccccccccccccccccccccccccccccccccaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	string *ret = NULL;
	/*ret = compressed(s);
	cout << (*ret).c_str() << endl;*/
	ret = compressBad(s);
	cout << (*ret).c_str() << endl;
	cout << "______________" << endl;
	string s1("aabcc");
	/*ret = compressed(s1);
	cout << (*ret).c_str() << endl;*/
	ret = compressBad(s1);
	cout << (*ret).c_str() << endl;
	cout << "______________" << endl;

}
