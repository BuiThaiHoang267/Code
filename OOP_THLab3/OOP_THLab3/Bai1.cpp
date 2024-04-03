#include<iostream>
using namespace std;

class MYINT {
private: 
    int A;
public:
    MYINT() {
        A = 0;
    }
    MYINT(int a) {
        A = a;
    }
    friend ostream& operator << (ostream& out, MYINT a);
    MYINT operator + (MYINT a);
    MYINT operator * (MYINT a);
    ~MYINT(){}
};
ostream& operator << (ostream& out, MYINT a) {
    out << a.A << endl;
    return out;
}
MYINT MYINT::operator+(MYINT a) {
    MYINT b;
    b.A = A - a.A;
    return b;
}
MYINT MYINT::operator*(MYINT a) {
    MYINT b;
    b.A = A * a.A;
    return b;
}

int main() {
    MYINT a(4), b(5);
    cout << (a + b) * a;
    cout << a * b;
    system("pause");
    return 0;
}