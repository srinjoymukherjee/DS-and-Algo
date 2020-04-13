/*
Stickler the thief wants to loot money from a society having n houses in a single line. 
He is a weird person and follows a certain rule when looting the houses.
According to the rule, he will never loot two consecutive houses. 
At the same time, he wants to maximize the amount he loots. 
The thief knows which house has what amount of money 
but is unable to come up with an optimal looting strategy. 
 
He asks for your help to find the maximum money he can get 
if he strictly follows the rule. 
Each house has a[i] amount of money present in it.
*/

#include <bits/stdc++.h>

using namespace std;

/*
Profit at any Index is equals to 
Maximum of,
    Max Profit up to adjacent last index 
                    and 
    Current Cost + Max profit up to adjacent second last index
*/
int calcMaxProfit(vector<int> house)
{
    int idx = 2;
    vector<int> profit(house.size());
    //Storing the highest value available up to index 0
    profit[0] = house[0];

    //Storing the highest value available up to index 1
    profit[1] = max(house[0], house[1]);

    for(;idx < house.size(); idx++)
    {
       //Storing the highest value available up to index 'idx'
        profit[idx] = max(profit[idx - 1], profit[idx - 2] + house[idx]);

        /*
        profit[idx]     => Highest Profit at index 'idx'
        profit[idx - 1] => Profit upto adjacent last Index ('idx - 1')
        profit[idx - 2] => Profit Upto adjacent second last index ('idx - 2')
        */
    }

    return profit[idx - 1];
}

int main()
{
    vector<int> house = {3,2,7,10,5,1,13,15};
    cout<<"Max Profit:\t";
    cout<<calcMaxProfit(house)<<endl;
    return 0; 
}