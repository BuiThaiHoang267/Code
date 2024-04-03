#include<iostream>
#include<cmath>
using namespace std;

class CDiemKhongGian {
private:
	float x;
	float y;
	float z;
public:
	CDiemKhongGian() {
		x = y = z = 0;
	}
	friend istream& operator >> (istream&, CDiemKhongGian&);
	friend ostream& operator << (ostream&, CDiemKhongGian&);
	float KhoangCach(CDiemKhongGian);
};

int main() {
	CDiemKhongGian O, A;
	cout << "Nhap toa do O!" << endl;
	cin >> O;
	cout << "Nhap toa do A!" << endl;
	cin >> A;
	cout << "\nToa do O la ";
	cout << O;
	cout << "\nToa do A la ";
	cout << A;
	cout << "\nKhoang cach giua 2 diem O va A la: ";
	cout<<O.KhoangCach(A);
	return 0;
}

istream& operator >> (istream& in, CDiemKhongGian& a) {
	cout << "Nhap x: ";
	in >> a.x;
	cout << "Nhap y: ";
	in >> a.y;
	cout << "Nhap z: ";
	in >> a.z;
	return in;
}
ostream& operator << (ostream& out, CDiemKhongGian& a) {
	out << "(" << a.x << "," << a.y << "," << a.z << ")" << endl;
	return out;
}

float CDiemKhongGian::KhoangCach(CDiemKhongGian a) {
	return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2) + pow(z - a.z, 2));
}