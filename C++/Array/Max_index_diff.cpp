#include <iostream>
#include <algorithm>

using namespace std;
int find_max_index_diff(int*&, int);

int main(){
	int n = 10;
	
	int* a = new int[n];
	
	int b[] = {35,8,10,3,2,80,30,33,1};
	a = b;
	
	cout<<find_max_index_diff(a, n)<<endl;
//	cout<<a[1]<<endl;
	return 0;
	
}

int find_max_index_diff(int*& a, int n){
	int* LMin = new int[n];
	int* RMax = new int[n];
	int maxDif = -1, l = 0, r = 0;
//	a[1] = 87;
	LMin[0] = a[0];
	RMax[n-1] = a[n-1];
	
	for(l = 1; l < n; l++)
	{
		LMin[l] = min(a[l], LMin[l - 1]);
	}
		
	for(r = n - 2; r >= 0; --r)
	{
		RMax[r] = max(a[r], RMax[r + 1]);
	}
//	cout<<endl;
	
	l = 0;
	r = 0;
	
	while(l < n && r < n)
	{
		if(LMin[l] < RMax[r])
		{
			maxDif = max(maxDif, r - l);
//			cout<<r<<"\t";
			r++;
		}
		else
			l++;
	}
//	cout<<endl;
	
	return maxDif;
}
