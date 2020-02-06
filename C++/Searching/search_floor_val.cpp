/*
Given a sorted array arr[] of size N without duplicates, 
and given a value x. 
Find the floor of x in given array. 
Floor of x is defined as the largest element K in arr[] 
such that K is smaller than or equal to x.
*/

#include <bits/stdc++.h>

using namespace std;

//int findFloor(vector<int>);
int searchFloor(vector<int>, size_t, size_t, int);

int main(){
	vector<int> vect = {13,20,29,45,121,490,502,1773};
	int key = 500;
	cout<<"The Floor value is: "<<endl;
	cout<<searchFloor(vect, 0, vect.size() - 1, key)<<endl;
	return 0;
}

int searchFloor(vector<int> vect, size_t start, size_t end, int key){
	int mid = 0;
	int val = INT_MIN;
	
	if(start > end || vect[start] > key)
		return val;
	
	//Calculate current mid
	mid = (start + end)/2;
	
	if(vect[mid] > key)
		val = searchFloor(vect,start,mid,key);
	else if(vect[mid] < key){
		/*
		Check whether there is a possibility
		that atleast one floor value is present 
		at the right half
		*/
		if(mid < vect.size() && vect[mid + 1] < key )
			val = searchFloor(vect, mid, end, key);
		else
			//If no Floor value is present in the right half,
			//then it is the dedired value
			val = vect[mid];
	}		
	else //If vect[mid] == key
		val = vect[mid];
		
	return val;
		
}
