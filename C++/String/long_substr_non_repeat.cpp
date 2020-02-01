/*
Given a string str, find the length of the longest substring 
without repeating characters
*/

#include <bits/stdc++.h>

using namespace std;

void startNewSubstr(unordered_set<char>&, char);
size_t findLongestSubstr(string);

int main(){
	string inp = "SRINJOYMUKHERJEE";
	cout<<findLongestSubstr(inp)<<endl;
	return 0;
}

void startNewSubstr(unordered_set<char> &s, char c){
	s.clear();
	s.insert(c);
}

size_t findLongestSubstr(string s){
	unordered_set<char> char_set;
	size_t maxSize = 0;
	
	for(auto val: s){
		if(char_set.find(val) == char_set.end()){
			char_set.insert(val);
			maxSize = max(maxSize, char_set.size());
		}
		else{
			startNewSubstr(char_set, val);
		}
	}
	return maxSize;
}
