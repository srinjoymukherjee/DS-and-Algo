/*
Given a chess board of order N x M and source points (s1, s2) 
and destination points (d1, d2). 
The task to find minimum number of moves 
required by the Knight to go to the destination cell.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph
{
    long num_of_vert;
    vector<vector<long> > adj_list;

public:
    Graph() = delete;
    Graph(long num) : num_of_vert(num)
    {
        //As we are not going to use 0 as key,
        //so adding one extra entry in adj_list
        //to ignore 0
        num++;
        while(num--)
        {
            vector<long> vect;
            adj_list.push_back(vect);
        }
    }

    void addEdge(long src, long dest)
    {
        adj_list[src].push_back(dest);
    }

    long getSteps(long, long);
};

//Function to calculate minimum number of movement
long Graph::getSteps(long src, long dest)
{
    long steps = 0;
    bool v_found = false;
    long pre = 0;
    unordered_set<long> visited;
    queue<long> m_queue;

    m_queue.push(src);
    m_queue.push(-1);

    //Perform BFS
    while(!m_queue.empty())
    {
        long temp = m_queue.front();
        m_queue.pop();

        visited.insert(temp);

        //Boundary condition
        //Maximum execution limit
        if(temp == -1 && pre == -1)
        {
            break;
        }
        //Boundary of a level
        else if(temp == -1)
        {
            steps++;
            m_queue.push(-1);
        }
        else
        {
            //Check if we have reached the destination
            if(temp == dest)
            {
                v_found = true;
                break;
            }
            
            //Process one level
            for(auto v : adj_list[temp])
            {
                //Condition to exclude upper level
                if(visited.find(v) == visited.end())
                    m_queue.push(v);
            }
                
        }
        pre = temp;
    }

    //If Destination is not reachable
    if(!v_found)
        return -1;
    
    return steps;
}

/*
Prepare the graph
This graph implies the connectivity of all the movements
possible by the knight.

A knight can move to below 8 possible vertex,
from it's current vertex, with position (r, c):
i.      r - 2, c - 1
ii.     r - 2, c + 1
iii.    r - 1, c - 2
iv.     r - 1, c + 2
v.      r + 2, c - 1
vi.     r + 2, c + 1
vii.    r + 1, c - 2
viii.   r + 1, c + 2

So, we have prepared the graph, 
with above 8 rules
*/
void prepare_graph(Graph &g, long row, long col)
{
    try{
        long cell = 1;
		for(size_t r = 1; r <= row; r++)
		{
			for(size_t c = 1; c <= col; c++)
			{
                //r - 2, c - 1
				if(r > 2 && c > 1)
					g.addEdge(cell, cell - 2 * col - 1);

                //r - 2, c + 1
				if(r > 2 && c < col)
					g.addEdge(cell, cell - 2 * col + 1);

                //r - 1, c - 2
				if(r > 1 && c > 2)
					g.addEdge(cell, cell - col - 2);

                //r - 1, c + 2
				if(r > 1 && c < col - 1)
					g.addEdge(cell, cell - col + 2);

                //r + 2, c - 1
				if(r < row - 1 && c > 1)
					g.addEdge(cell, cell + 2 * col - 1);

                //r + 2, c + 1
				if(r < row - 1 && c < col)
					g.addEdge(cell, cell + 2 * col + 1);

                //r + 1, c - 2
				if(r < row && c > 2)
					g.addEdge(cell, cell + col - 2);

                //r + 1, c + 2
				if(r < row && c < col - 1)
					g.addEdge(cell, cell + col + 2);

				cell++;
			}
			
		}
    }catch(exception e)
    {
        cout<<"Exception: "<<endl;
        cout<<e.what()<<endl;
    }
    
}

long getCell(long row, long col, long offset)
{
    return (row - 1) * offset + col;
}

int main()
{
    try{
        long row = 8, col = 8, steps = 0;
		pair<long, long> s;
		pair<long, long> d;
		s = {1,1};
		d = {5,7};
	
		long src = getCell(s.first, s.second, col);
		long dest = getCell(d.first, d.second, col);
	
		Graph knight(row * col);
		prepare_graph(knight, row, col);
		steps = knight.getSteps(src, dest);

		if(steps > 0)
		{
			cout<<steps<<endl;
		}
		else
		{
			cout<<"Destination not reachable"<<endl;
		}
    }catch(exception e)
    {
        cout<<"Exception: "<<e.what()<<endl;
    }
    
    return 0;
}