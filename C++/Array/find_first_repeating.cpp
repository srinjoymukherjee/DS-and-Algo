/*
Implement a space efficient algorithm to check 
First repeated character in a string without 
using any additional data structure in one traversal. 

Use additional data structures like count array, 
hash, etc is not allowed.
*/

#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

char find_first_repeating(string s){
	uint64_t checker = 0;
	uint64_t mover = 1;
	
	for(auto &i : s){
		int delta = i - 'A'; //get the delta
		
		//check whether the delta-bit is set for the particular bit
		if((checker & (mover << delta)) != 0){
			return i;
		}
		
		//set the delta bit, if it is not set
		checker |= (mover << delta);
		
		cout<<mover<<endl;
	} 
	return ' ';
}

int main(){
	string ip_str = "Anjkioupncl";
	cout<<"First repeating char: "<<find_first_repeating(ip_str)<<endl;
	return 0;
}
