/*
A top secret message containing letters from A-Z is being encoded 
to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You have to determine the total number of ways that message can be decoded.
Note: An empty digit sequence is considered to have one decoding. 
It may be assumed that the input contains valid digits 
from 0 to 9 and If there are leading 0’s, extra trailing 0’s 
and two or more consecutive 0’s then it is an invalid string.

Example :
Given encoded message "123",  it could be decoded as "ABC" (1 2 3) or "LC" (12 3) or "AW"(1 23).
So total ways are 3.
*/

#include <bits/stdc++.h>

using namespace std;

int getSeq(string ipStr)
{
    int count = 1;

    if(ipStr[0] == '0')
        return 0;

    for(size_t idx = 1; idx < ipStr.size(); idx++)
    {
        if(ipStr[idx - 1] == '0' && ipStr[idx] == '0')
            return 0;
        
        if(ipStr[idx] == '0')
            continue;

        //If the previous and new charecter creates a valid Sequence
        //then one extra combination will be added
        if(int(ipStr[idx - 1] - '0') > 0 &&
            int(ipStr[idx - 1] - '0') <= 2 &&
            int(ipStr[idx] - '0') <= 6)
        {
            count++;
        }            
    }
    return count;
}

int main()
{
    string ipStr = "1224523";
    cout<<getSeq(ipStr)<<endl;

    return 0;
}