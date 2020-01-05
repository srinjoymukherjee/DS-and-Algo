#include<bits/stdc++.h>

using namespace std; 
  
// Returns true if n is perfect 
bool isPerfect(int64_t n) 
{ 
    // To store sum of divisors 
    int64_t sum = 1;
    
    for(size_t idx = 2; idx <= sqrt(n); idx++){
    	if(n%idx == 0){
    		if(idx != sqrt(n))
    			sum = sum + idx + n/idx;
    		else
    			sum = sum + idx;
		}
    	
	}
	
	if(sum == n && n!= 1){
		return true;
	}
	
	return false;
} 
   
// Driver program 
int main() 
{ 
    cout << "Below are all perfect numbers till 10000\n"; 
    for (int n = 2;n < 10000; n++) 
        if (isPerfect(n)){
        	cout << n << " is a perfect number\n"; 
		} 
            
   
    return 0; 
}
