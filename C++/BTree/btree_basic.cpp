#include <iostream>
#include <climits>
#include <queue>

using namespace std;

typedef struct node_type
{
	long data;
	struct node_type* left;
	struct node_type* right;
} node;

typedef node* btree;

void insert_btree(btree& root, long val)
{
	auto bt = root;
	auto leafNode = [val](btree &bt){
			bt = new node;
			bt->data = val;
			bt->left = nullptr;
			bt->right = nullptr;
		};

	if(!root)
	{
		leafNode(root);
		return;
	}
	queue<btree> b_queue;
	b_queue.push(bt);

	while(!b_queue.empty())
	{
		bt = b_queue.front();
		b_queue.pop();
		if(bt->left)
		{
			b_queue.push(bt->left);
		}
		else
		{
			leafNode(bt->left);
			break;
		}

		if(bt->right)
		{
			b_queue.push(bt->right);
		}
		else
		{
			leafNode(bt->right);
			break;
		}
		
	}
}

void in_order(btree bt)
{
	if(!bt)
		return;
	
	cout<<bt->data<<"\t";
	in_order(bt->left);
	in_order(bt->right);
}

void level_order(btree bt)
{
	cout<<endl<<"level_order:\t";
	if(!bt)
		return;
	
	queue<btree> b_queue;
	b_queue.push(bt);

	while(!b_queue.empty())
	{
		bt = b_queue.front();
		cout<<bt->data<<"\t";
		b_queue.pop();

		if(bt->left)
			b_queue.push(bt->left);
		
		if(bt->right)
			b_queue.push(bt->right);
	}
	cout<<endl;
}

//Search any element in the tree
bool search_element(btree root, int val)
{
	if(root == nullptr)
	{
		return false;
	}

	if(root->data == val)
	{
		return true;
	}

	if(search_element(root->left, val))
	{
		return true;
	}
	if(search_element(root->right, val))
	{
		return true;
	}

	return false;
}

//Search Max element
long search_max(btree root)
{
	long max_val = INT_MIN;
	if(!root)
	{
		return max_val;
	}

	btree bt = nullptr;
	queue<btree> b_queue;
	b_queue.push(root);

	while(!b_queue.empty())
	{
		bt = b_queue.front();
		b_queue.pop();
		max_val = max(bt->data, max_val);

		if(bt->left)
		{
			b_queue.push(bt->left);
		}

		if(bt->right)
		{
			b_queue.push(bt->right);
		}
	}

	return max_val;
}

int main()
{
	btree bt = nullptr;
	
	for(size_t idx = 2; idx < 100; idx = idx * 2)
	{
		insert_btree(bt, idx);
	}

	cout<<"In Order:\t";
	in_order(bt);
	cout<<endl;

	level_order(bt);

	if(search_element(bt, 16))
	{
		cout<<"found"<<endl;
	}
	else
	{
		cout<<"Not Found"<<endl;
	}	

	cout<< search_max(bt)<<endl;

	return 0;
}
