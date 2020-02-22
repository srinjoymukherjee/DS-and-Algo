#include <iostream>

using namespace std;

template<class T> class SmartPtr
{
    T* m_ptr;
    public:
    SmartPtr(T* ptr = nullptr) : m_ptr(ptr){}
    SmartPtr(SmartPtr& sptr);

    ~SmartPtr()
    {
        delete m_ptr;
        m_ptr = nullptr;
    }

    T& operator*(){ return *m_ptr; }
    T* operator->(){ return m_ptr; }
    SmartPtr& operator=(SmartPtr& sptr);
    bool isNull(){ return this == nullptr; }
};

template<typename T>
SmartPtr<T>::SmartPtr(SmartPtr& sptr)
{
    this->m_ptr = sptr.m_ptr;
    sptr.m_ptr = nullptr;
}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator=(SmartPtr& sptr)
{
    if(&sptr == this)
        return *this;

    if(this->m_ptr){
        delete this->m_ptr;
        this->m_ptr = nullptr;
    }
    this->m_ptr = sptr.m_ptr;
    sptr.m_ptr = nullptr;
    return *this;
}

class Resource
{
    string m_val;
    public:
    Resource(string val) : m_val(val)
    {
        cout<<val<<" : Resource Acquired"<<endl;
    }
    ~Resource()
    {
        cout<<m_val<<" : Resource Destroyed"<<endl;
    }
    friend ostream& operator<<(ostream& out, Resource& r)
    {
        out<<r.m_val;
        return out;
    }
    Resource& operator=(string val)
    {
        this->m_val = val;
        cout<<m_val<<" : Resource: Assignement Operator Called"<<endl;
        return *this;
    }
};

int main()
{
    auto *res = new Resource("ptr1");
    SmartPtr<Resource> ptr1(res);
    SmartPtr<Resource> ptr2(ptr1);  
    *ptr2 = "ptr2";
    cout<<*ptr2<<endl;
    auto ptr3 = ptr2;
    cout<<*ptr3<<endl;
}