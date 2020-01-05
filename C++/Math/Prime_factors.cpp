#include <bits/stdc++.h> 
using namespace std; 
  
// A function to print all prime  
// factors of a given number n  
void primeFactors(int n)  
{  
    //Check whether 2 is a prime factor
	while(n%2 == 0){
    	n = n/2;
    	cout<<2<<" ";
	}
      
    //check for prime factor in the remaining odd Number  
    for(size_t i = 3; i < sqrt(n); i = i+2){
    	while(n%i == 0){
    		n = n/i;
    		cout<<i<<" ";
		}
	}
	
	//This condition is to handle the case 
	//when the remaining n is a prime number greater than 2  
	if(n > 2)
		cout<<n;
		
	cout<<endl;
}  
  
/* Driver code */
int main()  
{  
    int n = 35343;  
    primeFactors(n);  
    return 0;  
}
