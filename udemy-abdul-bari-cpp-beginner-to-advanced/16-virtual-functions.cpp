#include <iostream>

using namespace std;

class Base
{
    public:
        //need to make this function virtual to call the derived class function
        /* virtual void fun() {
            cout << "fun of base" << endl;
        } */
        virtual void fun() = 0;
};

class Derived1: public Base {
    public:
        void fun() {
            cout << "fun of derived1" << endl;
        }
};

class Derived2: public Base {
    public:
        void fun() {
            cout << "fun of derived2" << endl;
        }
};

int main()
{
    Derived1 d;
    Base *p = &d;
    p->fun();
    p = new Derived2;
    p->fun();
}