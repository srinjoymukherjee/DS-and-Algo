/*Largest Prime Factor*/
#include<bits/stdc++.h>

using namespace std;

int64_t largest_prime_factor(int64_t num){
	int64_t fact = 1, ulimit = sqrt(num), temp = 0;
	while(num%2 == 0){
		fact = fact * 2;
		num = num/2;
	}
	ulimit = ulimit%2 == 0 ? ulimit - 1 : ulimit;
	
	for(int64_t idx = ulimit; idx > 2; idx = idx - 2){
		while(num%idx == 0){
			fact = idx > fact ? idx : fact;
			num = num/idx;
		}
			
	}
	return num > fact ? num : fact;
}

int main(){
	int64_t num = 1132;
	cout<<largest_prime_factor(num)<<endl;
	return 0;
}
