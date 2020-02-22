#include <iostream>

using namespace std;

template<class T>
class myPtr
{
    T* m_ptr;
    public:
    myPtr()
    {
        m_ptr = nullptr;
    }
    myPtr(T* ptr)
    {
        m_ptr = ptr;
    }
    ~myPtr()
    {
        delete m_ptr;
        m_ptr = nullptr;
    }

    //Copy Constructor
    myPtr(const myPtr& mp)
    {
        cout<<"Copy Constructor called"<<endl;
        this->m_ptr = new T;
        *(this->m_ptr) = *(mp.m_ptr);
    }

    //Move Constructor 
    myPtr(myPtr&& mp)
    {
        cout<<"Move Constructor called"<<endl;
        this->m_ptr = mp.m_ptr;
        mp.m_ptr = nullptr;
    }

    //Copy Assignment
    myPtr& operator=(myPtr& mp)
    {
        cout<<"Copy Assignment Called"<<endl;

        if(this->m_ptr)
        {
            delete this->m_ptr;
            this->m_ptr = nullptr;
        }

        this->m_ptr = new T;
        *(this->m_ptr) = *(mp.m_ptr);

        return *this;
    }

    //Move Assignment
    myPtr& operator=(myPtr&& mp)
    {
        cout<<"Move Assignment Called"<<endl;
        if(this->m_ptr)
        {
            delete this->m_ptr;
            this->m_ptr = nullptr;
        }
        
        this->m_ptr = mp.m_ptr;
        mp.m_ptr = nullptr;
        return *this;
    }

    myPtr& operator*()
    {
        *(this->m_ptr);
    }

    myPtr* operator->()
    {
        this->m_ptr;
    }

    bool isNull()
    {
        return this->m_ptr == nullptr;
    }
};

class Resource
{
    public:
    Resource()
    {
        cout<<"Resource Allocated"<<endl;
    }

    ~Resource()
    {
        cout<<"Resource Deallocated"<<endl;
    }
};

myPtr<Resource> getResource()
{
    myPtr<Resource> res(new Resource);
    return res;
}

int main()
{
    myPtr<Resource> p1(new Resource);
    auto p2 = move(p1);
    auto p3(move(p2));

    myPtr<Resource> p4;
    p4 = move(p3);
    // auto p5 = move(getResource());
    return 0;
}