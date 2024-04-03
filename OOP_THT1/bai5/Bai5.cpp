#include<iostream>
using namespace std;
class Shape {
private:
	double x, y;
public:
	Shape(double a, double b) { x = a; y = b; }
	void Nhap() {
		cout << "Nhap a";
		cout << "\nNhap b";
	}
};
class HBH: public Shape {
public:
	int h;
	void NhapHBH() {
		Nhap();
		cout << " nhap h";
		cin >> h;
	}
};

int main(){
	return 0;
}