/*
Least Recently Used (LRU) Page Replacement algorithm
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

void printPage(unordered_set<int> page){
	for(auto itr : page){
		cout<<itr<<" ";
	}
	cout<<endl;
}

int lru_paging(int ip[], size_t size, size_t page_cap){
	unordered_map<int, int> index;
	unordered_set<int> page;
	int page_faults = 0;
	
	for(size_t idx = 0; idx < size; idx++){
		//Find if the Page Array (set) is Empty or the page has more capacity
		if(page.empty() || page.size() < page_cap){
			
			//If the page is not already present in the Page Array,
			//insert the page into the array
			if(page.find(ip[idx]) == page.end()){
				page.insert(ip[idx]);
				page_faults++;
			}
			
		}else{
			if(page.find(ip[idx]) == page.end()){
				size_t lru_idx = INT_MIN;
				int lru = INT_MIN;
				
				//Find the Least Recently Used Page
				for(auto itr : page){
					if(index[itr] < lru_idx){
						lru_idx = index[itr];
						lru = itr;
					}
				}
				
				//Erase the LRU Page
				page.erase(lru);
				
				page.insert(ip[idx]);
				page_faults++;
				
			}
		}	
		printPage(page);
		
		//Update the index of current page	
		index[ip[idx]] = idx;
	}
	
	return page_faults;
}

int main(){
	int ip[] = {3,3,400,45,1,67,10,1,2,2,2,45,3};
	size_t page_cap = 4;
	size_t size = sizeof(ip)/sizeof(int);
	cout<<"Number of Page Faults: "<<lru_paging(ip, size, page_cap);
		
	return 0;
}
