#include<iostream>
#include <string>
#include <unordered_set>

using namespace std;

int find_min_length(string s){
	unordered_set< char > char_set(s.begin(), s.end());
	int res = 0;
	for(size_t w_len = char_set.size(); w_len < s.size(); w_len++){
		int count = 0;
		bool found = false;
		for(size_t idx = 0; idx + w_len < s.size(); idx++){
			string sub_str = s.substr(idx,w_len);
			unordered_set< char > temp_char_set(sub_str.begin(), sub_str.end());
			
			if(temp_char_set.size() == char_set.size()){
				found = true;
				break;
			}
		}
		if(found){
			res = w_len;
			break;
		}
	}	
	return res;
}

int main(){
	string str("abbdabbcc");
	cout<<find_min_length(str)<<endl;
	
	return 0;
}
