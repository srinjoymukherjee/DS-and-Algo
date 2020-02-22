#include<bits/stdc++.h>

using namespace std;

enum CityType
{
    METRO,
    NONMETRO
};

class City
{
protected:
    int cityType;
    string cityName;
public:
    City()
    {
        cityType = 0;
        cityName = "Default";
    }

    virtual void setCityName(string name)
    {
        cityName = "Default";
    }
    virtual string getCityName()
    {
        return "Default";
    }
    virtual int getCityType()
    {
        return 0;
    }
};

class NonMetro : public City
{
public:
    NonMetro(int type){
        cityType = type;
    }
    virtual void setCityName(string name);
    virtual string getCityName();
    virtual int getCityType();
};

void NonMetro::setCityName(string name)
{
    cityName = name;
}

string NonMetro::getCityName()
{
    return cityName;
}

int NonMetro::getCityType()
{
    return cityType;
}

int main()
{
    NonMetro nm(NONMETRO);
    City& c1 = nm;
    cout<<c1.getCityType()<<endl;
    c1.setCityName("Krishnagar");
    cout<<c1.getCityName()<<endl;
    return 0;
}