#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

class Graph
{
    const long num_of_ver;
    vector<vector<int> > adj_matrix;
public:
    Graph() = delete;
    Graph(long num) : num_of_ver(num)
    {
        num++; //escape 0
        vector<vector<int> > t_matrix(num, vector<int>(num, 0));
        adj_matrix = t_matrix;        
    }

    void addEdge(int src, int dest, int weight)
    {
        adj_matrix[src][dest] = weight;
    }

    long getNumVertex()
    {
        return num_of_ver;
    }

    vector<vector<int> > getAdjMatrix()
    {
        return adj_matrix;
    }
};

vector<int> getSPT(Graph g)
{
	vector<int> path;
	
    try{
        long num = g.getNumVertex();
		auto adj_matrix = g.getAdjMatrix();
	
		vector<int> cost(num + 1, INF);
		vector<int> connect(num + 1, 0);
	
		
		cost[num] = 0;
		connect[num] = num;
	
		for(size_t s = num - 1; s > 0; s--)
		{
			for(size_t d = s + 1; d <= num; d++)
			{
				if(adj_matrix[s][d] != 0 
					&& adj_matrix[s][d] + cost[d] <= cost[s])
					{
						cost[s] = adj_matrix[s][d] + cost[d];
						connect[s] = d;
					}
			}
		}
        path.push_back(1);
		for(int d = connect[1]; d < num; d = connect[d])
		{
			path.push_back(d);
		}
        path.push_back(num);

    }catch(exception e)
    {
        cout<<"Exception: "<<e.what()<<endl;
		throw e;
    }
    
    return path;
}

int main()
{
	try{		
		int v_num = 12;
		Graph graph(12);
	
		graph.addEdge(1, 2, 9);
		graph.addEdge(1, 3, 7);
		graph.addEdge(1, 4, 3);
		graph.addEdge(1, 5, 2);
	
		graph.addEdge(2, 6, 4);
		graph.addEdge(2, 7, 2);
		graph.addEdge(2, 8, 1);
	
		graph.addEdge(3, 6, 2);
		graph.addEdge(3, 7, 7);
	
		graph.addEdge(4, 8, 11);
	
		graph.addEdge(5, 7, 11);
		graph.addEdge(5, 8, 8);
	
		graph.addEdge(6, 9, 6);
		graph.addEdge(6, 10, 5);
	
		graph.addEdge(7, 9, 4);
		graph.addEdge(7, 10, 3);
	
		graph.addEdge(8, 10, 5);
		graph.addEdge(8, 11, 6);
	
		graph.addEdge(9, 12, 4);
	
		graph.addEdge(10, 12, 2);
	
		graph.addEdge(11, 12, 5);
	
		auto path = getSPT(graph);
	
		for(auto val : path)
		{
			cout<<val<<" ";
		}
	
		cout<<endl;
    }catch(exception e)
    {
        cout<<"Exception: "<<e.what()<<endl;
    }

    return 0;
}