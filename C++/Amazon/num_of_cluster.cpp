/*
Find Number of Clusters in a binary array.
Clusters are formed by adjacent 1's.
Adjacency is defined Horizontally and vertically,
Not diagonally.

1 1 0 0
0 0 1 0
0 0 0 0
1 0 1 1
1 1 1 1

Above Matrix has 3 clusters

1st Cluster with nodes: 0,0 ; 0,1
2nd Cluster with Nodes: 1,2
3rd cluster with Nodes: 3,0 ; 3,2 ; 3,3 ; 4,0 ; 4,1 ; 4,2 ; 4,3
*/

#include <iostream>
#include <vector>

using namespace std;

void form_cluster(vector<vector<int> > matrix, size_t row, size_t col,
					size_t row_size, size_t col_size, 
					int cluster_num, vector<vector<int> > &visited)
{
	if(visited[row][col] == 0)
		visited[row][col] = cluster_num;			
	else
		return;
			
	if(row > 0 && matrix[row - 1][col] == 1)
	{
		form_cluster(matrix, row - 1, col,
						row_size, col_size,  
						cluster_num, visited);
	}
	
	if(row < row_size - 1 && matrix[row + 1][col] == 1) 
	{
		form_cluster(matrix, row + 1, col, 
						row_size, col_size,
						cluster_num, visited);
	}
	
	if(col > 0 && matrix[row][col - 1] == 1)
	{
		form_cluster(matrix, row, col - 1, 
						row_size, col_size,
						cluster_num, visited);
	}
	
	if(col < col_size - 1 && matrix[row][col + 1] == 1)
	{
		form_cluster(matrix, row, col + 1,
						row_size, col_size, 
						cluster_num, visited);
	}
	
	return;	
}

int num_of_cluster(vector<vector<int> > matrix, int row, int column){
	size_t row_idx, col_idx;
	int cluster_num = 0;
	vector<vector<int> > visited(row, vector<int>(column,0));
	
	for(row_idx = 0; row_idx < row; row_idx++){
		for(col_idx = 0; col_idx < column; col_idx++){
			
			if(matrix[row_idx][col_idx] == 1 && 
				visited[row_idx][col_idx] == 0)
			{
				form_cluster(matrix, row_idx, col_idx,
								row, column, 
								++cluster_num, visited);
			}
			visited[row_idx][col_idx] = -1;
		}
	}
	
	return cluster_num;
}

int main(){
	vector<vector<int> > matrix (5, vector<int> (4,0));
	matrix[0][0] = 1;	matrix[0][1] = 1;	matrix[0][2] = 0;	matrix[0][3] = 0;
	matrix[1][0] = 0;	matrix[1][1] = 0;	matrix[1][2] = 1;	matrix[1][3] = 0; 
	matrix[2][0] = 0;	matrix[2][1] = 0;	matrix[2][2] = 0;	matrix[2][3] = 0;
	matrix[3][0] = 1;	matrix[3][1] = 0;	matrix[3][2] = 1;	matrix[3][3] = 1;
	matrix[4][0] = 1;	matrix[4][1] = 1;	matrix[4][2] = 1;	matrix[4][3] = 1;
	
	cout<<"Number of clusters:\t"<<num_of_cluster(matrix, 5, 4)<<endl;
	return 0;
}
