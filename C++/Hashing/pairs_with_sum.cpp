#include <bits/stdc++.h>

using namespace std;

int pair_with_sum(vector<int>, int);

int main()
{
    vector<int> inp = {5,11,10,2,7,3};
    int key = 9;
    cout<<pair_with_sum(inp, key)<<endl;
    return 0;
}

int pair_with_sum(vector<int> vect, int key)
{
    unordered_set<int> s;
    int count = 0;
    for(auto val : vect)
    {
        if(s.find(key - val) != s.end())
        {
            count++;
        }
        
        s.insert(val);      
    }
    return count;
}