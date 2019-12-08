// C++ program to find longest contiguous subsequence 

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int findLongContSub(int arr[], int size){
	unordered_set<int> t_set;
	int res = 0;
	for(size_t idx = 0; idx < size; idx++){
		t_set.insert(arr[idx]);
	}
	
	for(size_t idx = 0; idx < size; idx++){
		int key = arr[idx];
		
		//check whether we are at the first element 
		//of a sequence
		if(t_set.find(arr[idx] - 1) == t_set.end()){
			//count consequtive elements
			while(t_set.find(key++) != t_set.end())
				res = max(res,(key - arr[idx]));
		}		
	}
	
	return res;
}

int main(){
	int arr[] = {30, 95, 31, 40, 32, 41, 33};
	int size = sizeof(arr)/sizeof(int);
	cout<<"Longest Contigous Subsequence length: "<<endl;
	cout<<findLongContSub(arr, size)<<endl;
	return 0;
}
