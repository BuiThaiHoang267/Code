#include<iostream>
using namespace std;

class PhanSo {
private:
	int Tu;
	int Mau;
public:
	//Nhom khoi tao
	void KhoiTao();
	void KhoiTao(int);
	void KhoiTao(int, int);
	void KhoiTao(PhanSo&);
	PhanSo();
	PhanSo(int);
	PhanSo(int, int);
	PhanSo(PhanSo&);
	void Nhap();
	friend istream& operator>>(istream&, PhanSo);
	//Nhom cung cap thong tin
	int getTu();
	int getMau();
	float getGiaTri();
	void Xuat();
	friend ostream& operator<<(ostream&, PhanSo);
	//Nhom cap nhat thong tin
	void setTu();
	void setMau();
	//Nhom kiem tra
	int isCoNghia();
	int isToiGian();
	int isKhong();
	int isDuong();
	int isAm();
	bool operator>(PhanSo&);
	bool operator<(PhanSo&);
	bool operator>=(PhanSo&);
	bool operator<=(PhanSo&);
	bool operator==(PhanSo&);
	bool operator!=(PhanSo&);
	//Nhom xu ly
	~PhanSo();
	PhanSo& operator=(PhanSo&);
	void RutGon();
	PhanSo Tong(PhanSo&);
	PhanSo Hieu(PhanSo&);
	PhanSo Tich(PhanSo&);
	PhanSo Thuong(PhanSo&);
	PhanSo operator+(PhanSo&);
	PhanSo operator-(PhanSo&);
	PhanSo operator*(PhanSo&);
	PhanSo operator/(PhanSo&);
	PhanSo& operator++();
	PhanSo& operator--();
	PhanSo operator++(int);
	PhanSo operator--(int);
	PhanSo& operator+=(PhanSo);
	PhanSo& operator-=(PhanSo);
	PhanSo& operator*=(PhanSo);
	PhanSo& operator/=(PhanSo);
	PhanSo operator^(int);
	PhanSo operator^=(int);
};


int main() {
	return 0;
}

void PhanSo::KhoiTao() {
	Tu = 0;
	Mau = 1;
}
void PhanSo::KhoiTao(int TuTu) {
	Tu = TuTu;
	Mau = 1;
}
void PhanSo::KhoiTao(int TuTu,int MauMau) {
	Tu = TuTu;
	Mau = MauMau;
}
void PhanSo::KhoiTao(PhanSo& x) {
	Mau = x.Mau;
	Tu = x.Tu;
}
PhanSo::PhanSo() {
	Tu = 0;
	Mau = 1;
}
PhanSo::PhanSo(int TuTu) {
	Tu = TuTu;
	Mau = 1;
}
PhanSo::PhanSo(int TuTu, int MauMau) {
	Tu = TuTu;
	Mau = MauMau;
}
PhanSo::PhanSo(PhanSo& x) {
	Mau = x.Mau;
	Tu = x.Tu;
}
