/*
Given an array of integers where each element represents 
the max number of steps that can be made forward from that element. 

The task is to find the minimum number of jumps 
to reach the end of the array (starting from the first element). 
If an element is 0, then cannot move through that element.

If answer is not possible print "-1"(without quotes).
*/
#include <bits/stdc++.h>

using namespace std;

//Minimum steps required to reach the end
int min_steps(vector<int> step)
{
    int count = 0;

    for(size_t idx = 0; idx < step.size();)
    {
        //If not reached the End and a blank cell is found
        if(step[idx] == 0 && idx != step.size() - 1)
        {
            return -1;
        }

        idx = idx + step[idx];
        count++;
    }

    return count;
}

int main()
{
    vector<int> step = {1, 3, 5, 8, 9, 2, 6, 0, 6, 8, 9};

    cout<<min_steps(step)<<endl;

    return 0;
}