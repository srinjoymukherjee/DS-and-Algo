#include <iostream>
#include <string>

using namespace std;

int check_pal(string word, size_t size){
	int l = 0, r;
	r = size - 1;
	while(l < r){
		if(word[l++] != word[r--])
		return 0;
	}
	return 1;
}

int main(){
	string word;
	cout<<"provide the word"<<endl;
	getline(cin,word);
	int size = word.size();
	if(check_pal(word, size))
		cout<<"Palindrome"<<endl;
	else
		cout<<"Not Palindrome"<<endl;
}
