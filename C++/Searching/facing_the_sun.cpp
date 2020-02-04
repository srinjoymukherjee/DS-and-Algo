#include <iostream>
#include <vector>

using namespace std;

int facing_the_sun(vector<int>);

int main(){
	vector<int> inp = {113,204,120,76,123,129};
	cout<<"Number of buildings receiving the sunlight:\n"<<facing_the_sun(inp);
	return 0;
}

int facing_the_sun(vector<int> buildList){
	int curMax = 0;
	int buildCount = 0;
	
	for(auto val: buildList){		
		if(val > curMax){
			buildCount++;
			curMax = val;
		}
	}
	return buildCount;
}
