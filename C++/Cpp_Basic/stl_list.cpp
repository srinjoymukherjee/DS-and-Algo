#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<int> new_list(5,1);
    
    auto it = new_list.begin();

    advance(it,3);
    *it = 5;

    auto itr = max_element(new_list.begin(), new_list.end());
    cout<<*itr<<endl;

    for(auto val : new_list)
    {
        cout<<val<<"\t";
    }
    cout<<endl;
    new_list.sort();

    for(auto val : new_list)
    {
        cout<<val<<"\t";
    }
    cout<<endl;


    return 0;
}