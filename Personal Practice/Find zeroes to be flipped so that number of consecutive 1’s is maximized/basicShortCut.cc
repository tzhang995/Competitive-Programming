/*

Find zeroes to be flipped so that number of consecutive 1’s is maximized

Given a binary array and an integer m, find the position of zeroes flipping which creates maximum number of consecutive 1s in array.

Examples:

Input:   arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
         m = 2
Output:  5 7
We are allowed to flip maximum 2 zeroes. If we flip
arr[5] and arr[7], we get 8 consecutive 1's which is
maximum possible under given constraints 

Input:   arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
         m = 1
Output:  7
We are allowed to flip maximum 1 zero. If we flip 
arr[7], we get 5 consecutive 1's which is maximum 
possible under given constraints.

Input:   arr[] = {0, 0, 0, 1}
         m = 4
Output:  0 1 2
Since m is more than number of zeroes, we can flip
all zeroes.



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

//first number is the number of bits I can switch
//rest is the bits; 

void numbits(vi num, int m) {
	int wL = 0;
	int wR = 0;
	int bestL =0;
	int bestWindow = 0;
	int zeroCount = 0;
	while(wR < num.size()) {
		if(zeroCount <= m) {
			if(arr[wR] == 0) {
				zeroCount++;
			}
			wR++;
		}
		if(zeroCount > m) {
			if(arr[wL] == 0) {
				zeroCount--;
			}
			wL++;
		}
		// Updqate widest window if this window size is more
        if (wR-wL > bestWindow)
        {
            bestWindow = wR-wL;
            bestL = wL;
        }

	}
	// Print positions of zeroes in the widest window
    for (int i=0; i<bestWindow; i++)
    {
        if (arr[bestL+i] == 0)
           cout << bestL+i << " ";
    }
}


int main() {
	vi bin;
	int m;
	cin>>m;

	int num;
	while(cin>>num) {
		bin.push_back(num);
	}

	numbits(num, m);

}
