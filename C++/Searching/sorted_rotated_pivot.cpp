/*
Given a sorted and rotated array A of N distinct elements 
which is rotated at some point.
Find the Pivot point i.e. the position,
from where the seqence is broken
*/

#include <bits/stdc++.h>

using namespace std;

/*
Note: For every element, one of the below array will be sorted
	  and other one will be unsorted:
		1. Array with range low .. mid (Left Sub Array)
		2. Array with range mid .. right (Right Sub Array)
*/	
size_t find_pivot(vector<int> vect, size_t low, size_t high){
	size_t mid = (low + high)/2;
	size_t key_pos = 0;
	
	if(vect[low] < vect[mid] && vect[mid] < vect[high]){
		return key_pos;
	}
	
	//Check, if this is the breaking position
	if((mid > 0) && (mid < vect.size() - 1) && 
		(vect[mid - 1] < vect[mid]) &&
		(vect[mid] > vect[mid + 1])){
			key_pos = mid;
	}
	else{
		if(vect[low] < vect[mid]){
			key_pos = find_pivot(vect, mid, high);
		}
		else{
			key_pos = find_pivot(vect, low, mid);
		}
	}
	
	return key_pos;
}

int main(){
	vector<int> inp = {10, 12, 15, 20, 30, 5, 8};
	cout<<"Pivot: "<<find_pivot(inp, 0, inp.size())<<endl;
	return 0;
}
