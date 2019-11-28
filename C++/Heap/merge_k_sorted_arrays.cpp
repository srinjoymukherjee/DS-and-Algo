/*
Given K sorted arrays (ascending order), arranged in form of a matrix. 
The task is to merge them into one list
*/

#include <iostream>
#include <queue>

using namespace std;

typedef pair< int, pair<size_t, size_t> > node_type;

vector<int> mergeKArray(vector< vector< int > > vect){
	size_t size = vect.size();
	priority_queue< node_type, vector< node_type >, greater< node_type > > pq;
	vector< int > result;
	
	for(size_t i = 0; i < size; i++){
		pq.push({vect[i][0], {i,0}});
	}
	
	while(!pq.empty()){
		result.push_back(pq.top().first);
		size_t arr_idx = pq.top().second.first;
		size_t pos_idx = pq.top().second.second;
		pq.pop();
		
		if(pos_idx + 1 < vect[arr_idx].size()){
			node_type next_node = {vect[arr_idx][pos_idx + 1], {arr_idx, pos_idx + 1}};
			pq.push(next_node);
		}
		
	}
	
	return result;
}

template <typename T>
void print_vect(vector<T> vect){
	for(auto itr = vect.begin(); itr != vect.end(); itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
}

int main(){
	vector< vector< int > > vect = {{1,4,6,10},
									{0,3,8},
									{2,5,7,9}};
	
	vector< int > result = mergeKArray(vect);
	print_vect(result);
	return 0;
}
