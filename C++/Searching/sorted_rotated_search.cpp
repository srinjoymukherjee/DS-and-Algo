/*
Given a sorted and rotated array A of N distinct elements 
which is rotated at some point, and given an element K. 
The task is to find the index of the given element K in the array A.
*/

#include <bits/stdc++.h>

using namespace std;

/*
Note: For every element, one of the below array will be sorted
	  and other one will be unsorted:
		1. Array with range low .. mid (Left Sub Array)
		2. Array with range mid .. right (Right Sub Array)
*/	
size_t searchSortRotate(vector<int> vect, size_t low, size_t high, int key){
	//Calculate mid
	int mid = (low + high)/2; 
	
	int key_idx = -1;
	
	//Check if we have already got the desired value
	if(key == vect[mid])
		return mid;
		
	/*
	If low and high are equal then low, high and mid are same.
	Then we should have been returned from the earlier check,
	if we would have found the element at this index.
	else, we need to flag false from here.
	*/
	if(low == high){
		return key_idx;
	}
	
	/*Check if left hand side of mid is sorted*/	
	if(vect[low] < vect[mid]){
		if(vect[low] <= key && key < vect[mid]){
			key_idx = searchSortRotate(vect, low, mid, key);
		}
		else{
			key_idx = searchSortRotate(vect, mid, high, key);
		}
	}
	else{ //Check if right hand side of mid is sorted
		if(vect[mid] <= key && key < vect[high]){
			key_idx = searchSortRotate(vect, mid, high, key);
		}
		else{
			key_idx = searchSortRotate(vect, low, mid, key);
		}
	}
	
	return key_idx;
}

int main(){
	vector<int> inp = {10, 12, 15, 20, 30, 5, 8};
	int key = 15;
	int pos = searchSortRotate(inp, 0, inp.size(), key);
	
	if(pos == -1)
		cout<<"Not found"<<endl;
	else
		cout<<"Element found at position: "<<pos<<endl;
		
	return 0;
}
