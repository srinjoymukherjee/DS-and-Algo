#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int sqrt(int num)
{
    int val = 1;
    if(num == 0 || num == 1)
        return num;

    while(val * val <= num)
    {
        val++;
    }

    return val - 1;
}

bool check_boundary(vector<vector<int> >, size_t, size_t, size_t);

bool check_row_bound(vector<vector<int> >, size_t, size_t);
bool check_col_bound(vector<vector<int> >, size_t, size_t);
bool check_box_bound(vector<vector<int> >, size_t, size_t, size_t);
bool get_next_unassigned(vector<vector<int> >, size_t&, size_t&, size_t);

bool fill_sudoku(vector<vector<int> >& grid, size_t offset = 9)
{
    size_t row = 0;
    size_t col = 0;

    if(!get_next_unassigned(grid, row, col, offset))
    {
        return true;
    }

    for(int val = 1; val <= offset; val++)
    {
        grid[row][col] = val;
        if(check_boundary(grid, offset, row, col))
        {
            if(fill_sudoku(grid, offset))
                return true;
        }
                               
        grid[row][col] = 0;                    
    }

    return false;
            
}
bool get_next_unassigned(vector<vector<int> >grid, size_t& row, 
                         size_t& col, size_t offset)
{
    for(row = 0; row < offset; row++)
    {
        for(col = 0; col < offset; col++)
        {
            if(grid[row][col] == 0)
            {
                return true;
            }
        }
    }

    return false;
}
bool check_boundary(vector<vector<int> > grid, size_t offset, 
                    size_t row, size_t col)
{
    int box_size = sqrt(offset);

    return  check_row_bound(grid, row, offset) &&
            check_col_bound(grid, col, offset) &&
            check_box_bound(grid, row - row % box_size, col - col % box_size, offset);
}

bool check_row_bound(vector<vector<int> > grid, size_t row, size_t col_size)
{
    unordered_set<int> row_hash;

    for(size_t idx = 0; idx < col_size; idx++)
    {
        if(row_hash.find(grid[row][idx]) != row_hash.end())
            return false;

        if(grid[row][idx] > 0)
            row_hash.insert(grid[row][idx]);
    }

    return true;
}

bool check_col_bound(vector<vector<int> > grid, size_t col, size_t row_size)
{
    unordered_set<int> col_hash;

    for(size_t idx = 0; idx < row_size; idx++)
    {
        if(col_hash.find(grid[idx][col]) != col_hash.end())
            return false;
        
        if(grid[idx][col] > 0)
            col_hash.insert(grid[idx][col]);
    }

    return true; 
}

bool check_box_bound(vector<vector<int> > grid, 
                        size_t row_start, size_t col_start, 
                        size_t offset)
{
    unordered_set<int> box_hash;
    size_t row_limit = row_start + sqrt(offset);
    size_t col_limit = col_start + sqrt(offset);

    for(size_t row = row_start; row < row_limit; row++)
    {
        for(size_t col = col_start; col < col_limit; col++)
        {
            if(box_hash.find(grid[row][col]) != box_hash.end())
            {
                return false;
            }
            
            if(grid[row][col] > 0)
                box_hash.insert(grid[row][col]);
        }
    }

    return true;
}

void print_grid(vector< vector<int> > grid)
{
    for(auto row : grid)
    {
        for(auto col : row)
        {
            cout<<col<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int> > grid = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if(fill_sudoku(grid))
    {
        print_grid(grid);
    }
    else
    {
        cout<<"Sudoku Invalid"<<endl;
    }
    

    return 0;
}