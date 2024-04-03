#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class PhanSo{
private:
    int tu;
    int mau;
public:
    friend istream& operator >> (istream& in, PhanSo& a);
    friend ostream& operator << (ostream& out, PhanSo a);
    friend PhanSo RutGon(PhanSo& a);
};

istream& operator >> (istream& in, PhanSo& a) {
    in >> a.tu;
    do {
        in >> a.mau;
    } while (a.mau == 0);
    return in;
}

ostream& operator << (ostream& out, PhanSo a) {
    if (a.tu == 0) {
        out << a.tu << "/" << 1;
        return out;
    }
    RutGon(a);
    out << a.tu << "/" << a.mau<<endl;
    return out;
}

int GCD(int a, int b) {
    if (a == 0 || b == 0) {
        return a + b;
    }
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}

PhanSo RutGon(PhanSo& a) {
    if (a.tu == 0 || a.tu == 1)
        return a;
    int t = abs(a.tu);
    int m = abs(a.mau);
    while (t != m) {
        if (t > m)
            t = t - m;
        else
            m = m - t;
    }
    a.tu = a.tu / t;
    a.mau = a.mau / t;
    return a;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    PhanSo* a=new PhanSo[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    delete[] a;
    return 0;
}
