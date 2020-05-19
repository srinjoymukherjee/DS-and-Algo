/*
Given an array arr[] consisting of 0’s and 1’s. 
A flip operation is one in which you turn 1 into 0 and a 0 into 1.
You have to do atmost one “Flip” operation of a subarray.
Then finally display maximum number of 1 you can have in the array.
*/

#include <bits/stdc++.h>

using namespace std;

/*
The idea here is to count the subarray, 
which has most number of 0s.
So we will use kedane's algorithm, 
while considering each 0 as adding 1 to the sum
and each 1 as adding -1 to the sum
*/
int calc_max_num(vector<int> bits)
{
    int sum = 0;
    int max_sum = INT_MIN;

    //These will store, total number of flip bit count
    //for 0s and 1s
    int count_one = 0;
    int count_zero = 0;
    
    //These will store, flip bit count in current subset
    //for 0s and 1s
    int sub_count_one = 0;
    int sub_count_zero = 0;

    //Total number of 1 in the array
    int total_count = 0;

    for(size_t idx = 0; idx < bits.size(); idx++)
    {
        if(bits[idx] == 0)
        {
            if(sum < 1)
            { 
                /*
                Start a new Subset as the subset before this contains:
                Either same number of 0s and 1s (sum = 0)
                or 
                more number of 1s (sum < 0).
                If the number of 1s are greater than 
                the number of 0s in a subarray, 
                then we should ignore this subarray, 
                as it will add a negative impact.
                */
                sum = 1;
                sub_count_zero = 1;
                sub_count_one = 0;
            }
            else
            {
                sum++;
                sub_count_zero++;
            }
        }
        else //got 1
        {
            sum--;
            sub_count_one++;

            //Count every 1 in the total count
            total_count++;
        }
        
        if(sum > max_sum)
        {
            max_sum = sum;
            count_one = sub_count_one;
            count_zero = sub_count_zero;
        }
    }

    /*
    Total number of 1s = 
                (Total number of 1s in the entire Array) +
                (Bit flip for 0 in the max subarray) -
                (Bit flip for 1 in the min subarray)
    */
    total_count = total_count + count_zero - count_one;

    return total_count;
}

int main()
{
    vector<int> bits = {1, 0, 0, 1, 0};
    cout<<calc_max_num(bits)<<endl;

    return 0;
}

//Time Complexity O(n)