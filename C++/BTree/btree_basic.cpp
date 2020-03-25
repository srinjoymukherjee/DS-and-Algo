#include <iostream>
#include <climits>
#include <queue>
#include <stack>
#include <vector> 
#include <algorithm>
#include <unordered_set>

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
	cout<<"level_order:\t";
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

//Print Left Subtree
void print_left(btree bt)
{
	if(!bt)
	{
		return;
	}

	queue<btree> q;
	q.push(bt);
	q.push(nullptr);
	btree prev = nullptr;

	while(!q.empty())
	{
		bt = q.front();
		q.pop();

		if(!bt && !prev)
			break;

		if(!prev)
		{
			cout<<bt->data<<"\t";
		}

		if(bt)
		{
			if(bt->left)
			{
				q.push(bt->left);
			}

			if(bt->right)
			{
				q.push(bt->right);
			}
		}
		else
		{
			q.push(nullptr);
		}
		
		prev = bt;
	}

}

//calculate the height of a tree
long calc_height(btree bt)
{
	if(!bt)
	{
		return -1;
	}

	long left_height = calc_height(bt->left);
	long right_height = calc_height(bt->right);

	return left_height > right_height ? left_height + 1 : right_height + 1;
}

//Mirror of the tree
void mirror_tree(btree bt)
{
	if(!bt)
	{
		// cout<<"Empty Tree"<<endl;
		return;
	}

	mirror_tree(bt->left);
	mirror_tree(bt->right);

	auto temp = bt->left;
	bt->left = bt->right;
	bt->right = temp;
	temp = nullptr;
}

/*
Calculates The Diameter/width of a tree
Diameter is the number of nodes in the longest path,
between two leaves in the tree.

Note: This count does'nt include these two leaf nodes,
	  mentioned above.
*/
long calc_width(btree bt)
{
	if(!bt)
	{
		return 0;
	}

	//Calculate Number of nodes in the left side
	long lheight = calc_height(bt->left);

	//Calculate Number of nodes in the right side
	long rheight = calc_height(bt->right);

	//Calculate current width
	long width = lheight + rheight + 1;

	//Calculate width of left subtree
	long lwidth = calc_width(bt->left);

	//Calculate width of left subtree
	long rwidth = calc_width(bt->right);

	return max(width, max(lwidth, rwidth));
}

//Find the LCA (Least Common Ancestor)
btree find_LCA(btree root, long a, long b)
{
	if(!root)
	{
		return nullptr;
	}

	if(root->data == a || root->data == b)
	{
		return root;
	}

	btree left = find_LCA(root->left, a, b);
	btree right = find_LCA(root->right, a, b);

	if(left && right)
	{
		return root;
	}
	else
	{
		return left ? left : right;
	}	
}
 
//Path finder function
void find_path(btree bt, long a, long b)
{
	btree lca = find_LCA(bt, a, b);
	cout<<lca->data<<"\t"<<endl;
	vector<btree> path1;	

	//search path from LCA to any node
	auto path = [](btree l, long v, vector<btree>& t_path){
		stack<btree> p_stack;
		p_stack.push(l);
		bool found = false;
		unordered_set<btree> visited;

		while(!p_stack.empty())
		{
			btree temp = p_stack.top();
			p_stack.pop();

			while(temp){
				visited.insert(temp);
				if(temp->data == v)
				{
					t_path.push_back(temp);
					found = true;
					break;
				}
				else
				{
					t_path.push_back(temp);
					p_stack.push(temp);
				}
				temp = temp->left;
			}

			if(found)
			{
				break;
			}
			
			temp = p_stack.top();
			p_stack.pop();

			auto top_ptr = t_path.rbegin();

			if(
				(
					visited.find((*top_ptr)->left) != visited.end() && 
					visited.find((*top_ptr)->right) != visited.end()
				) || 
				(
					(*top_ptr)->left == nullptr && 
					(*top_ptr)->right == nullptr
				) 
			)
				t_path.pop_back();

			p_stack.push(temp->right);
		}
	};

	if(lca->data != a && lca->data != b)
	{
		vector<btree> path2;
		path(lca, a, path1);
		path(lca, b, path2);

		reverse(path1.begin(), path1.end());

		auto ptr = path2.begin();
		advance(ptr, 1);

		for(; ptr != path2.end(); ptr++)
		{
			path1.push_back(*ptr);
		}
	}
	else
	{		
		lca->data == b ? path(lca, a, path1) : path(lca, b, path1);
	}

	for_each(path1.begin(), path1.end(),[](btree b){
		cout<<b->data<<"\t";
	});
	cout<<endl;
}

int main()
{
	btree bt = nullptr;
	
	for(size_t idx = 2; idx < 200; idx = idx * 2)
	{
		insert_btree(bt, idx);
	}

	cout<<"In Order:\t";
	in_order(bt);
	cout<<endl;

	level_order(bt);
	cout<<"Height: "<<calc_height(bt)<<endl;

	if(search_element(bt, 16))
	{
		cout<<"found"<<endl;
	}
	else
	{
		cout<<"Not Found"<<endl;
	}	

	cout<<"Left Tree:\t";
	print_left(bt);
	cout<<endl;

	cout<<"Max Val:\t"<< search_max(bt)<<endl;

	cout<<"Width:\t"<<calc_width(bt)<<endl;

	cout<< "LCA:\t" << find_LCA(bt, 16, 128)->data <<endl;

	cout<<"Path: ";
	find_path(bt, 64, 128);
	cout<<endl;

	cout<<"After Mirroring: "<<endl;
	mirror_tree(bt);
	level_order(bt);

	return 0;
}
