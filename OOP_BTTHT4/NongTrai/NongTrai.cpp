#include<iostream>
#include<queue>
using namespace std;

class GiaSuc {
protected:
	string Ten;
	int SoLuong;
	int Sua;
	int SoConTruongThanh;
public:
	GiaSuc() {
		Ten = '\0';
		SoLuong = 1;
		Sua = 0;
		SoConTruongThanh = 0;
	}
	void Nhap() {
		cin >> SoLuong;
		SoConTruongThanh = SoLuong;
	}
	virtual void TongConVaChoSua(int m) = 0;
	void Xuat() {
		cout << Ten << ": " << SoLuong << "," << Sua << endl;
	}
};
class Bo :public GiaSuc {
public:
	Bo() {
		Ten = "Bo";
	}
	void TongConVaChoSua(int m) {
		queue<int> DotConTruongThanh;
		for (int i = 1; i <= m; i++) {
			if (i >= 5) {
				SoConTruongThanh = SoConTruongThanh + DotConTruongThanh.front();
				DotConTruongThanh.pop();
			}
			DotConTruongThanh.push(SoConTruongThanh / 2);
			SoLuong = SoLuong + SoConTruongThanh / 2;
			Sua = Sua + SoConTruongThanh * 10;
		}
	}
};
class De :public GiaSuc {
public:
	De() {
		Ten = "De";
	}
	void TongConVaChoSua(int m) {
		queue<int> DotConTruongThanh;
		for (int i = 1; i <= m; i++) {
			if (i >= 5) {
				SoConTruongThanh = SoConTruongThanh + DotConTruongThanh.front();
				DotConTruongThanh.pop();
			}
			DotConTruongThanh.push(SoConTruongThanh / 2);
			SoLuong = SoLuong + SoConTruongThanh / 2;
			Sua = Sua + SoConTruongThanh * 8;
		}
	}
};
class Cuu :public GiaSuc {
public:
	Cuu() {
		Ten = "Cuu";
	}
	void TongConVaChoSua(int m) {
		queue<int> DotConTruongThanh;
		for (int i = 1; i <= m; i++) {
			if (i >= 5) {
				SoConTruongThanh = SoConTruongThanh + DotConTruongThanh.front();
				DotConTruongThanh.pop();
			}
			DotConTruongThanh.push(SoConTruongThanh / 2);
			SoLuong = SoLuong + SoConTruongThanh / 2;
			Sua = Sua + SoConTruongThanh * 5;
		}
	}
};
class Tho :public GiaSuc {
public:
	Tho() {
		Ten = "Tho";
	}
	void TongConVaChoSua(int m) {
		queue<int> DotConTruongThanh;
		for (int i = 1; i <= m; i++) {
			if (i >= 3) {
				SoConTruongThanh = SoConTruongThanh + DotConTruongThanh.front();
				DotConTruongThanh.pop();
			}
			DotConTruongThanh.push(SoConTruongThanh / 2);
			SoLuong = SoLuong + SoConTruongThanh / 2;
		}
	}
};

int main() {
	GiaSuc* g[4];
	g[0] = new Bo();
	g[1] = new Cuu();
	g[2] = new De();
	g[3] = new Tho();
	for (int i = 0; i < 4; i++) {
		g[i]->Nhap();
	}
	int m;
	cin >> m;
	for (int i = 0; i < 4; i++) {
		g[i]->TongConVaChoSua(m);
	}
	for (int i = 0; i < 4; i++)
	{
		g[i]->Xuat();
	}
	return 0;
}