/*
Robot in a Grid:
Imagine a robot sitting on the upper left corner of grid with r rows and c columns
The robot can only move in two directions, right and down, but certain cells are off limits
such as the robot cannot step on them.
Design an algorithm to find a path for the robot from the top left to the bottom right.


input, number of rows, number of columns
grid where 1 is the allowed path and 0 is the not allowed path

output: a series of points where 00 is the top left of the grid 
and rowcol is the bottom right of the grid

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

int main() {
	int row; int col;
	cin>>row>>col;
	vector<vi> grid;
	string s;
	while(getline(cin,s)) {
		vi currentRow;
		REP(i, 0, s.size()-1) {
			currentRow.push_back(s.at(i));
		}
		grid.push_back(currentRow);
	}
}
