/*
Dijkstra's algorithm for single source shortest path
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Graph
{
    int num_of_ver;
    vector<vector<pair<int,int> > > adj_list;
    vector<long> distance;
    vector<pair<int, int> > sptSet;
public:
    Graph() = delete;
    Graph(int v)
    {
        num_of_ver = v;
        //To skip the o th index and 
        //starting Vertex number from 1
        //increasing v
        v++; 
        while(v--)
        {
            vector<pair<int, int> > vect;
            adj_list.push_back(vect);
            distance.push_back(INT_MAX);
        }

    }

    void addEdge(int s, int d, int w)
    {
        adj_list[s].push_back({d, w});
        adj_list[d].push_back({s, w});
    }

    void findDijkstra(int src);
    int getNextVertex();

    friend ostream& operator<<(ostream& out, Graph g);
    
};

//This will fill up the vector sptSet,
//which inturn defines the shortest path tree (SPT)
void Graph::findDijkstra(int src)
{
    distance[src] = 0;

    //Define the queue for level order traversing
    queue<int> m_queue;
    m_queue.push(getNextVertex());

    while(!m_queue.empty())
    {
        auto v = m_queue.front();
        m_queue.pop();

        //if v = 0, break from here and end the computation;
        if(!v)
            break;

        //Push v into sptSet
        sptSet.push_back({v, distance[v]});
        // sptSetIndex.push_back(v);

        for(auto val : adj_list[v])
        {
            distance[val.first] = distance[v] + val.second;
        }

        //Push the next qualifying vertex into queue
        m_queue.push(getNextVertex());
    }

}

//Returns next smallest vertex,
//which is not processed so far,
//into the queue for next processing
int Graph::getNextVertex()
{
    int v = 0;
    long num = INT_MAX;
    int idx = 0;

    for(auto ptr = distance.begin(); ptr != distance.end(); ptr++)
    {
        //Get the vertex, for which distance from Origin is minimum
        v = ptr - distance.begin();

        //Store the Minimum distance and the corresponding index
        if(find_if(sptSet.begin(), sptSet.end(), 
                [=](pair<int, int> vertex){
                    return vertex.first == v;
                }
            ) == sptSet.end()
            && *ptr < num)
        {
            num = *ptr;
            idx = v;
        }        
    }
    return idx;
}

ostream& operator<<(ostream& out, Graph g)
{
    for(auto val : g.sptSet)
    {
        out<<"Vertex: "<<val.first<<" Distance: "<<val.second<<"\t";
    }

    return out;
}

int main()
{
    Graph graph(6);
    graph.addEdge(1,2,2);
    graph.addEdge(1,3,4);
    graph.addEdge(2,4,7);
    graph.addEdge(2,3,5);
    graph.addEdge(3,5,3);
    graph.addEdge(4,5,2);
    graph.addEdge(4,6,1);
    graph.addEdge(5,6,5);

    graph.findDijkstra(1);
    cout<<graph<<endl;
}