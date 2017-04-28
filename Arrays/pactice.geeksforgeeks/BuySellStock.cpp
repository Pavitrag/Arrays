/*
 * BuySellStock.cpp
 *
 *  Created on	:	Apr 25, 2017
 *  Author		:	i309980
 * 
 *  === SOURCE === 
 *
 *  === QUESTION ===
 *
 *
 *	=== SOLUTION APPROACH ===
 */

#include "Utils.h"
#include "Grid.h"
#include<vector>

using namespace std;
using namespace Utils;
using namespace com_pavitra_learning;


class Interval{
public:
	int buy;
	int sell;
	Interval():buy(0), sell(0){}
	Interval(int b, int s):buy(b), sell(s){}
};
void buySellStock(vector<int> prices){

	int n = prices.size();
	if(n == 1)
		return;
	int count=0;

	int i = 0;
	while(i < n){

		//finding local minima
		while((i < n) && (prices[i] > prices[i+1]))
			i++;

		if(i == n) //no local minima.
			break;

		Interval stock;
		stock.buy = prices[i];

		//finding local maxima
		while((i < n) && (prices[i] < prices[i+1]))
			i++;


	}
}
