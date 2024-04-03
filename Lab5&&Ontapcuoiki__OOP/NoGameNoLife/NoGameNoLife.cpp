#include<iostream>
#include<vector>
using namespace std;

static bool KiemTraMuVang = false;
static bool KiemTraMuBac = false;

class TrangBi {
public:
	string name;
	double price;
	string producer;
	double giathuc;
	string loai;
	TrangBi() {
		name = loai =producer= '\0';
		price = giathuc = 0;
	}
	virtual void Nhap() {
		cin >> name;
		cin >> price;
		cin >> producer;
	}
};
class Jean :public TrangBi {
public:
	float length;
	Jean() {
		length = 0;
		loai = "Quan";
	}
	void Nhap() {
		TrangBi::Nhap();
		giathuc = 0.8 * price;
		cin >> length;
	}
};
class Kaki :public TrangBi {
public:
	float length;
	Kaki() {
		length = 0;
		loai = "Quan";
	}
	void Nhap() {
		TrangBi::Nhap();
		giathuc = 1.5 * price;
		cin >> length;
	}
};
class AoNganTay :public TrangBi {
public:
	string color;
	int CoAo;
	AoNganTay() {
		color = "\0";
		CoAo = 0;
		loai = "Ao";
	}
	void Nhap() {
		TrangBi::Nhap();
		giathuc = price;
		cin >> color;
		cin >> CoAo;
	}
};
class AoDaiTay :public TrangBi {
public:
	string color;
	float ChieuDaiOngTayAo;
	AoDaiTay() {
		color = "\0";
		ChieuDaiOngTayAo = 0;
		loai = "Ao";
	}
	void Nhap() {
		TrangBi::Nhap();
		giathuc = price;
		cin >> color;
		cin >> ChieuDaiOngTayAo;
	}
};
class MuSat :public TrangBi {
public:
	int level;
	MuSat() {
		level = 0;
		loai = "Mu";
	}
	void Nhap() {
		TrangBi::Nhap();
		giathuc = 0;
		cin >> level;
	}
};
class MuBac :public TrangBi {
public:
	int level;
	MuBac() {
		level = 0;
		loai = "Mu";
	}
	void Nhap() {
		TrangBi::Nhap();
		giathuc = price;
		cin >> level;
		KiemTraMuBac = true;
	}
};
class MuVang :public TrangBi {
public:
	int level;
	MuVang() {
		level = 0;
		loai = "Mu";
	}
	void Nhap() {
		TrangBi::Nhap();
		giathuc = price;
		cin >> level;
		KiemTraMuVang = true;
	}
};
class RuongDo {
private:
	int n;
	vector<TrangBi*> ds;
public:
	RuongDo() {
		n = 0;
	}
	void Nhap() {
		cin >> n;
		TrangBi* temp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			switch (x)
			{
			case 1:temp = new Jean;
				break;
			case 2:temp = new Kaki;
				break;
			case 3:temp = new AoNganTay;
				break;
			case 4:temp = new AoDaiTay;
				break;
			case 5:temp = new MuSat;
				break;
			case 6:temp = new MuBac;
				break;
			case 7:temp = new MuVang;
				break;
			default:temp = NULL;
				break;
			}
			if (temp != NULL) {
				temp->Nhap();
				ds.push_back(temp);
			}
		}
	}
	void KiemTraBuff() {
		double x = 1;
		if (KiemTraMuBac == true)
			x = 1.5;
		if (KiemTraMuVang == true)
			x = 3.0;
		for (int i = 0; i < n; i++) {
			if (ds[i]->loai != "Mu")
				ds[i]->giathuc=ds[i]->giathuc*x;
		}
	}
	double GiaTriRuongDo() {
		double s = 0;
		for (int i = 0; i < n; i++) {
			s = s + ds[i]->giathuc;
		}
		return s;
	}
};


int main() {
	RuongDo Q;
	Q.Nhap();
	Q.KiemTraBuff();
	cout << Q.GiaTriRuongDo();
	return 0;
}