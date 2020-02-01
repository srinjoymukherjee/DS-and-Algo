/*Find 3 elements in an array,
so that the sum of those 3 numbers,
is equals to key*/

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int a[] = {4,20,9,88,3,6,0,2};
	int key = 12;
	int n = sizeof(a)/sizeof(int);
	sort(a,a+n);
	for(int i = n-1; i > 0; i--)
	{
		int l = 0;
		int r = i - 1;
		while(l < r)
		{
			if((a[l] + a[r] + a[i]) == key)
			{
				cout<<a[l]<<"\t"<<a[r]<<"\t"<<a[i]<<endl;
				l++;
				r--;
			}
			else if((a[l] + a[r] + a[i]) > key)
				r--;
			else
				l++;
		}
	}
}
