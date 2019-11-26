/*
Find median of a stream of data
*/

#include <iostream>
#include <queue>

using namespace std;

double find_mean(int ip[], int size){
	priority_queue< int > maxh;
	priority_queue< int, vector< int >, greater< int > > minh;
	maxh.push(ip[0]);
	double med = ip[0];
	
	for(int idx = 1; idx < size; idx++){
		if(maxh.size() > minh.size()){
			if(ip[idx] < med){
				minh.push(maxh.top());
				maxh.pop();
				maxh.push(ip[idx]);
			}else{
				minh.push(ip[idx]);
			}
			med = (maxh.top() + minh.top())/2.0;
		}else if(maxh.size() < minh.size()){
			if(ip[idx] > med){
				maxh.push(minh.top());
				minh.pop();
				minh.push(ip[idx]);
			}else{
				maxh.push(ip[idx]);
			}
			med = (maxh.top() + minh.top())/2.0;
		}else{
			if(ip[idx] > med){
				minh.push(ip[idx]);
				med = minh.top();
			}else{
				maxh.push(ip[idx]);
				med = maxh.top();
			}			
		}
	}
	
	return med;
}

int main(){
	int ip[] = {20,3,45,9,55};
	int size = sizeof(ip)/sizeof(int);
	cout<<"Median\t"<<find_mean(ip, size);
	return 0;
}
