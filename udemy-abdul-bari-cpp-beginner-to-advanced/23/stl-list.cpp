#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> v = {10,20,30,40};
    v.push_back(50);
    v.push_back(60);
    v.pop_back();
    //C++11 feature
    /*for(int x:v) {
        cout <<x << endl;
    }*/
    list<int>::iterator itr;

    for(itr=v.begin();itr !=v.end();itr++)
        cout << *itr << endl;

    return 0;
}