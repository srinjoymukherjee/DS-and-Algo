/*Armstrong Number*/

#include <iostream>

using namespace std;

int power(int val, int exp){
	if(exp == 0){
		return 1;
	}
	
	if(exp%2 == 0){
		return power(val, exp/2) * power(val, exp/2);
	}
	
	return val * power(val, exp/2) * power(val, exp/2);
}

int order(int val){
	int val_order = 0;
	
	while(val){
		val_order++;
		val /= 10;
	}
	
	return val_order;
}

bool is_armstrong(int val){
	int actual = val;
	int pow = order(val);
	int sum = 0;
	
	while(val){
		int temp_val = val%10;
		sum += power(temp_val, pow);
		val = val/10;
	}
	
	return actual == sum ? true : false;
}

int main(){
	is_armstrong(153) ? cout<<"Armstrong Number"<<endl : cout<<"Not an Armstrong Num"<<endl;
	return 0;
}
