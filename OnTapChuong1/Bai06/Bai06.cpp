#include<iostream>
using namespace std;

struct ngay {
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct ngay NGAY;

void Nhap(NGAY&);
void Xuat(NGAY);
NGAY KeTiep(NGAY);
int KiemTraNhuan(NGAY);

int main() {
	NGAY A;
	Nhap(A);
	cout << "Ngay ban dau:" << endl;
	Xuat(A);
	cout << "Ngay ke tiep: " << endl;
	Xuat(KeTiep(A));
	return 0;
}
void Nhap(NGAY& d) {
	cout << "Nhap ngay: ";
	cin >> d.Ngay;
	cout << "Nhap thang: ";
	cin >> d.Thang;
	cout << "Nhap nam: ";
	cin >> d.Nam;
}
void Xuat(NGAY a) {
	cout << "\nNgay " << a.Ngay;
	cout << "\nThang " << a.Thang;
	cout << "\nNam " << a.Nam;
	cout << endl;
}
int KiemTraNhuan(NGAY d) {
	if (d.Nam % 400 == 0)
		return 1;
	if (d.Nam % 4 == 0 && d.Nam % 100 != 0)
		return 1;
	return 0;
}
NGAY KeTiep(NGAY d) {
	int ThangNgay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (KiemTraNhuan(d) == 1)
		ThangNgay[1] = 29;
	d.Ngay++;
	if (d.Ngay > ThangNgay[d.Thang - 1]) {
		d.Thang++;
		if (d.Thang > 12) {
			d.Thang = 1;
			d.Nam++;
		}
		d.Ngay = 1;
	}
	return d;
}