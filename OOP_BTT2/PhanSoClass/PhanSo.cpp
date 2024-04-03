#include<iostream>
using namespace std;

class PhanSo {
private:
	int tu;
	int mau;
public:
	PhanSo() {
		tu = 0;
		mau = 1;
	}
	friend istream& operator >> (istream& in, PhanSo& a);
	friend ostream& operator << (ostream& out, PhanSo a);
	PhanSo operator + (PhanSo a);
	PhanSo operator - (PhanSo a);
	PhanSo operator * (PhanSo a);
	PhanSo operator / (PhanSo a);
	friend PhanSo RutGon(PhanSo& a);
	~PhanSo() {
		cout << "goi ham huy" << endl;
	}
};

istream& operator >> (istream& in, PhanSo& a) {
	cout << "\nNhap tu: ";
	in >> a.tu;
	cout << "Nhap mau: ";
	in >> a.mau;
	cout << endl;
	return in;
}

ostream& operator << (ostream& out, PhanSo a) {
	out << a.tu << "/" << a.mau;
	cout << endl;
	return out;
}

PhanSo PhanSo::operator+(PhanSo a) {
	PhanSo c;
	c.tu = this->tu * a.mau + this->mau * a.tu;
	c.mau = this->mau * a.mau;
	RutGon(c);
	return c;
}

PhanSo PhanSo::operator-(PhanSo a) {
	PhanSo c;
	c.tu = this->tu * a.mau - this->mau + a.tu;
	c.mau = this->mau * a.mau;
	RutGon(c);
	return c;
}

PhanSo PhanSo::operator*(PhanSo a) {
	PhanSo c;
	c.tu = this->tu * a.tu;
	c.mau = this->mau * a.mau;
	RutGon(c);
	return c;
}

PhanSo PhanSo::operator/(PhanSo a) {
	PhanSo c;
	c.tu = this->tu * a.mau;
	c.mau = this->mau * a.tu;
	RutGon(c);
	return c;
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

int main()
{
	PhanSo a, b;
	cin >> a;
	cin >> b;
	RutGon(a);
	cout << a;
	return 0;
}