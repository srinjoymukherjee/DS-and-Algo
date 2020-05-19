/*
We are given a row wise sorted matrix of size r*c, 
we need to find the median of the matrix given. 
It is assumed that r*c is always odd.
*/

#include <bits/stdc++.h>

using namespace std;

int find_median(vector<vector<int> > ip_matrix, int row, int col)
{
    //As we are using upper bound, '+ 1' is required
    int ideal = (row * col + 1) / 2;
    int min_val = INT_MAX;
    int max_val = 0;
    int mid = 0;

    for(size_t r = 0; r < row; r++)
    {
        min_val = min(ip_matrix[r][0], min_val);
        max_val = max(ip_matrix[r][col - 1], max_val);
    }

    while(min_val < max_val)
    {
        int min_count = 0;
        mid = (max_val + min_val) / 2;

        for(size_t r = 0; r < row; r++)
        {
            min_count += (upper_bound(ip_matrix[r].begin(), 
                            ip_matrix[r].end(), mid) 
                            - ip_matrix[r].begin());
        }

        if(min_count >= ideal)
            max_val = mid;
        else
        {
            min_val = mid + 1;
        }
        
    }
    return min_val;
}

int main()
{
    vector<vector<int> > ip_matrix = {
        {3, 5, 9},
        {1, 2, 5},
        {4, 5, 8}
    };

    int row = 3, col = 3;

    cout<<find_median(ip_matrix, row, col)<<endl;

    return 0;
}