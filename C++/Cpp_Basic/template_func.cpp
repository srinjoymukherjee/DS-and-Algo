#include<iostream>

using namespace std;

template <typename T>
T add_here(T& a, T& b)
{
    return a + b;
}

int main()
{
    int a = 3, b = 8;
    cout<<add_here(a,b)<<endl;

    double c = 1.3, d = 3.8;
    cout<<add_here(c, d)<<endl;
}