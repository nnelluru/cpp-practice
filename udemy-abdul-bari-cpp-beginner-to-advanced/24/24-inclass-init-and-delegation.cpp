#include <iostream>

using namespace std;

class Test
{
    int x = 10; //in class initialization - available in cpp 11
    int y = 20; //in class initialization - available in cpp 11
    public:
        Test(int a, int b)
        {
            x = a;
            y = b;
        }
        Test(): Test(1,1) {} // delegation of constructors. Calling one constructor from another.
        void Display()
        {
            cout << x << ", " << y << endl;
        }
};

int main()
{
    Test t;

    t.Display();

    Test t2(5, 6);
    t2.Display();

    return 0;
}

