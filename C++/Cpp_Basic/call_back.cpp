#include <iostream>
#include <climits>

using namespace std;

enum calc
{
    ADD,
    SUB
};

template<typename T> T default_func(T a, T b) 
{
    return INT_MIN;
}

template<typename T> T add(T a, T b) 
{
    return (a + b);
}

template<typename T> T sub(T a, T b) 
{
    return (a - b);
}

template<typename T>
void calculate(enum calc type, T (**func)(T, T))
{
    if(type == ADD)
        *func = add;
    else if(type == SUB)
        *func = sub;
}

int main()
{
    int (*func)(int, int) = default_func;
    calculate(SUB,&func);
    cout<<func(5,3);
}