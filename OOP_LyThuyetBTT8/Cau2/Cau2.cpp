#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Diem {
private:
	float x;
	float y;
public:
	Diem()
	{
		x = y = 0;
	}
	void Nhap() {
		cout << "Nhap x: ";
		cin >> x;
		cout << "Nhap y: ";
		cin >> y;
	}
	void Xuat() {
		cout << "(" << x << "," << y << ")";
	}
	void TinhTienDiem(float d, float k) {
		x = x + d * cos(k * 3.1459 / 180);
		y = y + d * sin(k * 3.1459 / 180);
	}
	~Diem(){}
};

class DaGiac {
protected:
	Diem* d;
	int SoDinh;
	string LoaiHinh;
public:
	DaGiac() {
		d = NULL;
		SoDinh = 0;
		LoaiHinh = '\0';
	}
	void Nhap() {
		char A = 'A';
		for (int i = 0; i < SoDinh; i++) {
			cout << "Nhap toa do " << (char)(A++) << endl;
			d[i].Nhap();
		}
	}
	virtual void Xuat() = 0;
	void TinhTien() {
		float l, k;
		cout << "Tinh tien hinh" << endl;
		cout << "Nhap do dai tinh tien: ";
		cin >> l;
		cout << "Nhap goc tinh tien: ";
		cin >> k;
		for (int i = 0; i < SoDinh; i++) {
			d[i].TinhTienDiem(l, k);
		}
	}
	~DaGiac(){}
};
class TamGiac : public DaGiac {
public:
	TamGiac() {
		SoDinh = 3;
		d = new Diem[SoDinh];
		LoaiHinh = "Tam Giac";
	}
	void Xuat() {
		cout << "Tam giac ABC\n";
		char A = 'A';
		for (int i = 0; i < SoDinh; i++) {
			cout << (char)(A++);
			d[i].Xuat();
			cout << endl;
		}
	}
	~TamGiac() {}
};
class TuGiac : public DaGiac {
public:
	TuGiac(){
		SoDinh = 4;
		d = new Diem[SoDinh];
		LoaiHinh = "Tu Giac";
	}
	void Xuat() {
		cout << "Tu giac ABC\n";
		char A = 'A';
		for (int i = 0; i < SoDinh; i++) {
			cout << (char)(A++);
			d[i].Xuat();
			cout << endl;
		}
	}
	~TuGiac() {}
};
class HinhChuNhat :public DaGiac {
public:
	HinhChuNhat() {
		SoDinh = 4;
		d = new Diem[SoDinh];
		LoaiHinh = "Hinh chu nhat";
	}
	void Xuat() {
		cout << "Hinh chu nhat ABCD\n";
		char A = 'A';
		for (int i = 0; i < SoDinh; i++) {
			cout << (char)(A++);
			d[i].Xuat();
			cout << endl;
		}
	}
	~HinhChuNhat() {}
};
class HinhVuong :public DaGiac {
public:
	HinhVuong() {
		SoDinh = 4;
		d = new Diem[SoDinh];
		LoaiHinh = "Hinh vuong";
	}
	void Xuat() {
		cout << "Hinh vuong ABCD\n";
		char A = 'A';
		for (int i = 0; i < SoDinh; i++) {
			cout << (char)(A++);
			d[i].Xuat();
			cout << endl;
		}
	}
	~HinhVuong() {}
};
class HinhBinhHanh :public DaGiac {
public:
	HinhBinhHanh() {
		SoDinh = 4;
		d = new Diem[SoDinh];
		LoaiHinh = "Hinh binh hanh";
	}
	void Xuat() {
		cout << "Hinh binh hanh ABCD\n";
		char A = 'A';
		for (int i = 0; i < SoDinh; i++) {
			cout << (char)(A++);
			d[i].Xuat();
			cout << endl;
		}
	}
	~HinhBinhHanh() {}
};
class Hinh {
private:
	DaGiac** H;
	string Loai;
public:
	Hinh() {
		H = NULL;
		Loai = '\0';
	}
	void Nhap() {
		cout << "\nBan muon nhap hinh gi ? " << endl;
		cout << "Nhap loai hinh: ";
		getline(cin, Loai);
		if (Loai == "Tam giac") {
			H = new DaGiac * [1];
			H[0] = new TamGiac;
			H[0]->Nhap();
		}
		if (Loai == "Tu giac") {
			H = new DaGiac * [1];
			H[0] = new TuGiac;
			H[0]->Nhap();
		}
		if (Loai == "Hinh chu nhat") {
			H = new DaGiac * [1];
			H[0] = new HinhChuNhat;
			H[0]->Nhap();
		}
		if (Loai == "Hinh vuong") {
			H = new DaGiac * [1];
			H[0] = new HinhVuong;
			H[0]->Nhap();
		}
		if (Loai == "Hinh binh hanh") {
			H = new DaGiac * [1];
			H[0] = new HinhBinhHanh;
			H[0]->Nhap();
		}
	}
	void Xuat() {
		cout << "\nThong tin hinh" << endl;
		H[0]->Xuat();
		cout << endl;
	}
	void TinhTien() {
		H[0]->TinhTien();
	}
	int Menu() {
		int x;
		cout << "Nhap lua chon: ";
		cin >> x;
		cin.ignore();
		if (x == 1) {
			Nhap();
			return 1;
		}
		if (x == 2) {
			Xuat();
			return 1;
		}
		if (x == 3) {
			TinhTien();
			return 1;
		}
		if (x == 0)
			return 0;
		return 0;
	}
	~Hinh() {}
};


int  main() {
	Hinh A;
	cout << "Nhap vao 1 de nhap thong tin cua hinh " << endl;
	cout << "Nhap vao 2 de xuat thong tin cua hinh " << endl;
	cout << "Nhap vao 3 de tinh tien hinh " << endl;
	cout << "Nhap vao 0 de ket thuc chuong trinh " << endl;
	cout << "Luu y: Neu muon nhap vao loai hinh phai nhap dung ten loai hinh\n";
	cout << "VD: Neu muon nhap vao la tam giac thi nhap: Tam giac\n";
	cout << "    Tuong tu neu nhap vao la hinh binh hanh thi nhap: Hinh binh hanh\n";
	while (true) {
		if (A.Menu() == 0)
			return 0;
	}
}