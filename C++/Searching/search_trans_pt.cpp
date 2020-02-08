/*
You are given a sorted array containing only numbers 0 and 1. 
Find the transition point efficiently. 
Transition point is a point where "0" ends and "1" begins.
*/

#include <bits/stdc++.h>

using namespace std;

int search_trans_pt(vector<int>, size_t, size_t);

int main(){
    vector<int> vect = {0, 1, 1, 1, 1, 1};
    cout<<"Transition Point is: "<<search_trans_pt(vect, 0, vect.size());
    return 0;
}

int search_trans_pt(vector<int> vect, size_t low, size_t high){
    size_t mid = (low + high)/2;
    int val = -1;

    if(low > high){
        return val;
    }
    else if(low == high){
        if(vect[low] == 0 && vect[low + 1] == 1){
            return low;
        }
        else 
            return val;
    }

    if(vect[mid] == 0){
        if(mid < vect.size() - 1 && vect[mid + 1] == 1){
            return mid;
        } 
        else{
            val = search_trans_pt(vect, mid, high);
        }
    }
    else{
        if(mid > 0 && vect[mid - 1] == 0){
            return mid - 1;
        }
        else{
            val = search_trans_pt(vect, low, mid);
        }
    }
    
    return val;
}