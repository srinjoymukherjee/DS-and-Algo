//GCD of two numbers
#include<iostream>

using namespace std;

int gcdOfTwo(int val1, int val2){
	if(val1 == 0)
		return val2;
	
	return gcdOfTwo(val2 % val1, val1);
}

int main(){
	cout<<gcdOfTwo(20,24);
}
