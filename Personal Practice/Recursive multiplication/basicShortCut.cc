/*
Multiply 2 positive integers without using * or / operators
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

int multiply(int a, int b, int  tempMultply[]){
	if(a == 0) {
		return 0;
	}
	if(a ==1) {
		return b;
	}
	if(tempMultply[a] >=0) {
		return tempMultply[a];
	}

	int s = a >> 1;
	int side1 = multiply(s,b,tempMultply);
	int side2 = side1;
	if(a %2 == 1) {
		side2 = multiply(a-s, b, tempMultply);
	}

	tempMultply[a] = side1+side2;
	return tempMultply[a];

}

int multiply(int a, int b) {
	int bigger = a > b? a:b;
	int smaller = a > b ? b : a;

	int dp_memo [9999];
	memset(dp_memo,-1,sizeof(int) * 9999);

	return multiply(smaller, bigger, dp_memo);
}

int main() {
	int a;
	int b;
	cin>>a>>b;
	cout<<multiply(a,b)<<endl;
}
