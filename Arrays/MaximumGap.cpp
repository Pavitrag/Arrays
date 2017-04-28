/*
 * MaximumGap.cpp
 *
 *  Created on	:	Jul 6, 2016
 *  Author		:	I309980
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

class MaximumGap{
public:
	static int min(int x, int y);
	static int max(int x, int y);
	static int maximumGap(const vector<int> &A);
};

int MaximumGap::min(int x, int y) {
	return (((x)<=(y)) ? (x) : (y));
}
int MaximumGap::max(int x, int y){
	return (((x)>=(y)) ? (x) : (y));

}
int MaximumGap::maximumGap(const vector<int> &A) {
    int mx=0;
    vector<int> lmin(A.size());
    vector<int> rmax(A.size());
    lmin[0] = A[0];
    rmax[A.size()-1] = A[A.size()-1];
    for(int i =1; i<A.size(); i++)
        lmin[i] = min(lmin[i-1], A[i]);

    for(int i =A.size()-2; i>=0; i--)
        rmax[i] = max(rmax[i+1], A[i]);

    for(int i =0, j=0; i<A.size() && j<A.size(); ){
        if(lmin[i] <= rmax[j]){
            mx = max(mx, j-i);
            j++;
        }
        else
            i++;
    }
    return mx;
}
