#include<iostream>
using namespace std;

class CTimeSpan {
private:
	int gio;
	int phut;
	int giay;
public:
	CTimeSpan() {
		gio = 0;
		phut = 0;
		giay = 0;
	}
	void Nhap();
	void Xuat();
	CTimeSpan Cong(CTimeSpan);
	CTimeSpan Tru(CTimeSpan);
	int SoSanh(CTimeSpan);
	~CTimeSpan() {
	}
};

int main() {
	CTimeSpan T = CTimeSpan();
	CTimeSpan Temp = CTimeSpan();
	cout << "Nhap t1" << endl;
	T.Nhap();
	cout << "Nhap t2" << endl;
	Temp.Nhap();
	
	cout << "\nt1 + t2 = ";
	T.Cong(Temp).Xuat();
	cout << "\nkhoang cach giua t1 và t2 la: ";
	T.Tru(Temp).Xuat();
	if (T.SoSanh(Temp) == 0)
		cout << "\nt1 bang t2";
	else if (T.SoSanh(Temp) == 1)
		cout << "\nt1 nhanh hon t2";
	else
		cout << "\nt1 cham hon t2";
	return 0;
}
void CTimeSpan::Nhap() {
	cout << "Nhap gio: ";
	cin >> gio;
	cout << "Nhap phut: ";
	cin >> phut;
	cout << "Nhap giay: ";
	cin >> giay;
}
void CTimeSpan::Xuat() {
	cout << gio << "h " << phut << "p " << giay << "s";
	cout << endl;
}
CTimeSpan CTimeSpan::Cong(CTimeSpan t) {
	CTimeSpan temp;
	int add = 0;
	temp.giay = (giay + t.giay) % 60;
	add = (giay + t.giay) / 60;
	temp.phut = (phut + t.phut + add) % 60;
	add = (phut + t.phut + add) / 60;
	temp.gio = (gio + t.gio + add) % 24;
	return temp;
}
CTimeSpan CTimeSpan::Tru(CTimeSpan t) {
	CTimeSpan temp;
	int time = abs(gio * 3600 + phut * 60 + giay - t.gio * 3600 - t.phut * 60 - t.giay);
	temp.gio = (time / 3600) % 24;
	time = time % 3600;
	temp.phut = (time / 60);
	time = time % 60;
	temp.giay = time;
	return temp;
}
int CTimeSpan::SoSanh(CTimeSpan t) {
	int time = gio * 3600 + phut * 60 + giay - t.gio * 3600 - t.phut * 60 - t.giay;
	if (time == 0)
		return 0;
	else if (time < 0)
		return -1;
	else
		return 1;
}
