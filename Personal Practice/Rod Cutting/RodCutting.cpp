//Rod Cutting Problem
//Given a rod of length n, and a table of prices pi fpr i = 1..n
//determine the maximum revenue rn obtained by cutting up the rods

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <climits>
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

//Bad for n large
int rodCuttingRecursiveTopDown(int p [], int n) {
	if (n == 0) return 0;
	int q = -1;
	for(int i = 1; i <= n; i++) {
		q = max(q, p[i] + rodCuttingRecursiveTopDown(p, n-i));
	}
	return q;
}

//Uses a tracking array
int memoizedCutRod(int p [], int n, int r[]) {
	if (r[n] >= 0) {
		return r[n];
	}
	int q = 0;
	if (n != 0) {
		q = INT_MIN;
		REP(i,1,n) {
			q = max(q,p[i] + memoizedCutRod(p,n-i,r));
		}
	}
	r[n] = q;
	return q;
}

//BottomUp 
int bottomUpCutRod(int p[], int n) {
	int newArray[n+1];
	newArray[0] = 0;
	REP(j,1,n) {
		q = -1;
		REP(i, 1, j) {
			q = max(q, p[i] + r[j-i] )
		}
		r[j] = q;
	}
	return r[n];
}

int main () {
	int dp_memo[9999];
	memset(dp_memo, -1, 9999 * sizeof(int));
	int numPrices;
	cin>>numPrices;
	for (int i = 1; i <= numPrices; i++) {
		cin>>dp_memo[i];
	}
	// cout<<rodCuttingRecursiveTopDown(dp_memo, numPrices);

	int r[9999];
	memset(r, -1, 9999 * sizeof(int));

	cout<<memoizedCutRod(dp_memo, numPrices, r)<<endl;
}