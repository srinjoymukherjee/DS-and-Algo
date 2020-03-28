/*
How to find the largest number with given digit sum s and number of digits d?
*/

#include <iostream>
#include <sstream>

using namespace std;

string find_largest_num(long sum, int digit)
{
    int num = 9;
    string retVal;
    stringstream num_stream;

    while(digit--)
    {
        num++;
        while(num--)
        {
            if(sum >= num)
            {
                num_stream << num;
                sum -= num;
                break;
            }
        }
    }
    num_stream >> retVal;
    return retVal;
}

int main()
{
    long sum = 0;
    int digit = 0;

    sum = 9;
    digit = 5;
    cout<<find_largest_num(sum, digit)<<endl;

    return 0;
}