#include<iostream>
#include<cmath>
using namespace std;

class Diem {
public:
	float x;
	float y;
	Diem() {
		x = y = 0;
	}
	float getY() {
		return y;
	}
	void NhapDiem() {
		cout << "Nhap x: ";
		cin >> x;
		cout << "Nhap y: ";
		cin >> y;
	}
	void XuatDiem() {
		cout << "(" << x << "," << y << ")";
		cout << endl;
	}
	float KhoangCach(Diem a) {
		return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
	}
	~Diem(){}
};
class HinhHoc {
private:
	Diem A, B, C, D;
	float ChuVi;
	float DienTich;
public:
	HinhHoc() {
		ChuVi = 0;
		DienTich = 0;
	}
	Diem getA() {
		return A;
	}
	Diem getB() {
		return B;
	}
	Diem getC() {
		return C;
	}
	Diem getD() {
		return D;
	}
	void setCV(float CV) {
		ChuVi = CV;
	}
	void setDT(float DT) {
		DienTich = DT;
	}
	void NhapToaDo4Diem() {
		cout << "Nhap toa do A" << endl;
		A.NhapDiem();
		cout << "Nhap toa do B" << endl;
		B.NhapDiem();
		cout << "Nhap toa do C" << endl;
		C.NhapDiem();
		cout << "Nhap toa do D" << endl;
		D.NhapDiem();
	}
	void Xuat() {
		cout << "Toa do cac dinh lan luot la: ";
		cout << "\nA"; A.XuatDiem();
		cout << "B"; B.XuatDiem();
		cout << "C"; C.XuatDiem();
		cout << "D"; D.XuatDiem();
		cout << "Chu vi C = " << ChuVi;
		cout << "\nDien Tich S = " << DienTich;
	}
	void TinhChuVi() {
		float CV;
		float AB = getA().KhoangCach(getB());
		float BC = getB().KhoangCach(getC());
		float CD = getC().KhoangCach(getD());
		float DA = getD().KhoangCach(getA());
		CV = AB + BC + CD + DA;
		this->setCV(CV);
	}
};
class HinhVuong : public HinhHoc {
public:
	void TinhDienTich(){
		float DT = getA().KhoangCach(getB()) * getA().KhoangCach(getB());
		this->setDT(DT);
	}
};
class HinhChuNhat : public HinhHoc {
public:
	void TinhDienTich() {
		float DT =(float) getA().KhoangCach(getB()) * getB().KhoangCach(getC());
		this->setDT(DT);
	}
};
class HinhThang : public HinhHoc {
public:
	void TinhDienTich() {
		float DT =(float)(getA().KhoangCach(getB()) + getC().KhoangCach(getD())) / 2 * abs(getA().getY() - getD().getY());
		this->setDT(DT);
	}
};
class HinhBinhHanh : public HinhHoc {
public:
	void TinhDienTich() {
		float DT = (float)getA().KhoangCach(getB()) * abs(getA().getY() - getD().getY());
		this->setDT(DT);
	}
};
int main() {
	HinhVuong A;
	A.NhapToaDo4Diem();
	A.TinhChuVi();
	A.TinhDienTich();
	A.Xuat();
	return 0;
}