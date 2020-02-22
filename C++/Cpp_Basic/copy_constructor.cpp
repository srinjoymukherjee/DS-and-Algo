#include <iostream>

using namespace std;

class FruitBasket
{
    long busket_id;
    int* fruits = new int[5];
public:
    FruitBasket(long id, int* fruit = nullptr)
        : busket_id(id), fruits(fruit) {}

    FruitBasket(): FruitBasket(0){}

    FruitBasket(const FruitBasket& fb)
    {
        cout<<"calling copy constructor"<<endl;
        this->busket_id = fb.busket_id;

        if(this->fruits)
        {
            delete[] fruits;
            this->fruits = nullptr;
        }

        this->fruits = new int[5];

        for(size_t idx = 0; idx < 4; idx++)
        {
            this->fruits[idx] = fb.fruits[idx];
        }
    }

    FruitBasket& operator=(const FruitBasket& fb)
    {
        cout<<"calling copy constructor"<<endl;
        this->busket_id = fb.busket_id;

        if(this->fruits)
        {
            delete[] fruits;
            this->fruits = nullptr;
        }

        this->fruits = new int[5];

        for(size_t idx = 0; idx < 4; idx++)
        {
            this->fruits[idx] = fb.fruits[idx];
        }

        return *this;
    }

    void printBasket(){
        for(size_t idx = 0; idx < 4; idx++)
        {
            cout<<fruits[idx]<<" ";
        }
        cout<<endl;
    }

    void setFruits(int num)
    {
        this->fruits[0] = num;
    }

};

int main()
{
    int a[] = {1,2,3,4};
    int b[] = {5,6,7,8};
    FruitBasket fr1(7, a);
    FruitBasket fr2(fr1);    
    FruitBasket fr3;
    fr3 = fr1;
    fr2.setFruits(99);
    fr3.setFruits(777);
    fr2.printBasket();
    fr1.printBasket();
    fr3.printBasket();
}