#include<iostream>
using namespace std;

class CNgay {
private:
	int ngay;
	int thang;
	int nam;
public:
	CNgay() {
		ngay = thang = 1;
		nam = 1;
	}
	friend istream& operator >> (istream& in, CNgay& a) {
		cout << "Nhap ngay: ";
		in >> a.ngay;
		cout << "Nhap thang: ";
		in >> a.thang;
		cout << "Nhap nam: ";
		in >> a.nam;
		return in;
	}
	friend ostream& operator << (ostream& out, CNgay& a) {
		cout << a.ngay << "/" << a.thang << "/" << a.nam << endl;
		return out;
	}
	int KtNamNhuan();
	CNgay operator++(int);
};

int main(){
	CNgay D,kq;
	cin >> D;
	cout << "Ngay ban dau la ";
	cout << D;
	cout << "\nNgay ke tiep la ";
	D++;
	cout << D;
	return 0;
}

int CNgay::KtNamNhuan() {
	if (nam % 400 == 0)
		return 1;
	else if (nam % 4 == 0 && nam % 100 != 0)
		return 1;
	return 0;
}
CNgay CNgay::operator++(int) {
	int ThangNgay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (KtNamNhuan() == 1)
		ThangNgay[1] = 29;
	ngay++;
	if (ngay > ThangNgay[thang]) {
		thang++;
		if (thang > 12) {
			thang = 1;
			nam++;
		}
		ngay = 1;
	}
	return *this;
}