/*
Kedane's Algorithm:
Given an array arr of N integers. 
Find the contiguous sub-array with maximum sum.
*/

#include <bits/stdc++.h>

using namespace std;

int find_largest_sum(vector<int> val)
{
    vector<int> sum;
    sum.push_back(val[0]);

    for(size_t idx = 1; idx < val.size(); idx++)
    {
        //If, sum[idx - 1] < 0 then val[idx] > sum[idx - 1] + val[idx]
        //and the position idx is a start of a new cluster
        sum.push_back(max(sum[idx - 1] + val[idx], val[idx]));
    }

    return *max_element(sum.begin(), sum.end());
}

int main()
{
    vector<int> val = {4, 2, 7, -10, 15, 3, -4, 1};
    cout<<"The Maximum Sum of Substrings:\t";
    cout<<find_largest_sum(val)<<endl;
    return 0;
}