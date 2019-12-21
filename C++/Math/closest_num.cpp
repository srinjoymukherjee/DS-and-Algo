/*
Given two integers n and m. 
The problem is to find the number closest to n and divisible by m. 
If there are more than one such number, 
then output the one having maximum absolute value. 
If n is completely divisible by m, then output n only. 
Time complexity of O(1) is required.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int closest_number(int n, int m){
	if(n%m == 0)
		return n;
		
	int q = n/m;
	int n1 = m * q;
	int n2 = 0;	
	
	if(q > 0){ //if both n and m are +ve or -ve
		n2 = m * (q + 1);
	}else{ //if one of n or m is -ve and other one is +ve
		n2 = m * (q - 1);
	}
	
	if(abs(n - n1) > abs(n - n2))
		return n2;
	else if (abs(n - n1) < abs(n - n2)) 
		return n1;
	else{
		return abs(n1) > abs(n2) ? n1 : n2;
	}
}

int main(){
	cout<<closest_number(12,-5)<<endl;
	return 0;
}
