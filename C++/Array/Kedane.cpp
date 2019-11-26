#include <iostream>
#include <algorithm>

using namespace std;

//Write an efficient program to find the sum of contiguous subarray 
//within a one-dimensional array of numbers which has the largest sum.
int exec_Kedane(int*, int);

int main(){
	int b[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(b)/sizeof(int);
	
	cout<<"The maximum Sum of Substrings\t"<<exec_Kedane(b, n);
	return 0;
}

int exec_Kedane(int* a, int n){
	int prev_max = 0, cur_max = 0;
	for(int idx = 0; idx < n; idx++){
		cur_max += a[idx];
		prev_max = max(prev_max, cur_max);
		
		if(cur_max < 0)
			cur_max = 0;
	}
	return prev_max;
}
