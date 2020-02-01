#include <bits/stdc++.h>

using namespace std;

string addBinaryNum(string, string);

int main(){
	string num1 = "110";
	string num2 = "1011";
	
	cout<<"Final Result: "<<addBinaryNum(num1,num2)<<endl;
	
	return 0;
}

string addBinaryNum(string num1, string num2){
	string res = "";
	int s = 0;
	
	int idx1 = num1.size() - 1;
	int idx2 = num2.size() - 1;
	
	while(idx1 >= 0 || idx2 >= 0 || s == 1){
		s += ((idx1 >= 0) ? int(num1[idx1] - '0') : 0);
		s += ((idx2 >= 0) ? int(num2[idx2] - '0') : 0);
		
		/*There are 3 possible calues of s: 1, 2 and 3
			If s = 2, then add 0 and carry 1
			If s = 1, then add 1
			If s = 3, then add 1 and carry 1
		*/
		
		//Append current value with old string
		res = char(s%2 + '0') + res;
		
		//compute the carry, if s = 2 or s = 3, we need to carry 1  
		s = s/2;
		
		//go for next digit
		idx1--;
		idx2--;
	}
	
	return res;
}
