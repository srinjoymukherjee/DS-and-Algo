/*check whether number is prime*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int64_t largest_prime_factor(int64_t);
bool check_prime(int);

int main(){
	for(size_t i = 1; i < 50; i++){
		if(check_prime(i))
			cout<<i<<endl;
	}
}

/*Find the largest prime factor of the number.
If this is the number itself, then the number is a prime number*/
bool check_prime(int num){
	if(num < 2)
		return false;
	if(num == largest_prime_factor(num)){
		return true;
	}
	
	return false;
}

//Function to find largest prime factor
int64_t largest_prime_factor(int64_t num){
	int64_t fact = 1, ulimit = sqrt(num), temp = 0;
	
	/*Check if the Number is Even,
	then devide it by 2 until it becomes odd*/
	while(num%2 == 0){
		fact = 2;
		num = num/2;
	}
	
	/*Set the upper limit as the largest odd Number,
	less than or equals to the square root of the actual number*/
	ulimit = ulimit%2 == 0 ? ulimit - 1 : ulimit;
	
	/*Check for the Prime factors in the remaining Odd Number
	and store the largest prime factor*/
	for(int64_t idx = ulimit; idx > 2; idx = idx - 2){
		while(num%idx == 0){
			fact = idx > fact ? idx : fact;
			num = num/idx;
		}
			
	}
	
	/*Check if the remaining number is greater
	than the factor we have found so far
	if yes, it is the largest prime factor and return it
	else, return the factor, we have found so far*/
	return num > fact ? num : fact;
}
