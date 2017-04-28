/*
 * PowerOf2.cpp
 *
 *  Created on	:	Jul 7, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int e){
    if(e == 2) return true;
    if(e%2 == 0) return false;
    if(e == 1) return false;
    int ul = (int)sqrt(e);
    for(int i = 3; i<=ul; i+=2)
        if(e%i == 0)
            return false;
    return true;
}
vector<int> primeFactors(int n){
    vector<int> v;
    if(n == 2){
        v.push_back(n);
        return v;
    }
    for(int i = 2; i<=sqrt(n); i++){
        if(isPrime(i) && (n%i == 0))
            v.push_back(i);
    }
}
bool isPower(int n) {
	if (n == 2)
		return false;
	if (n == 1)
		return true;
	vector<int> v = primeFactors(n);
	int prod = 0;
	for (int i = 0; i < v.size(); i++) {
		while (n % v[i] == 0){
			n = n / v[i];
			prod++;
		}
		if(prod == 1)
			return false;
		prod = 0;
	}
	if (n == 1)
		return true;
	return false;
}

void isPowerDriver(){
	//long n = 1024000000;
	long n = 75250;
	cout << isPower(n) << endl;
}
