//Three way partitioning

#include <iostream>
#include <algorithm>

using namespace std;

int* threeWayPart(int arr[], size_t size, size_t lowVal, size_t highVal){
	int left = 0, right = size - 1;
	
	for(size_t idx = left; idx <= right;){
		if(arr[idx] < lowVal)
			swap(arr[idx++], arr[left++]);
		else if(arr[idx] > highVal)
			swap(arr[idx], arr[right--]);
		else
			idx++;
	}
	
	int* res = arr;
	return res;
}

int main(){
	int arr[] = {11,8,2,42,20,15,37,12};
	int size = sizeof(arr)/sizeof(int);
	int lowVal, highVal;
	cout<<"Provide Low val: "<<endl;
	cin>>lowVal;
	cout<<"Provide High Val: "<<endl;
	cin>>highVal;
	
	int* res = threeWayPart(arr, size, lowVal, highVal);
	for(size_t idx = 0; idx < size; idx++){
		cout<<arr[idx]<<" ";
	}
	cout<<"\n";
	return 0;
}
