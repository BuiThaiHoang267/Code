#include<iostream>
#include<string>
using namespace std;

class Person {
private:
	string Name;
	string DateOfBirth;
	string Accommodation;
	string Sex;
public:
	void Nhap() {
		cout << "Nhap ten: ";
		getline(cin, Name);
		cout << "Nhap ngay sinh: ";
		cin >> DateOfBirth;
		cout << "Nhap noi o: ";
		cin.ignore();
		getline(cin, Accommodation);
		cout << "Nhap gioi tinh: ";
		cin >> Sex;
	}
	void Xuat() {
		cout << "Ho va ten: ";
		cout << Name << endl;
		cout << "Ngay sinh: ";
	    cout << DateOfBirth << endl;
		cout << "Noi o: ";
		cout << Accommodation << endl;
		cout << "Gioi tinh: ";
		cout << Sex << endl;
	}
};
class SinhVien: public Person{
private:
	int Namhoc;
	string NienKhoa;
	string TruongHoc;
	string NganhHoc;
public:
	SinhVien() {
		Namhoc = 0;
		NienKhoa = '\0';
		TruongHoc = '\0';
		NganhHoc = '\0';
	}
	void NhapRieng() {
		cout << "Nhap sinh vien nam may: ";
		cin >> Namhoc;
		cout << "Nhap nien khoa: ";
		cin.ignore();
		getline(cin, NienKhoa);
		cout << "Nhap truong hoc: ";
		getline(cin, TruongHoc);
		cout << "Nhap nganh hoc: ";
		getline(cin, NganhHoc);
	}
	void XuatRieng() {
		cout << "Sinh vien nam " << Namhoc << endl;
		cout << "Nien khoa: " << NienKhoa << endl;
		cout << "Truong hoc: " << TruongHoc << endl;
		cout << "Nganh hoc: " << NganhHoc << endl;
	}
	~SinhVien() {}
};
class HocSinh : public Person {
private:
	string Truong;
	int Lop;
public:
	HocSinh() {
		Truong = '\0';
		Lop = 0;
	}
	void NhapRieng() {
		cout << "Nhap lop: ";
		cin >> Lop;
		cout << "Nhap truong hoc: ";
		cin.ignore();
		getline(cin, Truong);
	}
	void XuatRieng() {
		cout << "Truong: " << Truong << endl;
		cout << "Lop: " << Lop << endl;
	}
	~HocSinh() {}
};
class CaSi: public Person {
private:
	string NgheDanh;
	string LinhVucChuyenMon;
public:
	CaSi() {
		NgheDanh = '\0';
	    LinhVucChuyenMon = '\0';
	}
	void NhapRieng() {
		cout << "Nhap nghe danh: ";
		getline(cin, NgheDanh);
		cout << "Nhap linh vuc chuyen mon: ";
		getline(cin, LinhVucChuyenMon);
	}
	void XuatRieng() {
		cout << "Nghe danh: " << NgheDanh << endl;
		cout << "Linh vuc chuyen mon: " << LinhVucChuyenMon << endl;
	}
	~CaSi(){}
};
class NgheSi: public CaSi {
};
class CongNhan :public Person {
private:
	string NoiLamViec;
	int luong;
public:
	CongNhan() {
		NoiLamViec = '\0';
		luong = 0;
	}
	void NhapRieng() {
		cout << "Nhap luong: ";
		cin >> luong;
		cout << "Nhap noi lam viec: ";
		cin.ignore();
		getline(cin, NoiLamViec);
	}
	void XuatRieng() {
		cout << "Noi lam viec: " << NoiLamViec << endl;
		cout << "Luong: " << luong << endl;
	}
	~CongNhan(){}
};

int main() {
	cout << "Ban muon nhap xuat thong tin cua:" << endl;
	cout << "Sinh vien vui long nhap 1" << endl;
	cout << "Hoc Sinh vui long nhap 2" << endl;
	cout << "Ca si vui long nhap 3" << endl;
	cout << "Nghe si vui long nhap 4 " << endl;
	cout << "Cong Nhan vui long nhap 5 " << endl;
	int n;
	cin >> n;
	if (n == 1) {
		SinhVien S = SinhVien();
		cin.ignore();
		S.Nhap();
		S.NhapRieng();
		S.Xuat();
		S.XuatRieng();
	}
	else if (n == 2) {
		HocSinh H = HocSinh();
		cin.ignore();
		H.Nhap();
		H.NhapRieng();
		H.Xuat();
		H.XuatRieng();
	}
	else if (n == 3) {
		CaSi C = CaSi();
		cin.ignore();
		C.Nhap();
		cin.ignore();
		C.NhapRieng();
		C.Xuat();
		C.XuatRieng();
	}
	else if (n == 4) {
		NgheSi N;
		cin.ignore();
		N.Nhap();
		cin.ignore();
		N.NhapRieng();
		N.Xuat();
		N.XuatRieng();
	}
	else if (n == 5) {
		CongNhan C = CongNhan();
		cin.ignore();
		C.Nhap();
		C.NhapRieng();
		C.Xuat();
		C.XuatRieng();
	}
	return 0;
}