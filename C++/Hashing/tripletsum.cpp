/*
Triplet sum:
============
From a set of integers S, find count of all those sets
for which e1 + e2 + e3 = k where e1, e2 and e3 belongs to S
*/

#include <bits/stdc++.h>

using namespace std;

int count_set(vector<int> ipArr, int key)
{
    int check_sum;
    int count_set = 0;

    for(size_t idx1 = 0; idx1 < ipArr.size(); idx1++)
    {
        check_sum = key - ipArr[idx1];
        unordered_set<int> set_sum;
        for(size_t idx2 = idx1 + 1; idx2 < ipArr.size(); idx2++)
        {
            if(set_sum.find(check_sum - ipArr[idx2]) == set_sum.end())
            {
                set_sum.insert(ipArr[idx2]);
            }
            else
            {
                count_set++;
            }            
        }
    }

    return count_set;
}

int main()
{
    vector<int> ipArr = {7, 3, 5, 8, 9, 20, 32, 6};
    int key = 20;

    cout<<count_set(ipArr, key)<<endl;

    return 0;
}
