/*
There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top
*/

#include <bits/stdc++.h>

using namespace std;

int calcWays(int num = 1)
{
    vector<int> ways(num + 1);
    ways[0] = 1; //Fib[1] -- to adjust ways[2] values
    ways[1] = 1; //Fib[2] -- ways[1] is actualy 1 only
    
    for(size_t idx = 2; idx <= num; idx++)
        ways[idx] = ways[idx - 1] + ways[idx - 2];

    return *(ways.rbegin());
}

int main()
{
    int num_of_stairs = 6;
    cout<<calcWays(num_of_stairs)<<endl;
    return 0;
}