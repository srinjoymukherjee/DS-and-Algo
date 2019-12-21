#include <iostream>

using namespace std;

int find_gcd_for_two(int val1, int val2){
	if(val2 == 0)
		return val1;
		
	return find_gcd_for_two(val2, val1%val2);
}

int find_gcd(int inp[],size_t size){
	size_t idx = 0;
	int gcd = 0;
	
	for(idx = 0; idx < size; idx++){
		gcd = find_gcd_for_two(inp[idx], gcd);
	}
	
	return gcd;
}

int find_multiple(int inp[],size_t size){
	int result = 1;
	
	for(size_t idx = 0; idx < size; idx++){
		result = result * inp[idx];
	}
	
	return result;
}

int find_lcm(int inp[],size_t size){
	int gcd = find_gcd(inp,size);
	int mult = find_multiple(inp,size);
	int lcm = mult/gcd;
	
	//As this is LCM of an array, 
	//we should devide the gcd for mutliple times
	for(size_t idx = 1; idx < size -1; idx ++){
		lcm = lcm/gcd;
	}
	return lcm;
}

int main(){
	int input[] = {30,40,45,20};
	size_t size = sizeof(input)/sizeof(int);
	cout<<find_lcm(input,size)<<endl;
	return 0;
}
