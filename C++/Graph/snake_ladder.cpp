/*
Given a snake and ladder board of order 5x6, 
find the minimum number of dice throws required 
to reach the destination or last cell (30th cell) 
from source (1st cell) 
*/

#include <bits/stdc++.h>

// #define INF INT_MAX/2

using namespace std;

class Graph
{
    const int num_of_ver;
    vector<vector<int> > adj_matrix;
public:
    Graph() = delete;
    Graph(int num) : num_of_ver(num)
    {
        vector< vector<int> > matrix(num + 1, vector<int>(num + 1, 0));
        adj_matrix = matrix;
    }

    void addEdge(int src, int dest, int weight)
    {
        adj_matrix[src][dest] = weight;
    }

    int getShortestPath()
    {
        int v = 1;
        int d = 1;
        int step = 0;
        try{
			while(v != num_of_ver)
			{
				for(int di = 1; di <= 6; di++)
				{
					int row = v + di;
                    if(row > num_of_ver)
                        continue;

					d = max(d, row);
					for(int col = 1; col <= num_of_ver; col++)
					{
						if(adj_matrix[row][col] == 1)
						{
							d = max(d, col);
						}
						else if(adj_matrix[row][col] == -1)
						{
							d = max(d,col);
						}
					}
				}
				v = d;
				step++;
			}
        }catch(exception e)
        {
            cout<<"Exception: "<<e.what()<<endl;
        }
		
        return step;
    }
};

int main()
{
    int row = 5, col = 6;
    Graph g(row * col);
    
    //Add Ladder
    // g.addEdge(3, 22, 1);
    g.addEdge(5, 8, 1);
    // g.addEdge(11, 26, 1);
    g.addEdge(20, 29, 1);
    // g.addEdge(24, 50, 1);

    //Add Snake
    g.addEdge(27, 1, -1);
    g.addEdge(17, 4, -1);
    g.addEdge(21, 9, -1);
    g.addEdge(19, 7, -1);
    // g.addEdge(45, 15, -1);

    cout<<g.getShortestPath()<<endl;

    return 0;
}