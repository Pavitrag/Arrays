//PROBLEM : Sort an array of 0s, 1s and 2s
/*http://www.practice.geeksforgeeks.org/problem-page.php?pid=341*/
// URL: http://code.geeksforgeeks.org/gKEI7U
#include <iostream>
#include <vector>
using namespace std;

void mySwap(vector<int> &v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void sortZOT(vector<int>& v){
    int l=0;
    int m = 0;
    int h = v.size()-1;
    while(m <= h){
        if(v[m] == 0){
            mySwap(v, m, l);
            m++, l++;
        }
        else if(v[m] == 1) m++;
        else{
            mySwap(v, m, h);
            h--;
        }
    }
}
int dutchNationalFlagDriver() {
	int T;
	int t=0, sz;
	cin >> T;
	while(t++ < T){
	    cin >> sz;
	    int val;
	    vector<int> v;
	    for(int i = 0; i< sz; i++){
	        cin >> val;
	        v.push_back(val);
	    }
	    sortZOT(v);
	    for(int i = 0; i< sz; i++){
	        cout << v[i] << " ";
	    }
	    cout << endl;
	    
	}
	return 0;
}
