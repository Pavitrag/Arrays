/*
 * Anagram.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: I309980
 */
//#include <ostream>
#include<algorithm>
#include<iostream>

using namespace std;
/*
using std::endl;
using std::string;
using std::cout;
*/


class Solution {
public:
    static bool isAnagram(string s, string t) {
        bool c[26] = {false,};

        for(auto is : s){
        //for(int i = 0; i< s.length(); i++){
            c[is/*s[i]*/-'A'] = true;
        }

        for(int i = 0; i< t.length(); i++){
            if(c[t[i]-'A'] == false)
                return false;
        }
        return true;
    }
};

int mainAnagram(){
	bool veal = Solution::isAnagram("abcdef", "fbcdeA");
	//cout << veal << endl;
	return 0;

}
