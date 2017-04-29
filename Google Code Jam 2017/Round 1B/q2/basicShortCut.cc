#define _CRT_SECURE_NO_DEPRECATE //suppress compilation warnings for VC++

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//Common data types in shortcut form
typedef long long ll; 
typedef vector<int> vi;//vector of ints
typedef pair<int, int> ii; //int int
typedef vector<ii> vii; //vector of pair of int int
typedef set<int> si;
typedef map<string, int> msi; //map from string to int

//Basic forloop, including the starting(a) and ending number(b) using i as the local variable
#define REP(i, a, b) \
	for(int i = int(a); i <= int(b); i++)

//Basic Traverse Vector(c) using it as the pointer
#define TRvi(c, it) \
	for(vi::iterator it = (c).begin(); it != (c).end(); it++)

//Traverse a vector of pairrpair
#define TRvii(c, it) \
	for(vii::iterator it = (c).begin(); it != (c).end(); it++)

//Traverse A map of string to int
#define TRmsi(c, it) \
	for(msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array 

int getFirstGoodHorse(vi horses, int index) {
	int newIndex = index + 2;
	if (newIndex >5) {
		newIndex = newIndex - 6;
	}
	//now since the index is valid, we must check +-1 is not a horse
	for(int i = 0; i <3; i++) {
		if(horses[newIndex] > 0) {
			return newIndex;
		}
		newIndex++;
		if (newIndex >5) {
			newIndex =newIndex - 6;
		}
	}
	return -10;
}

void changeToString(vi combo) {
	TRvi (combo, it) {
		switch(*it) {
			case 0 :
				cout<<"R";
				break;
			case 1 :
				cout<<"O";
				break;
			case 2 :
				cout<<"Y";
				break;
			case 3 :
				cout<<"G";
				break;
			case 4 :
				cout<<"B";
				break;
			case 5 :
				cout<<"V";
				break;
		}
	}
	cout<<endl;
}

int main() {
	long long numCases;
	long long currentCase = 1;
	cin>>numCases;
	while (currentCase <= numCases) {
		int numStalls;
		cin >>numStalls;
		vi fakehorses;
		vi horses;
		REP(i, 1, 6) {
			int j;
			cin>>j;
			horses.push_back(j);
		}
		fakehorses = horses;
		bool ok = false;
		int lastGoodHorse;
		vi combo;
		for(int i = 0; i < 6; i++) {
			ok = true;
			if (horses[i] <= 0) {
				continue;
			}
			lastGoodHorse = i;
			//add to the combo
			combo.push_back(lastGoodHorse);
			//subtract the horse
			horses[lastGoodHorse]--;

			//Now to this for the rest of the horses
			REP(j, 2, numStalls) {
				lastGoodHorse = getFirstGoodHorse(horses, lastGoodHorse);
				if (lastGoodHorse == -10) {
					ok = false;
					break;
				}
				//add to the combo
				combo.push_back(lastGoodHorse);
				//subtract the horse
				horses[lastGoodHorse]--;
			}
			if (ok) {
				break;
			} else {
				vi ne;
				combo = ne;
				horses = fakehorses;
			}

		}
		if (lastGoodHorse != -10) {
			//check if cylic
			if (abs(combo[0]-combo[combo.size()-1]) <= 1  && !(combo[0] == 0 && combo[combo.size()-1] == 5 || combo[0] == 5 && combo[combo.size()-1] == 0 )) {
				cout << "Case #"<<currentCase<<": IMPOSSIBLE"<<endl;
			} else {
				cout << "Case #"<<currentCase<<": ";
				changeToString(combo);
			}
		} else {
			cout << "Case #"<<currentCase<<": IMPOSSIBLE"<<endl;
		}
		currentCase++;
	}
}
