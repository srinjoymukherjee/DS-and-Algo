/*
Algorithm to find shortest path among 
all pairs of vertices

Ans: For k-th node, the Adjacency Matrix A should be
processed with below formula-
A[row][col] = min(A[row][col], (A[row][k] + A[k][col]))
*/

#include <bits/stdc++.h>

#define INF 16777216

using namespace std;

class Graph
{
    const long num_of_ver;
    vector<vector<long> > adj_matrix;
public:
    Graph() = delete;
    Graph(long num) : num_of_ver(num)
    {
        vector<vector<long> > v_matrix(num + 1, vector<long>(num + 1,INF));

        for(int row = 1; row <= num; row++)
        {
            for(int col = 1; col <= num; col++)
            {
                if(col == row)
                    v_matrix[row][col] = 0;
            }
        }
        adj_matrix = v_matrix;
    }

    void addEdge(int src, int dest, int weight);

    vector<vector<long> > getAdjMatrix()
    {
        return adj_matrix;
    }

    long getNumOfEdges()
    {
        return num_of_ver;
    }
};

void Graph::addEdge(int src, int dest, int weight)
{
    adj_matrix[src][dest] = weight;
}

vector<vector<long> > getSPTMatrix(Graph g)
{
    auto matrix = g.getAdjMatrix();
    long num = g.getNumOfEdges();

    for(auto mid = 1; mid <= num; mid++)
    {
        for(auto row = 1; row <= num; row++)
        {
            for(auto col = 1; col <= num; col++)
            {
                matrix[row][col] = min(matrix[row][col], 
                                    (matrix[row][mid] + matrix[mid][col]));
            }
        }
    }
    return matrix;
}

int main()
{
    int num = 4;
    Graph g(num);

    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 7);
    g.addEdge(2, 1, 8);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 1, 5);
    g.addEdge(4, 1, 2);

    auto matrix = getSPTMatrix(g);

    for(size_t row = 1; row <= num; row++)
    {
        for(size_t col = 1; col <= num; col++)
        {
            cout<<matrix[row][col]<<" ";
        }
        cout<<endl;
    }

    return 0;
}