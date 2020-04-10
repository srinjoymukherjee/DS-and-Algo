/*
Bellman Ford algorithm:
Single source shortest path,
with negative edges

Hint:
d[v] = min(d[v], d[u] + d[u,v])
*/

#include <iostream>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <climits>

#define INF INT_MAX/2

using namespace std;

class Graph
{
    const long num_of_ver;
    vector<vector<long> > adj_matrix;
public:
    Graph() = delete;
    Graph(long num) : num_of_ver(num)
    {
        vector<vector<long> > v_matrix(num + 1, vector<long>(num + 1, 0));
        adj_matrix = v_matrix;
    }

    void addEdge(long src, long dest, long weight);

    long getNumOfVer()
    {
        return num_of_ver;
    }

    vector<vector<long> > getAdjMatrix()
    {
        return adj_matrix;
    }
};

void Graph::addEdge(long src, long dest, long weight)
{
    adj_matrix[src][dest] = weight;
}

vector<long> calcBellFord(Graph g)
{
    long num = g.getNumOfVer();
	long idx = num;
	auto matrix = g.getAdjMatrix();
	vector<long> dist(num + 1, INF);
    dist[1] = 0;
	
	try{	
		//To detect cycle:
		idx++;
	
		while(idx--)
		{
			for(size_t row = 1; row <= num; row++)
			{
				for(size_t col = 1; col <= num; col++)
				{
					if(matrix[row][col] != 0
						&& dist[col] > dist[row] + matrix[row][col])
					{
						if(idx == 0)
						{                            
							throw runtime_error("Negative Cycle found");
						}
						dist[col] = dist[row] + matrix[row][col];
					}
				}
			}
		}
	}catch(exception &e)
	{
		cerr<<"Negative Cycle found"<<endl;
        throw e;
	}
    return dist;
}

int main()
{
    try{
		Graph g(7);
		g.addEdge(1, 2, 6);
		g.addEdge(1, 3, 5);
		g.addEdge(1, 4, 5);
	
		g.addEdge(2, 5, -1);
		
		g.addEdge(3, 2, -2);
		g.addEdge(3, 5, 1);
	
		g.addEdge(4, 3, -2);
		g.addEdge(4, 6, -1);
	
		g.addEdge(6, 7, 3);
		g.addEdge(5, 7, 3);
	
		auto dist = calcBellFord(g);
		auto ptr = dist.begin();
		advance(ptr,1);
	
		for(;ptr != dist.end(); ptr++)
		{
			cout<<*ptr<<" ";
		}
		cout<<endl;
    }catch(exception e)
    {
        cout<<"Exception: "<<e.what()<<endl;
    }

    return 0;
}