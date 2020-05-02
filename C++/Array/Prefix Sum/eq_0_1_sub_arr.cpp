/*
Given an array containing only 0s and 1s, 
find the largest subarray which contain equal no of 0s and 1s. 
Expected time complexity is O(n).
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int calc_sub_arr(vector<int> ip_arr)
{
    int max_sum = 0, min_sum = INT_MAX, min_index = 0, max_index = -2;
    vector<int> pref_sum(ip_arr.size());
    // pref_sum[0] = (ip_arr[0] == 0 ? -1 : 1);
    
    //Calculate Cumulatiove sum Considering 0's as -1
    for(size_t idx = 0; idx < ip_arr.size(); idx++)
    {
        if(idx == 0)
            pref_sum[idx] = (ip_arr[idx] == 0 ? -1 : 1);
        else
        {
            pref_sum[idx] = pref_sum[idx - 1] + 
                            (ip_arr[idx] == 0 ? -1 : 1);
        }        

        if(pref_sum[idx] < min_sum)
            min_sum = pref_sum[idx];
        
        if(pref_sum[idx] > max_sum)
            max_sum = pref_sum[idx];
    }

    //Build the visited hash table
    vector<int> visited(max_sum + 1, -1);

    for(size_t idx = 0; idx < pref_sum.size(); idx++)
    {
        if(pref_sum[idx] == 0)
        {
            min_index = 0;
            max_index = idx;
        }

        if(visited[pref_sum[idx]] == -1)
        {
            visited[pref_sum[idx]] = idx;
        }
        else
        {
            if((max_index - min_index) < 
                    (idx - (visited[pref_sum[idx]] + 1)))
            {
                max_index = idx;
                min_index = visited[pref_sum[idx]] + 1;
            }
        }        
    }

    return (max_index - min_index + 1);
}

int main()
{
    vector<int> ipArr = {1, 0, 1, 1, 1, 0, 0};
    int size = calc_sub_arr(ipArr);
    
    if(size > 0)
        cout<<"Sub Array Size: "<<size<<endl;
    else
    {
        cout<<"No Such Sub Array"<<endl;
    }
    
}