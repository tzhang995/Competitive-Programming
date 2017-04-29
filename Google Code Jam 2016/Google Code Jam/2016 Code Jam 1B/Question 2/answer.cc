#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
	int numTest;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> numTest;
	int testNum = 1;

	while(testNum <= numTest){
		getline(cin, s);
		cout << "Case #" << testNum << ": ";
		stringstream sss(s);
		string team1;
		string team2;

		sss>>team1;
		sss>>team2;

		//0 = tie  1 = team1 2=team2
		int whobigger = 0;
		for(int i = 0; i<team1.size();i++){
			if(team1.at(i) == '?' && team2.at(i) == '?'){
				if(whobigger = 0){
					team1[i] = '0';
				}
			} else if ({

			}
		}

		testNum++;
	}
}