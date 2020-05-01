/*
Given an array a[] of N positive and negative numbers. 
Find if there is a subarray (of size at-least one) with 0 sum.
*/

#include <bits/stdc++.h>

using namespace std;

bool calcSubArr(vector<int> ipArr)
{
    vector<int> prefsum(ipArr.size() + 1);
    unordered_set<int> visited;
    prefsum[0] = 0;

    for(size_t idx = 1; idx <=ipArr.size(); idx++)
    {
        prefsum[idx] = prefsum[idx - 1] + ipArr[idx - 1];

        if(prefsum[idx] == 0 || 
                visited.find(prefsum[idx]) != visited.end())
            return true;
    }

    return false;
}

int main()
{
    vector<int> ipArr = {1, 4, -2, -2, 5, -4, 3};

    if(calcSubArr)
        cout<<"Array with sum 0 exists"<<endl;
    else
        cout<<"Array with sum 0 does not exist"<<endl;
    
    return 0;
}