#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>, pair<int, int>);
int fill_up_knapsack(vector< pair<int, int> >, int);

int main(){
    try
    {
        vector< pair<int, int> > items;
        items.push_back({60,10});
        items.push_back({100,20});
        items.push_back({120,30});
        
        int total_weight = 50;
        int total_cost = fill_up_knapsack(items, total_weight);
        cout<<total_cost<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}

int fill_up_knapsack(vector< pair<int, int> > items, int total_weight)
{
    sort(items.begin(), items.end(), cmp);
    int cur_weight = total_weight;
    int cost = 0;
    for(auto item : items){
        if(cur_weight - item.second >= 0)
        {
            cur_weight -= item.second;
            cost += item.first;
        }
        else
        {
            cost += ( (double)item.first / (double)item.second ) * cur_weight;
        }        
    }

    return cost;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    int f1 = a.first/a.second;
    int f2 = b.first/b.second;
    return f1>f2;
}
