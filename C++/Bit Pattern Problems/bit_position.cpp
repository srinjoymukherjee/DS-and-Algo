/*
Given a number having only one ‘1’ and all other ’0’s in its binary representation, 
find position of the only set bit. If there is only one '1' bit 
then print that position else print -1. 
Position of  set bit '1' should be counted starting with 1 from LSB side 
in binary representation of the number.
*/

#include <bits/stdc++.h>

using namespace std;

int log2n(int num)
{
    return (num > 1) ? 1 + log2n(num / 2) : 0;
}

bool isPow2(int x)
{
    return !(x & (x - 1));
}

int bit_position(int num)
{
    if(!isPow2(num))
    {
        return 0;
    }

    return log2n(num);
}

int main()
{
    int num = 1022;
    int bit_pos = bit_position(num);

    if(!bit_pos)
    {
        cout<<"Not power of 2";
    }
    else
    {
        cout<<"Bit Position:\t"<<bit_pos;
    }

    return 0;    
}