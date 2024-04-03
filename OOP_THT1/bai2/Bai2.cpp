#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class PhanSo {
public:
    int tu;
    int mau;
    friend istream& operator >> (istream& in, PhanSo& a);
    friend ostream& operator << (ostream& out, PhanSo a);
    bool operator - (PhanSo a);
    PhanSo operator = (PhanSo& a);
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
        out << "0/1";
        return out;
    }
    out << a.tu << "/" << a.mau << endl;
    return out;
}

bool PhanSo::operator - (PhanSo a) {
    PhanSo c;
    c.tu = tu * a.mau - mau * a.tu;
    c.mau = mau * a.mau;
    float i = c.tu*1.0 / c.mau * 1.0;
    if (i < 0)
        return true;
    else return false;
}
PhanSo PhanSo::operator=(PhanSo& a) {
    this->tu = a.tu;
    this->mau = a.mau;
    return *this;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    PhanSo* a = new PhanSo[n];
    PhanSo Max, Min;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            Max = a[0];
            Min = a[0];
        }
        if (i >= 1) {
            Max = (Max-a[i]) ? a[i] : Max;
            Min = (a[i]-Min) ? a[i] : Min;
        }
    }
    cout << Min<<Max;
    delete[] a;
    return 0;
}
