/*
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block 
i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. 

A rat starts from source and has to reach the destination. The rat can move in only two directions: 
first forward if possible or down. If multiple solutions exist, the shortest earliest hop will be 
accepted. For the same hop distance at any point, forward will be preferred over downward.

In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be 
used in the path from source to destination. The non-zero value of mat[i][j] indicates number of 
maximum jumps rat can make from cell mat[i][j].

In this variation, Rat is allowed to jump multiple steps at a time instead of 1.
*/

#include <iostream>
#include <vector>

using namespace std;

bool find_path(vector<vector<int> > maze, vector<vector<int> >& movement, 
                int row, int col, size_t size)
{
    if(row < 0 || row >= size || col < 0 || col >= size)
        return false;

    if(maze[row][col] == 0)
        return false;

    if(movement[row][col])
        return false;

    //mark this cell as visited
    movement[row][col] = 1;
    
    if(row == size - 1 && col == size - 1)
        return true;

    int jump_size = maze[row][col];

    //check all horizontal movements
    for(int jump = 1; jump <= jump_size; jump++)
    {
        if(find_path(maze, movement, row, col - jump, size))
            return true;

        if(find_path(maze, movement, row, col + jump, size))
            return true;
    }

    //check all vertical movements
    for(int jump = 1; jump <= jump_size; jump++)
    {
        if(find_path(maze, movement, row - jump, col, size))
            return true;

        if(find_path(maze, movement, row + jump, col, size))
            return true;
    }    

    movement[row][col] = 0;
    return false;
}

void print_maze(vector< vector<int> > maze)
{
    for(auto row : maze)
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
    size_t size = 4;

    vector< vector<int> > maze = {
        {2, 1, 1, 0},
        {3, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 0, 0, 1}
    };

    vector< vector<int> > movement = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    // visited[0][0] = 1;

    find_path(maze, movement, 0, 0, size);

    print_maze(movement);

    return 0;
}