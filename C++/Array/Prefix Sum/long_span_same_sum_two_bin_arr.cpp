/*
Given two binary arrays arr1[] and arr2[] of same size n. 
Find length of the longest common span (i, j) 
where j >= i such that arr1[i] + arr1[i+1] + …. + arr1[j] = 
                        arr2[i] + arr2[i+1] + …. + arr2[j].

Hint: If we calculate a prefix sum array then below two cases can be possible:
==============================================================================
1.  If prefix sum of both arrays are same at any point then
    the span from starting up to this point has same number of 0s and 1s

2.  If differences of prefix sum of arr1 and arr2 are same 
    at any two indices then the delta change (incement/ decrement)
    among these two indices are same. 
    So, same number of 0s and 1s has been encountered between 
    these two points.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int calc_sub_arr(vector<int> arr1, vector<int> arr2)
{
    int pref_sum1;
    int pref_sum2;
    int diff;
    int max_index = -2, min_index = 0;
    unordered_map<int, int> diff_sum;

    for(size_t idx = 0; idx < arr1.size(); idx++)
    {
        if(idx == 0)
        {
            pref_sum1 = arr1[idx];
            pref_sum2 = arr2[idx];
        }
        else
        {
            pref_sum1 += arr1[idx];
            pref_sum2 += arr2[idx];    
        }       

        diff = pref_sum1 - pref_sum2;
        
        if(!diff)
        {
            max_index = idx;
            min_index = 0;
        }

        if(diff_sum.find(diff) == diff_sum.end())
        {
            diff_sum[diff] = idx;
        }
        else
        {
            int pre_length = max_index - min_index;
            int cur_lenngth = idx - (diff_sum[diff] + 1);

            if(cur_lenngth > pre_length)
            {
                max_index = idx;
                min_index = diff_sum[diff] + 1;
            }
        }        
    }

    return (max_index - min_index + 1);
}

int main()
{
    vector<int> arr1 = {0, 0, 0, 1, 1, 1, 1};
    vector<int> arr2 = {1, 1, 1, 1, 1, 0, 1};

    int size = calc_sub_arr(arr1, arr2);

    if(size > 0)
        cout<<"Sub Array Size: "<<size<<endl;
    else
    {
        cout<<"No Such Sub Array"<<endl;
    }

    return 0;
}