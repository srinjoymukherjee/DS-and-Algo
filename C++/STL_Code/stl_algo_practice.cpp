#include<bits/stdc++.h>

using namespace std;

void print_vect(vector<int> vect){
    for(auto val : vect)
        cout<<val<<" ";
    
    cout<<endl;
}

int main()
{
    vector<int> v1 = {5,2,18,1,6};
    vector<int> v2 = v1;

    cout<<"Before sorting: ";
    print_vect(v1);
    sort(v1.begin(), v1.end());
    cout<<"After sorting: ";
    print_vect(v1);

    reverse(v2.begin(), v2.end());
    cout<<"After reversing: ";
    print_vect(v2);

    cout<<"Accumulation: ";
    cout<<accumulate(v1.begin(), v1.end(), 0)<<endl;

    cout<<"Max Element: ";
    cout<<*max_element(v2.begin(), v2.end())<<endl;

    cout<<"Min Element: ";
    cout<<*min_element(v2.begin(), v2.end())<<endl;

    v2.erase(v2.begin());
    print_vect(v2);

    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(50);
    pq1.push(14);
    pq1.push(20);
    pq1.push(30);
    pq1.push(11);
    pq1.push(5);
    pq1.push(40);
    pq1.push(31);

    size_t pq_size = pq1.size();

    while(pq_size--)
    {
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<endl;

    set<int, greater<int>> set1;
    set1.insert(45);
    set1.insert(11);
    set1.insert(63);
    set1.insert(2);
    set1.insert(8);
    set1.insert(23);
    set1.insert(25);
    set1.insert(32);
    set1.insert(6);
    set1.insert(49);

    for(auto val : set1)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    map<int,int> mp;

    mp.insert({10,15});
    mp.insert({15,20});
    mp.insert({10,29});

    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }

    cout<<mp[10]<<endl;
    
    return 0;
}