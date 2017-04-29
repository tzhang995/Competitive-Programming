#define _CRT_SECURE_NO_DEPRECATE //suppress compilation warnings for VC++

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
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

//return the cost of the cycle
ll getCycle(map<ll,ll> & array, ll n) {
	if (array[n] > 0) {
		return array[n];
	}
	ll m;
	if (n % 2 == 0) {
		m = n / 2;
	} else {
		m = 3 * n + 1;
	}
	array[n] = 1 + getCycle (array, m);
	return array[n];
}

 int main() {
// 	ll dp_memo[10000000];
// 	memset(dp_memo, -1, 10000000 * sizeof(ll));
	map<ll,ll> dp_memo;
	dp_memo[1] = 1;
	ll i;
	ll j;
	while (cin>>i>>j) {
		cout << i << " " << j << " ";
		ll q = -1;
		if (i < j) {
			for(ll a= i; a<=j ; a++) {
				q = max(getCycle(dp_memo, a), q);
			}
		} else {
			for(ll a= j; a<=i ; a++) {
				q = max(getCycle(dp_memo, a), q);
			}
		}
		cout<<q<<endl;
	}
	return 0;
}
