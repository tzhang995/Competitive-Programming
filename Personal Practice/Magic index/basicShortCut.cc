/*
A magic index in an array A[1...n-1] is define ti be an index such that A[i] = i
Given a sorted of distinct integers, write a method to find a magic index
if one exist in array A

Follow up: again but the integers are not distinct
*/

#define _CRT_SECURE_NO_DEPRECATE //suppress compilation warnings for VC++

#include <bits/stdc++.h>
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

int magicIndex(vi myvec,int start, int end){
	if(end < start) {
		return -1;
	}

	int midIndex = (start + end) /2;
	int midValue = myvec[midIndex];
	if (midValue == midIndex) {
		return midValue;
	}

	//searchleft
	int leftIndex = min(midIndex-1, midValue);
	int left = magicIndex(myvec, start, leftIndex);
	if(left >=0) {
		return left;
	}

	int rightIndex = max(midIndex+1, midValue);
	return magicIndex(myvec, rightIndex, end);
}

int main() {
	vi myvec;
	int i;
	while(cin>>i){
		myvec.push_back(i);
	}
	cout<<magicIndex(myvec,0,myvec.size()-1)<<endl;
}
