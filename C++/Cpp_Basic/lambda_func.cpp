#include <iostream>

using namespace std;

int main()
{
    int n = 5;
    auto var = [&n](){
        cout<<n<<endl;
        n = 50;
    };
    var();
    cout<<n<<endl;
}