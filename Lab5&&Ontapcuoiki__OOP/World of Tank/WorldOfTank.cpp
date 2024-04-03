#include<iostream>
using namespace std;

class CThapPhao {
protected:
	float size;
	int num_ammos;
public:
	CThapPhao() {
		size = num_ammos = 0;
	}
	void Nhap() {
		cin >> num_ammos;
	}
	int getNum_Ammos() {
		return num_ammos;
	}
	void setNum_Ammos(int x) {
		num_ammos = x;
	}
	virtual float Damage(int numcrews,int SoLuongDanDaBan) = 0;
};
class CML20S :public CThapPhao {
public:
	CML20S() {
		size = 152;
	}
	float Damage(int numcrews, int SoLuongDanDaBan) {
		return (float)numcrews / 4 * size * (num_ammos-SoLuongDanDaBan);
	}
};
class CF34 :public CThapPhao {
public:
	CF34() {
		size = 76.2;
	}
	float Damage(int numcrews,int SoLuongDanDaBan) {
		return 3 * size * (num_ammos - SoLuongDanDaBan);
	}
};
class CD25T :public CThapPhao {
public:
	CD25T() {
		size = 122;
	}
	float Damage(int numcrews,int SoLuongDanDaBan) {
		return 3 * size * (num_ammos - SoLuongDanDaBan);
	}
};
class CM65L :public CThapPhao {
public:
	CM65L() {
		size = 130;
	}
	float Damage(int numcrews, int SoLuongDanDaBan) {
		return (float)numcrews / 4 * size * (num_ammos - SoLuongDanDaBan);
	}
};

class CDongCo {
protected:
	float HP;
	float Xang;
public:
	CDongCo() {
		HP = Xang = 0;
	}
	void Nhap() {
		cin >> Xang;
	}
	float getXang() {
		return Xang;
	}
	virtual float TieuThu(int weight) = 0;
};
class CV2 :public CDongCo {
public:
	CV2() {
		HP = 500;
	}
	float TieuThu(int weight) {
		return 450.0 / weight;
	}
};
class CV2K :public CDongCo {
public:
	CV2K() {
		HP = 600;
	}
	float TieuThu(int weight) {
		return 450.0 / weight;
	}
};
class C2DG8M :public CDongCo {
public:
	C2DG8M() {
		HP = 1000;
	}
	float TieuThu(int weight) {
		return 400.0 / weight;
	}
};

class CTank {
protected:
	string Name;
	float weight;
	int num_crews;
	CThapPhao* tp;
	CDongCo* dc;
public:
	CTank() {
		Name = "\n";
		weight = num_crews = 0;
		tp = NULL;
		dc = NULL;
	}
	void Nhap() {
		cin >> weight;
		cin >> num_crews;
		tp->Nhap();
		dc->Nhap();
	}
	string getName() {
		return Name;
	}
	float getWeight() {
		return weight;
	}
	int getNum_Crews() {
		return num_crews;
	}
	float Damage(int SoDanDaBan) {
		if (SoDanDaBan >= tp->getNum_Ammos())
			return 0;
		else
			return tp->Damage(num_crews, SoDanDaBan);
	}
	virtual float Performance(int SoDanDaBan,float QuangDuongDaDi) = 0;
};
class CSU152 :public CTank {
public:
	CSU152() {
		Name = "SU152";
		tp = new CML20S;
		dc = new CV2K;
	}
	float Performance(int SoDanDaBan, float QuangDuongDaDi) {
		return (float)(tp->getNum_Ammos() - SoDanDaBan) / tp->getNum_Ammos() * 100.0;
	}
};
class CKV2 :public CTank {
public:
	CKV2() {
		Name = "KV2";
		tp = new CF34;
		dc = new CV2;
	}
	float Performance(int SoDanDaBan, float QuangDuongDaDi) {
		return (float)(tp->getNum_Ammos() - SoDanDaBan) / tp->getNum_Ammos() * 100.0;
	}
};
class CIS :public CTank {
public:
	CIS() {
		Name = "IS";
		tp = new CD25T;
		dc = new CV2K;
	}
	float Performance(int SoDanDaBan, float QuangDuongDaDi) {
		float HieuSuat = 100;
		HieuSuat = HieuSuat - (QuangDuongDaDi/100.0 * dc->TieuThu(weight) / dc->getXang() * 100.0);
		if (HieuSuat <= 0)
			return 0;
		return HieuSuat;
	}
};
class COject279 :public CTank {
public:
	COject279() {
		Name = "Object279";
		tp = new CM65L;
		dc = new C2DG8M;
	}
	float Performance(int SoDanDaBan, float QuangDuongDaDi) {
		return 100.0 * num_crews / 4;
	}
};

class CTankManagement {
protected:
	int n;
	CTank** ds;
	float KM;
	int LuongDan;
public:
	CTankManagement() {
		n = 0;
		ds = NULL;
		KM = LuongDan = 0;
	}
	void Nhap() {
		cin >> n;
		ds = new CTank * [n];
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == 1) {
				ds[i] = new CSU152;
			}
			if (x == 2) {
				ds[i] = new CKV2;
			}
			if (x == 3) {
				ds[i] = new CIS;
			}
			if (x == 4) {
				ds[i] = new COject279;
			}
			ds[i]->Nhap();
		}
		cin >> KM;
		cin >> LuongDan;
	}
	void Xuat() {
		for (int i = 0; i < n; i++) {
			cout << ds[i]->getName() << ", ";
			cout << "weight: " << ds[i]->getWeight() << ", ";
			cout << "number of crews: " << ds[i]->getNum_Crews() << ", ";
			cout << "damage: " << ds[i]->Damage(LuongDan) << ", ";
			cout << "performance: " << ds[i]->Performance(LuongDan, KM) <<"%" << endl;
		}
	}
};

int main() {
	CTankManagement M;
	M.Nhap();
	M.Xuat();
	return 0;
}