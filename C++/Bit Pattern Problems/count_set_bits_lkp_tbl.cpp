/*
count all the set bits of a number using lookup table
*/

#include <bits/stdc++.h>

#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)

using namespace std;

unsigned int count_set_bit(unsigned int num)
{
    int lookuptable[256] = {B6(0), B6(1), B6(1), B6(2)};

    int count_bits = lookuptable[num & 0xff] +
                        lookuptable[(num >> 8) & 0xff] +
                        lookuptable[(num >> 16) & 0xff] +
                        lookuptable[(num >> 24) & 0xff];

    return count_bits;
}

int main()
{
    cout<<count_set_bit(12456)<<endl;
    return 0;
}