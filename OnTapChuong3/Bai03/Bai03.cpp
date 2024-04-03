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
	friend istream& operator >> (istream&, CPhanSo&);
	friend ostream& operator << (ostream&, CPhanSo&);
	int SoSanh(CPhanSo);
};


int main() {
	CPhanSo A, B;
	cin >> A >> B;
	if (A.SoSanh(B) == 1)
		cout << A;
	else
		cout << B;
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
int CPhanSo::SoSanh(CPhanSo a) {
	float X = (float)tu / mau;
	float Y = (float)a.tu / a.mau;
	if (X >= Y)
		return 1;
	else
		return 0;
}
