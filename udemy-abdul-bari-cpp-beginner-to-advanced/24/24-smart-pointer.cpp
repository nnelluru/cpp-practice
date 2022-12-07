#include <iostream>

using namespace std;

class Rectangle
{
    int length;
    int breadth;
    public:
        Rectangle(int length, int breadth) {
            this->length = length;
            this->breadth = breadth;
        }

        int area()
        {
            return length*breadth;
        }
};

int main()
{
    /*
    unique_ptr<Rectangle> ptr(new Rectangle(10, 20));

    cout << ptr->area()<<endl;

    unique_ptr<Rectangle> ptr2; //not allowed error - error: call to deleted constructor of 'unique_ptr<Rectangle>'
    //ptr2 = ptr; //error: error: overload resolution selected deleted operator '='
    ptr2 = move(ptr);

    cout << ptr2->area()<<endl;
    */

   shared_ptr<Rectangle> ptr(new Rectangle(10,5));

   cout << ptr->area()<< endl;

   shared_ptr<Rectangle> ptr2 = ptr;

   cout << ptr2->area()<< endl;
   cout << ptr.use_count() << endl;
}