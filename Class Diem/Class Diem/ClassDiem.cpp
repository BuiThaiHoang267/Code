#include<iostream>
#include<cmath>
using namespace std;

class Diem {
private:
	float x;
	float y;
public:
	void Nhap();
	void Xuat();
	void ChiThi1() {
		x = x * 2;
		y = y * 2;
	}
	void ChiThi2() {
		x = 0;
		y = 0;
	}
	void ChiThi3(int k, float d) {
		if (k == 0)
			x = x + d;
		else
			y = y + d;
	}
};

void Diem::Nhap() {
	cin >> x;
	cin >> y;
}
void Diem::Xuat() {
	cout << "(" << x << "," << y << ")";
}

int main() {
	Diem a;
	int n, t, k, d;
	a.Nhap();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (t == 1)
			a.ChiThi1();
		else if (t == 2)
			a.ChiThi2();
		else if (t == 3) {
			cin >> k >> d;
			a.ChiThi3(k,d);
		}
	}
	a.Xuat();
	return 0;
}