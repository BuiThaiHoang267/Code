#include<iostream>
#include<vector>
using namespace std;

class NhomMau {
protected:
	string Nhom;
	bool Rh;
	string KieuMau;
public:
	NhomMau() {
		Nhom = KieuMau = "\0";
		Rh = false;
	}
	void Nhap() {
		int x;
		cout << "Nhap tinh trang Rh(0. Rh-, 1. Rh+): ";
		cin >> x;
		if (x == 1) {
			Rh = true;
			KieuMau = Nhom + '+';
		}
		else
			KieuMau = Nhom + '-';
	}
	string GetKieuMau() {
		return KieuMau;
	}
	string GetNhom() {
		return Nhom;
	}
	virtual bool NhanMau(NhomMau* a) = 0;
};
class A:public NhomMau {
public:
	A() {
		Nhom = "A";
	}
	virtual bool NhanMau(NhomMau* a) {
		if (Rh == false) {
			if (a->GetKieuMau() == "O-" || a->GetKieuMau() == "A-")
				return true;
			return false;
		}
		else {
			if (a->GetKieuMau() == "O-")
				return true;
			else if (a->GetKieuMau() == "O+")
				return true;
			else if (a->GetKieuMau() == "A+")
				return true;
			else if (a->GetKieuMau() == "A-")
				return true;
			else
				return false;
		}
	}
};
class B :public NhomMau {
public:
	B() {
		Nhom = "B";
	}
	virtual bool NhanMau(NhomMau* a) {
		if (Rh == false) {
			if (a->GetKieuMau() == "O-" || a->GetKieuMau() == "B-")
				return true;
			return false;
		}
		else {
			if (a->GetKieuMau() == "O-")
				return true;
			else if (a->GetKieuMau() == "O+")
				return true;
			else if (a->GetKieuMau() == "B+")
				return true;
			else if (a->GetKieuMau() == "B-")
				return true;
			else
				return false;
		}
	}
};
class AB :public NhomMau {
public:
	AB() {
		Nhom = "AB";
	}
	virtual bool NhanMau(NhomMau* a) {
		if (Rh == false) {
			if (a->GetKieuMau() == "O-")
				return true;
			else if (a->GetKieuMau() == "A-")
				return true;
			else if (a->GetKieuMau() == "B-")
				return true;
			else if (a->GetKieuMau() == "AB-")
				return true;
			else
				return false;
		}
		else {
			return true;
		}
	}
};
class O :public NhomMau {
public:
	O() {
		Nhom = "O";
	}
	virtual bool NhanMau(NhomMau* a) {
		if (Rh == false) {
			if (a->GetKieuMau() == "O-")
				return true;
			return false;
		}
		else {
			if (a->GetKieuMau() == "O-" || a->GetKieuMau() == "O+")
				return true;
			return false;
		}
	}
};

