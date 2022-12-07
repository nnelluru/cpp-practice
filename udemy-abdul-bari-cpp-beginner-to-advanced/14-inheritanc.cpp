#include <iostream>

using namespace std;

//constructors in inheritance

class Base
{
    public:
        Base()
        {
            cout <<"Default of Base"<<endl;
        }
        Base(int x)
        {
            cout << "param of Base"<< x << endl;
        }
};

class Derived: public Base
{
    public:
        Derived()
        {
            cout << "Default of Derived" << endl;
        }
        Derived(int a)
        {
            cout << "Param of Derived" << a << endl;
        }
        Derived(int x, int a):Base(x)
        {
            cout << "Param of Derived" << a << endl;
        }
};

int main()
{
    Derived d1;
    Derived d2(10);
    Derived d3(20, 30);
    return 0;
}