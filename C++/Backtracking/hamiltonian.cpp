/*
A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly once. 
Given an undirected graph  the task is to check if a Hamiltonian path is present in it or not.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool get_hamiltonian(vector<vector<int> > graph, vector<int>& path, size_t path_idx,
                     int vertex, unordered_set<int>& visited, size_t size)
{
    if(path_idx == size)
    {
        return true;
    }

    if(visited.find(vertex) != visited.end())
        return false;
   
    visited.insert(vertex);

    path[path_idx] = vertex;

    for(size_t v_idx = 1; v_idx <= size; v_idx++)
    {
        if(graph[vertex][v_idx])
        {
            if(get_hamiltonian(graph, path, path_idx + 1, v_idx, visited, size))
            {
                return true;
            }
        }            
    }
    
    visited.erase(vertex);
    path[path_idx] = 0;

    return false;
}

int main()
{
    int start = 1; //starting vertex
    size_t vertex_num = 0;
    size_t edge_num = 0;
    size_t path_idx = 0;
    size_t num_t = 0;

    size_t v1 = 0;
    size_t v2 = 0;

    vector<vector<int> > graph;
    vector<int> path;    
    unordered_set<int> visited;

    cin >> num_t;

    while(num_t--)
    {
        cin >> vertex_num;

        path.assign(vertex_num, 0);
        graph.assign(vertex_num + 1, vector<int>(vertex_num + 1, 0));

        cin >> edge_num;

        while(edge_num--)
        {
            cin >> v1;
            cin >> v2;
            graph[v1][v2] = 1;
            graph[v2][v1] = 1;
        }

        if(get_hamiltonian(graph, path, path_idx, start, visited, vertex_num))
        {
            cout<<endl<<"Hamiltonian path:"<<endl;

            for(auto val : path)
            {
                cout<<val<<"\t";
            }

            cout<<endl;
        }
        else
        {
            cout<<"No Hamiltonian path possible";
        }
    }    
    
    return 0;
}