#include <iostream>
#include <map>

using namespace std;

void mod_map(map <string, int> &age_map)
{
	age_map["Gopu"] = 1;
}

int main(){
	map <string, int> age_map;
	age_map.insert({"Mantu",26});
	age_map["Tatai"] = 32;
	mod_map(age_map);
	for(map<string, int>::iterator itr = age_map.begin(); 
		itr != age_map.end(); ++itr)
		cout<<"Name: "<<itr->first<<"\tAge: "<<itr->second<<endl;
	return 0;
}
