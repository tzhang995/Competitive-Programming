//This program produces the fib number where f(0) = 0 and f(1) = 1

#define _CRT_SECURE_NO_DEPRECATE //suppress compilation warnings for VC++roduci

//#include <bits/stdc++.h>
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


//Really slow, do not recommend
long long getFibNumberNoDP(long long n){
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return getFibNumberNoDP(n-1) + getFibNumberNoDP(n-2);
}


//TOp down Approach
unsigned long long getFibNumberDP(unsigned long long dpMemo[], unsigned long long n){
	if (dpMemo[n] != -1) {
		return dpMemo[n];
	}
	unsigned long long returnNum;
	if (n == 0){
		returnNum = 0;
	}else if (n == 1) {
		returnNum = 1;
	} else {
		returnNum = getFibNumberDP(dpMemo, n-1) + getFibNumberDP(dpMemo, n-2);
	}
	dpMemo[n] = returnNum;
	return returnNum;
}

///Bottom Up Approach
unsigned long long getFibNumberDPBottomUp(unsigned long long dpMemo[], unsigned long long n){
	dpMemo[0] = 0;
	dpMemo[1] = 1;

	for(unsigned long long i = 2; i <= n; i++) {
		dpMemo[i] = dpMemo[i-1] + dpMemo[i-2];
	}
	return dpMemo[n];
}

int main() {
	unsigned long long number;
	unsigned long long dpMemo[9999];
	memset(dpMemo, -1, sizeof(unsigned long long) * 9999);

	unsigned long long dpMemo2[9999];
	memset(dpMemo2, -1, sizeof(unsigned long long) * 9999);

	cin >> number;
	cout<< getFibNumberDP(dpMemo, number)<<endl;
	cout<<getFibNumberDPBottomUp(dpMemo2, number)<<endl;
}
