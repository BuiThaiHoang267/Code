#include<iostream>
#include<fstream>
using namespace std;

class CPhanSo {
private:
	int tu;
	int mau;
public:
	CPhanSo(){
		tu = 0;
		mau = 1;
	}
	friend istream& operator >> (istream&, CPhanSo&);
	friend ostream& operator << (ostream&, CPhanSo&);
	int XetDau();
};

int main() {
	CPhanSo A;
	cin >> A;
	cout << A;
	if (A.XetDau() == 1)
		cout << "\nPhan so A > 0";
	else if (A.XetDau() == -1)
		cout << "\nPhan so A < 0";
	else 
		cout << "\nPhan so A = 0";
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
int CPhanSo::XetDau() {
	float A = (float) tu / mau;
	if (A > 0)
		return 1;
	else if (A < 0)
		return -1;
	else return 0;
}
