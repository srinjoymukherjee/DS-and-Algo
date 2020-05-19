/*
Given two sorted matrices mat1 and mat2 of size n x n of distinct elements. 
Given a value x. 
The problem is to count all pairs from both matrices whose sum is equal to x.

Note: The pair has an element from each matrix. 
Matrices are strictly sorted which means that matrices are sorted 
in a way such that all elements in a row are sorted in increasing order 
and for row ‘i’, where 1 <= i <= n-1, first element of row 'i' is 
greater than the last element of row 'i-1'.
*/

#include <bits/stdc++.h>

using namespace std;

int find_pair_sum(vector< vector<int> > mtrx1, vector<vector<int> > mtrx2, int size, int key)
{
    int c1 = 0, c2 = size - 1, r1 = 0, r2 = size - 1, count = 0;

    while(r1 < size && r2 >= 0)
    {
        int val = mtrx1[r1][c1] + mtrx2[r2][c2];

        if(val == key)
        {
            cout<<"Matrix 1:\t"<<mtrx1[r1][c1]<<"\t";
            cout<<"Matrix 2:\t"<<mtrx2[r2][c2]<<endl;
            c1++;
            c2++;
            count++;
        }
        else if(val > key)
        {
            c2--;
        }
        else
        {
            c1++;
        }

        if(c1 >= size)
        {
            r1++;
            c1 = 0;
        }

        if(c2 < 0)
        {
            r2--;
            c2--;
        }
        
    }
    cout<<"Total number of Pairs:\t";
    return count;
}

int main()
{
    int size = 3, key = 21;
    vector< vector<int> > mtrx1 = {
        {1, 5, 6},
        {8, 10, 11},
        {15, 16, 18}
    };

    vector< vector<int> > mtrx2 = {
        {2, 4, 7},
        {9, 10, 12},
        {13, 16, 20} 
    };
    // cout<<"Total number of Pairs:\t";
    cout<<find_pair_sum(mtrx1, mtrx2, size, key)<<endl;
    return 0;
}