class ABO {
private:
	int n;
	vector<NhomMau*> N;
public:
	ABO() {
		n = 0;
	}
	void Nhap() {
		cout << "Nhap n: ";
		cin >> n;
		NhomMau* temp;
		for (int i = 0; i < n; i++) {
			int x;
		    cout << "Nhap loai mau(1: A, 2: B, 3: AB, 4: O): ";
			cin >> x;
			switch (x)
			{
			case 1: temp = new A;
				break;
			case 2: temp = new B;
				break;
			case 3: temp = new AB;
				break;
			case 4: temp = new O;
				break;
			default: temp = NULL;
				break;
			}
			if (temp != NULL) {
				temp->Nhap();
				N.push_back(temp);
			}
		}
	}
	void KiemTraDiTruyen() {
		N.clear();
		n = 3;
		cout<<"Nhap vao lan luot la nhom mau cua Bo, Me, Con de kiem tra!"<<endl;
		NhomMau* temp;
		for (int i = 0; i < n; i++) {
			int x;
			cout << "Nhap loai mau(1: A, 2: B, 3: AB, 4: O): ";
			cin >> x;
			switch (x)
			{
			case 1: temp = new A;
				break;
			case 2: temp = new B;
				break;
			case 3: temp = new AB;
				break;
			case 4: temp = new O;
				break;
			default: temp = NULL;
				break;
			}
			if (temp != NULL) {
				temp->Nhap();
				N.push_back(temp);
			}
		}
		if ((N[0]->GetNhom() == "A" && N[1]->GetNhom() == "B") || (N[1]->GetNhom() == "A" && N[0]->GetNhom() == "B")) {
			cout << "\nPhu hop voi quy luat duy truyen";
		}
		else if ((N[0]->GetNhom() == "A" && N[1]->GetNhom() == "AB") || (N[1]->GetNhom() == "A" && N[0]->GetNhom() == "AB")) {
			if (N[2]->GetNhom() != "O")
				cout << "\nPhu hop voi quy luat duy truyen";
		}
		else if ((N[0]->GetNhom() == "A" && N[1]->GetNhom() == "O") || (N[1]->GetNhom() == "A" && N[0]->GetNhom() == "O") || (N[1]->GetNhom() == "A" && N[0]->GetNhom() == "A")) {
			if (N[2]->GetNhom() == "A" || N[2]->GetNhom() == "O")
				cout << "\nPhu hop voi quy luat duy truyen";
		}
		else if ((N[0]->GetNhom() == "B" && N[1]->GetNhom() == "O") || (N[1]->GetNhom() == "B" && N[0]->GetNhom() == "O") || (N[1]->GetNhom() == "B" && N[0]->GetNhom() == "B")) {
			if (N[2]->GetNhom() == "B" || N[2]->GetNhom() == "O")
				cout << "\nPhu hop voi quy luat duy truyen";
		}
		else if ((N[0]->GetNhom() == "B" && N[1]->GetNhom() == "AB") || (N[1]->GetNhom() == "B" && N[0]->GetNhom() == "AB")) {
			if (N[2]->GetNhom() != "O")
				cout << "\nPhu hop voi quy luat duy truyen";
		}
		else if ((N[0]->GetNhom() == "AB" && N[1]->GetNhom() == "AB")) {
			if (N[2]->GetNhom() != "O")
				cout << "\nPhu hop voi quy luat duy truyen";
		}
		else if ((N[0]->GetNhom() == "O" && N[1]->GetNhom() == "AB") || (N[1]->GetNhom() == "O" && N[0]->GetNhom() == "AB")) {
			if (N[2]->GetNhom() == "A" || N[2]->GetNhom() == "B")
				cout << "\nPhu hop voi quy luat duy truyen";
		}
		else if ((N[0]->GetNhom() == "O" && N[1]->GetNhom() == "O")) {
			if (N[2]->GetNhom() == "O")
				cout << "\nPhu hop voi quy luat duy truyen";
		}
		else
			cout << "Khong phu hop voi quy luat duy truyen";
		N.clear();
		n == 0;
	}
	void XuatNguoiTruyenMau() {
		cout << "\nChon vi tri cua mot nguoi, de xuat tat ca nhung nguoi co the truyen mau: ";
		int x;
		cin >> x;
		cout << "\nNhung nguoi co the truyen mau la: ";
		for (int i = 0; i < n; i++) {
			if(i!=x)
			{
				if (N[x]->NhanMau(N[i]) == true)
					cout << "N["<< i << "]" << " ";
			}
		}
	}
	void Menu() {
		cout << "\nNhap lua chon: ";
		cout << "\nNhap 1: de Nhap danh sach nhom mau";
		cout << "\nNhap 2: de kiem tra 3 nguoi co dung quy luat duy truyen khong";
		cout << "\nNhap 3: de chon mot nguoi va xuat nhung nguoi con lai trong danh sach co the truyen mau";
		cout << "\nNhap 0: de ket thuc chuong trinh";
		while (true) {
			int x;
			cout << "\nNhap lua chon: ";
			cin >> x;
			if (x == 1) {
				Nhap();
			}
			if (x == 2) {
				KiemTraDiTruyen();
			}
			if (x == 3) {
				XuatNguoiTruyenMau();
			}
			if (x == 0)
				return;
		}
	}
};


int main() {
	ABO M;
	M.Menu();
	return 0;
}