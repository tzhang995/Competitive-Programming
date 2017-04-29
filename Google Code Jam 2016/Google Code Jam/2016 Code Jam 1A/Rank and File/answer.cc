#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool myfunction (vector<int> i, vector<int> j){
	return i[0]<j[0];
}

void thisfunction(vector<vector<int> > bigger, vector<vector<int> > smaller, int gridsize){
	for(int i = 0; i<bigger.size();i++){
		vector<int> tempSmall;
		for(int j = 0; j<gridsize; j++){
			tempSmall.push_back(bigger[j][i]);
		}
		sort(tempSmall.begin(), tempSmall.end());

		bool found = false;
		for(int j = 0; j<smaller.size();j++){
			if(tempSmall == smaller[j]){
				break;
				found= true;
			}
		}
		if(found == false){
			for(int k = 0; k<tempSmall.size(); k++){
				cout<<tempSmall[k]<<" ";
			}
			break;
		}

	}
}

int main(){
	int numTest;
	string s;
	getline(cin, s);
	stringstream ss(s);

	ss>> numTest;
	int testNum = 1;

	while (testNum <= numTest){
		getline(cin, s);
		stringstream sss(s);
		int gridsize;
		sss>>gridsize;
		int readsize = (gridsize * 2) -1;
		vector<vector<int> > gridrow;
		vector<vector<int> > gridcol;


		cout<<"Case #"<<testNum<<": ";
		for(int i = 0; i<readsize; i++){
			getline(cin, s);
			stringstream ssss(s);
			vector<int> row;

			for(int j = 0; j<gridsize; j++){
				int cur;
				ssss>>cur;

				row.push_back(cur);
			}
			sort(row.begin(), row.end());

			bool iscol = false;
			for(int j=0; j<gridrow.size();j++){
				if(gridrow[j][0] == row[0]){
					iscol = true;
					gridcol.push_back(row);
					break;
				}
			}
			if(iscol == false){
				gridrow.push_back(row);
			}
		} 

		for(int i = 0; i<gridrow.size();i++){
			for(int j = 0; j<gridsize;j++){
				cout<<gridrow[i][j]<<"|";
			}
			cout<<endl;
		}

		for(int i = 0; i<gridcol.size();i++){
			for(int j = 0; j<gridsize;j++){
				cout<<gridcol[i][j]<<"|";
			}
			cout<<endl;
		}

		if(gridrow.size()>gridcol.size()){
			//thisfunction(gridrow, gridcol, gridsize);
		}else {
			//thisfunction(gridcol,gridrow, gridsize);
		}


		cout<<endl;
		testNum++;
	}
}