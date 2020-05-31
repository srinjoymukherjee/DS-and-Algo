/*
Given a string of length N of lowercase alphabet characters. 
The task is to count the total number of distinct substrings of this string.
*/
#include <iostream>
#include <vector>

#define NUM_OF_CHAR 26

using namespace std;

class Suffix_Trie
{
    size_t term;
    vector<Suffix_Trie*> child_array;
    static size_t node_count;

public:
    Suffix_Trie()
    {
        term = 0;
        child_array.assign(NUM_OF_CHAR, nullptr);
        node_count++;
    }

    void insert_suffix(string key)
    {    
        /*
            Inserting all suffixes
            ----------------------
            if we are having "ababa" as key, then suffixes are:
            "" -----------------------> This is counted, when "root" is created
            a, ab, aba, abab, ababa --> All of these are inserted into trie,
                                        when first suffix set "ababa" is inserted
            b, ba, bab, baba ---------> All of these are inserted into trie,
                                        when second suffix set "baba" is inserted
        */    
        for(size_t pref = 0; pref < key.size(); pref++)
        {
            Suffix_Trie* head = this;
            for(size_t suff = pref; suff < key.size(); suff++)
            {
                if(!head->child_array[key[suff] - 'a'])
                {
                    head->child_array[key[suff] - 'a'] = new Suffix_Trie;
                }
                head = head->child_array[key[suff] - 'a'];
            }
        }
    }

    //Every node in the try corresponds
    //to one of the possible suffixes
    size_t get_node_count()
    {
        return node_count;
    }
};

size_t Suffix_Trie::node_count = 0;

int main()
{
    Suffix_Trie trie;
    string key = "abcd";

    trie.insert_suffix(key);
    cout<<trie.get_node_count()<<endl;

    return 0;
}