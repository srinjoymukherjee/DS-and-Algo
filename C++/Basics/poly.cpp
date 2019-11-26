#include <iostream>

using namespace std;


class Animal
{
	string a_type;
	int a_legs;
public:
	Animal()
	{
		a_type = "???";
		a_legs = 0;
	}
	Animal(string type, int legs = 4) : a_type(type), a_legs(legs)
	{}
	virtual string getType() const;
	int getLegs() const;
};

string Animal::getType() const
{
	return a_type;
}

int Animal::getLegs() const
{
	return a_legs;
}

class Mamal : public Animal
{
	string m_type;
	int m_legs;
public:
	Mamal() = delete;
	Mamal(string type, int legs = 4) : m_type(type), m_legs(legs)
	{
		//Animal(type,legs);
	}
	string getType() const;
	int getLegs() const;
};

string Mamal::getType() const
{
	return m_type;
}

int Mamal::getLegs() const
{
	return m_legs;
}

int main()
{
	Animal* a = new Animal("Eagle", 2);
	cout<<a->getType()<<endl;
	Animal* m = new Mamal("Horse");
	cout<<m->getType()<<endl;
	return 0;
}
