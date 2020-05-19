/*
Given a boolean 2D array, where each row is sorted. 
Find the row with the maximum number of 1s.
*/

//Hint: The time complexity of below approach will be O(row + col)

#include <bits/stdc++.h>

using namespace std;

int calc_max_one_row(vector<vector<int> > mtrx, int row, int col)
{
    int off_col = -1;
    int offset = -1;
    int off_row = -1;
    
    // Get the position just before the first 1 in the first row
    for(int c = 0; c < col; c++)
    {
        if(mtrx[0][c] == 1)
        {
            off_col = c - 1;
            off_row = 0;
            break;
        }
    }
    offset = off_col;

    for(size_t r = 1; r < row; r++)
    {
        // Check whether this row has an one before the current offset col
        if(mtrx[r][offset] == 1)
        {
            for(int c = offset; c >= 0; c--)
            {
                if(mtrx[r][c] == 0)
                {
                    break;
                }

                off_col = c - 1;
            }
            off_row = r;
        }

        // If we have already reached the Starting position
        // then no need to check anymore, this is the row
        if(off_col == -1)
            break;

        // Set current offset
        offset = off_col;
    }

    return off_row;
}

int main()
{
    int row = 4, col = 4;
    vector<vector<int> > mtrx = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    cout<<calc_max_one_row(mtrx, row, col);
    cout<<endl;

    return 0;
}