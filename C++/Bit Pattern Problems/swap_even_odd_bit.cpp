/*
Given an unsigned integer N. The task is to swap all odd bits with even bits. 
For example, if the given number is 23 (00010111), it should be converted to 43(00101011). 
Here, every even position bit is swapped with adjacent bit on right side
(even position bits are highlighted in binary representation of 23), 
and every odd position bit is swapped with adjacent on left side.
*/

#include <bits/stdc++.h>

using namespace std;

int swap_bits(int num)
{
    int even_bit_mask = 0xAAAAAAAA;
    int odd_bit_mask = 0x55555555;

    int even_bit_num = num & even_bit_mask;
    int odd_bit_num = num & odd_bit_mask;

    even_bit_num >>= 1;
    odd_bit_num <<= 1;
    /*
    bitset<32> ret_bit(even_bit_num | odd_bit_num);
    cout<<ret_bit<<endl;
    */
   
    return (even_bit_num | odd_bit_num);
}

int main()
{
    int num = 23;
    cout<<swap_bits(num)<<endl;
    return 0;
}