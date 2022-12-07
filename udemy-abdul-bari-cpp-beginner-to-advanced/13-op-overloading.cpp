#include <iostream>

using namespace std;

class Complex
{
    private:
        int real;
        int img;

    public:
        Complex(int real=0, int img=0) {
            this->real = real;
            this->img = img;
        }

        Complex add(Complex x);
        //Complex operator+(Complex x);
        void display();
        friend ostream & operator<<(ostream &s, Complex &c);
        friend istream & operator>>(istream &in, Complex &c);
        void operator=(Complex &c);

        //friend fucntion
        friend Complex operator+(Complex x, Complex y);
        
};

void Complex::display() {
    cout << this->real << "+i" << this->img << endl;
}

//Insertion operator
ostream & operator<<(ostream &s, Complex &c) {
    s << c.real << "+i" <<c.img << endl;
    return s;
}

//extraction operato
istream & operator>>(istream &in, Complex &c){
    in >> c.real;
    in >> c.img;
    return in;
}

void Complex::operator=(Complex &c) {
    real = c.real;
    img = c.img;
}

Complex Complex::add(Complex x) {
    Complex temp;
    temp.real = this->real + x.real;
    temp.img = this->img + x.img;
    return temp;
}

/*Complex Complex::operator+(Complex x) {
    cout << "operator overloaded" << endl;
    Complex temp;
    temp.real = this->real + x.real;
    temp.img = this->img + x.img;
    return temp;
}*/

Complex operator+(Complex x, Complex y) {
    cout << "operator overloaded via friend function" << endl;
    Complex temp;
    temp.real = x.real + y.real;
    temp.img = x.img + y.img;
    return temp;
}


int main()
{
    Complex c1(5, 10);
    Complex c2(15, 20);
    Complex c3 = c1.add(c2);
    cout << c3;
    //c3.display();
    Complex c4;
    Complex c5 = c4 + c2;
    cout << c5;
    operator<<(cout, c5);
    Complex c6;
    cin >>c6;
    cout << c6;
    Complex c7;
    c7 = c6;
    cout <<c7;
    //c5.display();
    return 0;
}