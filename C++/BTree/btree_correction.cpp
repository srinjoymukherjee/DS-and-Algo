/*
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class BTreeNode{
public:
	int data;
	BTreeNode* left;
	BTreeNode* right;
	BTreeNode(){
		data = INT_MIN;
		left = nullptr;
		right = nullptr;
	}
};

void insert_BST(BTreeNode*& root, int val){
	if(root->data > val){
		if(root->left){
			insert_BST(root->left, val);
		}
		else{
			BTreeNode* temp = new BTreeNode();
			temp->data = val;
			root->left = temp;
		}
		
	}else{
		if(root->right){
			insert_BST(root->right, val);
		}
		else{
			BTreeNode* temp = new BTreeNode();
			temp->data = val;
			root->right = temp;
		}
	}
	
	return;	
}

void inorder(BTreeNode*& root, vector<int>& i_list){
	if(root == nullptr)
		return;
				
	inorder(root->left, i_list);
	i_list.emplace_back(root->data);
	inorder(root->right, i_list);
}

void print_vector(vector<int>& vect){
	for(auto itr = vect.begin() ;itr != vect.end(); itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
}

void corrupt_btree(BTreeNode*& root, BTreeNode*& first, BTreeNode*& second, int v1, int v2){
	
	if(!root)
		return;
		
	corrupt_btree(root->left, first, second, v1, v2);
	
	if((root->data == v1) || (root->data == v2)){
		if(!first)
			first = root;
		else
			second = root;
	}
	
	corrupt_btree(root->right, first, second, v1, v2);
}

void corrupt_BST_Handler(BTreeNode*& root){
	int v1 = 10, v2 = 100;
	BTreeNode* first = nullptr;
	BTreeNode* second = nullptr;	
	corrupt_btree(root, first, second, v1, v2);
	if(first && second)
		swap(first->data, second->data);
	else if(first && !second){
		if(first->left)
			swap(first->data, first->left->data);
		else if(first->right)
			swap(first->data, first->right->data);
	}
	else if(!first && second){
		if(second->left)
			swap(second->data, second->left->data);
		else if(second->right)
			swap(second->data, second->right->data);
	}
}

void correct_btree(BTreeNode*& root, BTreeNode*& prev, BTreeNode*& mid, BTreeNode*& first, BTreeNode*& sec){
	
	if(root == nullptr)
		return;
		
	correct_btree(root->left, prev, mid, first, sec);

	if(prev && root->data < prev->data){
		if(!first){
			first = prev;
			mid = root;
		}
		else{
			sec = root;
		}
	}
	
	prev = root;
	
	correct_btree(root->right, prev, mid, first, sec);
}

correct_btree_handler(BTreeNode*& root){
	BTreeNode* prev = nullptr;
	BTreeNode* mid = nullptr;
	BTreeNode* first = nullptr;
	BTreeNode* sec = nullptr;
	
	correct_btree(root, prev, mid, first, sec);
	
	if(first && sec){
		swap(first->data, sec->data);
	}
	else if(first){
		swap(first->data,mid->data);
	}
}

int main(){
	int inp[] = {25,10,6,15,30,26,50};
	int size = sizeof(inp)/sizeof(int);
	
	BTreeNode* root = new BTreeNode();
	root->data = inp[0];
	
	for(int idx = 1; idx < size; idx++){
		insert_BST(root, inp[idx]);
	}
	
	vector<int> inorder_list;
	
	inorder(root, inorder_list);
	print_vector(inorder_list);	
		
	inorder_list.clear();
	corrupt_BST_Handler(root);		
	inorder(root, inorder_list);
	print_vector(inorder_list);
		
	inorder_list.clear();
	correct_btree_handler(root);
	inorder(root, inorder_list);
	print_vector(inorder_list);	
	
	return 0;
}
