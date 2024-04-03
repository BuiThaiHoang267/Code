#include<iostream>
using namespace std;

class PhanSo {
public:
	int tu;
	int mau;
	friend istream& operator >> (istream& in, PhanSo& a);
	bool operator < (PhanSo a);
};

istream& operator >> (istream& in, PhanSo& a) {
	in >> a.tu;
	do {
		cin >> a.mau;
	} while (a.mau == 0);
	return in;
}

bool PhanSo::operator<(PhanSo a) {
	a.tu = tu * a.mau - mau * a.tu;
	a.mau = mau * a.mau;
	float i = a.tu * 1.0 / a.mau * 1.0;
	return (i < 0);
}


int main() {
	int n, k;
	cin >> n >> k;
	if (k > n || k <= 0)
		return 0;
	PhanSo* a=new PhanSo[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for(int j=1;j<i;j++)
			if (a[i] < a[j])
			{
				PhanSo c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
	}
	cout << a[n - k + 1].tu << "/" << a[n - k + 1].mau << endl;
	cout << a[k].tu << "/" << a[k].mau;
	delete[] a;
	return 0;
}