#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int check_anag(string str1, string str2, size_t s1, size_t s2){
	if(s1 != s2){
		return 0;
	}
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	
	if(str1 != str2)
		return 0;
	
	return 1;
}

int main(){
	string str1, str2;
	cout<<"provide the strings"<<endl;
	getline(cin,str1);
	getline(cin,str2);
	int size1 = str1.size();
	int size2 = str2.size();
	if(check_anag(str1, str2, size1, size2))
		cout<<"Anagram"<<endl;
	else
		cout<<"Not Anagram"<<endl;
}
