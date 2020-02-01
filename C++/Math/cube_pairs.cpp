/*Count pairs (a, b) whose sum of cubes is N (a^3 + b^3 = N)*/
#include <bits/stdc++.h>

using namespace std;

void cube_pairs(int num){
	int temp = num;
	
	for(int idx = 1; idx <= cbrt(num); idx++){
		//Substract the cube of the number
		//from the actual number
		temp = temp - (idx*idx*idx);
		
		//Check whether the remaining number is a cube
		int tempcb = cbrt(temp);
		
		if(tempcb*tempcb*tempcb == temp)
			cout<<num<<": "<<idx<<", "<<tempcb<<endl;
		
		temp = num;
	}
	
}

int main(){
	int limit = 101;
	cout<<"All numbers which are cube pairs in the range of "<<0<<" to "<<limit - 1<<endl;
	
	while(--limit){
		cube_pairs(limit);
	}
}
