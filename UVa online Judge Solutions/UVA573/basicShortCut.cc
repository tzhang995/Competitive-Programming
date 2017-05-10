#define _CRT_SECURE_NO_DEPRECATE //suppress compilation warnings for VC++

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
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

int main() {
	long double H,U,D,F;
	cin >>H>>U>>D>>F;
	while (!(H==0 &&U==0 &&D==0 && F==0)) {
		long long day = 1;
		long double initH = 0;
		F = U * (F/100);
		while (initH >= 0) {
			initH = initH + U;
			cout<<initH<<endl;
			if (initH > H) {
				cout<< "success on day "<<day<<endl;
				break;
			}
			U = U -F;
			initH = initH - D;
			day++;
		}
		if (initH <=0) {
			cout<<"failure on day "<<day-1<<endl;
		}
		cin >>H>>U>>D>>F;
	}
}
