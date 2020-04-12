/*
A knapsack, which has to be filled up with elemenst
from a list.

Element shall be taken either full or null.

Fractional selection is not allowed
*/

#include <bits/stdc++.h>

using namespace std;

int prep_knapsack(vector<int> profit, vector<int> weight, int w_max)
{
    size_t row = 0, col = 0;
    vector<vector<int> > knapsack(weight.size(), vector<int>(w_max + 1, 0));

    for(row = 0; row < weight.size(); row++)
    {
        for(col = 0; col <= w_max; col++)
        {
            if(row == 0 || col == 0)
            {
                knapsack[row][col] = 0;
            }
            else if(col >= weight[row])
            {
                knapsack[row][col] = max(knapsack[row - 1][col], 
                                        (profit[row] + knapsack[row - 1][col - weight[row]]));
            }
            else
            {
                knapsack[row][col] = knapsack[row - 1][col];
            }            
        }
    }

    return knapsack[--row][--col];
}

int main()
{
    vector<int> profit = {0, 3, 8, 7, 10};
    vector<int> weight = {0, 2, 1, 5, 4};
    int w_max = 8;

    cout<<prep_knapsack(profit, weight, w_max)<<endl;
}