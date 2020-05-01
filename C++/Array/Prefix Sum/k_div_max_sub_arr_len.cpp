/*
Given an array containing N integers and a positive integer K. 
The task is to find the length of the longest sub array 
with sum of the elements divisible by the given value K.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> prefSum(vector<int> ip_arr)
{
    vector<int> pref_sum(ip_arr.size() + 1, 0);
    pref_sum[0] = 0;

    for(size_t idx = 1; idx <= ip_arr.size(); idx++)
    {
        pref_sum[idx] = pref_sum[idx - 1] + ip_arr[idx - 1];
    }        

    return pref_sum;
}

int calc_max_sub_arr_size(vector<int> pref_sum, int size, int key)
{
    int max = size + 1;  
    
    while(--max)
    {
        for(size_t idx = max; idx <= size; idx++)
        {
            if((pref_sum[idx] - pref_sum[idx - max]) % key == 0)
            {
                return max;
            }
        }
    }

    return max;
}

int max_len(vector<int> arr, int key)
{
    vector<int> pref_sum = prefSum(arr);
    int size = arr.size();
    return calc_max_sub_arr_size(pref_sum, size, key);
}

int main()
{
    vector<int> arr = {2, 7, 6, 1, 4, 5};
    int key = 3;
    cout<<max_len(arr, key)<<endl;
    return 0;
}