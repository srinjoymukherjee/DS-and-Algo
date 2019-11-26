/*
check whether a Sum of two elements ,
in an array of length n, 
is equal to a particular integer k
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
	int l = 0, r = 4, c = 0;
	int a[] = {13, 9, 11, 7, 4}; // the given array
	int key = 20; //assigning the value of k here
	sort(a, a+5);
	while(l < r){
		if((a[l] + a[r]) == key){
			cout<<a[l]<<", "<<a[r]<<endl;
			l++;
			r--;
			c++;
		}			
		else if((a[l] + a[r]) > key)
			r--;
		else
			l++;
	}
	if(c == 0)
		cout<<"Not available"<<endl;
}
