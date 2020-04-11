//Huffman Coding

#include <bits/stdc++.h>

using namespace std;

typedef struct tree_node
{
    pair<string, int> data;
    tree_node* left;
    tree_node* right;
} tree;

typedef tree* btree;

class compare_btree
{
public:
    bool operator()(btree bt1, btree bt2)
    {
        return bt1->data.second > bt2->data.second;
    }
};

btree build_hfm_cd_tree(unordered_map<string, int> leaf)
{    
    btree root = nullptr;
    priority_queue<btree, vector<btree>, compare_btree> nodes;

    for(auto l : leaf)
    {
        btree bt = new tree;
        bt->data = l;    
        bt->left = nullptr;
        bt->right = nullptr;
        nodes.push(bt);
    }

    while(!nodes.empty())
    {
        btree lt = nodes.top();
        nodes.pop();

        btree rt = nodes.top();
        nodes.pop();

        btree r = new tree;

        r->data.second = lt->data.second + rt->data.second;        
        r->left = lt;
        r->right = rt;

        if(!nodes.empty()){
            r->data.first = "Inter";        
            nodes.push(r);
        }
        
        r->data.first = "Root"; 
        root = r;       
    }
    return root;
}

void prepareCode(btree bt, list<int> code, map<string, list<int> > &ret)
{
    if(bt->left == nullptr && bt->right == nullptr)
    {
        ret.insert({bt->data.first, code});
        return;
    }

    if(bt->left)
    {
        code.push_back(0);
        prepareCode(bt->left, code, ret);
        code.pop_back();
    }

    if(bt->right)
    {
        code.push_back(1);
        prepareCode(bt->right, code, ret);
        code.pop_back();
    }

    return;
}

int main()
{
    unordered_map<string, int> leaf;
    list<int> raw_code;
    map<string, list<int> > huff_code;

    //insert input
    leaf.insert({"a", 5});
    leaf.insert({"b", 9});
    leaf.insert({"c", 12});
    leaf.insert({"d", 13});
    leaf.insert({"e", 16});
    leaf.insert({"f", 2});
    leaf.insert({"g", 20});

    btree root = build_hfm_cd_tree(leaf);
    prepareCode(root, raw_code, huff_code);

    for(auto code : huff_code)
    {
        cout << code.first <<": ";
        for(auto val : code.second)
            cout<<val<<" ";
        
        cout<<endl;
    }
    return 0;
}