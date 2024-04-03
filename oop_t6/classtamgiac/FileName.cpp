#include<iostream>
#include<cmath>
using namespace std;

class TamGiac {
public:
	float x, y;
	
	void Nhap() {
		cin >> x >> y;
	}
	void Xuat(float k,float d) {
		cout << "(" << x+d * cos(k / 180.0 * 3.14) << "," << y+d * sin(k / 180.0 * 3.14) << ")" << endl;
	}
};


int main() {
	TamGiac* a=new TamGiac[3];
	for (int i = 0; i < 3; i++)
		a[i].Nhap();
	float k, d;
	cin >> k >> d;
	for (int i = 0; i < 3; i++) {
		a[i].Xuat(k,d);
	}
	delete[] a;
	return 1;
}