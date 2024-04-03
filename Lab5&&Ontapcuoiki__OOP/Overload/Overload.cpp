#include<iostream>
#include<string>
#include<vector>
using namespace std;

static int DemNhanLoai = 0;
static int DemDevil = 0;


class ThanhVien {
protected:
	string Name;
	float HP, ATK, DEF;
public:
	ThanhVien() {
		Name = "\0";
		HP = ATK = DEF = 0;
	}
	virtual void Nhap() {
		cin >> Name;
		cin >> HP;
		cin >> ATK;
		cin >> DEF;
	}
	void setHP(float x) {
		HP = x;
	}
	string getName() {
		return Name;
	}
	float getHP() {
		return HP;
	}
	float getATK() {
		return ATK;
	}
	float getDEF() {
		return DEF;
	}
	virtual void KichThuocTinh() = 0;
};
class HuMan :public ThanhVien {
protected:
	string jobclass;
public:
	HuMan() {
		jobclass = '\0';
	}
	void Nhap() {
		ThanhVien::Nhap();
		cin.ignore();
		cin >> jobclass;
	}
	void KichThuocTinh() {
	}
};
class Elf :public ThanhVien {
protected:
	string jobclass;
public:
	Elf() {
		jobclass = '\0';
	}
	void Nhap() {
		ThanhVien::Nhap();
		cin >> jobclass;
	}
	void KichThuocTinh() {
		DEF = DEF * 15/10;
	}
};
class Orc :public ThanhVien {
protected:
	string racialclass;
public:
	Orc() {
		racialclass = '\0';
	}
	void Nhap() {
		ThanhVien::Nhap();
		cin >> racialclass;
	}
	void KichThuocTinh() {
		HP = HP * 15/10;
	}
};
class Golbin :public ThanhVien {
protected:
	string racialclass;
public:
	Golbin() {
		racialclass = '\0';
	}
	void Nhap() {
		ThanhVien::Nhap();
		cin >> racialclass;
	}
	void KichThuocTinh() {
		ATK = ATK * 11/10;
	}
};
class Vampire :public ThanhVien {
public:
	void Nhap() {
		ThanhVien::Nhap();
	}
	void KichThuocTinh() {
		HP = HP + HP * DemNhanLoai * 1/10;
	}
};
class Devil :public ThanhVien {
public:
	void Nhap() {
		ThanhVien::Nhap();
	}
	void KichThuocTinh() {
		ATK = ATK + ATK * DemDevil *1/10;
		DEF = DEF + DEF * DemDevil *1/10;
	}
};
class BOSS :public ThanhVien {
public:
	void Nhap() {
		ThanhVien::Nhap();
	}
	void KichThuocTinh() {
	}
};

class Guild {
private:
	int n;
	vector<ThanhVien*> ds;
	BOSS B;
public:
	Guild() {
		n = 0;
	}
	void Nhap() {
		cin >> n;
		int x;
		for (int i = 0; i < n; i++) {
			ThanhVien* temp;
			cin >> x;
			cin.ignore();
			switch(x){
			case 1:temp = new HuMan;
				DemNhanLoai++;
				break;
			case 2:temp = new Elf;
				DemNhanLoai++;
				break;
			case 3:temp = new Orc;
				break;
			case 4:temp = new Golbin;
				break;
			case 5:temp= new Vampire;
				break;
			case 6:temp = new Devil;
				DemDevil++;
				break;
			default:
				temp = NULL;
				break;
			}
			if (temp != NULL) {
				temp->Nhap();
				ds.push_back(temp);
			}
		}
		n = ds.size();
		B.Nhap();
	}
	void Xuat(int j) {
		for (int i = j; i < n; i++) {
			cout << ds[i]->getName() << " " << ds[i]->getHP() << endl;
		}
	}
	int KiemTra() {
		if (ds.empty()) {
			cout << B.getName() << " " << B.getHP();
			return 1;
		}
		return 0;
	}
	void OanhBoss() {
		if (n == 0) {
			cout << B.getName() << " " << B.getHP();
			return;
		}
		float TongDame = 0;
		for (int i = 0; i < n - 1; i++) {
			float x = ds[i]->getHP();
			int index = i;
			for (int j = i + 1; j < n; j++)
				if (ds[j]->getHP() < x) {
					x = ds[j]->getHP();
					index = j;
				}
			swap(ds[i], ds[index]);
		}

		for (int i = 0; i < n; i++) {
			if (ds[i]->getATK() > B.getDEF())
				TongDame += ds[i]->getATK() - B.getDEF();
		}
		int j = 0;
		for (int i = 0; i <= 100; i++) {
			B.setHP(B.getHP() - TongDame);
			if (B.getHP() <= 0) {
				Xuat(j);
				return;
			}
			ds[j]->setHP(ds[j]->getHP() + ds[j]->getDEF() - B.getATK());
			if (ds[j]->getHP() <= 0) {
				if(ds[j]->getATK() > B.getDEF())
				   TongDame = TongDame - (ds[j]->getATK() - B.getDEF());
				j++;
				if (j == n) {
					cout << B.getName() << " " << B.getHP();
					return;
				}
			}
		}
		cout << B.getName() << " " << B.getHP();
	}
	void KichHe() {
		for (int i = 0; i < n; i++) {
			ds[i]->KichThuocTinh();
		}
	}
};


int main() {
	Guild G;
	G.Nhap();
	if (G.KiemTra() == 1)
		return 0;
	G.KichHe();
	G.OanhBoss();
	return 0;
}