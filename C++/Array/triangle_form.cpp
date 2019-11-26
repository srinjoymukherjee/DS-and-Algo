#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num_tc = 0, ip_size = 0, i=0, j = 0, k = 0, count = 0, n = 0;
    
	cin>>num_tc;
	
	for(int idx = 0; idx < num_tc; idx++)
	{
	    cin>>ip_size;
	    int* ip_array = new int[ip_size];
	    for(i = 0; i<ip_size; i++)
	    {
	        cin>>ip_array[i];
	        
	    }
	    sort(ip_array,ip_array + ip_size);
	    n = ip_size;
	    for(i = n-1; i > 0; i--)
	    {
	    	int l = 0;
	    	int r = i - 1;
	    	while(l < r)
			{
				if((ip_array[l] + ip_array[r]) > ip_array[i])
				{
					count+= (r - l);
					cout<<ip_array[l]<<" + "<<ip_array[r]<<" > "<<ip_array[i]<<endl;
					r--;
				}
				else
					l++;
			}	    	
		}
	    cout<<count<<endl;    
	    delete[] ip_array;
	    ip_array = NULL;
	}
	return 0;
}
