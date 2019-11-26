#include<iostream>

using namespace std;

int main(){
	int a[] = {20,25,30,35,40};
	for(int i = 0; i< 5; i++){
		a[i] = a[i] - 10;
	}
	for(int i = 0; i< 5; i++){
		cout<<a[i]<<endl;
	}
}
