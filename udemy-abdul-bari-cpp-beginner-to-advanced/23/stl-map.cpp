#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int, string> m;
    m.insert(pair<int,string>(1, "Naresh"));
    m.insert(pair<int,string>(2, "Swathi"));
    m.insert(pair<int,string>(3, "Karthi"));
    m.insert(pair<int,string>(4, "Tejaswi"));
    //v.();
    
    cout << "using iterator"<< endl;
    map<int,string>::iterator itr;
    for(itr=m.begin();itr !=m.end();itr++)
        cout << itr->first << " " << itr->second << endl;

    cout << "using for each loop"<< endl;
    //C++11 feature
    for(auto x:m) {
        cout <<x.first << " " << x.second << endl;
    }

    cout << "searching" << endl;
    map<int,string>::iterator findItr;

    findItr = m.find(5);
    if(findItr != m.end()) {
        cout << findItr->first << " " << findItr->second << endl;
    } else {
        cout << "not found"<<endl;
    }

    return 0;
}