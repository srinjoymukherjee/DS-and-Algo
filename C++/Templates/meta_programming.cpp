#include <iostream>

using namespace std;

template<int size> struct fibo
{
    static constexpr int val = fibo<size - 2>::val + fibo<size - 1>::val;
};

template<> struct fibo<0>
{
    static constexpr int val = 0;
};

template<> struct fibo<1>
{
    static constexpr int val = 1;
};

int main()
{
    cout<<fibo<8>::val<<endl;
}