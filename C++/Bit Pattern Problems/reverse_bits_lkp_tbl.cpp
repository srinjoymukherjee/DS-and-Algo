/*
Reverse all the bits of a 32 bit string and print the decimal 
equivalent of the same
*/

//Using lookup table. Time complexity O(1)

#include <bits/stdc++.h>

#define R2(n) n, n + (2 * 64), n + (1 * 64), n + (3 * 64)
#define R4(n) R2(n), R2(n + (2 * 16)), R2(n + (1 * 16)), R2(n + (3 * 16))
#define R6(n) R4(n), R4(n + (2 * 4)), R4(n + (1 * 4)), R4(n + (3 * 4))

using namespace std;

unsigned int reverse_bit(unsigned int num)
{
    int look_up_tbl[256] = {R6(0), R6(2), R6(1), R6(3)};

    unsigned int reverse_bit = look_up_tbl[num & 0xFF] << 24 |
                        look_up_tbl[(num >> 8) & 0xff] << 16 |
                        look_up_tbl[(num >> 16) & 0xff] << 8 |
                        look_up_tbl[(num >> 24) & 0xff];
    
    return reverse_bit;
}

int main()
{
    cout<<reverse_bit(12456)<<endl;
    return 0;
}