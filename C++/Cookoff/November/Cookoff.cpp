#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void calc_skill(vector<map<string, int> > m_vect, vector<map<string, int> > q_vect, int n){
	vector<int> v_skill;
	cout<<m_vect.size()<<endl;
    for(int idx = 1; idx <= n; idx++){
    	int skill = 0;
        for(auto itr = q_vect.begin(); itr != q_vect.end(); itr++){
            int a = (*itr)["a"];
            int b = (*itr)["b"];
			for(int q_idx = a; q_idx<=b; q_idx++){
				auto m_itr = m_vect.begin();
				if(m_vect.size() > q_idx - 1)
					advance(m_itr, q_idx);
				else
					break;
				cout<<(*m_itr)["l"]<<" "<<idx<<" "<<(*m_itr)["r"]<<endl;	
				if((*m_itr)["l"] <= idx <= (*m_itr)["r"]){
					if((*m_itr)["x"] >= 0){
						skill += (*m_itr)["x"];
					}
				}
			}			
        }
    
	        
    }
    
    for(auto itr = v_skill.begin(); itr != v_skill.end(); ++itr){
	    	cout<<*itr<<" ";
		}
    
//    return v_skill;
}

int main() {
	int t, n, m , q;
	cin>>t;
	map<string,int> m_map;
	vector< map<string,int> > m_vect;
	map<string,int> q_map;
	vector< map<string,int> > q_vect;
	
	for(int i = 0; i<t; i++){
	    cin>>n;
	    cin>>m;
	    cin>>q;
	    for(int j = 0; j<m; j++){
	        cin>>m_map["l"];
	        cin>>m_map["r"];
	        cin>>m_map["x"];
	        m_vect.push_back(m_map);
	    }
	    
	    for(int k = 0; k<q; k++){
	        cin>>q_map["a"];
	        cin>>q_map["b"];
	        q_vect.push_back(q_map);
	    }
	    
	    calc_skill(m_vect, q_vect, n);
	    
		cout<<endl;
	}
	
	return 0;
}

