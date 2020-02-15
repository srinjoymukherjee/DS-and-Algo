#include<bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> prep_map_of_val(vector<string>);
void search_anagrams(vector<string>);

int main()
{
    vector<string> inp = {"cat", "dog", "tac", "god", "act"};
    search_anagrams(inp);
    return 0;
}

void search_anagrams(vector<string> vect)
{
    size_t num_of_anagrams = 0;
    unordered_map<string, vector<string>> m_val = 
        prep_map_of_val(vect);

    for(auto itr = m_val.begin(); itr != m_val.end(); itr++){
        if(itr->second.size() > 1){
            num_of_anagrams += itr->second.size();
            
            for(auto val : itr->second)
            {
                cout<<val<<" ";
            }
        }
        cout<<endl;
    }
}

unordered_map<string, vector<string>> prep_map_of_val(vector<string> vect){
    unordered_map<string, vector<string>> m;

    for(auto val : vect){
        auto orig_val = val;
        sort(val.begin(), val.end());
        m[val].push_back(orig_val);
    }
    return m;
}