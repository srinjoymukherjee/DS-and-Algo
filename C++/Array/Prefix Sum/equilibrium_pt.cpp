// C++ program to find equilibrium 
// index of an array 

#include <iostream>

using namespace std;

int* getPrefSum(int* arr, size_t size){
	int* prefSuf = new int[size + 1];
	prefSuf[0] = 0;
	for(size_t idx = 1; idx <= size; idx++){
		prefSuf[idx] = prefSuf[idx - 1] + arr[idx - 1];
	}
	return prefSuf;
}

int getEqlPt(int* arr, size_t size){
	int* prefSum = getPrefSum(arr, size);
	size_t res_idx = 0;
	int res = 0;
	
	for(size_t idx =  1; idx <= size; idx++){
		if(prefSum[idx - 1] == (prefSum[size] - prefSum[idx])){
			res = idx;
		}
	}
	return res;
}

int main(){
	int arr[] = {3, 6, 1, 10, -2, 1};
	size_t size = sizeof(arr)/sizeof(int);
	int ptr = getEqlPt(arr, size);
	if(ptr)
		cout<<"Equilibrium Point: "<<ptr<<endl;
	else
		cout<<"No equilibrium point"<<endl;
	return 0;
}
