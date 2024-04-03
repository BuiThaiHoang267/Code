#include<iostream>
using namespace std;

class CTime {
private:
	int gio;
	int phut;
	int giay;
public:
	void Nhap();
	void Xuat();
	void CongThem1s();
	void TruThem1s();
	void Cong(int);
	void Tru(int);
	CTime KhoangCach(CTime);
};

int main(){
	CTime A, B;
	A.Nhap();
	B.Nhap();
	cout << "A + them 1 s: ";
	A.CongThem1s();
	A.Xuat();
	cout << "B - di 1s: ";
	B.TruThem1s();
	B.Xuat();
	cout << "Khoang cach giua 2 khoang thoi gian: ";
	A.KhoangCach(B).Xuat();
	cout << "A,B +- 20s: " << endl;
	A.Cong(20);
	B.Tru(20);
	A.Xuat();
	B.Xuat();

	return 0;
}
void CTime::Nhap() {
	cout << "Nhap gio: ";
	cin >> gio;
	cout << "Nhap phut: ";
	cin >> phut;
	cout << "Nhap giay: ";
	cin >> giay;
}
void CTime::Xuat() {
	cout << gio << "h " << phut << "p " << giay << "s";
	cout << endl;
}
CTime CTime::KhoangCach(CTime t) {
	CTime temp;
	int time = abs(gio * 3600 + phut * 60 + giay - t.gio * 3600 - t.phut * 60 - t.giay);
	temp.gio = (time / 3600) % 24;
	time = time % 3600;
	temp.phut = (time / 60);
	time = time % 60;
	temp.giay = time;
	return temp;
}
void CTime::CongThem1s() {
	int time = abs(gio * 3600 + phut * 60 + giay + 1);
	gio = (time / 3600) % 24;
	time = time % 3600;
	phut = (time / 60);
	time = time % 60;
	giay = time;
}
void CTime::TruThem1s() {
	int time = abs(gio * 3600 + phut * 60 + giay - 1);
	gio = (time / 3600) % 24;
	time = time % 3600;
	phut = (time / 60);
	time = time % 60;
	giay = time;
}
void CTime::Cong(int x) {
	int time = abs(gio * 3600 + phut * 60 + giay + x);
	gio = (time / 3600) % 24;
	time = time % 3600;
	phut = (time / 60);
	time = time % 60;
	giay = time;
}
void CTime::Tru(int x) {
	int time = abs(gio * 3600 + phut * 60 + giay - x);
	gio = (time / 3600) % 24;
	time = time % 3600;
	phut = (time / 60);
	time = time % 60;
	giay = time;
}