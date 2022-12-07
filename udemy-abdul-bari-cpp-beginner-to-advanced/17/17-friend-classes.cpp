#include <iostream>

using namespace std;

class Your;

class My
{
    private:
        int a;
    protected:
        int b;
    public:
        int c;

    friend class Your;
};

class Your
{
    public:
        My m;
        void fun()
        {
            m.a = 10;
            m.b = 20;
            m.c = 30;

            cout << m.a <<", " << m.b << ", " << m.c << endl;
        }
};

int main()
{
    Your y;
    y.fun();
    return 0;
}