#include <iostream>

using namespace std;

/*
E.g.1 - [](){cout << "Hello" <<endl;};
To execute the function immediately use parentheses at the end as shown below.
[](){cout << "Hello" << endl;}();

E.g.2 - [](int x, int y){ cout << "Sum: " << x+y<< end;}(10, 5);
E.g.3 - int(auto) x = [](int x, int y){return x+y;}(10.20);
E.g.4 - auto f = [](){cout << "hello"<<endl;};
              f();
E.g.5 - int(auto) a = [](int x, int y)->int {return x+y;}(10, 30);
E.g.6 - int main()
int a=10, b=20;
[a, b] (){cout << a<< b<< endl;}();
E.g.7 -
[&a, &b](){cout << ++a<< ++b<< endl;}();
E.g.8 -
[&]()(){cout << ++a<< ++b<< endl;}();
E.g. 9 - can be passed to a function
*/

//E.g. 9
template<typename T>
void fun(T p)
{
    p();
}

int main()
{
    //E.g. 1
    [](){cout <<"hello" << endl;}();
    //E.g. 2
    [] (int x, int y){cout << "Sum: " << x+y << endl;} (10, 5);
    //E.g. 3
    auto a = [] (int x, int y){return x+y;}(10, 20);
    cout << a << endl;

    //E.g.5
    int b = [] (int x, int y)->int {return x+y;}(20, 30);
    cout << b << endl;

    //E.g.4
    auto f = [] (int x, int y)->int {return x+y;};
    int c = f(30, 40);
    //cout << c << endl;

    //E.g. 6
    [c](){cout << c <<endl;}();
    //cout << c << endl;

    //E.g. 7
    auto f2 = [&c](){cout << ++c <<endl;};
    fun(f2);
    c++;
    fun(f2);
    //cout << c << endl;

}