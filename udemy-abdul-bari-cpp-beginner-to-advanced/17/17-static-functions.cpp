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
        static int getCount(){
            return count;
        }
};

//int Test::count = 0;

int main()
{
    cout << Test::getCount()<<endl;
    Test t1;
    cout <<t1.count<<endl;
    Test t2;
    cout <<t2.count<<endl;
    cout <<Test::count<<endl;
}