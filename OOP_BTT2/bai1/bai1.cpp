#include<iostream>
using namespace std;
struct phanso
{
	float Tu;
	float Mau;
};
typedef struct phanso PHANSO;
void Nhap(PHANSO&,PHANSO&);
void Xuat(PHANSO);
PHANSO RutGon(PHANSO&);

PHANSO operator+(PHANSO p1, PHANSO p2)
{
	PHANSO p;
	p.Tu = p1.Tu * p2.Mau + p2.Tu * p1.Mau;
	p.Mau = p1.Mau * p2.Mau;
	return p;
}
PHANSO operator-(PHANSO p1, PHANSO p2)
{
	PHANSO p;
	p.Tu = p1.Tu * p2.Mau - p2.Tu * p1.Mau;
	p.Mau = p1.Mau * p2.Mau;
	return p;
}
PHANSO operator*(PHANSO p1, PHANSO p2)
{
	PHANSO p;
	p.Tu = p1.Tu * p2.Tu;
	p.Mau = p1.Mau * p2.Mau;
	return(p);
}
PHANSO operator/(PHANSO p1, PHANSO p2)
{
	PHANSO p;
	p.Tu = p1.Tu * p2.Mau;
	p.Mau = p1.Mau * p2.Tu;
	return p;
}

int main()
{
	PHANSO P1, P2, P3;
	Nhap(P1, P2);
	P3 = P1 + P2;
	cout << "Tong = ";
	Xuat(P3);
	P3 = P1 - P2;
	cout << "Hieu = ";
	Xuat(P3);
	P3 = P1 * P2;
	cout << "Tich = ";
	Xuat(P3);
	P3 = P1 / P2;
	cout << "Thuong = ";
	Xuat(P3);
	
	return 0;
}
PHANSO RutGon(PHANSO& p)
{
	if (p.Tu == 0)
		return p;
	int a = abs(p.Tu);
	int b = abs(p.Mau);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	p.Tu = p.Tu / a;
	p.Mau = p.Mau / a;
	return p;
}
void Xuat(PHANSO p)
{
	RutGon(p);
	cout << p.Tu << "/" << p.Mau << endl;
}
void Nhap(PHANSO& p1, PHANSO& p2)
{
	cout << "Nhap phan so P1";
	cout << "\nNhap tu = ";
	cin >> p1.Tu;
	do
	{
		cout << "Nhap mau = ";
		cin >> p1.Mau;
	} while (!p1.Mau);
	cout << "Nhap phan so P2";
	cout << "\nNhap tu = ";
	cin >> p2.Tu;
	do
	{
		cout << "Nhap mau = ";
		cin >> p2.Mau;
	} while (!p2.Mau);
}


