#include<iostream>
using namespace std;
struct SoPhuc
{
	float Thuc;
	float Ao;
};
typedef struct SoPhuc SOPHUC;
void Nhap(SOPHUC&, SOPHUC&);
void Xuat(SOPHUC);
SOPHUC operator+(SOPHUC a, SOPHUC b)
{
	SOPHUC c;
	c.Thuc = a.Thuc + b.Thuc;
	c.Ao = a.Ao + b.Ao;
	return c;
}
SOPHUC operator-(SOPHUC a, SOPHUC b)
{
	SOPHUC c;
	c.Thuc = a.Thuc - b.Thuc;
	c.Ao = a.Ao - b.Ao;
	return c;
}
SOPHUC operator*(SOPHUC a, SOPHUC b)
{
	SOPHUC c;
	c.Thuc = a.Thuc * b.Thuc - a.Ao * b.Ao;
	c.Ao = a.Thuc * b.Ao + a.Ao * b.Thuc;
	return c;
}
SOPHUC operator/(SOPHUC a, SOPHUC b)
{
	SOPHUC c;
	c.Thuc = (a.Thuc * b.Thuc + a.Ao * b.Ao) / (b.Thuc * b.Thuc + b.Ao * b.Ao);
	c.Ao = (a.Ao * b.Thuc - a.Thuc * b.Ao) / (b.Thuc * b.Thuc + b.Ao * b.Ao);
	return c;
}
int main()
{
	SOPHUC A, B, C;
	Nhap(A, B);
	C = A + B;
	Xuat(C);
	C = A - B;
	Xuat(C);
	C = A * B;
	Xuat(C);
	C = A / B;
	Xuat(C);
	return 0;
}
void Xuat(SOPHUC C)
{
	cout << C.Thuc << " + " << C.Ao << "i" << endl;
}
void Nhap(SOPHUC& a, SOPHUC& b)
{
	cout << "Nhap so phuc A";
	cout << "\nNhap phan thuc: ";
	cin >> a.Thuc;
	cout << "Nhap phan ao: ";
	cin >> a.Ao;
	cout << "Nhap so phuc B";
	cout << "\nNhap phan thuc: ";
	cin >> b.Thuc;
	cout << "Nhap phan ao: ";
	cin >> b.Ao;
}