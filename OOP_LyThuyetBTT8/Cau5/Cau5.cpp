#include<iostream>
#include<string>
using namespace std;

class GiaSuc {
protected:
	int SoLuong;
	string TiengKeu;
	float LitSua;
	string Loai;
public:
	GiaSuc() {
		SoLuong = 0;
		TiengKeu = '\0';
		LitSua = 0;
		Loai = '\0';
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
	int getSoLuong() {
		return SoLuong;
	}
	float getLitSua() {
		return LitSua;
	}
	void Xuat() {
		cout << Loai << endl;
		cout << "So luong: " << SoLuong << " con";
		cout << endl;
		cout << "Sua: " << LitSua << " (lit)";
		cout << endl;
	}
	int SinhCon() {
		srand(time(NULL));
		SoLuong = SoLuong + rand() % (SoLuong + 1);
		return SoLuong;
	}
	virtual float ChoSua() = 0;
	~GiaSuc() {}
};

class Bo : public GiaSuc {
public:
	Bo() {
		setTiengKeu("Booooo");
		Loai = "Bo";
	}
	float ChoSua() {
		srand(time(NULL));
		LitSua = SoLuong * (rand() % (20 + 1));
		return LitSua;
	}
	~Bo() {};
};
class Cuu : public GiaSuc {
public:
	Cuu() {
		setTiengKeu("Eeeeeeee");
		Loai = "Cuu";
	}
	float ChoSua() {
		srand(time(NULL));
		LitSua = SoLuong * (rand() % (5 + 1));
		return LitSua;
	}
	~Cuu() {};
};
class De : public GiaSuc {
public:
	De() {
		setTiengKeu("Ee ee ee");
		Loai = "De";
	}
	float ChoSua() {
		srand(time(NULL));
		LitSua = SoLuong * (rand() % (10 + 1));
		return LitSua;
	}
	~De() {};
};

class TrangTrai {
private:
	GiaSuc* G[3];
public:
	TrangTrai() {
		for (int i = 0; i < 3; i++)
			G[i] = NULL;
	}
	void Nhap() {
		G[0] = new Bo;
		G[1] = new Cuu;
		G[2] = new De;
		cout << "Bo\n";
		G[0]->Nhap();
		cout << "Cuu\n";
		G[1]->Nhap();
		cout << "De\n";
		G[2]->Nhap();
	}
	void AmThanhKhiGiaSucDoi() {
		cout << "Am thanh o trang trai khi gia suc doi: ";
		for (int i = 0; i < 3; i++) {
			G[i]->Doi();
			cout << "   ";
		}
		cout << endl;
	}
	void ChoSuaSinhCon() {
		cout << "Sau khi cho sua va sinh con\n";
		for (int i = 0; i < 3; i++) {
			G[i]->ChoSua();
			G[i]->SinhCon();
		}
	}
	int TongSoCon() {
		return G[0]->getSoLuong() + G[1]->getSoLuong() + G[2]->getSoLuong();
	}
	float TongSoSua() {
		return G[0]->getLitSua() + G[1]->getLitSua() + G[2]->getLitSua();
	}
	void Xuat() {
		G[0]->Xuat();
		G[1]->Xuat();
		G[2]->Xuat();
		cout << "Tong so gia suc: " << TongSoCon() <<" con"<< endl;
		cout << "Tong so sua: " << TongSoSua() <<" (lit)"<< endl;
	}
	int Menu() {
		int x;
		cout << endl;
		cout << "Nhap lua chon: ";
		cin >> x;
		cout << endl;
		if (x == 1) {
			Nhap();
			return 1;
		}
		if (x == 2) {
			Xuat();
			return 1;
		}
		if (x == 3) {
			AmThanhKhiGiaSucDoi();
			return 1;
		}
		if (x == 4) {
			ChoSuaSinhCon();
			Xuat();
			return 1;
		}
		if (x == 0)
			return 0;
	}
	~TrangTrai(){}
};


int main() {
	TrangTrai Farm;
	cout << "Nhap vao 1 de nhap thong tin gia suc cua trang trai " << endl;
	cout << "Nhap vao 2 de xuat thong tin gia suc trong trang trai " << endl;
	cout << "Nhap vao 3 de nghe am thanh cua trang trai khi gia suc doi" << endl;
	cout << "Nhap vao 4 de xuat ra thong tin cua dan gia suc sau khi sinh va cho sua" << endl;
	cout << "Nhap vao 0 de ket thuc chuong trinh " << endl;
	while (true) {
		if (Farm.Menu() == 0)
			return 0;
	}
}