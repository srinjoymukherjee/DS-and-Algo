/*
You are given an array A[] of size N. 
Now, we call the value of an array the bit-wise XOR of all elements it contains. 
For example, the value of the array [1,2,3] = 1^2^3. 
Now, Your task is to find the bit-wise XOR of the values of all sub arrays of array A. 

Example:

Input: A[] = {1,2,3} 
Output: 2
xor[1] = 1, 
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result : 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
*/

#include <bits/stdc++.h>

using namespace std;

//Solution with Time Complexity O(n)
int get_sub_arr_xor(vector<int> num_list)
{
    int size = num_list.size();
    int xor_val = 0;
    int cur_val = 0;

    //If size is even, then XOR value will always be 0
    if((size & 1) == 0)
    {
        return 0;
    }

    // The value at ith position will be repeated for:
    // (size - idx) * (idx + 1)
    for(size_t idx = 0; idx < size; idx++)
    {
        cur_val = (size - idx) * (idx + 1) % 2 != 0 ? cur_val : 0;
        xor_val ^= cur_val;
    }

    return xor_val;
}

//Solution with Time Complexity O(n/2)

/*
Case 1: i is odd, N is odd
Let i = 2k+1, N = 2m+1
freq[i] = ((2k+1)+1)*((2m+1)-(2k+1)) = 4(m-k)(k+1) = even

Case 2: i is odd, N is even
Let i = 2k+1, N = 2m
freq[i] = ((2k+1)+1)*((2m)-(2k+1)) = 2(k+1)(2m-2k-1) = even

Case 3: i is even, N is odd
Let i = 2k, N = 2m+1
freq[i] = ((2k)+1)*((2m+1)-(2k)) = 2k(2m-2k+1)+(2m-2k)+1 = odd

Case 4: i is even, N is even
Let i = 2k, N = 2m
freq[i] = ((2k)+1)*((2m)-(2k)) = 2(m-k)(2k+1) = even
*/
int get_sub_arr_xor_1(vector<int> num_list)
{
    int size = num_list.size();
    int xor_val = 0;
    // int cur_val = 0;

    //If size is even, then XOR value will always be 0
    if((size & 1) == 0)
    {
        return 0;
    }

    // Capture only when size is odd and idx is even
    for(size_t idx = 0; idx < size; idx += 2)
    {
        xor_val ^= num_list[idx];
    }

    return xor_val;
}

int main()
{
    vector<int> num_rail = {1, 2, 3};
    cout<<get_sub_arr_xor_1(num_rail)<<endl;
    return 0;
}