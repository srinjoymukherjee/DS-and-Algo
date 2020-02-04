/*
Given n Magnets which are placed linearly, 
with each magnet to be considered as of point object. 
Each magnet suffers force from its left sided magnets 
such that they repel it to the right and vice versa. 
All forces are repulsive. 
The force being equal to the distance (1/d , d being the distance). 
Now given the positions of the magnets, 
the task to find all the points 
along the linear line where net force is ZERO. 

Note: Distance have to be calculated with precision of 0.0000000000001.
*/

#include <bits/stdc++.h>

using namespace std;

void findNullPoint(vector<int>);
double searchPtr(double, double, vector<int>);

int main(){
	vector<int> inp = {0,20,30,100};
	findNullPoint(inp);
	return 0;
}

//Main wrapper function
void findNullPoint(vector<int> vect){
	double nullPtr = -1.0;
	
	//Every interval between two points will have one Null Point
	for(size_t idx = 0; idx < vect.size() - 1; idx++){
		//Search for the null pointer in the current interval
		nullPtr = searchPtr(vect[idx], vect[idx + 1], vect);
		cout<<fixed<<setprecision(2)<<nullPtr<<"\t";
	}
	cout<<endl;
	return;
}

double searchPtr(double low, double high, vector<int> vect){
	double force = 0.0;
	double d = 0.0000000000001;
	double key = (high + low)/2.0;
	
	for(auto val:vect){
		force += (1.0000000000000/(key - val));	
	}
	
	if(abs(force) < d){
		return key;
	}
	
	if(force > 0){
		searchPtr(key, high, vect);
	}
	else{
		searchPtr(low, key, vect);
	}
}
