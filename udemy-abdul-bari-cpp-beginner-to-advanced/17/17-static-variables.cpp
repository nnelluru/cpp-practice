#include <iostream>

using namespace std;

class Test
{
    private:
        int a;
        int b;
    public:
        static int count;
        Test() {
            a = 10;
            b = 10;
            count++;
        }
};

//int Test::count = 0;

int main()
{
    Test t1;
    Test t2;

    cout <<t1.count<<endl;
    cout <<t2.count<<endl;
    cout <<Test::count<<endl;
}