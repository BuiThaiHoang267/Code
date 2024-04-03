#include<iostream>
using namespace std;

class CThoiGian {
private:
	int gio;
	int phut;
	int giay;
public: 
	// Nhom phuong thuc khoi tao
	void KhoiTao();
	void KhoiTao(int,int,int);
	void KhoiTao(const CThoiGian&);
	CThoiGian();
	CThoiGian(int, int, int);
	CThoiGian(const CThoiGian&);
	void Nhap();
	friend istream& operator>>(istream&, CThoiGian&);
	// Nhom phuong thuc cung cap thong tin
	void Xuat();
	friend ostream& operator <<(ostream&, CThoiGian&);
	int getGio();
	int getPhut();
	int getGiay();
	// Nhom phuong thuc cap nhat thong tin
	CThoiGian& operator=(const CThoiGian&);
	void setGio(int);
	void setPhut(int);
	void setGiay(int);
	// Nhom phuong thuc kiem tra
	int ktHopLe();
	int ktSang();
	int ktTrua();
	int ktChieu();
	int ktToi();
	// Nhom phuong thuc xu ly
	int operator == (const CThoiGian&);
	int operator != (const CThoiGian&);
	int operator > (const CThoiGian&);
	int operator >= (const CThoiGian&);
	int operator < (const CThoiGian&);
	int operator <= (const CThoiGian&);
	int SoGiay();
};

int main() {
	CThoiGian n;
	do
	{
		cin >> n;
		if (!n.ktHopLe())
			cout << "Khong hop le! Nhap lai\n" << endl;
	} while (!n.ktHopLe());
	cout << "\nGio vua nhap: " << n;
	CThoiGian b(1, 30, 0);
	cout << endl << "Thoi Gian I: " << b;
	CThoiGian a(n);
	cout << endl << "Thoi Gian II: " << a;
	cout << "\n\nKet Thuc\n";
	return 0;
}

void CThoiGian::KhoiTao() 
{
	gio = 0;
	phut = 0;
	giay = 0;
}
void CThoiGian::KhoiTao(int giogio, int phutphut, int giaygiay)
{
	gio = giogio;
	phut = phutphut;
	giay = giaygiay;
}
void CThoiGian::KhoiTao(const CThoiGian& a)
{
	gio = a.gio;
	phut = a.phut;
	giay = a.giay;
}
CThoiGian::CThoiGian() 
{
	gio = 0;
	phut = 0;
	giay = 0;
}
CThoiGian::CThoiGian(int giogio, int phutphut, int giaygiay)
{
	gio = giogio;
	phut = phutphut;
	giay = giaygiay;
}
CThoiGian::CThoiGian(const CThoiGian& a)
{
	gio = a.gio;
	phut = a.phut;
	giay = a.giay;
}
void CThoiGian::Nhap() 
{
	cout << "Nhap Gio: ";
	cin >> gio;
	cout << "Nhap Phut: ";
	cin >> phut;
	cout << "Nhap Giay: ";
	cin >> giay;
}
istream& operator>>(istream& in, CThoiGian& a) {
	cout << "Nhap Gio: ";
	in >> a.gio;
	cout << "Nhap Phut: ";
	in >> a.phut;
	cout << "Nhap Giay: ";
	in >> a.giay;
	return in;
}

void CThoiGian::Xuat()
{
	cout << gio << "h " << phut << "p " << giay << "s";
}
ostream& operator <<(ostream& out, CThoiGian& a) 
{
	out << a.gio << "h " << a.phut << "p " << a.giay << "s";
	return out;
}
int CThoiGian::getGio()
{
	return gio;
}
int CThoiGian::getPhut()
{
	return phut;
}
int CThoiGian::getGiay()
{
	return giay;
}

CThoiGian& CThoiGian::operator=(const CThoiGian& a)
{
	gio = a.gio;
	phut = a.phut;
	giay = a.giay;
	return *this;
}
void CThoiGian::setGio(int a)
{
	gio = a;
}
void CThoiGian::setPhut(int a)
{
	phut = a;
}
void CThoiGian::setGiay(int a)
{
	giay = a;
}

int CThoiGian::ktHopLe()
{
	if (gio > 23 || gio < 0)
		return false;
	if (phut > 59 || phut < 0)
		return false;
	if (giay > 59 || giay < 0)
		return false;;
	return true;
}
int CThoiGian::ktSang()
{
	CThoiGian start, end;
	start = CThoiGian();
	end= CThoiGian();
	start.setGio(1);
	end.setGio(11);
	if (*this >= start && *this <= end)
		return true;
	return false;
}
int CThoiGian::ktTrua()
{
	CThoiGian start, end;
	start = CThoiGian();
	end = CThoiGian();
	start.setGio(11);
	end.setGio(13);
	if (*this >= start && *this <= end)
		return true;
	return false;
}
int CThoiGian::ktChieu()
{
	CThoiGian start, end;
	start = CThoiGian();
	end = CThoiGian();
	start.setGio(13);
	end.setGio(18);
	if (*this >= start && *this <= end)
		return true;
	return false;
}
int CThoiGian::ktToi()
{
	CThoiGian start, end;
	start = CThoiGian();
	end = CThoiGian();
	start.setGio(18);
	end.setGio(23);
	end.setPhut(59);
	end.setGiay(59);
	CThoiGian start1, end1;
	start1 = CThoiGian();
	end1 = CThoiGian();
	end1.setGio(1);
	if ((*this >= start && *this <= end)|| (*this >= start1 && *this <= end1))
		return true;
	return false;
}

int CThoiGian::operator == (const CThoiGian& a)
{
	CThoiGian temp = a;
	if (SoGiay() == temp.SoGiay())
		return 1;
	return 0;
}
int CThoiGian::operator != (const CThoiGian& a)
{
	CThoiGian temp = a;
	if (SoGiay() != temp.SoGiay())
		return 1;
	return 0;
}
int CThoiGian::operator > (const CThoiGian& a)
{
	CThoiGian temp = a;
	if (SoGiay() > temp.SoGiay())
		return 1;
	return 0;
}
int CThoiGian::operator >= (const CThoiGian& a)
{
	CThoiGian temp = a;
	if (SoGiay() >= temp.SoGiay())
		return 1;
	return 0;
}
int CThoiGian::operator < (const CThoiGian& a)
{
	CThoiGian temp = a;
	if (SoGiay() < temp.SoGiay())
		return 1;
	return 0;
}
int CThoiGian::operator <= (const CThoiGian& a)
{
	CThoiGian temp = a;
	if (SoGiay() <= temp.SoGiay())
		return 1;
	return 0;
}
int CThoiGian::SoGiay()
{
	return gio * 3600 + phut * 60 + giay;
}