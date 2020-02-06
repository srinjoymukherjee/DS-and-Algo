/*
Given a sorted array A of size N and a number X, 
you need to find the number of occurrences of X in A.
*/

#include<bits/stdc++.h>

using namespace std;

void countOccurence(int &count, vector<int> vect, size_t low, size_t high, int key){
	if(low <= high){
		size_t mid = (low + high)/2;
		
		if(vect[mid] == key){
			count++;
			if(vect[mid - 1] == key){
				countOccurence(count, vect, low, mid - 1, key);
			}
			if(vect[mid + 1] == key){
				countOccurence(count, vect, mid + 1, high, key);
			}
			return;				
		}
		else if(vect[mid] > key){
			countOccurence(count, vect, low, mid - 1, key);
		}
		else{
			countOccurence(count, vect, mid + 1, high, key);
		}
	}
	
	return;
}

int main(){
	int count = 0;
	vector<int> inp = {0,1,1,2,2,2,4,4,5,6,7,9,9};
	int key = 2;
	countOccurence(count, inp, 0, inp.size() - 1, key);
	cout<<"Count: "<<count<<endl;
	return 0;
}
