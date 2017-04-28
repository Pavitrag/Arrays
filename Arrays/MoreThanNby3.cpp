/*
 * MoreThanNby3.cpp
 *
 *  Created on	:	Jul 5, 2016
 *  Author		:	I309980
 */
// source : http://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
// https://www.interviewbit.com/problems/n3-repeat-number/
/*
 * QUESTION===========
 * You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1
1 occurs 3 times which is more than 5/3 times.
*/
#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include<vector>
#include<iostream>

using namespace std;

struct __Count
{
    int e;
    int c;
    __Count():e(0), c(0){}
};

int repeatedNumber(const vector<int> &A) {
    int k = 3;
	int n = A.size();
    if (k < 2)
       return -1;

    vector<__Count> holder(k-1);

    for (int i = 0; i < n; i++)
    {
        int j;

        for (j=0; j<k-1; j++)
        {
            if (holder[j].e == A[i])
            {
                 holder[j].c += 1;
                 break;
            }
        }

        if (j == k-1)
        {
            int l;

            for (l=0; l<k-1; l++)
            {
                if (holder[l].c == 0)
                {
                    holder[l].e = A[i];
                    holder[l].c = 1;
                    break;
                }
            }
            if (l == k-1)
                for (l=0; l<k; l++)
                    holder[l].c -= 1;
        }
    }

    for (int i=0; i<k-1; i++)
    {
        int ac = 0;
        for (int j=0; j<n; j++)
            if (A[j] == holder[i].e)
                ac++;

        if (ac > n/k)
           return holder[i].e;
    }
	return -1;
}
