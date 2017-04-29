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

	vector<string> mylist;
	mylist.push_back("ZERO");
	mylist.push_back("ONE");
	mylist.push_back("TWO");
	mylist.push_back("THREE");
	mylist.push_back("FOUR");
	mylist.push_back("FIVE");
	mylist.push_back("SIX");
	mylist.push_back("SEVEN");
	mylist.push_back("EIGHT");
	mylist.push_back("NINE");


	while(testNum <= numTest){
		getline(cin, s);
		string mystring;
		cout << "Case #" << testNum << ": ";

		map<char,int> mymap;
		for(int i = 0; i<26; i++){
			mymap['A'+i] = 0;
		}
		for(int i = 0; i<s.length();i++){
			mymap[s.at(i)]++;
		}
		for(int i = 0; i<26; i++){
			char b = 'A'+i;
			cout<<b<<" | "<<mymap['A'+i]<<endl;
		}

		for(int i = 0; i < mylist.size();i++){
			map<char,int> lownum;
			for(int j = 0; j<26; j++){
				lownum['A'+j] = 0;
			}
			for(int j = 0; j<mylist[i].length(); j++){
				lownum[mylist[i].at(j)]++;
			}

			bool everycorrect = true;
			while(everycorrect){
				for(int j = 0; j<26; j++){
					//cout<<mymap['A'+j]<<"|"<<lownum['A'+j]<<endl;
					if(mymap['A'+j]< lownum['A'+j]){
						everycorrect = false;
						break;
					}
				}

				if (everycorrect == true){
					for(int j = 0; j<26; j++){
						mymap['A'+j] = mymap['A'+j] - lownum['A'+j];
					}
					mystring.push_back('0'+i);
				}
			}

		}
		cout<<mystring<<endl;
		testNum++;
	}
}