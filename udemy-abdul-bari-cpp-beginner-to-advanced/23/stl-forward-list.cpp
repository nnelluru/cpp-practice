#include<iostream>
#include<forward_list>

using namespace std;

int main()
{
    forward_list<int> v = {10,20,30,40};
    v.push_front(50);
    v.push_front(60);
    v.pop_front();
    //C++11 feature
    /*for(int x:v) {
        cout <<x << endl;
    }*/
    forward_list<int>::iterator itr;

    for(itr=v.begin();itr !=v.end();itr++)
        cout << *itr << endl;

    return 0;
}