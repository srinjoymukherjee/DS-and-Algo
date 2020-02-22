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
    unique_ptr<Resource> p1{ new Resource("ptr") };
    cout<<*p1<<endl;
    auto p2 = move(p1);
    auto p3 = make_unique<Resource>("ptr3");
    //cout<<*p1<<endl;
    cout<<*p2<<endl;
    cout<<*p3<<endl;
}