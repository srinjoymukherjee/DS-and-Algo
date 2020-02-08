/*
Given three increasingly sorted arrays 
A, B, C of sizes N1, N2, and N3 respectively, 
you need to print all common elements in these arrays.
*/

#include<bits/stdc++.h>

using namespace std;

void common_element_in_three_sorted(vector<int>, vector<int>, vector<int>);

int main(){
    vector<int> v1 = {1, 5, 10, 20, 40, 80};
    vector<int> v2 = {6, 7, 20, 80, 100};
    vector<int> v3 = {3, 4, 15, 20, 30, 70, 80, 120};
    common_element_in_three_sorted(v1, v2, v3);
    cout<<endl;
}

void common_element_in_three_sorted(
        vector<int> v1, vector<int> v2, vector<int> v3) 
{
    size_t i = 0, j = 0, k = 0;

    while(i < v1.size() && j < v2.size() && k < v3.size())
    {
        if(v1[i] == v2[j] && v2[j] == v3[k] && v3[k] == v1[i])
        {
            cout<<v1[i]<<", ";
            i++;
            j++;
            k++;
        }

        if(v1[i] < v2[j] || v1[i] < v3[k])
            i++;

        if(v2[j] < v1[i] || v2[j] < v3[k])
            j++;

        if(v3[k] < v2[j] || v3[k] < v1[i])
            k++;
    }
    
}