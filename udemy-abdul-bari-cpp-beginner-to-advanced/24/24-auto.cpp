#include <iostream>
#include <typeinfo>

using namespace std;

float fun()
{
    return 2.34f;
}

int main()
{
    double d=13.4;
    int i = 9;
    auto x = 2*d+i;

    cout <<x << typeid(x).name() << endl;

    auto y = fun();

    cout << y << endl;

    int a = 10;
    float b = 20.44;

    decltype(b) z = a*b;

    cout << z << endl;
}