// Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands
// In this case, connected means everything around

// Input : mat[][] = {{1, 1, 0, 0, 0},
//                    {0, 1, 0, 0, 1},
//                    {1, 0, 0, 1, 1},
//                    {0, 0, 0, 0, 0},
//                    {1, 0, 1, 0, 1} 
// Note: it does not need to be in a  rectangle max row/col 100 for memory
// Output : 5
//


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


bool isValid(int dp[][100], int i, int j){
	if (i < 0 || i > 99 || j < 0 || j > 99) return false;
	if (dp[i][j] == 0) return false;
	return true;
}

//8 directions
void depth_search(int dp[][100], int i, int j) {
	dp[i][j] = 0;
	if(isValid(dp, i-1, j-1)) {
		depth_search(dp,i-1,j-1);
	}
	if(isValid(dp, i-1, j)) {
		depth_search(dp,i-1,j);
	}
	if(isValid(dp, i-1, j+1)) {
		depth_search(dp,i-1,j+1);
	}
	if(isValid(dp, i, j-1)) {
		depth_search(dp,i,j-1);
	}
	if(isValid(dp, i, j+1)) {
		depth_search(dp,i,j+1);
	}           
	if(isValid(dp, i+1, j-1)) {
		depth_search(dp,i+1,j-1);
	}
	if(isValid(dp, i+1, j)) {
		depth_search(dp,i+1,j);
	}
	if(isValid(dp, i+1, j+1)) {
		depth_search(dp,i+1,j+1);
	}

}


int main() {
	int dp_memo[100][100];
	REP(i,0,99){
		memset(dp_memo[i],0, sizeof(int) * 100); 
	}
	string s;
	int row = 0;
	while(getline(cin,s)) {
		REP(i, 0, s.size()-1) {
			dp_memo[row][i] = s.at(i)-'0';
		}
		row++;
	}

	int total_compontents = 0;
	REP(i,0,99){
		REP(j,0,99){
			if(isValid(dp_memo,i,j)) {
				depth_search(dp_memo,i,j);
				total_compontents++;
			}
		}
	}
	cout<<total_compontents<<endl;
}
