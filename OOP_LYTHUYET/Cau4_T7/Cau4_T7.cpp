#include<iostream>
#include<cmath>
using namespace std;

class Diem {
private:
	float x;
	float y;
public:
	Diem() {
		x = 0;
		y = 0;
	}
	void NhapDiem() {
		cout << "Nhap x: ";
		cin >> x;
		cout << "Nhap y: ";
		cin >> y;
	}
	void XuatDiem() {
		cout << "(" << x << "," << y << ")";
	}
	void TinhToan(Diem a,float k,int d) {
		x = (float)a.x + d*cos(k / 180 * 3.14159);
		y = (float)a.x + d*sin(k / 180 * 3.14159);
	}
	void DiemDoiXung(Diem a, Diem b) {
		x = (float)a.x * 2 - b.x;
		y = (float)a.y * 2 - b.y;
	}
};

class HinhTron{
private:
	Diem I;
	float R;
public:
	HinhTron() {
		R = 0;
	}
	void NhapHinhTron() {
		cout << "Nhap toa do I" << endl;
		I.NhapDiem();
		cout << "Nhap ban kinh R = ";
		cin >> R;
	}
	void XuatHinhTron() {
		cout << "\nToa do tam I";
		I.XuatDiem();
		cout << "\nBan kinh R = " << R;
	}
};
class Ellipse{
private:
	float DoDaiTrucLon;
	float DoDaiTrucBe;
	Diem O;
	float Goc;
	Diem F1;
	Diem F2;
public:
	Ellipse() {
		DoDaiTrucLon = 0;
		DoDaiTrucBe = 0;
		Goc = 0;
	}
	void NhapEllipse() {
		cout << "Nhap do dai truc lon: ";
		cin >> DoDaiTrucLon;
		cout << "Nhap do dai truc be: ";
		cin >> DoDaiTrucBe;
		cout << "Nhap toa do tam O";
		O.NhapDiem();
		cout << "Nhap huong cua hinh ellipse: ";
		cin >> Goc;
	}
	void TieuCu() {
		F1.TinhToan(O, Goc,DoDaiTrucLon);
		F2.DiemDoiXung(O, F1);
	}
	void Xuat() {
		cout << "Do dai truc lon: " << DoDaiTrucLon << endl;
		cout << "Do dai truc be: " << DoDaiTrucBe << endl;
		cout << "Toa do tam O";
		O.XuatDiem();
		cout << endl;
		cout << "2 tieu cu: F1";
		F1.XuatDiem();
		cout << " va F2";
		F2.XuatDiem();	
	}
	~Ellipse(){}
};

int main() {
	Ellipse A;
	A.NhapEllipse();
	A.TieuCu();
	A.Xuat();
	return 0;
}