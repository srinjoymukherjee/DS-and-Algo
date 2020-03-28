/*
You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time.
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

string activity_selection(multimap<int, int> activity)
{
    vector<pair<int,int> > ret_list;
    string ret;
    int prev = -1;
    stringstream ss;
    // int index = 0;
    for(auto act = activity.begin(); act != activity.end(); act++)
    {
        auto val = *act;

        if(act->second > prev)
        {
            ss << "{" << val.second << "," << val.first << "} ";            
            prev = act->first;
        }
    }
    ret = ss.str();
    return ret;
}

int main()
{
    multimap<int,int> activity;

    activity.insert({9,8});
    activity.insert({9,5});
    activity.insert({6,0});
    activity.insert({7,5});
    activity.insert({4,3});
    activity.insert({2,1});
    // activity.insert({9,8});
    // activity.insert({9,8});

    cout<<"Task to be done: \n"<<activity_selection(activity);
    return 0;
}