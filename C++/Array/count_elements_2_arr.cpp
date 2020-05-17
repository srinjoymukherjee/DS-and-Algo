/*
Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. 
For each element in arr1[] count elements less than or equal to it in array arr2[].
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> num_element(vector<int> list1, vector<int> list2)
{
    int max_list1 = *max_element(list1.begin(), list1.end());
    int max_list2 = *max_element(list2.begin(), list2.end());

    int max_num = max(max_list1, max_list1);

    vector<int> ret_list(list1.size(), 0);
    vector<int> hash_tbl(max_num + 1, 0);

    for(auto val : list2)
    {
        hash_tbl[val] = hash_tbl[val] + 1;
    }

    for(size_t idx = 1; idx < hash_tbl.size(); idx++)
    {
        hash_tbl[idx] = hash_tbl[idx] + hash_tbl[idx - 1];
    }

    for(size_t idx = 0; idx < list1.size(); idx++)
    {
        ret_list[idx] = hash_tbl[list1[idx]];
    }

    return ret_list;
}

int main()
{
    vector<int> list1 = {4, 8, 7, 5, 1};
    vector<int> list2 = {4, 4, 8, 3, 0, 1, 1, 5};
    auto ret_list = num_element(list1, list2);   

    for(auto val : ret_list)
        cout<<val<<"\t";

    return 0;
}