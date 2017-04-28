/*
 * NextSmallestPalindrome.cpp
 *
 *  Created on	:	Apr 25, 2016
 *  Author		:	I309980
 */
// Source 1: http://www.algorithmist.com/index.php/SPOJ_PALIN
//source 2 : http://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/


#include<vector>
#include"Utils.h"

using namespace Utils;

using namespace std;
//#define TESTING;

bool areAllNines(vector<int> number){
	for(vector<int>::iterator it = number.begin(); it != number.end(); it++){
		if(*it != 9)
			return false;
	}
	return true;
}

vector<int>& handleAll9s(vector<int>& number){
	number.insert(number.begin(), 1);
	for (vector<int>::iterator it = number.begin()+1; it != number.end() - 1; it++)
		*it = 0;
	number[number.size() - 1] = 1;
	//vector<int> *newNumber = new vector<int>(number.begin(), number.end());
	//printVector(newNumber->begin(), newNumber->end());
	return number;
}
void generateNextLargerPalindrome(vector<int>& number, int pos1, int pos2) {
	if (pos1 < 0) {
		number.insert(number.begin(), 1);
		number[number.size() - 1] = 1;
		return;
	}
	if (number[pos1] < 9) {
		number[pos1] = number[pos2] = number[pos1] + 1;
		return;
	} else {
		number[pos1] = number[pos2] = 0;
		generateNextLargerPalindrome(number, --pos1, ++pos2);
		return;
	}
}

void copyFirstHalfToSecondHalf(vector<int>& number){
	for(int i = 0; i < number.size()-1-i; i++)
		number[number.size()-1-i] = number[i];
}

int comp(vector<int>& first, vector<int>& second){
	if(first.size() != second.size())
		return first.size() - second.size();
	else{
		for(size_t i = 0; i < first.size(); i++)
			if(first[i] != second[i])
				return first[i] - second[i];
	}
	return 0;
}
/*Alog Strategy - Recursive:
 * 1. Copy the original number
 * 2. handle case if all are 9's => increase vector size by 1 and make boundaries 1 and all between as 0's & return
 * 3. Else, copy first half to second half.
 * 4. Check if this number is greater than original number. If true, we have our next smallest palindrome larger
 * 		than original and we can return
 * 5. Else, make the vector palindrome starting with middle digits:
 * 		5.1. If we have reached boundary positions (pos < 0) then increment vector size by 1 in the front.
 * 				make first and last digit as 1 and return.
 * 		5.2. If numbers at positions are less than 9 then increment them both and return.
 * 		5.3. else if they are equal to 9 (cant be greater because each vector entry contains single digit number)
 * 				then set digits at those positions as 0 and recurse with --pos1 and ++pos2. END!
 * */
vector<int>& nextSmallestPalindromeMain(vector<int>& number) {
	vector<int> orig(number.begin(), number.end());
#ifdef TESTING
	printVector(orig.begin(), orig.end());
#endif
	bool all9s = areAllNines(number);
	if (all9s) {
		return handleAll9s(number);
	}
	copyFirstHalfToSecondHalf(number);
#ifdef TESTING
	printVector(number.begin(), number.end());
#endif
	int compare = comp(orig, number);
	if(compare < 0) return number; //second number, i.e., "number" is not equal (greater, infact) to "orig".
	//which implies that copying first half of original to IInd half actually makes larger palindrome,
	//so we can return "number" as next smallest palindrome larger than "orig" without doing further processing.

	int mid1 = -1, mid2 = -1;
	if (number.size() % 2 == 0) {
		mid2 = number.size() / 2;
		mid1 = mid2 - 1; // not valid in case of total odd elements.
	} else {
		mid1 = mid2 = number.size() / 2;
	}

	generateNextLargerPalindrome(number, mid1, mid2);
#ifdef TESTING
	printVector(number.begin(), number.end());
#endif
	return number;
}

void nextSmallestPalindromicNumberDriver(){
	cout << "Next smallest palindromic number larger than given number" <<endl;
	cout << "Test case # 1" << endl;
	int palin_arr[] = { 1, 2, 3, 4 };
	vector<int> palin_v(palin_arr, palin_arr + 4);
	cout << "next smallest palindromic number larger than : ";
	printVector(palin_v.begin(), palin_v.end());
	cout << " is : ";
	vector<int> &p = nextSmallestPalindromeMain(palin_v);
	printVector(p.begin(), p.end());

	cout << "===Test case # 2" << endl;
	int palin_arr1[] = { 0 };
	vector<int> palin_v1(palin_arr1, palin_arr1 + 1);
	cout << "next smallest palindromic number larger than : ";
	printVector(palin_v1.begin(), palin_v1.end());
	cout << " is : ";
	p = nextSmallestPalindromeMain(palin_v1);
	printVector(p.begin(), p.end());

	cout << "===Test case # 3" << endl;
	int palin_arr2[] = { 1, 9, 9, 1 };
	vector<int> palin_v2(palin_arr2, palin_arr2 + 4);
	cout << "next smallest palindromic number larger than : ";
	printVector(palin_v2.begin(), palin_v2.end());
	cout << " is : ";
	p = nextSmallestPalindromeMain(palin_v2);
	printVector(p.begin(), p.end());

	cout << "===Test case # 4" << endl;
	int palin_arr3[] = { 9 };
	vector<int> palin_v3(palin_arr3, palin_arr3 + 1);
	cout << "next smallest palindromic number larger than : ";
	printVector(palin_v3.begin(), palin_v3.end());
	cout << " is : ";
	p = nextSmallestPalindromeMain(palin_v3);
	printVector(p.begin(), p.end());

	cout << "Test case # 5" << endl;
	int palin_arr4[] = { 9, 9, 9, 9, 8 };
	vector<int> palin_v4(palin_arr4, palin_arr4 + 5);
	cout << "next smallest palindromic number larger than : ";
	printVector(palin_v4.begin(), palin_v4.end());
	cout << " is : ";
	p = nextSmallestPalindromeMain(palin_v4);
	printVector(p.begin(), p.end());
}
