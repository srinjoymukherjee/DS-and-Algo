/*
Given a positive integer N, print count of set bits in it. 
For example, if the given number is 6(binary: 110), 
output should be 2 as there are two set bits in it.
*/

#include <iostream>

using namespace std;

int count_set_bit(int num)
{
    int count = 0;

    while(num)
    {
        num = (num & (num - 1));
        count++;
    }

    return count;
}

int main()
{
    int num = 15;

    cout<<"The number of 1's in "<<num<<" is ";
    cout<<count_set_bit(num)<<endl;

    return 0;
}
