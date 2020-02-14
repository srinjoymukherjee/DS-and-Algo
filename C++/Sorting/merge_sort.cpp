#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>&, size_t, size_t, size_t);
void merge_sort(vector<int>&, size_t, size_t);

int main(){
    vector<int> inp = {5,7,2,31,25,100,4,1};
    merge_sort(inp, 0, inp.size() - 1);
    for(auto val: inp){
        cout<<val<<", ";
    }
    cout<<endl;
    return 0;
}

void merge_sort(vector<int> &vect, size_t low, size_t high)
{
    if(low < high){
        size_t mid = (low + high)/2;
        merge_sort(vect, low, mid);
        merge_sort(vect, mid+1, high);
        merge(vect, low, mid, high);
    }    
}

void merge(vector<int> &vect, size_t low, size_t mid, size_t high){
    vector<int> v1;
    vector<int> v2;
    
    for(size_t idx = low; idx <= mid; idx++){
        v1.push_back(vect[idx]);
    }

    for(size_t idx = mid + 1; idx <= high; idx++){
        v2.push_back(vect[idx]);
    }

    size_t k = low, i = 0, j = 0;

    while(i < v1.size() && j < v2.size())
    {
        if(v1[i] < v2[j]){
            vect[k++] = v1[i++];
        }
        else
        {
            vect[k++] = v2[j++];
        }
        
    }

    while(i < v1.size())
    {
        vect[k++] = v1[i++];
    }

    while(j < v2.size())
    {
        vect[k++] = v2[j++];
    }

    return;

}
