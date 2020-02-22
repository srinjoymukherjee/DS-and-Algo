#include <iostream>
#include <memory>

using namespace std;

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
};

int main()
{
    shared_ptr<Resource> p1{ new Resource("ptr1")};
    cout<<*p1<<endl;
    
    auto p2 = p1;
    // cout<<*p2<<endl;
    cout<<*(p2.get())<<endl;

    auto p3 = make_unique<Resource>("ptr3");    
    cout<<*p3<<endl;

    auto p4 = move(p3);
    cout<<*p4<<endl;
}