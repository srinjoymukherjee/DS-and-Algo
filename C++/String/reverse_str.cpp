//Reverse a string

#include <bits/stdc++.h>

using namespace std;

void swap(string& str, size_t first, size_t sec){
	char ch = str[first];
	str[first] = str[sec];
	str[sec] = ch;
}

void revStr(string& str){
	size_t start = 0;
	size_t end = str.size() - 1;
	
	while(start < end){
		swap(str,start++,end--);
	}
}

int main(){
	string str;
	getline(cin,str);
	
	revStr(str);
	cout<<str<<endl;
	return 0;
}
