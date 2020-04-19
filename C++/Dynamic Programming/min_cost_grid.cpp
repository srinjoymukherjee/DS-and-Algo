/*
Given a square grid of size N, each cell of which contains integer cost 
which represents a cost to traverse through that cell, 
we need to find a path from top left cell to bottom right cell 
by which total cost incurred is minimum.

Note : It is assumed that negative cost cycles do not exist in input matrix.
*/

#include <bits/stdc++.h>
#define INF INT_MAX/2

using namespace std;

class Graph
{
    int num_of_node;
    vector<vector<int> > adj_matrix;
public:
    Graph() = delete;
    Graph(int num) : num_of_node(num)
    {
        vector<vector<int> > matrix(num + 1, vector<int>(num + 1, 0));
        adj_matrix = matrix;
    }

    void addNode(int src, int dest, int w)
    {
        adj_matrix[src][dest] = w;
    }

    int nextMin(vector<int>, unordered_set<int>);
    int calcMinCostDijkstra(int src, int dest);
    int calcMinCostBlFord(int src, int dest);
};

//################## Dijkstra's Algorithm implementation #####################
int Graph::calcMinCostDijkstra(int src, int dest)
{
    int num = num_of_node;
    vector<int> dist(num + 1, INF);
    dist[src] = 0;
    unordered_set<int> visited;
    int min_idx = -1;

    do
    {
        min_idx = nextMin(dist, visited);
        visited.insert(min_idx);

        for(size_t idx = 1; idx <= num; idx++)
        {
            if(visited.find(idx) == visited.end()
                && adj_matrix[min_idx][idx] != 0)
            {
                dist[idx] = min(dist[idx], 
                                    dist[min_idx] + adj_matrix[min_idx][idx]);
            }
                
        }
    } while(min_idx != -1);
    
    return dist[dest];
}

int Graph::nextMin(vector<int> dist, unordered_set<int> visited)
{
    int prev = INF;
    int min_idx = -1;

    for(size_t idx = 1; idx < dist.size(); idx++)
    {
        if(dist[idx] < prev && 
            visited.find(idx) == visited.end())
        {
            prev = dist[idx];
            min_idx = idx;
        }
    }
    return min_idx;
}

//################## End of Dijkstra's Algorithm #################

//################## Bell-Ford Algorithm ###################
int Graph::calcMinCostBlFord(int src, int dest)
{
    int num = num_of_node;
    vector<int> dist(num + 1, INF);
    dist[src] = 0;

    while(num-- > 1)
    {
        for(size_t row = 1; row <= num_of_node; row++)
        {
            for(size_t col = 1; col <= num_of_node; col++)
            {
                if(adj_matrix[row][col] != 0)
                {
                    dist[col] = min(dist[col], 
                                    dist[row] + adj_matrix[row][col]);
                }
                
            }
        }
    }

    return dist[dest];
}
//################## End of Bellman-Ford ##################

Graph prepareGraph(vector<vector<int> > grid, int num)
{
    int cell = 1;
    Graph graph(num * num);

    for(size_t row = 0; row < num; row++)
    {
        for(size_t col = 0; col < num; col++)
        {
            if(row < num - 1 && grid[row + 1][col] != 0)
                graph.addNode(cell, cell + num, grid[row + 1][col]);

            if(row >= 1 && grid[row - 1][col] != 0)
                graph.addNode(cell, cell - num, grid[row - 1][col]);

            if(col < num - 1 && grid[row][col + 1] != 0)
                graph.addNode(cell, cell + 1, grid[row][col + 1]);

            if(col >= 1 && grid[row][col - 1] != 0)
                graph.addNode(cell, cell - 1, grid[row][col - 1]);
            cell++;
        }
    }
    return graph;
}

int getMinCost(Graph g, vector<vector<int> > grid, 
                pair<int, int> src, pair<int, int> dest, int num)
{
    int src_node = (src.first * num) + (src.second + 1);
    int dest_node = (dest.first * num) + (dest.second + 1);

    //Use Dijkstra's Algorithm to get the shortest path
    int min_cost_djk = grid[src.first][src.second] + 
                    g.calcMinCostDijkstra(src_node, dest_node);

    //Use Bellman-Ford Algorithm to get the shortest path
    int min_cost_bfd = grid[src.first][src.second] +
                g.calcMinCostBlFord(src_node, dest_node);

    return min_cost_bfd;
}

int main()
{
    int num = 5;
    vector<vector<int> > grid = {
        {31, 100, 65, 12, 18},
        {10, 13, 47, 157, 6},
        {100, 113, 174, 11, 33},
        {88, 124, 41, 20, 140},
        {99, 32, 111, 41, 20} 
    };

    Graph graph = prepareGraph(grid, num);

    cout << "Min Cost of Grid:\t"<<getMinCost(graph,grid,{0,0},{4,4},5) << endl;
    return 0;
}