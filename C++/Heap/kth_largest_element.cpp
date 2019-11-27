/*
Find K-th largest element from a stream of inputs
*/

#include <iostream>
#include <queue>

using namespace std;

int main(){
	int ip[] = {20,9,45,3,6,5,2,10};
	int k = 5;
	int size = sizeof(ip)/sizeof(int);
	
	//prepare a Heap with 1st k elements
	priority_queue< int, vector< int >, greater< int > > minh(ip,ip+k);
	
	/*
	Check for all the elements and if they qualify,
	pop the minimum element from heap and push the current element
	*/
	for(size_t idx = k; idx < size; idx++){
		/*
		Rule for qulification:
		The element must be greater than the highest 
		priority element in the heap i.e. The minimum element
		*/
		if(ip[idx] > minh.top()){
			minh.pop();
			minh.push(ip[idx]);
		}
	}
	
	cout<<minh.top()<<endl;
	
	return 0;	
}
