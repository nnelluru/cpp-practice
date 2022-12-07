#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> v = {10,20,30,40};
    v.insert(50);
    v.insert(60);
    //v.();
    
    cout << "using iterator"<< endl;
    set<int>::iterator itr;
    for(itr=v.begin();itr !=v.end();itr++)
        cout << *itr << endl;

    cout << "using for each loop"<< endl;
    //C++11 feature
    for(int x:v) {
        cout <<x << endl;
    }
    return 0;
}