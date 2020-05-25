#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define NUM_OF_CHAR 26

using namespace std;

class TrieNode
{
    public:
    size_t term;
    vector<TrieNode*> child_list;
    TrieNode()
    {
        child_list.assign(NUM_OF_CHAR, nullptr);
        term = 0;
    }
};

class Trie
{
    TrieNode* root;
    public:
    Trie()
    {
        root = new TrieNode();
        root->term = 0;
    }

    void insert_trie(string key)
    {
        TrieNode* current = root;
        for(size_t idx = 0; idx < key.length(); idx++)
        {
            if(current->child_list[int(key[idx] - 'a')] == nullptr)
            {
                current->child_list[int(key[idx] - 'a')] = new TrieNode();
            }
            current = current->child_list[int(key[idx] - 'a')];
            // cout<<current<<endl;
        }  
        current->term++;     
    }

    size_t query_trie(string key)
    {
        TrieNode* current = root;
        for(size_t idx = 0; idx < key.length(); idx++)
        {
            if(current->child_list[int(key[idx] - 'a')] == nullptr)
            {
                return 0;
            }
            current = current->child_list[int(key[idx] - 'a')];
        } 
        return current->term;
    }

    void delete_trie(string key)
    {
        TrieNode* head = root;

        //Using double pointer stack to avoid shallow copy
        stack<TrieNode**> parent;

        for(size_t idx = 0; idx < key.length(); idx++)
        {
            if(head->child_list[int(key[idx] - 'a')] == nullptr)
            {
                return;
            }            

            //Deep copying every node to the stack             
            parent.push(&head->child_list[int(key[idx] - 'a')]);

            //Shallow copying next value to 'head'
            head = head->child_list[int(key[idx] - 'a')];
        } 
        // cout<<endl;
        head->term = 0;
        while(!parent.empty())
        {
            TrieNode** temp = parent.top(); //Deep Copy
            parent.pop();
            // cout<<*temp<<endl;

            if(all_of((*temp)->child_list.begin(), 
                      (*temp)->child_list.end(),
                        [](TrieNode* node)
                        {
                            return node == nullptr;
                        }))
            {
                delete *temp;
                *temp = nullptr;
            }
            else
            {
                break;
            }            
        }
    }
};

int main()
{
    Trie new_trie;
    new_trie.insert_trie("pqrs");
    new_trie.insert_trie("srinjoy");
    new_trie.insert_trie("pqrs");

    cout<<new_trie.query_trie("pqrs")<<endl;

    new_trie.insert_trie("srpt");
    new_trie.insert_trie("xyz");

    new_trie.delete_trie("srinjoy");
    cout<<new_trie.query_trie("srinjoy")<<endl;

    new_trie.insert_trie("pqrstuvwxyz");
    new_trie.delete_trie("pqrstuvwxyz");

    cout<<new_trie.query_trie("pqrstuvwxyz")<<endl;
    new_trie.insert_trie("abcd");
    new_trie.insert_trie("abcdefghijklmnop");

    new_trie.delete_trie("abcd");
    cout<<new_trie.query_trie("abcd")<<endl;

    return 0;

}