/*
Given a value N, find the number of ways to make change for N cents, 
if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. 
The order of coins doesn’t matter. 

For example, for N = 4 and S = {1,2,3}, 
there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. 

For N = 10 and S = {2, 5, 3, 6}, 
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.
*/
#include <bits/stdc++.h>

using namespace std;

int max_coin_change(vector<int> coins, int cent)
{
    int row, col;

    sort(coins.begin(), coins.end());
    coins.erase(unique(coins.begin(), coins.end()), coins.end());
    
    size_t row_num = coins.size();
    vector<vector<int> > result(row_num + 1, vector<int>(cent + 1, 0));

    result[0][0] = 1;

    for(row = 0; row <= row_num; row++)
    {
        for(col = 0; col <= cent; col++)
        {
            if(row > 0 && col >= coins[row - 1])
            {
                //If we plot this problem in Tabular form, 
                //we can get this equation
                result[row][col] = result[row - 1][col] +
                                    result[row][col - coins[row - 1]];
            }
            else if(row > 0)
            {
                result[row][col] = result[row - 1][col];
            }
            //To print the table
            // cout<<result[row][col]<<"\t";            
        }
        // cout<<endl;
    }
    return result[row - 1][col - 1];
}

int main()
{
    vector<int> ip_arr = {2,2,5,5,5,5,3,3,3,5,6};
    int num = 10;
    cout<<max_coin_change(ip_arr, num)<<endl;
}