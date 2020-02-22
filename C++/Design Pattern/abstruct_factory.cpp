#include<bits/stdc++.h>

using namespace std;

//<<Procuct>>
class City
{
    protected:
    string cityName;
    string cityLocation;
    public:
    City(){}
    virtual void setCityName(string name) = 0;
    virtual string getCityName() = 0;
    virtual void setCityLocation(string name) = 0;
    virtual string getCityLocation() = 0;
};

//Concrete Product
class NonMetro : public City
{
    public:
    NonMetro(string name, string location)
    {
        string tempName = "Non Metro: " + name; 
        cityName = tempName;
        cityLocation = location;
    }
    
    void setCityName(string name)
    {
        string tempName = "Non Metro: " + name; 
        cityName = tempName;
    }

    string getCityName()
    {
        return cityName;
    }

    void setCityLocation(string location)
    {
        cityLocation += location;
    }

    string getCityLocation()
    {
        return cityLocation;
    }
};

//Concrete Product
class Metro : public City
{
    public:
    Metro(string name, string location)
    {
        string tempName = "Metro: " + name; 
        cityName = tempName;
        cityLocation = location;
    }
    void setCityName(string name)
    {
        string tempName = "Metro: " + name; 
        cityName = tempName;
    }

    string getCityName()
    {
        return cityName;
    }

    void setCityLocation(string location)
    {
        cityLocation += location;
    }

    string getCityLocation()
    {
        return cityLocation;
    }
};

//Abstract Factory
class Location
{
    public:
    Location(){}
    virtual City* getCity(string cityType) = 0;
};

//Concrete Factory
class NorthIndia : public Location
{
    public:
    NorthIndia(){}

    //Factory Method
    City* getCity(string cityType)
    {
        City *city;
        if(cityType == "Metro")
            city = new Metro("Kolkata", "North");
        else if(cityType == "Non Metro")
            city = new NonMetro("Krishnagar","North");
        
        return city;
    }
};

//Concrete Factory
class SouthIndia : public Location
{
    public:
    SouthIndia(){}

    //Factory Method
    City* getCity(string cityType)
    {
        City *city;
        if(cityType == "Metro")
            city = new Metro("Hyderabad", "South");
        else if(cityType == "Non Metro")
            city = new NonMetro("Warangle","South");
        
        return city;
    }
};

//Factory Producer
class Citylocator
{
    public:
    Citylocator(){}
    static Location* getCityByLocation(string loc_name)
    {
        Location* locate = nullptr;
        if(loc_name == "North")
        {
            locate = new NorthIndia;
        }
        else if(loc_name == "South")
        {
            locate = new SouthIndia;
        }
        return locate;
    }    
};

int main()
{
    Location* location = Citylocator::getCityByLocation("North");
    City* city = location->getCity("Metro");
    cout<<city->getCityName()<<endl;

    Location* location2 = Citylocator::getCityByLocation("South");
    City* city2 = location2->getCity("Non Metro");
    cout<<city2->getCityName()<<endl;
    return 0;
}
