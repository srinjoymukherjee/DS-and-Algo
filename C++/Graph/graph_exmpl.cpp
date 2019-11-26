#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void create_graph(vector< vector<int> > &g_list, int size, int u, int v)
{
	//cout<<"##123@"<<endl;
	g_list[u].push_back(v);
	g_list[v].push_back(u);
}

void print_graph(vector< vector<int> > &g_list, int size)
{
	for(int i = 1; i <= size; i++)
	{
		cout<<i<<"\t";
		for(auto idx = g_list[i].begin(); idx != g_list[i].end(); idx++)
			cout<<*idx<<"\t";
			
		cout<<endl;
	}
}

void do_BFS(vector< vector<int> > &g_list, int size, int s)
{
	cout<<"BFS Traversal:\t";
	bool *visited = new bool[size + 1];
	for(int i = 0; i <= size; i++)
		visited[i] = false;
	
	queue<int> q_bfs;
	visited[s] = true;
	q_bfs.push(s);
	
	while(!q_bfs.empty())
	{
		s = q_bfs.front();
		
		cout<<s<<"\t";
		
		q_bfs.pop();
		
		for(auto idx = g_list[s].begin(); idx != g_list[s].end(); idx++)
		{
			if(visited[*idx] == true)
				continue;
			visited[*idx] = true;
			q_bfs.push(*idx);
		}
	}
	cout<<"\n";
}

void do_DFS(vector< vector<int> > &g_list, int size, int s)
{
	cout<<"DFS Traversal:\t";
	bool *visited = new bool[size + 1];
	for(int i = 0; i <= size; i++)
		visited[i] = false;
	
	stack<int> s_bfs;
	visited[s] = true;
	s_bfs.push(s);
	
	while(!s_bfs.empty())
	{
		s = s_bfs.top();
		
		cout<<s<<"\t";
		
		s_bfs.pop();
		
		for(auto idx = g_list[s].begin(); idx != g_list[s].end(); idx++)
		{
			if(visited[*idx] == true)
				continue;
			cout<<*idx<<"  ";
			visited[*idx] = true;
			s_bfs.push(*idx);
		}
	}
	cout<<"\n";
}

int main()
{
	try{
		int e_total = 6;
		vector< vector<int> > g_list(e_total + 1);
		create_graph(g_list,e_total,1,2);
		create_graph(g_list,e_total,1,3);
		create_graph(g_list,e_total,2,4);
		create_graph(g_list,e_total,3,4);
		create_graph(g_list,e_total,4,5);
		create_graph(g_list,e_total,4,6);
		create_graph(g_list,e_total,5,6);
		
		print_graph(g_list,e_total);
		
		do_BFS(g_list,e_total,2);
		do_DFS(g_list,e_total,1);
		
	} catch(exception &e){
		cout<<"Exception in program:\t"<<e.what()<<endl;
	}
	
}
