/*
Given an array A of size N, 
find all combination of four elements in the array 
whose sum is equal to a given value K. 
For example, if the given array is {10, 2, 3, 4, 5, 9, 7, 8} 
and K = 23, one of the quadruple is “3 5 7 8” (3 + 5 + 7 + 8 = 23).

The output should contain only unique quadrples.
For example, if input array is {1, 1, 1, 1, 1, 1} 
and K = 4, then output should be only one quadrple {1, 1, 1, 1}
*/

#include<bits/stdc++.h>

using namespace std;

int count_four_sum(vector<int>, int);

int main(){
    vector<int> inp = {2,5,3,8,1,4,6,7,9,11};
    int key = 33;
    cout<<count_four_sum(inp, key)<<endl;
    return 0;
}

int count_four_sum(vector<int> vect, int key)
{
    int count = 0;
    unordered_map<int, pair<size_t,size_t>> mp;
    
    for(size_t idx1 = 0; idx1 < vect.size(); idx1++)
    {
        for(size_t idx2 = idx1 + 1; idx2 < vect.size(); idx2++)
        {
            //check if the current sum of pair, and any old sum of pair
            //are sum up to required key
            if(mp.find(key - (vect[idx1] + vect[idx2])) != mp.end())
            {
                size_t idx3 = mp[key - (vect[idx1] + vect[idx2])].first;
                size_t idx4 = mp[key - (vect[idx1] + vect[idx2])].second;
                unordered_set<int> s;

                //Check whether all nodes forming this combination
                //are not same
                s.insert(idx1);
                s.insert(idx2);
                s.insert(idx3);
                s.insert(idx4);
                if(s.size() == 4)
                {
                    cout<<idx1<<" "<<idx2<<" "<<idx3<<" "<<idx4<<endl; 
                }

                count++;

            }
            //Insert the current sum of pairs into the map
            mp[vect[idx1] + vect[idx2]] = {idx1, idx2};
        }
    }
    return count;
}