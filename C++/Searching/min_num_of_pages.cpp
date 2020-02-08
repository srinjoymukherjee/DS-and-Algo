// C++ program for optimal allocation of pages 
#include<bits/stdc++.h> 
using namespace std; 

int search_max_page_sum(vector<int>, size_t, size_t, int);
bool isValid(vector<int>, int, int);

int main(){
    vector<int> vect = {10, 15, 20, 50, 60, 80};
    int sum = 0;
    int num_of_students = 3;
    for(auto val : vect)
        sum += val;

    cout<<search_max_page_sum(vect, vect[vect.size() - 1], sum, num_of_students);
    return 0;
}

int search_max_page_sum(vector<int> vect, size_t low, size_t high, int num_of_students){
    int mid = (low + high)/2;
    int val = INT_MAX;

    if(low > high){
        return val;
    }
    
    if(isValid(vect, mid, num_of_students)){
        val = min(mid, search_max_page_sum(vect, low, mid - 1, num_of_students));
    }
    else{
        val = search_max_page_sum(vect, mid + 1, high, num_of_students);
    }
    return val;
}

bool isValid(vector<int> vect, int max_sum, int num_of_students){
    int sum = 0;
    size_t local_num_of_students = 1;

    for(size_t idx = 0; idx < vect.size(); idx++){
        if(vect[idx] > max_sum)
            return false;

        if(sum + vect[idx] > max_sum){

            if(++local_num_of_students > num_of_students){
                return false;
            }
            sum = vect[idx];
        }
        else{
            sum += vect[idx];
        }
    }
    return true;
}