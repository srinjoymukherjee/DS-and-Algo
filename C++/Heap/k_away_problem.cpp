/*
Given an array of n elements, where each element is at most k away from its target position, 
devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, 
an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.
*/

#include <iostream>
#include <queue>

using namespace std;

void print_vect(vector<int> vect){
	for(auto itr = vect.begin(); itr != vect.end(); itr++){
		cout<<*itr<<" ";
	}
	
	cout<<endl;
}

int main(){
	int ip[] = {6, 5, 3, 2, 8, 10, 9};
	int k = 3;
	size_t size = sizeof(ip)/sizeof(int);
	
	priority_queue< int, vector<int>, greater<int> > pq(ip, ip+k+1);
	vector<int> res;
	
	for(size_t idx = k+1; idx < size; idx++){
		res.push_back(pq.top());
		pq.pop();
		pq.push(ip[idx]);
	}
	
	while(!pq.empty()){
		res.push_back(pq.top());
		pq.pop();
	}
		
	
	print_vect(res);
	return 0;
}
