/*
Given N X N matrix filled with 1 , 0 , 2 , 3 . 
Find whether there is a path possible from source to destination, 
traversing through blank cells only. 
You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.

Note : there is only single source and single destination(sink).
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;

template <class T>
class Graph
{
    int vertex;
    vector< vector<T> > adj_list;
public:
    Graph() = delete;
    Graph(int v)
    {
        vertex = v + 2;
        while(vertex--)
        {
            vector<T> vect;
            adj_list.push_back(vect);
        }
    }

    void add_edge(T root, T sub);
    T bfs_node(T node);
    bool dfs_path(T root, T sub);
};

template <typename T>
void Graph<T>::add_edge(T root, T sub)
{
    if(find(adj_list[root].begin(), adj_list[root].end(), sub) 
        == adj_list[root].end())
    {
        adj_list[root].push_back(sub);
    }        

    if(find(adj_list[sub].begin(), adj_list[sub].end(), root) 
        == adj_list[sub].end())
    {
        adj_list[sub].push_back(root);
    }
}

template <typename T>
bool Graph<T>::dfs_path(T root, T sub)
{
    stack<T> dfs;
    unordered_set<T> visited;    

    dfs.push(root);

    while(!dfs.empty())
    {
        auto temp = dfs.top();
        dfs.pop();
        

        if(temp == sub)
        {
            // cout<<temp<<endl;
            return true;
        }  

        if(visited.find(temp) == visited.end())
        {   
            // cout<<temp<<endl;         
            visited.insert(temp);
            if(!adj_list[temp].empty()) 
            {
                for(auto val : adj_list[temp])
                {
                    dfs.push(val);
                }
            }   
        }
    }
    return false;
}

template <typename T>
T Graph<T>::bfs_node(T node)
{

}

Graph<int> creat_graph(vector< vector<int> > cell_matrix, int row, int col, int& s, int& d)
{
    int cell = 1;
    int num = row * col;
    Graph<int> graph(num);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(cell_matrix[i][j] != 0)
            {
                if(i - 1 > 0 && cell_matrix[i-1][j] != 0)
                    graph.add_edge(cell, cell - col);
                
                if(i + 1 < row && cell_matrix[i+1][j] != 0)
                    graph.add_edge(cell, cell + col);

                if(j - 1 > 0 && cell_matrix[i][j - 1] != 0)
                    graph.add_edge(cell, cell - 1);
                
                if(j + 1 < col && cell_matrix[i][j + 1] != 0)
                    graph.add_edge(cell, cell + 1);
            }
            if(cell_matrix[i][j] == 1)
                s = cell;
            
            if(cell_matrix[i][j] == 2)
                d = cell;
            
            cell++;
        }
    }
    return graph;
}

int main()
{
    try{
        int row = 4;
		int col = 4;
		int source = 0;
		int dest = 0;
		// vector<vector<int> > cell_matrix(row, vector<int>(col,0));
		vector<vector<int> > cell_matrix{
			{ 0 , 3 , 1 , 0 },
			{ 3 , 0 , 3 , 3 },
			{ 2 , 3 , 0 , 3 },
			{ 0 , 3 , 3 , 3 }
		};
	
		Graph<int> graph = creat_graph(cell_matrix, row, col, source, dest);
		if(graph.dfs_path(source, dest))
			cout<<"Found"<<endl;
		else
		{
			cout<<"Not Found"<<endl;
		}
    }catch(exception e)
    {
        cout << "Exception occured: "<<e.what()<<endl;
    }
    
    return 0;
}