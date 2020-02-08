/*
Given an array of integers. Find a peak element in it. 
An array element is peak if it is NOT smaller than its neighbors. 
For corner elements, we need to consider only one neighbor. 

For example, for input array {5, 10, 20, 15}, 
20 is the only peak element. 
For input array {10, 20, 15, 2, 23, 90, 67}, 
there are two peak elements: 20 and 90. 

Note that we need to return any one peak elements.
*/

#include <bits/stdc++.h>

using namespace std;

int find_peak_element(vector<int>, size_t, size_t);

int main(){
    vector<int> vect = {2,3,10,5,7,11,15,12,20};
    cout<<"Peak element: "<<endl;
    cout<<find_peak_element(vect, 0, vect.size());
    return 0;
}

int find_peak_element(vector<int> vect, size_t low, size_t high){
    size_t mid = (low + high)/2;
    int peak = INT_MIN;

    if(low > high || vect.size() < 1){
        return peak;
    }
    else {
        if(mid > 0 && mid < vect.size()){
            if((vect[mid] > vect[mid - 1]) 
                && (vect[mid] > vect[mid + 1]))
                peak = vect[mid];
            if(vect[mid] <= vect[mid - 1] && peak == INT_MIN)
                peak = find_peak_element(vect, low, mid);
            if(vect[mid] <= vect[mid + 1] && peak == INT_MIN)
                peak = find_peak_element(vect, mid, high);
        }
        else if(mid == 0 && vect[mid] > vect[mid + 1])
        {
            peak = vect[mid];
        }
        else if(mid == vect.size() - 1 && vect[mid] > vect[mid - 1])
        {
            peak = vect[mid];
        }

        return peak;        
    }
}