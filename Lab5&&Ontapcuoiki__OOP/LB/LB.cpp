#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Diem {
public:
	int x;
	int y;
	Diem() {
		x = y = 0;
	}
	void Nhap() {
		cin >> x;
		cin >> y;
	}
	float KhoangCach(Diem a) {
		return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
	}
};

class Request {
public:
	int ID;
	float weight;
	Diem ToaDo;
	int IdServerXuly;
	Request() {
		ID = weight = 0;
		IdServerXuly = 0;
	}
	void Nhap() {
		cin >> ID;
		cin >> weight;
		ToaDo.Nhap();
	}
};

class LB {
public:
	int ID;
	Diem ToaDo;
	string tb;
	int Loai;
	LB() {
		ID = 0;
		tb = "\0";
		Loai = 0;
	}
	virtual void Nhap() = 0;
	int getLoai() {
		return Loai;
	}
	virtual float XuLy(int loai, vector<Request> &t, vector<Request> &x) = 0;
};

class Server :public LB {
public:
	float RAM;
	float CPU;
	Server() {
		RAM = CPU = 0;
		tb = "Server";
	}
	void Nhap() {
		cin >> ID;
		cin >> RAM;
		cin >> CPU;
		ToaDo.Nhap();
	}
	float XuLy(int loai, vector<Request> &t, vector<Request> &x) {
		if (loai == 2) {
			return RAM * CPU;
		}
		return 0;
	}
};
class LBc: public LB {
public:
	int n;
	int m;
	vector<LB*> lb;
	LBc() {
		Loai = 1;
		m = 0;
		n = 0;
		tb = "LB";
	}
	void Nhap() {
		cin >> ID;
		cin >> Loai;
		ToaDo.Nhap();
		cin >> n;
		cin >> m;
		for (int i = 0; i < n; i++) {
			LB* temp = new Server;
			temp->Nhap();
			lb.push_back(temp);
		}
		for (int i = 0; i < m; i++) {
			LB* temp = new LBc;
			temp->Nhap();
			lb.push_back(temp);
		}
	}
	float XuLy(int loai,vector<Request> &t, vector<Request> &x) {
		if (loai == 1) {
			for (int i = 0; i < n-1; i++) {
				t[0].IdServerXuly = lb[i]->ID;
				x.push_back(t[0]);
				t.erase(t.begin() + 0);
			}
			while (!t.empty()) {
				t[0].IdServerXuly = lb[n - 1]->ID;
				x.push_back(t[0]);
				t.erase(t.begin() + 0);
			}
		}
		else if (loai == 2) {
			int k = n;
			for (int i = 0; i < k; i++) {
				float lc = 1000;
				int vt1=0;
				int vt2=0;
				for (int j = 0; j < n; j++) {
					for (int z = t.size()-1; z >= 0; z--) {
						if (lc > abs(t[z].weight - lb[j]->XuLy(2, t, x))) {
							lc = abs(t[z].weight - lb[j]->XuLy(2, t, x));
							vt1 = j;
							vt2 = z;
						}
					}
				}
				t[vt2].IdServerXuly = lb[vt1]->ID;
				x.push_back(t[vt2]);
				t.erase(t.begin() + vt2);
				lb.erase(lb.begin() + vt1);
				n--;
				if (t.empty()||lb.empty())
					break;
			}
		}
		else if (loai == 3) {
			int k = n;
			for (int i = 0; i < k; i++) {
				float lc = 1000;
				int vt1=0;
				int vt2=0;
				for (int j = 0; j < n; j++) {
					for (int z = 0; z < t.size(); z++) {
						if (lc > (ToaDo.KhoangCach(lb[j]->ToaDo)+lb[j]->ToaDo.KhoangCach(t[z].ToaDo))) {
							lc = ToaDo.KhoangCach(lb[j]->ToaDo) + lb[j]->ToaDo.KhoangCach(t[z].ToaDo);
							vt1 = j;
							vt2 = z;
						}
					}
				}
				t[vt2].IdServerXuly = lb[vt1]->ID;
				x.push_back(t[vt2]);
				t.erase(t.begin() + vt2);
				lb.erase(lb.begin() + vt1);
				n--;
				if (t.empty() || lb.empty())
					break;
			}
		}
		for (int i = n; i < m - 1 + n; i++) {
			if (t.empty()) {
				break;
			}
			vector<Request> temp;
			temp.push_back(t[0]);
			t.erase(t.begin() + 0);
			lb[i]->XuLy(lb[i]->Loai, temp, x);
		}
		if (!t.empty()) {
			lb[m - 1 + n]->XuLy(lb[m - 1 + n]->Loai, t, x);
		}
		return 0;
	}
};

class LoadBalancing {
public:
	int n;
	vector<Request> r;
	LBc l;
	vector<Request> RequestDaxuly;
	LoadBalancing() {
		n = 0;
	}
	void Nhap() {
		l.Nhap();
		cin >> n;
		for (int i = 0; i < n; i++) {
			Request temp;
			temp.Nhap();
			r.push_back(temp);
		}
	}
	void XuLy() {
		if (n == 0) {
			return;
		}
		l.XuLy(l.Loai,r, RequestDaxuly);
		for (int i = 0; i < RequestDaxuly.size() - 1; i++) {
			for (int j = i + 1; j < RequestDaxuly.size(); j++) {
				if (RequestDaxuly[i].ID > RequestDaxuly[j].ID)
					swap(RequestDaxuly[i], RequestDaxuly[j]);
			}
		}
		for (int i = 0; i < RequestDaxuly.size(); i++) {
			cout << RequestDaxuly[i].ID << " " << RequestDaxuly[i].IdServerXuly << endl;
		}
	}
};

int main() {
	LoadBalancing LBC;
	LBC.Nhap();
	LBC.XuLy();
	return 0;
}

