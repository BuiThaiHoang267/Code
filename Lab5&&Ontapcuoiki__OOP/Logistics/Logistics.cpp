#include<iostream>
#include<string>
using namespace std;

class Xe {
protected:
	string BienKiemSoat;
	string LoaiXe;
	double TrongTai;
	string XuatXu;
	double ThoiGianSanXuat;
public:
	Xe() {
		BienKiemSoat = LoaiXe = XuatXu = "\0";
		TrongTai = ThoiGianSanXuat = 0;
	}
	virtual void Nhap() {
		cout << "Nhap bien so xe: ";
		cin >> BienKiemSoat;
		cout << "Nhap xuat xu: ";
		cin.ignore();
		getline(cin, XuatXu);
		cout << "Nhap trong tai(tan,m^3): ";
		cin >> TrongTai;
		cout << "Nhap thoi gian san xuat(nam): ";
		cin >> ThoiGianSanXuat;
	}
	virtual long long TienCuoc1Chuyen(double km) = 0;
};
class Container:public Xe {
public:
	Container() {
		LoaiXe = "Container";
	}
	void Nhap() {
		Xe::Nhap();
		if (TrongTai >= 35)
			TrongTai = 35;
	}
	long long TienCuoc1Chuyen(double km) {
		return 2 * (TrongTai * 1000 * 150 * km);
	}
};
class XeBen :public Xe {
public:
	XeBen() {
		LoaiXe = "XeBen";
	}
	void Nhap() {
		Xe::Nhap();
		if (TrongTai >= 20)
			TrongTai = 20;
	}
	long long TienCuoc1Chuyen(double km) {
		return 2 * (TrongTai * 5000 * km);
	}
};
class XeDongLanh :public Xe {
public:
	XeDongLanh() {
		LoaiXe = "XeDongLanh";
	}
	void Nhap() {
		Xe::Nhap();
		if (TrongTai >= 3.5)
			TrongTai = 3.5;
	}
	long long TienCuoc1Chuyen(double km) {
		return 2 * (TrongTai * 1000 * 200 * km);
	}
};

class TuyenDuong {
private:
	long MaTuyenDuong;
	string TenTuyenDuong;
	double DoDaiTuyenDuong;
public:
	TuyenDuong() {
		MaTuyenDuong = DoDaiTuyenDuong = 0;
		TenTuyenDuong = "\0";
	}
	void Nhap() {
		cout << "Nhap ma tuyen duong: ";
		cin >> MaTuyenDuong;
		cout << "Nhap ten duong: ";
		cin.ignore();
		getline(cin, TenTuyenDuong);
		cout << "Nhap do dai quang duong(km): ";
		cin >> DoDaiTuyenDuong;
	}
	double getDodai() {
		return DoDaiTuyenDuong;
	}
};

class ChuyenHang {
private:
	int MaChuyenHang;
	Xe* X;
	TuyenDuong T;
	string ThoiGianXeChay;
public:
	ChuyenHang() {
		X = NULL;
		MaChuyenHang = 0;
		ThoiGianXeChay = "\0";
	}
	void Nhap() {
		cout << "Nhap ma chuyen hang: ";
		cin >> MaChuyenHang;
		int x;
		cout << "Nhap(1: xe container, 2: xe ben, 3: xe dong lanh): ";
		cin >> x;
		if (x == 1) {
			X = new Container;
			X->Nhap();
		}
		if (x == 2) {
			X = new XeBen;
			X->Nhap();
		}
		if (x == 3) {
			X = new XeDongLanh;
			X->Nhap();
		}
		T.Nhap();
		cout << "Nhap thoi gian xe chay: ";
		cin.ignore();
		cin >> ThoiGianXeChay;
	}
	long long TienCuoc() {
		return X->TienCuoc1Chuyen(T.getDodai());
	}
};
class Logistics {
private:
	int n;
	ChuyenHang* C;
public:
	Logistics() {
		n = 0;
		C = NULL;
	}
	void Nhap() {
		cout << "Nhap so luong chuyen hang: ";
		cin >> n;
		C = new ChuyenHang[n];
		for (int i = 0; i< n; i++) {
			cout << "\nNhap chuyen hang " << i << ": " << endl;
			C->Nhap();
		}
	}
	void TienCuoc1Chuyen(){
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << "Xe[" << i << "]: " << C[i].TienCuoc() << " VND" << endl;
		}
	}
	void TienCuoc1Thang() {
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << "Xe[" << i << "]: " << 30*C[i].TienCuoc() << " VND" << endl;
		}
	}
};

int main() {
	Logistics L;
	L.Nhap();
	cout << "Tien cuoc 1 chuyen: ";
	L.TienCuoc1Chuyen();
	cout << "Tien cuoc 1 thang: ";
	L.TienCuoc1Thang();
	return 0;
}