#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int a[] = {1,2,-3,4,5,-9};
	int n = sizeof(a)/sizeof(int);
	for(int i = n-1; i > 0; i--)
	{
		int l = 0;
		int r = i - 1;
		while(l < r)
		{
			if((a[l] + a[r] + a[i]) == 0)
			{
				cout<<a[l]<<"\t"<<a[r]<<"\t"<<a[i]<<endl;
				l++;
				r--;
			}
			else if((a[l] + a[r] + a[i]) > 0)
				r--;
			else
				l++;
		}
	}
}
