/*
Reverse all the bits of a 32 bit string and print the decimal 
equivalent of the same
*/

//Using shifting method

#include <bits/stdc++.h>

#define NUM_OF_BITS() sizeof(int) * 8;

using namespace std;

unsigned int reverse_bit(unsigned int num)
{
    unsigned int reverse_num = 0;

    //Total number of shifts required 
    //will be one less than the overall count
    size_t count = NUM_OF_BITS();
    count--;
    
    while(num)
    {
        reverse_num |= (num & 1);

        //Count number of shifts
        count--;

        //Shift 'num' to right, to get the next Bit
        num >>= 1;

        //Shift 'reverse_num' to left, 
        //to preserve the stored bit
        reverse_num <<= 1;
    }

    //Overall we need to do shift for NUM_OF_BITS time
    //so, after the loop, if 'count' is not 0,
    //shift reverse_num to left for count times
    reverse_num <<= count;

    return reverse_num;
}

int main()
{
    cout<<reverse_bit(12456)<<endl;
    return 0;
}