#include<bits/stdc++.h>

using namespace std;

size_t partition(vector<int>&, size_t, size_t);
void quicksort(vector<int>&, size_t, size_t);

void swap_int(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    vector<int> inp = {5,7,20,15,25,100,4,1};
    quicksort(inp, 0, inp.size() - 1);

    for(auto val: inp){
        cout<<val<<", ";
    }
    cout<<endl;
    return 0;
}

void quicksort(vector<int> &vect, size_t low, size_t high)
{
    if(low < high){
        size_t part = partition(vect, low, high);
        
        if(part > low)
            quicksort(vect, low, part - 1);

        if(part < high)
            quicksort(vect, part + 1, high);
    }
    return;
}

size_t partition(vector<int> &vect, size_t low, size_t high)
{
    size_t part = (low + high)/2;
    int pivot = vect[part];

    while(low <= high){
        while(vect[low] <= pivot && low <= high){
            low++;
        }
        while(vect[high] >= pivot && high >= low){
            high--;
        }
        if(low < high){
            if(vect[low] > vect[high]){
                swap_int(vect[low++], vect[high--]);
            }
        }        
    }
    if(part != high)
        swap_int(vect[part], vect[high]);

    return high;
}