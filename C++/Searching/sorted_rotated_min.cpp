/*
Given a sorted and rotated array A of N distinct elements 
which is rotated at some point.
Find the minimum element in the sequence
*/

#include <bits/stdc++.h>

using namespace std;

/*
Note: For every element, one of the below array will be sorted
	  and other one will be unsorted:
		1. Array with range low .. mid (Left Sub Array)
		2. Array with range mid .. right (Right Sub Array)
*/	
void find_min(vector<int> vect, size_t low, size_t high, int &min_num){
	size_t mid = (low + high)/2;
	
	if(low == high){
		min_num = min(min_num, vect[low]);
		return;
	}
	
	if(vect[low] < vect[mid]){
		min_num = min(min_num, vect[low]);
		find_min(vect, mid, high, min_num);
	}
	else{
		min_num = min(min_num, vect[mid]);
		find_min(vect, low, mid, min_num);
	}
	
	return;
}

int main(){
	vector<int> inp = {10, 12, 15, 20, 30, 5, 8};
	int min_num = INT_MAX;
	find_min(inp, 0, inp.size(), min_num);
	cout<<"Minimum Number: "<<min_num<<endl;
	return 0;
}
