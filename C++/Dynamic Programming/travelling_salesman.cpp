/*
In a directed graph, all vertices are connected to each other.
we need to define minimum travel cost for a circular path,
covering all vertices from a particular source and finished 
at the same vertex.
*/

#include <bits/stdc++.h>

#define INF INT_MAX/2

using namespace std;

int calcCost(vector<vector<int> > cost_table, set<int> l_vertex, int src, int final)
{
    int cost = INF;

    for(auto v : l_vertex)
    {
        set<int> temp_table(l_vertex.begin(), l_vertex.end());
        temp_table.erase(v);

        if(!temp_table.empty())
        {
            cost = min(cost, cost_table[src][v] + 
                        calcCost(cost_table, temp_table, v, final));
            temp_table.clear();
        }
        else
            cost = min(cost, cost_table[src][v] + 
                                cost_table[v][final]);       
    }

    return cost;
}

int main()
{
    int src = 1;
    set<int> l_vertex;
    int v = 1;

    vector<vector<int> > cost_table{
            {0, 0, 0, 0, 0},
            {0, 0, 10, 15, 20},
            {0, 5, 0 , 9, 10},
            {0, 6, 13, 0, 12},
            {0, 8, 8, 9, 0}
    };    

    while(++v <= 4)
        l_vertex.insert(v);

    cout<<calcCost(cost_table, l_vertex, src, src)<<endl;

    return 0;
}