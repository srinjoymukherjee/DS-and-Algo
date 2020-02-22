#include<iostream>
#include<string>
#include<cstring>

using namespace std;

template<class T>
class Register
{
    T m_val;
    public:
    Register() = default;
    Register(T val) : m_val(val){}
    T getVal();
};

template<typename T>
T Register<T>::getVal()
{
    return m_val;
}

template<>
class Register<double>
{
    double m_val;
    public:
    Register() = default;
    Register(double val) : m_val(val){}
    double getVal()
    {
        return m_val;
    }
    friend ostream& operator<<(ostream& out, Register<double> r);
};

template<typename T>
class Register<T*>
{
    T* m_val;
    public:
    Register() = default;
    Register(T* val)
    {
        m_val = new T(*val);
    }
    T* getVal();
};

template<typename T>
T* Register<T*>::getVal()
{
    return m_val;
}

template<>
Register<char*>::Register(char* val)
{
    int length = strlen(val);
    m_val = new char[length + 1];
    m_val[length] = '\0';
    cout<<length<<endl;
    for(size_t idx = 0; idx < length; idx++)
    {
        m_val[idx] = val[idx];
    }
}

ostream& operator<<(ostream& out, Register<int> r)
{
    out<<r.getVal();
    return out;
}

ostream& operator<<(ostream& out, Register<double> r)
{
    out<<r.getVal();
    return out;
}

template<class T, int size>
class myArr
{
    T m_arr[size];
    int m_idx;

    public:
    myArr()
    {
        m_idx = 0;
    }

    void setVal(T val)
    {
        m_arr[m_idx++] = val;
    }

    T& operator[](int);    
};

template<typename T, int size>
T& myArr<T,size>::operator[](int idx)
{
    return m_arr[idx];
}

template<int size>
class myArr<char, size>
{
    char m_arr[size];
    int m_idx;

    public:
    myArr()
    {
        m_idx = 0;
    }

    void setVal(char val)
    {
        m_arr[m_idx++] = val;
    }

    char& operator[](int);    
};

template<int size>
char& myArr<char,size>::operator[](int idx)
{
    return m_arr[idx];
}

int main()
{
    Register<int> r1(1);
    cout<<r1<<endl;
    
    Register<double> r2(1.3);
    cout<<r2<<endl;

    int* i = new int{9};
    Register<int*> r3(i);
    delete i;
    i = nullptr;
    cout<<*(r3.getVal())<<endl;

    string name_str = "Mantu";
    int length = name_str.length();
    char* str = new char[length];
    
    for(size_t idx = 0; idx < length; idx++)
    {
        str[idx] = name_str[idx];
    }
    str[length] = '\0';
    Register<char*> r4(str);
    delete[] str;
    str = nullptr;
    cout<<r4.getVal()<<endl;

    myArr<int,5> m1;
    m1.setVal(3);
    m1.setVal(5);
    cout<<m1[0]<<endl;

    myArr<char,5> m2;
    m2.setVal('s');
    m2.setVal('r');
    cout<<m2[0]<<endl;

    return 0;
}
