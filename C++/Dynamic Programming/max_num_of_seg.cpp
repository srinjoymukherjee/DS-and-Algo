/*
Given a rod of length L, the task is to cut the rod in such a way 
that the total number of segments of length p, q and r is maximized. 

The segments can only be of length p, q, and r.
*/

#include <bits/stdc++.h>

using namespace std;

int calcMaxSeg(int len, vector<int> pieces)
{
    int row = 1, col = 0, temp = -1;
    vector<vector<int> > cluster(pieces.size() + 1, vector<int>(len + 1, -1));
    cluster[0][0] = 0;

    //Prepare the cluster table
    //Every column in the table is 
    //a possible length of any single 
    //or collection of pieces
    //7 = (2 * 2) + (1 * 3) => 3 clusters
    //2 => this length is not possible if any of the pieces
    // is equal to or less than 2
    for(row = 1; row <= pieces.size(); row++)
    {
        for(col = 0; col <= len; col++)
        {
            //
            if(col != 0 && //Check if Col is Non zero
                col >= pieces[row] && 
                //Check whether this length is possible
                cluster[row][col - pieces[row]] != -1)
            {
                cluster[row][col] = max(cluster[row - 1][col], 
                                        1 + cluster[row][col - pieces[row]]);
            }
            else
            {
                cluster[row][col] =  cluster[row - 1][col];
            }
            
            temp = cluster[row][col];
        }
    }

    return cluster[row - 1][col - 1];
}

int main()
{
    int num = 9;
    vector<int> pieces;
    pieces.push_back(0);
    pieces.push_back(2);
    pieces.push_back(3);
    pieces.push_back(5);

    cout<<calcMaxSeg(num, pieces)<<endl;
    return 0;
}