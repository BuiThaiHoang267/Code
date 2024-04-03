#include<iostream>
using namespace std;

struct sophuc {
	float thuc;
	float ao;
};
typedef struct sophuc SOPHUC;

void Nhap(SOPHUC&);
SOPHUC Tong(SOPHUC, SOPHUC);
SOPHUC Hieu(SOPHUC, SOPHUC);
SOPHUC Tich(SOPHUC, SOPHUC);
void Xuat(SOPHUC);

int main() {
	SOPHUC A, B;
	Nhap(A);
	Nhap(B);
	cout << "\nTong 2 phan so\n";
	Xuat(Tong(A, B));
	cout << "\nHieu 2 phan so\n";
	Xuat(Hieu(A, B));
	cout << "\nTich 2 phan so\n";
	Xuat(Tich(A, B));
	return 0;
}

void Nhap(SOPHUC& a) {
	cout << "Nhap thuc: ";
	cin >> a.thuc;
	cout << "Nhap ao: ";
	cin >> a.ao;
}
SOPHUC Tong(SOPHUC a, SOPHUC b)
{
	SOPHUC temp;
	temp.thuc = a.thuc + b.thuc;
	temp.ao = a.ao + b.ao;
	return temp;
}
SOPHUC Hieu(SOPHUC a, SOPHUC b)
{
	SOPHUC temp;
	temp.thuc = a.thuc - b.thuc;
	temp.ao = a.ao - b.ao;
	return temp;
}
SOPHUC Tich(SOPHUC a, SOPHUC b) {
	SOPHUC temp;
	temp.thuc = a.thuc * b.thuc - a.ao * b.ao;
	temp.ao = a.ao * b.thuc + a.thuc * b.ao;
	return temp;
}
void Xuat(SOPHUC a) {
	cout << a.thuc << "+" << a.ao << "i";
}