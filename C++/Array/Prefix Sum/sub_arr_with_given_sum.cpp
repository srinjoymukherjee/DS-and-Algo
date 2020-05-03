/*
Given an unsorted array A of size N of non-negative integers, 
find the first continuous sub-array which adds to a given number S.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void get_positions_from_diff(vector<int>, int);

void calc_sub_arr(vector<int> arr, int sum)
{
    int size = arr.size();

    vector<int> pref_sum(size + 1);
    pref_sum[0] = 0;

    for(size_t idx = 1; idx <= size; idx++)
    {
        pref_sum[idx] = pref_sum[idx - 1] + arr[idx - 1];
        if(pref_sum[idx] == sum)
        {
            cout<<"Start: 0"<<"\tEnd: "<<idx<<endl;
            return;
        }
    }

    get_positions_from_diff(pref_sum, sum);
}

//Algorithm to find a particular difference from a 
//sorted array.
void get_positions_from_diff(vector<int> arr, int key)
{
    int size = arr.size();
    int start = 0, end = size, mid = 0;

    //Find the value, just greater than key
    while(start < end)
    {
        mid = (start + end)/2;

        if(arr[mid] > key)
        {
            end--;
        }
        else
        {
            start++;
        }        
    }
    //Here, start and end is in same position
    
    //Reset End if required
    end = arr[end] > key ? end : (end + 1);

    //Reset Start
    start = 0;

    while(start < end && end < size)
    {
        if((arr[end] - arr[start]) > key)
        {
            start++;
        }
        else if((arr[end] - arr[start]) < key)
        {
            end++;
        }
        else
        {
            //As We are dealing with prefix sum array, size of the array is
            //one more than tha current array. So the ans is based on index 1
            cout<<"Start: "<<(start + 1)<<"\tEnd: "<<end<<endl;
            
            return;
        }

        if(start == end)
            end++;
        
    }

    cout<<"Not found"<<endl;
    return;
}

int main()
{
    vector<int> arr = {1, 2, 4, 7, 5};
    int sum = 12;
    calc_sub_arr(arr, sum);
    return 0;
}