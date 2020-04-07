/*
Kruskal's Algorithm to find Minimum Spanning Tree
in a connected, weighted and undirected graph
*/
#include <iostream>
#include <vector>
// #include <unordered_map>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class edge_type 
{
public:
    int weight;
    int src;
    int dest;

    edge_type(int w, int s, int d)
    {
        weight = w;
        src = s;
        dest = d;
    }

    friend ostream& operator<<(ostream& out, edge_type e);
};

ostream& operator<<(ostream& out, edge_type e)
{
    out<<"Source: "<<e.src<<" Destination: "<<e.dest<<" Weight: "<<e.weight;
    return out;
}

class Graph
{
    long num_of_vertex;
    vector<edge_type> graph_edges;
    vector< vector<pair<int,int> > > adj_list;
    vector<int> parent;
    // multimap<int, pair<int,int> > graph_edge;
    // priority_queue<int, vector<int>, greater<int> > edge_list;  

public:
    Graph() = delete;

    Graph(long num)
    {
        num_of_vertex = num;
        num++;
        while(num--)
        {
            vector<pair<int, int> > vect;
            adj_list.push_back(vect);
            parent.push_back(-1);
        }
    }

    void addEdge(edge_type edge)
    {
        graph_edges.push_back(edge);
        adj_list[edge.src].push_back({edge.dest, edge.weight});
        adj_list[edge.dest].push_back({edge.src, edge.weight});
    }

    vector<edge_type> getMST();
    int find(int v);
    bool weighted_union(int, int);
};

int Graph::find(int v)
{
    if(parent[v] == -1)
        return v;
    
    return find(parent[v]);
}

bool Graph::weighted_union(int v1, int v2)
{
    int p1 = find(v1);
    int p2 = find(v2);

    if(p1 == p2)
        return false;
    
    parent[p2] = p1;

    return true;
}

vector<edge_type> Graph::getMST()
{
    vector<edge_type> mst;
    unordered_set<int> visited_vertex;

    sort(graph_edges.begin(), graph_edges.end(),
        [](edge_type a, edge_type b)
        {
            return a.weight < b.weight;
        }
    );

    for(auto edge : graph_edges)
    {
        if(weighted_union(edge.src, edge.dest) 
            && mst.size() <= num_of_vertex - 1)
            mst.push_back(edge);
    }
    
    return mst;
}

int main()
{
    Graph graph(6);
    graph.addEdge(edge_type(2, 1, 2));
    graph.addEdge(edge_type(4, 1, 3));
    graph.addEdge(edge_type(1, 2, 3));
    graph.addEdge(edge_type(7, 2, 4));
    graph.addEdge(edge_type(3, 3, 5));
    graph.addEdge(edge_type(2, 4, 5));
    graph.addEdge(edge_type(1, 4, 6));
    graph.addEdge(edge_type(5, 5, 6));

    auto edge_mst = graph.getMST();

    for(auto edge : edge_mst)
    {
        cout<<edge<<endl;
    }

    return 0;
}
