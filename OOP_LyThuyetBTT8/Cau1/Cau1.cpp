# include<iostream>
#include<string>
using namespace std;

class Sach {
protected:
	int Gia;
	string Ten;
	string Loai;
	int SoTrang;
	string NgayXuatBan;
public:
	Sach() {
		Gia = SoTrang = 0;
		Ten = Loai = NgayXuatBan = '\0';
	}
	virtual void Nhap() = 0;
	virtual string getTen() = 0;
	virtual int getGia() = 0;
	virtual void Xuat() = 0;
	~Sach(){}
};

class SachGiaoKhoa : public Sach {
private:
	string Mon;
	int Lop;
public:
	SachGiaoKhoa() {
		Mon = '\0';
		Lop = 0;
		Loai = "Sach giao khoa";
	}
	void Nhap() {
		cout << "Nhap gia: ";
		cin >> Gia;
		cout << "Nhap so trang: ";
		cin >> SoTrang;
		cout << "Nhap lop: ";
		cin >> Lop;
		cout << "Nhap mon: ";
		cin.ignore();
		getline(cin, Mon);
		cout << "Nhap ten: ";
		getline(cin, Ten);
		cout << "Nhap ngay xuat ban: ";
		cin >> NgayXuatBan;
	}
	string getTen() {
		return Ten;
	}
	int getGia() {
		return Gia;
	}
	void Xuat() {
		cout << "Ten: " << Ten << endl;
		cout << "Mon hoc: " << Mon << endl;
		cout << "Lop: " << Lop << endl;
		cout << "Loai: " << Loai << endl;
		cout << "Gia: " << Gia << endl;
		cout << "So Trang: " << SoTrang << endl;
		cout << "Ngay xuat ban: " << NgayXuatBan << endl;
	}
};
class TieuThuyet: public Sach {
private:
	string TheLoai;
public:
	TieuThuyet() {
		TheLoai = '\0';
		Loai = "Tieu thuyet";
	}
	void Nhap() {
		cout << "Nhap gia: ";
		cin >> Gia;
		cout << "Nhap so trang: ";
		cin >> SoTrang;
		cout << "Nhap the loai tieu thuyet: ";
		cin.ignore();
		getline(cin, TheLoai);
		cout << "Nhap ten: ";
		getline(cin, Ten);
		cout << "Nhap ngay xuat ban: ";
		cin >> NgayXuatBan;
	}
	string getTen() {
		return Ten;
	}
	int getGia() {
		return Gia;
	}
	void Xuat() {
		cout << "Ten: " << Ten << endl;
		cout << "The loai: " << TheLoai << endl;
		cout << "Loai: " << Loai << endl;
		cout << "Gia: " << Gia << endl;
		cout << "So trang: " << SoTrang << endl;
		cout << "Ngay xuat ban: " << NgayXuatBan << endl;
	}
	~TieuThuyet(){}
};
class TapChi : public Sach {
private:
	string ChuDe;
public:
	TapChi() {
		ChuDe = '\0';
		Loai = "Tap chi";
	}
	void Nhap() {
		cout << "Nhap gia: ";
		cin >> Gia;
		cout << "Nhap so trang: ";
		cin >> SoTrang;
		cout << "Nhap chu de tap chi: ";
		cin.ignore();
		getline(cin, ChuDe);
		cout << "Nhap ten: ";
		getline(cin, Ten);
		cout << "Nhap ngay xuat ban: ";
		cin >> NgayXuatBan;
	}
	string getTen() {
		return Ten;
	}
	int getGia() {
		return Gia;
	}
	void Xuat() {
		cout << "Ten: " << Ten << endl;
		cout << "Chu de: " << ChuDe << endl;
		cout << "Loai: " << Loai << endl;
		cout << "Gia: " << Gia << endl;
		cout << "So trang: " << SoTrang << endl;
		cout << "Ngay xuat ban: " << NgayXuatBan << endl;
	}
	~TapChi() {}
};

class ThuVien {
private:
	Sach** s;
	string LoaiSach;
	int SoLuong;
public:
	ThuVien() {
		SoLuong = 0;
		s = NULL;
	}
	void Nhap() {
		cout << "Nhap so luong sach: ";
		cin >> SoLuong;
		s = new Sach * [SoLuong];
		for (int i = 0; i < SoLuong; i++) {
			cout << "Nhap loai sach: ";
			cin.ignore();
			getline(cin, LoaiSach);
			if (LoaiSach == "Sach giao khoa") {
				s[i] = new SachGiaoKhoa();
				s[i]->Nhap();
			}
			else if (LoaiSach == "Tieu thuyet") {
				s[i] = new TieuThuyet(); 
				s[i]->Nhap();
			}
			else if (LoaiSach == "Tap chi") {
				s[i] = new TapChi();
				s[i]->Nhap();
			}
			cout << endl;
		}
	}
	void Xuat() {
		for (int i = 0; i < SoLuong; i++) {
			s[i]->Xuat();
			cout << endl;
		}
	}
	int TongTien() {
		int k = 0;
		for (int i = 0; i < SoLuong; i++) {
			k = k + s[i]->getGia();
		}
		return k;
	}
	bool TimKiemSach() {
		string x;
		cout << "Nhap ten sach can tim: ";
		cin.ignore();
		getline(cin, x);
		for (int i = 0; i < SoLuong; i++) {
			if (x == s[i]->getTen()) {
				s[i]->Xuat();
				return true;
			}
		}
		return false;
	}
	int Menu() {
		int option;
		cin >> option;
		if (option == 1) {
			cout << "Tong tien: " << TongTien();
			return 1;
		}
		if (option == 2) {
			if (TimKiemSach() == false)
				cout << "Khong tim thay sach";
			return 1;
		}
		if (option == 3) {
			Xuat();
			return 1;
		}
		if (option == 0)
			return 0;
	}
	~ThuVien() {}
};

int main() {
	ThuVien a;
	a.Nhap();
	cout << "\nNhap lua chon:";
	cout << "\nNhap 1 de biet tong so tien sach";
	cout << "\nNhap 2 de tiem kiem sach";
	cout << "\nNhap 3 de xuat tat ca sach co trong thu vien";
	cout << "\nNhap 0 de ket thuc";
	cout << endl;
	while (true) {
		if (a.Menu() == 0)
			return 0;
		cout << endl;
	}
}