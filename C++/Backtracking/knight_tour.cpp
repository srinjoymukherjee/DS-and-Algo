#include <iostream>
#include <vector>

using namespace std;

void knight_tour(vector<vector<int> >& tour, 
                 vector<vector<bool> >& visited,
                 size_t row, size_t col, size_t& move,
                 size_t row_idx = 0, size_t col_idx = 0)
{
    if(row_idx < 0 || row_idx >= row ||
        col_idx < 0 || col_idx >= col)
        return;

    if(visited[row_idx][col_idx])
        return;

    visited[row_idx][col_idx] = true;
    tour[row_idx][col_idx] = move++;

    knight_tour(tour, visited, row, col, move, row_idx + 1, col_idx + 2);
    knight_tour(tour, visited, row, col, move, row_idx + 1, col_idx - 2);
    knight_tour(tour, visited, row, col, move, row_idx - 1, col_idx + 2);
    knight_tour(tour, visited, row, col, move, row_idx - 1, col_idx - 2);

    knight_tour(tour, visited, row, col, move, row_idx + 2, col_idx + 1);
    knight_tour(tour, visited, row, col, move, row_idx + 2, col_idx - 1);
    knight_tour(tour, visited, row, col, move, row_idx - 2, col_idx + 1);
    knight_tour(tour, visited, row, col, move, row_idx - 2, col_idx - 1);
}

void print_tour(vector< vector<int> > tour)
{
    for(auto row : tour)
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
    size_t row = 8;
    size_t col = 8;
    size_t move = 0;

    vector<vector<int> > tour;
    tour.assign(row, vector<int>(col, 0));

    vector<vector<bool> > visited;
    visited.assign(row, vector<bool>(col, false));

    knight_tour(tour, visited, row, col, move);
    print_tour(tour);

    return 0;
}