//A Child is running up a staircase with n steps and can hop either 1 step, 2 steps, 3 steps at a time
//Implement a method to count how many possible ways the child can run up the stairs.

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

//Bottom Up Approach
unsigned long long getSteps(unsigned long long n) {
	unsigned long long dp_memo [9999];

	dp_memo[1] = 1;
	dp_memo[2] = 2;
	dp_memo[3] = 4;

	for(unsigned long long i = 4; i<= n; i++) {
		dp_memo[i] = dp_memo[i-1] + dp_memo[i-2] + dp_memo[i-3];
	}
	return dp_memo[n];


}

int main() {
	unsigned long long i;
	cin>>i;
	cout<<getSteps(i)<<endl;
}
