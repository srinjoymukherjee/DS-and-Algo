//Find 2nd largest element in a stack in O(1) times
//Consider pop operation also

#include <iostream>
#include <stack>

using namespace std;

template<class T>
class MyStack
{
    stack<T> max_stack;
    stack<T> sec_max_stack;
    stack<T> m_stack;

    public:
    MyStack(){}
    void push_val(T);
    void pop_val();
    T& get_sec_max();
};

template<typename T>
void MyStack<T>::push_val(T val)
{
    m_stack.push(val);

    if(max_stack.empty() && sec_max_stack.empty())
    {
        max_stack.push(val);
        sec_max_stack.push(val);
    }
    else if(val > max_stack.top())
    {
        auto temp = max_stack.top();
        max_stack.push(val);
        sec_max_stack.push(temp);
    }
    else if(val < max_stack.top() 
            && val > sec_max_stack.top())
    {
        sec_max_stack.push(val);
        auto temp = max_stack.top();
        max_stack.push(temp);
    }
    else
    {
        auto temp = max_stack.top();
        max_stack.push(temp);

        temp = sec_max_stack.top();
        sec_max_stack.push(temp);
    }  
}

template<typename T>
void MyStack<T>::pop_val()
{
    if(!m_stack.empty())
        m_stack.pop();

    if(!max_stack.empty())
        max_stack.pop();

    if(!sec_max_stack.empty())
        sec_max_stack.pop();
}

template<typename T>
T& MyStack<T>::get_sec_max()
{
    return this->sec_max_stack.top();
}

int main()
{
    MyStack<int> stack1;
    stack1.push_val(5);
    stack1.push_val(7);
    stack1.push_val(9);

    cout<<stack1.get_sec_max()<<endl;

    stack1.push_val(4);
    stack1.push_val(9);

    cout<<stack1.get_sec_max()<<endl;

    stack1.push_val(8);
    stack1.push_val(3);
    stack1.push_val(5);
    
    cout<<stack1.get_sec_max()<<endl;

    stack1.push_val(7);
    stack1.push_val(8);
    
    cout<<stack1.get_sec_max()<<endl;

    stack1.pop_val();

    cout<<stack1.get_sec_max()<<endl;

    stack1.push_val(4);
    stack1.push_val(2);

    cout<<stack1.get_sec_max()<<endl;

    return 0;
}
