#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
    public:
        virtual float fun() final
        {
            return 2.34f;
        }
};

class Derived: public Base
{
    public:
        // float fun() 
        // {
        //     return 5.46f;
        // }
};


int main()
{
    Derived d;
    auto x = d.fun();
    cout << x << endl;
}