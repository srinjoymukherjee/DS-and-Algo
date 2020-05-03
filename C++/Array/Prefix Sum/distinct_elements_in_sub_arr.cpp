/*
Given an array of size n and an integer k, 
return the count of distinct numbers in all windows of size k.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void calc_windows(vector<int> arr, int key)
{
    //Stores distinct elements in current window
    unordered_set<int> distinct;

    //Store the number of repetetion of every element
    //in the current window
    unordered_map<int, int> num;

    for(size_t idx = 0; idx < arr.size(); idx++)
    {
        //Check if we are not forming the first Interval
        if(idx >= key)
        {
            //Print the size of last window
            cout<<distinct.size()<<"\t";
            num[arr[idx - key]] -= 1;

            if(num[arr[idx - key]] == 0)
                distinct.erase(arr[idx - key]);
        }
        
        //If element is not present
        if(distinct.find(arr[idx]) == distinct.end())
        {
            distinct.insert(arr[idx]);
            num.insert({arr[idx], 1});
        } 
        else //If element is already present
        {
            num[arr[idx]] += 1;
        }
    }
    //Print the Last Value
    cout<<distinct.size()<<endl;
}

int main()
{
    vector<int> arr = {1, 2, 1, 2, 4, 2, 3};
    int key = 4;
    calc_windows(arr, key);
    return 0;
}