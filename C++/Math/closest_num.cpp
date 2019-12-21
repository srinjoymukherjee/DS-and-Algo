#include <iostream>
#include <cstdlib>

using namespace std;

int closest_number(int n, int m){
	if(n%m == 0)
		return n;
		
	int q = n/m;
	int n1 = m * q;
	int n2 = 0;	
	
	if(q > 0){
		n2 = m * (q + 1);
	}else{
		n2 = m * (q - 1);
	}
	
	if(abs(n - n1) > abs(n - n2))
		return n2;
	else if (abs(n - n1) < abs(n - n2)) 
		return n1;
	else{
		return abs(n1) > abs(n2) ? n1 : n2;
	}
}

int main(){
	cout<<closest_number(12,-5)<<endl;
	return 0;
}
