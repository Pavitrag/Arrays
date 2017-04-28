/*
 * HotelBookingsPossible.cpp
 *
 *  Created on	:	Jul 7, 2016
 *  Author		:	Pavi
 *
 *  source : https://www.interviewbit.com/problems/hotel-bookings-possible/
 *  Hotel Bookings Possible:
 *  A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking.
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input :
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0

At day = 5, there are 2 guests in the hotel. But I have only one room.
 */

#include "Utils.h"
#include "Grid.h"
using namespace Utils;
using namespace com_pavitra_learning;

#include<vector>
#include<algorithm>
#include<sstream>
#include<cstdio>
using namespace std;
#if 0 //Approach # 1.
struct Booking{
  int arrive;
  int depart;
  int index;
  Booking(int a, int d, int idx): arrive(a), depart(d), index(idx){}
  string display();
};

string Booking::display(){
	stringstream s;
	s << index << " = (" << arrive << ", " << depart << ")" ;
	return s.str();
}

void printBookings(vector<Booking>& v){
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].display() << "; " ; //endl;
		//cout << v[i].index << "= (" << v[i].arrive << ", " << v[i].depart << ")" << endl;
	}
	cout << endl;
	//std::flush(cout);
}
bool bookings_compare(Booking f, Booking s){
    if(f.depart < s.depart)
        return true;
    else if((f.depart == s.depart)&&(f.arrive < s.arrive))
    	return true;
    return false;
}

bool bookings_compare_start(Booking f, Booking s){
	if(f.arrive < s.arrive)
		return true;
	 else if((f.arrive == s.arrive)&&(f.depart < s.depart))
		 return true;
	return false;

}
bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<Booking> bookings;
	if (K > depart.size())
		return true;
    for(int i =0; i< depart.size(); i++){
		int s = (arrive[i] < depart[i] ? arrive[i] : depart[i]);
		int b = (arrive[i] > depart[i] ? arrive[i] : depart[i]);
		bookings.push_back(Booking(s, b, i));
    }
    sort(bookings.begin(), bookings.end(), bookings_compare_start);
    printBookings(bookings);
    vector<int> occupied(1, bookings[0].depart);
    for(int i = 1; i<bookings.size(); i++){
    	bool alloted = false;
    	for(int j = 0; j<occupied.size(); j++){
			if (bookings[i].arrive >= occupied[j]) {
				occupied[j] = bookings[i].depart;
				alloted = true;
				break;
			}
    	}
    	if(!alloted)
    		occupied.push_back(bookings[i].depart);
    	cout << occupied.size() << endl;
    	if(occupied.size() > K)
    		return false;
    }
    return true;
}

void hotelBookingsPossibleDriver() {
	int Arrivals[] = { 1, 3, 5 };
	int Departures[] = { 2, 6, 8 };
	int K = 1;
	vector<int> arrive(Arrivals, Arrivals + 3);
	vector<int> depart(Departures, Departures + 3);
	cout << "Hotel Bookings Possible : " << hotel(arrive, depart, K) << endl;
	cout << "--------------------------------------" << endl;

	int Arrivals1[] =   {  9, 47, 17, 39, 35, 35, 20, 18, 15, 34, 11,  2, 45, 46, 15, 33, 47, 47, 10, 11, 27 };
	int Departures1[] = { 32, 82, 39, 86, 81, 58, 64, 53, 40, 76, 40, 46, 63, 88, 56, 52, 50, 72, 22, 19, 38 };
	int K1 = 16;
	vector<int> arrive1(Arrivals1, Arrivals1 + 21);
	vector<int> depart1(Departures1, Departures1 + 21);
	cout << "Hotel Bookings Possible : " << hotel(arrive1, depart1, K1) << endl;
	cout << "--------------------------------------" << endl;

	int Arrivals2[] = { 1, 3, 4 };
	int Departures2[] = { 12, 8, 6 };
	int K2 = 2;
	vector<int> arrive2(Arrivals2, Arrivals2 + 3);
	vector<int> depart2(Departures2, Departures2 + 3);
	cout << "Hotel Bookings Possible : " << hotel(arrive2, depart2, K2) << endl;
	cout << "--------------------------------------" << endl;

	int Arrivals3[] = {   41, 10, 12, 30,  0, 17, 38, 36, 45,  2, 33, 36, 39, 25, 22,  5, 41, 24, 12, 33, 19, 30, 25, 12, 36,  8  };
	int Departures3[] = { 47, 20, 15, 65, 35, 51, 38, 36, 94, 30, 50, 38, 67, 64, 67, 24, 62, 38, 18, 59, 20, 74, 33, 43, 56, 32  };
	int K3 = 12;
	vector<int> arrive3(Arrivals3, Arrivals3 + 26);
	vector<int> depart3(Departures3, Departures3 + 26);
	printVector(arrive.begin(), arrive.end());
	printVector(depart.begin(), depart.end());
	cout << "Hotel Bookings Possible : " << hotel(arrive3, depart3, K3) << endl;
	cout << "--------------------------------------" << endl;

	int Arrivals4[] = { 40, 18 };
	int Departures4[] = { 40, 43 };
	int K4 = 1;
	vector<int> arrive4(Arrivals4, Arrivals4 + 2);
	vector<int> depart4(Departures4, Departures4 + 2);
	cout << "Hotel Bookings Possible : " << hotel(arrive4, depart4, K4) << endl;
	cout << "--------------------------------------" << endl;

}
#endif

