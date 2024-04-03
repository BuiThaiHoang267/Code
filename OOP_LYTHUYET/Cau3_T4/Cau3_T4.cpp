#include<iostream>
using namespace std;

class CNgay {
private:
	int ngay;
	int thang;
	int nam;
public:
	void Nhap();
	void Xuat();
	int KtNamNhuan();
	CNgay NgayHomQua();
	CNgay NgayKeTiep();
	CNgay Cong(int);
	CNgay Tru(int);
	void SaoChep(CNgay &a){
		a.ngay = ngay;
		a.thang = thang;
		a.nam = nam;
	}
};

int main() {
	CNgay D;
	int n;
	cout << "Nhap so ngay muon cong them: ";
	cin >> n;
	D.Nhap();
	cout << "Ngay ban dau la ";
	D.Xuat();
	cout << "\nNgay hom qua la: ";
	D.NgayHomQua().Xuat();
	cout << "\nNgay ke tiep la: ";
	D.NgayKeTiep().Xuat();
	cout << "Cong them n ngay: ";
	D.Cong(n).Xuat();
	return 0;
}

void CNgay::Nhap() {
	cout << "Nhap ngay ";
	cin >> ngay;
	cout << "Nhap thang ";
	cin >> thang;
	cout << "Nhap nam ";
	cin >> nam;
}
void CNgay::Xuat() {
	cout << ngay << "/" << thang << "/" << nam;
}
int CNgay::KtNamNhuan() {
	if (nam % 400 == 0)
		return 1;
	else if (nam % 4 == 0 && nam % 100 != 0)
		return 1;
	return 0;
}
CNgay CNgay::NgayHomQua() {
	CNgay temp;
	this->SaoChep(temp);
	int ThangNgay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (KtNamNhuan() == 1)
		ThangNgay[2] = 29;
	temp.ngay--;
	if (temp.ngay < 1) {
		temp.thang--;
		if (temp.thang < 1) {
			temp.thang = 12;
			temp.nam--;
		}
		temp.ngay = ThangNgay[thang];
	}
	return temp;
}
CNgay CNgay::NgayKeTiep() {
	CNgay temp;
	this->SaoChep(temp);
	int ThangNgay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (KtNamNhuan() == 1)
		ThangNgay[2] = 29;
	temp.ngay++;
	if (temp.ngay > ThangNgay[thang]) {
		temp.thang++;
		if (temp.thang > 12) {
			temp.thang = 1;
			temp.nam++;
		}
		temp.ngay = 1;
	}
	return temp;
}
CNgay CNgay::Cong(int n) {
	for (int i = 0; i < n; i++) {
		this->NgayKeTiep();
	}
	return *this;
}
CNgay CNgay::Tru(int n) {
	for (int i = 0; i < n; i++) {
		this->NgayHomQua();
	}
	return *this;
}