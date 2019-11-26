#include <iostream>
#define INCREMENT(x) ++x

using namespace std;

int main(){
	char* name = "Tanmoyee";
	int a[] = {1,4,9,2};
	int *b = new int;
	*b = 10;
	cout<<sizeof(name)<<endl;
	cout<<name<<endl;
	cout<<INCREMENT(name)<<endl;
	cout<<*a<<endl;
	cout<<a<<endl;
	//int *b = INCREMENT(a);
	cout<<"Size of b:\t"<<sizeof(b)<<endl;
	cout<<*(a + 1)<<endl;
	return 0;
}