//Approach # 2. //inteviewBit Solution approach
/*
1. Create event points for every interval start, and end.
2. Sort it according to the day.
3. Now, iterate over them one by one. If you encounter a start, then the number of active guests increase by one. If you encounter an end, the number of active guests decrease by one.
4. If at any point, the number of active guests exceed K, we know that scheduling is not possible.

GOTCHAS : What if there are multiple start and end on the same day ? How should they be ordered ?*/

class Event{
public:
	int event;
	int arrive;
	Event(int e, int a):event(e), arrive(a){};
};
bool event_compare(Event a, Event b){
	if(a.event < b.event)
		return true;
	return false;
}

bool hotel(vector<int> &arrive, vector<int> &depart, int K){
#if 0
	vector<Event> events;
	if (K > depart.size())
		return true;
	for (int i = 0; i < depart.size(); i++) {
		events.push_back(Event(arrive[i], 1));
		events.push_back(Event(depart[i], -1));
	}
	sort(events.begin(), events.end(), event_compare);
	int count = 0;
	for(int i = 0; i<events.size(); i++){
		count += events[i].arrive;
		if(count > K)
			return false;
	}
	return true;
#endif
	//------Interview bit solution-----but there is a flaw:
/*	As pointed out in previous comments output for input:
A : [ 40, 18 ]
B : [ 40, 43 ]
C : 1
is 0 (allocation not possible) but your expected output shows 1 (allocation possible).
Your expected output of 1 is wrong output whereas 0 is correct. As you can clearly see that first person arrives on 18th and departs on 43 and stays resident at the only available room. Now when second person comes on 40th day there is no room available as first person is staying there till 43rd, which implies no allocation of room possible.

Now I think your expected output of 1 is shown as 1 because there is a flaw in your sorting algorithm based on events. Here's my guess.
Your sorting algorithm is sorting events as follows:

#1. [18, 1] -> arrival
#2. [40, 0] -> departure
#3. [40, 1] -> arrival
#4. [43, 0] -> departure
What your sorting algo. is doing is that its sorts events based on second value whenever the events have same first value , as is the case above at #2. and #3.
In fact sorting algo is doing it right because its sorting based on lexicographical second value (0 comes before 1) when first values are same.

The impact of this sorting algo is that departure will be placed before arrival. Its like departing before you have even arrived. Therefore, the output shows as allocation possible, which is 1.

Please correct the above mistake in the expected output and also your internal evaluation algorithm.

Thanks & Regards,
~ Pavi.8081*/
	if (K == 0)
		return false;

	int N = arrive.size();

	vector<pair<int, int> > vec;
	for (int i = 0; i < N; ++i) {
		vec.push_back(make_pair(arrive[i], 1));
		vec.push_back(make_pair(depart[i], 0));
	}

	sort(vec.begin(), vec.end());

	int curActive = 0;
	int maxAns = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].second == 1) { // arrival
			curActive++;
			maxAns = max(maxAns, curActive);
		} else {
			curActive--;
		}
	}

	if (K >= maxAns)
		return true;
	return false;
	//--------------------------------------------------------
}


void hotelBookingsPossibleDriver() {
	int Arrivals[] = { 1, 3, 5 };
	int Departures[] = { 2, 6, 8 };
	int K = 1;
	vector<int> arrive(Arrivals, Arrivals + 3);
	vector<int> depart(Departures, Departures + 3);
	cout << "Hotel Bookings Possible : " << hotel(arrive, depart, K) << endl;
	cout << "--------------------------------------" << endl;

	int Arrivals1[] =   {  9, 47, 17, 39, 35, 35, 20, 18, 15, 34, 11,  2, 45, 46, 15, 33, 47, 47, 10, 11, 27 };
	int Departures1[] = { 32, 82, 39, 86, 81, 58, 64, 53, 40, 76, 40, 46, 63, 88, 56, 52, 50, 72, 22, 19, 38 };
	int K1 = 16;
	vector<int> arrive1(Arrivals1, Arrivals1 + 21);
	vector<int> depart1(Departures1, Departures1 + 21);
	cout << "Hotel Bookings Possible : " << hotel(arrive1, depart1, K1) << endl;
	cout << "--------------------------------------" << endl;

	int Arrivals2[] = { 1, 3, 4 };
	int Departures2[] = { 12, 8, 6 };
	int K2 = 2;
	vector<int> arrive2(Arrivals2, Arrivals2 + 3);
	vector<int> depart2(Departures2, Departures2 + 3);
	cout << "Hotel Bookings Possible : " << hotel(arrive2, depart2, K2) << endl;
	cout << "--------------------------------------" << endl;

	int Arrivals3[] = {   41, 10, 12, 30,  0, 17, 38, 36, 45,  2, 33, 36, 39, 25, 22,  5, 41, 24, 12, 33, 19, 30, 25, 12, 36,  8  };
	int Departures3[] = { 47, 20, 15, 65, 35, 51, 38, 36, 94, 30, 50, 38, 67, 64, 67, 24, 62, 38, 18, 59, 20, 74, 33, 43, 56, 32  };
	int K3 = 12;
	vector<int> arrive3(Arrivals3, Arrivals3 + 26);
	vector<int> depart3(Departures3, Departures3 + 26);
	printVector(arrive.begin(), arrive.end());
	printVector(depart.begin(), depart.end());
	cout << "Hotel Bookings Possible : " << hotel(arrive3, depart3, K3) << endl;
	cout << "--------------------------------------" << endl;

	int Arrivals4[] = { 40, 18 };
	int Departures4[] = { 40, 43 };
	int K4 = 1;
	vector<int> arrive4(Arrivals4, Arrivals4 + 2);
	vector<int> depart4(Departures4, Departures4 + 2);
	cout << "Hotel Bookings Possible : " << hotel(arrive4, depart4, K4) << endl;
	cout << "--------------------------------------" << endl;

}
