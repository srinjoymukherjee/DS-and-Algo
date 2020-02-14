/*
Given two arrays A1[] and A2[], 
sort A1 in such a way that the relative order 
among the elements will be same as those are in A2. 
For the elements not present in A2, 
append them at last in sorted order.
*/

#include <bits/stdc++.h>

using namespace std;

void relative_sorting(vector<int>&, vector<int>);

int main(){
    vector<int> A1 = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    vector<int> A2 = {2, 1, 6, 3};
    relative_sorting(A1, A2);
    for(auto val : A1){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}

void relative_sorting(vector<int>& v1, vector<int> v2){
    unordered_map<int, int> count;
    map<int, bool> visited;

    for(auto val:v1){
        //If element is already present in Map
        //then increase the count
        if(count.find(val) != count.end())
        {
            count[val]++;
        }
        else //If the element is not present, insert it
        {
            count.insert({val,1});
            visited.insert({val,false});
        }
    }
    size_t idx = 0;

    //All the elements, present in v2,
    //will be stored into v1 in the same order,
    //as they are in v2
    for(auto val : v2){
        if(count.find(val) != count.end()){
            int val_count = count[val];
            while(val_count--){
                v1[idx++] = val;
            }
            visited[val] = true;
        }        
    }

    //store rest of the elements back in v1,
    //in a sorted order
    for(auto val = visited.begin(); val != visited.end(); val++){
        if(!val->second){
            int val_count = count[val->first];
            while(val_count--){
                v1[idx++] = val->first;
            }
            val->second = true; 
        }
    }
}