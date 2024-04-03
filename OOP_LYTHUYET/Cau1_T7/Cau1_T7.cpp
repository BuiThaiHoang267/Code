#include<iostream>
#include<string>
using namespace std;

class CPerson {
private:
	string hoten;
	string ngaysinh;
	int luong;
public:
	string getht() {
		return hoten;
	}
	string getns() {
		return ngaysinh;
	}
	int getl() {
		return luong;
	}
	void setht(string ht) {
		hoten = ht;
	}
	void setns(string ns) {
		ngaysinh = ns;
	}
	void setl(int l) {
		luong = l;
	}
	CPerson() {
		hoten = '\0';
		ngaysinh = "00/00/0000";
		luong = 0;
	}
	void Nhap() {
		cout << "Nhap ten nhan vien: ";
		getline(cin, hoten);
		cout << "Nhap ngay sinh nhan vien: ";
		getline(cin,ngaysinh);
	}
	void Xuat() {
		cout << "\nHo ten nhan vien: " << hoten;
		cout << "\nNgay sinh: " << ngaysinh;
		cout << "\nLuong: " << luong;
	}
	~CPerson(){}
};
class NvSanXuat: public CPerson  {
private:
	int LuongCanBan;
	int SoSanPham;
public:
	void setLCB(int LCB) {
		LuongCanBan = LCB;
	}
	void setSSP(int SSP) {
		SoSanPham = SSP;
	}
	NvSanXuat() {
		LuongCanBan = 0;
		SoSanPham = 0;
	}
	void Luong() {
		int x = LuongCanBan + SoSanPham * 5000;
		this->setl(x);
	}
	~NvSanXuat(){}
};
class NvVanPhong : public CPerson {
private:
	int SoNgaylamViec;
public:
	void setSNLV(int SNLV) {
		SoNgaylamViec = SNLV;
	}
	NvVanPhong() {
		SoNgaylamViec = 0;
	}
	void Luong() {
		int x = SoNgaylamViec * 100000;
		this->setl(x);
	}
	~NvVanPhong(){}
};

int main() {
	NvVanPhong A=NvVanPhong();
	NvSanXuat B = NvSanXuat();
	cout << "Nhan vien A" << endl;
	A.Nhap();
	cout << "Nhap so ngay lam viec: ";
	int SNLV;
	cin >> SNLV;
	A.setSNLV(SNLV);
	cin.ignore();
	cout << "Nhan vien B" << endl;
	B.Nhap();
	int SSP, LCB;
	cout << "Nhap luong can ban: ";
	cin >> LCB;
	B.setLCB(LCB);
	cout << "Nhap so san pham: ";
	cin >> SSP;
	B.setSSP(SSP);
	A.Luong();
	B.Luong();
	A.Xuat();
	B.Xuat();
	return 0;
}