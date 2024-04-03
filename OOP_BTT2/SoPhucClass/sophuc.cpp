#include<iostream>
using namespace std;

class SoPhuc {
private:
	int thuc;
	int ao;
public:
	friend istream& operator >> (istream& in, SoPhuc& a);
	friend ostream& operator << (ostream& out, SoPhuc a);
	SoPhuc operator + (SoPhuc a);
	SoPhuc operator - (SoPhuc a);
};

istream& operator >> (istream& in, SoPhuc& a) {
	cout << "\nNhap phan thuc: ";
	in >> a.thuc;
	cout << "Nhap phan ao: ";
	in >> a.ao;
	return in;
}

ostream& operator << (ostream& out, SoPhuc a) {
	out << a.thuc << " + " << a.ao << "i";
	out << endl;
	return out;
}

SoPhuc SoPhuc::operator + (SoPhuc a) {
	SoPhuc c;
	c.thuc = this->thuc + a.thuc;
	c.ao = this->ao + a.ao;
	return c;
}

SoPhuc SoPhuc::operator-(SoPhuc a) {
	SoPhuc c;
	c.thuc = this->thuc - a.thuc;
	c.ao = this->ao - a.ao;
	return c;
}

int main() {
	SoPhuc a, b;
	cout << "Nhap so phuc a";
	cin >> a;
	cout << "Nhap so phuc b";
	cin >> b;
	cout << a + b;
	cout << endl;
	cout << a;
	return 0;
}