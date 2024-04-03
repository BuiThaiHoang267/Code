#include<iostream>
#include<cmath>
using namespace std;

class CNgay {
private:
	int ngay;
	int thang;
	int nam;
public:
	// Nhom phuong thuc cung cap thong tin
	void Xuat();
	friend ostream& operator << (ostream&, CNgay&);
	int getNgay();
	int getThang();
	int getNam();
	// Nhom phuong thuc cap nhat thong tin
	CNgay& operator = (const CNgay&);
	void setNgay(int);
	void setThang(int);
	void setNam(int);
	// Nhom phuong thuc kiem tra
	int IsHopLe();
	int IsNhuan();
	// Nhom phuong thuc xu li
	int operator==(const CNgay&);
	int operator!=(const CNgay&);
	int operator>(const CNgay&);
	int operator>=(const CNgay&);
	int operator<(const CNgay&);
	int operator<=(const CNgay&);
	int MaximumNumberOfDayInMonth();
	int MaximumNumberOfDayInYear();
	int SoThutuTrongNam();
	int SoThuTu();
	int SoSanh(CNgay);
	int KhoangCach(CNgay);
	CNgay& KeTiep();
	CNgay& HomQua();
	CNgay& TruocDo(int);
	void XuatThu();
	~CNgay();
	// Nhom phuong thuc khoi tao
	void KhoiTao();
	void KhoiTao(int,int,int);
	void KhoiTao(const CNgay&);
	void Nhap();
	CNgay();
	CNgay(int, int, int);
	CNgay(const CNgay&);
	friend istream& operator >> (istream& in, CNgay&);

};

int main() 
{
	return 0;
}

void CNgay::Xuat() 
{
	cout << "Ngay " << ngay << " Thang " << thang << " Nam " << nam;
}
ostream& operator<<(ostream& out, CNgay& a)
{
	out << "Ngay " << a.ngay << " Thang " << a.thang << " Nam " << a.nam;
	return out;
}
int CNgay::getNgay()
{
	return ngay;
}
int CNgay::getThang()
{
	return thang;
}
int CNgay::getNam()
{
	return nam;
}

CNgay& CNgay::operator=(const CNgay& a) 
{
	ngay = a.ngay;
	thang = a.thang;
	nam = a.nam;
	return *this;
}
void CNgay::setNgay(int a) 
{
	ngay = a;
}
void CNgay::setThang(int a) 
{
	thang = a;
}
void CNgay::setNam(int a) 
{
	nam = a;
}

int CNgay::IsHopLe()
{
	if (ngay<1 || ngay>MaximumNumberOfDayInMonth())
		return 0;
	if (thang < 1 || thang>12)
		return 0;
	if (nam < 1)
		return 0;
	return 1;
}
int CNgay::IsNhuan()
{
	if (nam % 4 == 0 && nam % 100 != 0)
		return 1;
	if (nam % 400 == 0)
		return 1;
	return 0;
}

