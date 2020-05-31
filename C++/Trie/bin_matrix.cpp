/*
Given a binary matrix, print all unique rows of the given matrix
*/

#include <iostream>
#include <vector>

#define NUM_OF_VAL 2

using namespace std;

void print_trie(vector<int>);

class Trie
{
    int term;
    vector<Trie*> child_array;

    public:
    Trie()
    {
        child_array.assign(NUM_OF_VAL, nullptr);
        term = 0;
    }

    void insert_trie(vector<int> key)
    {
        Trie* head = this;

        for(size_t idx = 0; idx < key.size(); idx++)
        {
            if(!head->child_array[key[idx]])
            {
                head->child_array[key[idx]] = new Trie;
            }
            head = head->child_array[key[idx]];
        }

        head->term++;
    }

    friend void traverse_trie(Trie* root, vector<int>& result);
};

void traverse_trie(Trie* root, vector<int>& result)
{
    if(root == nullptr)
        return;

    Trie* head = root;

    if(head->term > 0)
        print_trie(result);

    for(int idx = 0; idx < head->child_array.size(); idx++)
    {
        if(head->child_array[idx])
        {
            result.push_back(idx);
            traverse_trie(head->child_array[idx], result);
            result.pop_back();
        }
        
    }
}

void print_trie(vector<int> trie_list)
{
    for(auto val : trie_list)
    {
        cout<<val;       
    }
    cout<<"$";
}

int main()
{
    size_t row = 0;
    size_t col = 0;
    size_t tc = 0;

    vector<vector<int> > bin_matrix;
    // {
    //     {1, 0, 0, 1},
    //     {1, 1, 0, 1},
    //     {1, 0, 0, 1},
    //     {1, 1, 0, 1}
    // };

    vector<int> trie_list;

    Trie* root = new Trie;

    cin >> tc;

    while(tc--)
    {
        cin >> row;
        cin >> col;

        bin_matrix.assign(row, vector<int>(col, 0));

        for(size_t row_idx = 0; row_idx < row; row_idx++)
        {
            for(size_t col_idx = 0; col_idx < col; col_idx++)
            {
                cin >> bin_matrix[row_idx][col_idx];
            }
        }    

		for(auto row : bin_matrix)
		{        
			root->insert_trie(row);
		}
	
		traverse_trie(root, trie_list);
		cout<<endl;
	}
	
	return 0;
}