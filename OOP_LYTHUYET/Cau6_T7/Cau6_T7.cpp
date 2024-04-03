#include<iostream>
#include<string>
using namespace std;

class GiaSuc {
private:
	int SoLuong;
	string TiengKeu;
	int LitSua;
public:
	GiaSuc() {
		SoLuong = 0;
		TiengKeu = '\0';
		LitSua = 0;
	}
	void setTiengKeu(string tieng) {
		TiengKeu = tieng;
	}
	void Nhap() {
		cout << "Nhap so luong: ";
		cin >> SoLuong;
	}
	void Doi() {
		cout << TiengKeu << "!" << "  ";
	}
	void Xuat() {
		cout << "So luong: " << SoLuong << " con";
		cout << endl;
		cout << "Sua: " << LitSua << " (lit)";
		cout << endl;
	}
	void SinhCon() {
		srand(time(NULL));
		SoLuong = SoLuong + rand() % (SoLuong + 1);
	}
	void ChoSua(int t) {
		srand(time(NULL));
		LitSua = SoLuong * (rand() % (t + 1));
	}
	~GiaSuc(){}
};
class Bo : public GiaSuc {
public:
	Bo() {
		setTiengKeu("Booooo");
	}
	~Bo() {};
};
class Cuu : public GiaSuc {
public:
	Cuu() {
		setTiengKeu("Eeeeeeee");
	}
	~Cuu() {};
};
class De : public GiaSuc {
public:
	De() {
		setTiengKeu("Ee ee ee");
	}
	~De() {};
};


int main() {
	Bo B = Bo();
	Cuu C = Cuu();
	De D = De();
	cout << "Nhap so luong loai Bo" << endl;
	B.Nhap();
	cout << "Nhap so luong loai Cuu" << endl;
	C.Nhap();
	cout << "Nhap so luong loai De" << endl;
	D.Nhap();
	cout << "Tieng keu nghe duoc trong nong trai la: ";
	B.Doi();
	C.Doi();
	D.Doi();

	cout << "Sau mot luot sinh con va cho sua" << endl;
	B.ChoSua(20);
	B.SinhCon();
	cout << "Bo:" << endl;
	B.Xuat();

	C.ChoSua(5);
	C.SinhCon();
	cout << "Cuu:" << endl;
	C.Xuat();

	D.ChoSua(10);
	D.SinhCon();
	cout << "De:" << endl;
	D.Xuat();
	return 0;
}