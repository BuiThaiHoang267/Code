#include<iostream>
#include<string>
using namespace std;

static int SNLV = 0;
static int SSP = 0;

class NhanVien {
protected:
	string name;
public:
	NhanVien() {
		name = '\0';
	}
	virtual void Nhap() = 0;
	virtual float TinhLuong() = 0;
	void Xuat() {
		cout << name << ": " << TinhLuong() << endl;
	}
	~NhanVien() {}
};
class NVSX:public NhanVien {
private:
	float LuongCanBan;
	int SoSanPham;
public:
	NVSX() {
		LuongCanBan = 0;
		SoSanPham = 0;
	}
	void Nhap() {
		cin >> name;
		cin >> LuongCanBan;
		cin >> SoSanPham;
		SSP += SoSanPham;
	}
	float TinhLuong() {
		return LuongCanBan + SoSanPham * 5;
	}
	~NVSX() {}
};
class NVVP :public NhanVien {
private:
	int SoNgaylamViec;
public:
	NVVP() {
		SoNgaylamViec = 0;
	}
	void Nhap() {
		cin >> name;
		cin >> SoNgaylamViec;
		SNLV += SoNgaylamViec;
	}
	float TinhLuong() {
		return SoNgaylamViec * 100;
	}
	~NVVP() {}
};
class Sep :public NhanVien {

public:
	Sep(){}
	void Nhap() {
		cin >> name;
	}
	float TinhLuong() {
		return 100+SNLV*40+SSP*2;
	}
	~Sep() {}
};


int main() {
	int n;
	cin >> n;
	NhanVien** dsNV = new NhanVien * [n];
	// NhanVien* dsNV[100];
	for (int i = 0; i < n; i++) {
		int loai;
		cin >> loai;
		if (loai == 1) {
			dsNV[i] = new NVSX();
		}

		if (loai == 2) {
			dsNV[i] = new NVVP();
		}

		if (loai == 3) {
			dsNV[i] = new Sep();
		}
		dsNV[i]->Nhap();
	}

	for (int i = 0; i < n; i++) {
		dsNV[i]->Xuat();
	}
	return 0;
}