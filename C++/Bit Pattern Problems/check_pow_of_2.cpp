/*
Given a positive integer N.
The task is to check if N is a power of 2.
That is N is 2x for some x.
*/

#include <bits/stdc++.h>

using namespace std;

bool check_num(int num)
{
    return !(num & (num - 1));
}

int main()
{
    int num = 9;
    if(check_num(num))
        cout<<"True"<<endl;
    else 
        cout<<"False"<<endl;

    return 0;
}