//We are given 2 sequences ie (x = (x1,x2,x3,x4...xm), y = (y1,y2,y3,y4...yn))
//Find the largest subsequence (z = (z1,z2,z3,z4...zk)) where there is an strict increasing
//sequence for both x and y
//Example:
//  x = (A,B,C,B,D,A,B)
//  y = (B,D,C,A,B,A)
//  z = (B,C,B,A)
//  Note: A = (B,C,A) is also a common subsequence but it is not the longest

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

struct TableCell {
	int val;
	string direction; //up left diagonal
};

//Calculate the LCS length 
TableCell ** LCS_Length(string x, string y) {
	int m = x.size();
	int n = y.size();
	TableCell ** c = new TableCell*[m+1];
	for (int i = 0; i < m+1; i++) {
		c[i] = new TableCell[n+1];
	}

	REP(i,1,m) {
		c[i][0].val = 0;
	}

	REP(j,0,n) {
		c[0][n].val = 0;
	}

	REP(i,1,m) {
		REP(j,1,n) {
			if(x.at(i-1) == y.at(j-1)) {
				c[i][j].val = c[i-1][j-1].val + 1;
				c[i][j].direction = "diagonal";
			} else if (c[i-1][j].val >= c[i][j-1].val){
				c[i][j].val = c[i-1][j].val;
				c[i][j].direction = "up";
			} else if (c[i][j].val = c[i][j-1].val) {
				c[i][j].direction = "left";
			}
		}
	}

	return c;
}

void Print_LCS(TableCell **B, string x, int i, int j) {
	if(i == 0 || j == 0) {
		return;
	}
	if (B[i][j].direction == "diagonal") {
		Print_LCS(B, x, i-1, j-1);
		cout<<x.at(i-1);
	} else if (B[i][j].direction == "up") {
		Print_LCS(B,x,i-1,j);
	} else {
		Print_LCS(B,x,i,j-1);
	}

}

int main() {
	string x;
	string y;

	cin >>x>>y;
	TableCell **cell= LCS_Length(x,y);

	Print_LCS(cell,x,x.size(), y.size());
}
