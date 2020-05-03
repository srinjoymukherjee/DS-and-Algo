/*
Given a string of length n, print all the possible subsets 
of the string in a lexiographically-sorted order
*/
#include <bits/stdc++.h>

using namespace std;

void power_set(vector<char> list_str, int pos_size)
{
    long power_set_size = pow(2, pos_size);
    
    for(size_t idx = 1; idx < power_set_size; idx++)
    {
        int mask = 1;
        for(size_t pos = 0; pos < pos_size; pos++)
        {
            if((idx & mask) != 0)
                cout<<list_str[pos];            
            
            mask = mask << 1;
        }
        cout<<endl;
    }    
}

vector<char> list_from_str(string str)
{
    vector<char> list_str(str.begin(), str.end());
    sort(list_str.begin(), list_str.end(), greater<char>());
    return list_str;
}

int main()
{
    string str = "bgacthd";
    auto list_str = list_from_str(str);
    power_set(list_str, list_str.size());
    return 0;
}