#include<iostream>
using namespace std;

class CPhanSo {
private:
	int tu;
	int mau;
public:
	CPhanSo() {
		tu = 0;
		mau = 1;
	}
	CPhanSo(CPhanSo& a) {
		tu = a.tu;
		mau = a.mau;
	}
	friend istream& operator >> (istream&, CPhanSo&);
	friend ostream& operator << (ostream&, CPhanSo&);
	CPhanSo operator+(CPhanSo );
	CPhanSo operator-(CPhanSo );
	CPhanSo operator/(CPhanSo );
	CPhanSo operator*(CPhanSo );
};

int main() {
	CPhanSo A, B;
	cin >> A;
	cin >> B;
	CPhanSo kq;
	cout << "Tong 2 phan so:" << endl;
	kq = A+B;
	cout << kq;
	cout << "Hieu 2 phan so:" << endl;
	kq = A-B;
	cout << kq;
	cout << "Thuong 2 phan so:" << endl;
	kq = A/B;
	cout << kq;
	cout << "Tich 2 phan so:" << endl;
	kq = A*B;
	cout << kq;
	return 0;
}

istream& operator >> (istream& in, CPhanSo& a) {
	cout << "Nhap tu: ";
	in >> a.tu;
	cout << "Nhap mau: ";
	in >> a.mau;
	return in;
}
ostream& operator << (ostream& out, CPhanSo& a) {
	out << a.tu << "/" << a.mau << endl;
	return out;
}
CPhanSo CPhanSo::operator+(CPhanSo b) {
	CPhanSo temp;
	temp.tu = tu * b.mau + mau * b.tu;
	temp.mau = mau * b.mau;
	return temp;
}
CPhanSo CPhanSo::operator-(CPhanSo b) {
	CPhanSo temp;
	temp.tu = tu * b.mau - mau * b.tu;
	temp.mau = mau * b.mau;
	return temp;
}
CPhanSo CPhanSo::operator/(CPhanSo b) {
	CPhanSo temp;
	temp.tu = tu * b.mau;
	temp.mau = mau * b.tu;
	return temp;
}
CPhanSo CPhanSo::operator*(CPhanSo b) {
	CPhanSo temp;
	temp.tu = tu * b.tu;
	temp.mau = mau * b.mau;
	return temp;
}