int CNgay::operator==(const CNgay& a)
{
	if (nam != a.nam)
		return 0;
	if (thang != a.thang)
		return 0;
	if (ngay != a.ngay)
		return 0;
	return 1;
}
int CNgay::operator!=(const CNgay& a)
{
	if (nam != a.nam)
		return 1;
	if (thang != a.thang)
		return 1;
	if (ngay != a.ngay)
		return 1;
	return 0;
}
int CNgay::operator>(const CNgay& a)
{
	if (nam > a.nam)
		return 1;
	if (thang > a.thang)
		return 1;
	if (ngay > a.ngay)
		return 1;
	return 0;
}
int CNgay::operator>=(const CNgay& a)
{
	if (nam >= a.nam)
		return 1;
	if (thang >= a.thang)
		return 1;
	if (ngay >= a.ngay)
		return 1;
	return 0;
}
int CNgay::operator<(const CNgay& a)
{
	if (nam < a.nam)
		return 1;
	if (thang < a.thang)
		return 1;
	if (ngay < a.ngay)
		return 1;
	return 0;
}
int CNgay::operator<=(const CNgay& a)
{
	if (nam <= a.nam)
		return 1;
	if (thang <= a.thang)
		return 1;
	if (ngay <= a.ngay)
		return 1;
	return 0;
}
int CNgay::MaximumNumberOfDayInMonth()
{
	int NgayThang[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (IsNhuan() == 1)
		NgayThang[1] = 29;
	return NgayThang[thang - 1];
}
int CNgay::MaximumNumberOfDayInYear()
{
	if (IsNhuan() == 1)
		return 366;
	return 365;
}
int CNgay::SoThutuTrongNam()
{
	int stt = 0;
	for (int i = 1; i <= thang - 1; i++)
	{
		CNgay temp = { 1,i,nam };
		stt = stt + temp.MaximumNumberOfDayInMonth();
	}
	return (stt + ngay);
}
int CNgay::SoThuTu()
{
	int stt = 0;
	for (int i = 1; i < nam; i++)
	{
		CNgay temp = { 1,1,i };
		stt = stt + temp.MaximumNumberOfDayInYear();
	}
	return stt + SoThutuTrongNam();
}
int CNgay::SoSanh(CNgay a)
{
	if (nam > a.nam)
		return 1;
	if (nam < a.nam)
		return -1;
	if (thang > a.thang)
		return 1;
	if (thang < a.thang)
		return -1;
	if (ngay > a.ngay)
		return 1;
	if (ngay < a.ngay)
		return -1;
	return 0;
}
int CNgay::KhoangCach(CNgay x)
{
	int a = SoThuTu();
	int b = x.SoThuTu();
	return abs(a - b);
}
CNgay& CNgay::KeTiep()
{
	int NgayThang[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (IsNhuan() == 1)
		NgayThang[1] = 29;
	ngay++;
	if (ngay > NgayThang[thang - 1])
	{
		thang++;
		if (thang > 12)
		{
			thang = 1;
			nam++;
		}
		ngay = 1;
	}
	return *this;
}
CNgay& CNgay::HomQua()
{
	int NgayThang[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (IsNhuan() == 1)
		NgayThang[1] = 29;
	ngay--;
	if (ngay < 1)
	{
		thang--;
		if (thang < 1)
		{
			thang = 12;
			nam--;
		}
		ngay = NgayThang[thang-1];
	}
	return *this;
}
CNgay& CNgay::TruocDo(int k)
{
	for (int i = 1; i <= k; i++)
		*this = this->HomQua();
	return *this;
}
void CNgay::XuatThu()
{
	int stt = SoThuTu();
	switch (stt % 7)
	{
	case 0:cout << "Chu nhat";
		break;
	case 1:cout << "Thu hai";
		break;
	case 2:cout << "Thu ba";
		break;
	case 3:cout << "Thu tu";
		break;
	case 4:cout << "Thu nam";
		break;
	case 5:cout << "Thu sau";
		break;
	case 6:cout << "Thu bay";
		break;
	}
}
CNgay::~CNgay()
{
	return;
}

void CNgay::KhoiTao()
{
	ngay = 1;
	thang = 1;
	nam = 1;
}
void CNgay::KhoiTao(int ngayngay, int thangthang, int namnam) 
{
	ngay = ngayngay;
	thang = thangthang;
	nam = namnam;
}
void CNgay::KhoiTao(const CNgay& a)
{
	ngay = a.ngay;
	thang = a.thang;
	nam = a.nam;
}
void CNgay::Nhap()
{
	cout << "Nhap ngay: ";
	cin >> ngay;
	cout << "Nhap thang: ";
	cin >> thang;
	cout << "Nhap nam: ";
	cin >> nam;
}
CNgay::CNgay()
{
	ngay = 1;
	thang = 1;
	nam = 1;
}
CNgay::CNgay(int ngayngay, int thangthang, int namnam)
{
	ngay = ngayngay;
	thang = thangthang;
	nam = namnam;
}
CNgay::CNgay(const CNgay& a)
{
	ngay = a.ngay;
	thang = a.thang;
	nam = a.nam;
}
istream& operator >> (istream& in, CNgay& a)
{
	cout << "Nhap ngay: ";
	cin >> a.ngay;
	cout << "Nhap thang: ";
	cin >> a.thang;
	cout << "Nhap nam: ";
	cin >> a.nam;
	return in;
}
