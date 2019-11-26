#include <iostream>

using namespace std;

int main(){
	int i = 0, n = 5;
	while((1<<i) < n)
	{
		i++;
	}
	cout<<(i - 1)<<endl;	
	return 0;
}
