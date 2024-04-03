#include<iostream>
using namespace std;

static int TongSucChua = 0;

class CPhong {
protected:
	string Name;
	int Floor;
	int RoomNumber;
	int Capacity;
public:
	CPhong() {
		Name = '\n';
		Floor = 9999;
		RoomNumber = 0;
		Capacity = 0;
	}
	virtual void Nhap() {
		cin >> Name;
		cin >> Floor;
		cin >> RoomNumber;
		cin >> Capacity;
		TongSucChua += Capacity;
	}
	int getRoomNumber() {
		return RoomNumber;
	}
	int getFloor() {
		return Floor;
	}
	int getCapacity() {
		return Capacity;
	}
	string getName() {
		return Name;
	}
};

class CPhongLyThuyet :public CPhong {
private:
	int MayLanh;
public:
	CPhongLyThuyet() {
		MayLanh = 0;
	}
	void Nhap() {
		CPhong::Nhap();
		cin >> MayLanh;
	}
};
class CPhongThucHanh : public CPhong {
private:
	int SoLuongMayTinh;
public:
	CPhongThucHanh() {
		SoLuongMayTinh = 0;
	}
	void Nhap() {
		CPhong::Nhap();
		cin >> SoLuongMayTinh;
	}
};
class CGiangDuong : public CPhong {
private:
	int SoLuongMayChieu;
public:
	CGiangDuong() {
		SoLuongMayChieu = 0;
	}
	void Nhap() {
		CPhong::Nhap();
		cin >> SoLuongMayChieu;
	}
};

class CoSoVatChat {
protected:
	int n;
	CPhong** ds;
public:
	CoSoVatChat() {
		n = 0;
		ds = NULL;
	}
	void Nhap() {
		cin >> n;
		ds = new CPhong * [n];
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			switch (x) {
			case 1: ds[i] = new CPhongLyThuyet;
				break;
			case 2: ds[i] = new CPhongThucHanh;
				break;
			case 3: ds[i] = new CGiangDuong;
				break;
			}
			ds[i]->Nhap();
		}
	}
	void TimPhong() {
		int k;
		cin >> k;
		cout << TongSucChua << endl;
		CPhong kq;
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if(ds[i]->getCapacity()>=k)
				if (ds[i]->getFloor() <= kq.getFloor())
				{
					if (ds[i]->getFloor() < kq.getFloor()) {
						kq = *ds[i];
						flag = 1;
					}
					else
						if (ds[i]->getRoomNumber() < kq.getRoomNumber()) {
							kq = *ds[i];
							flag = 1;
						}
				}
		}
		if (flag == 1)
			cout << kq.getName();
		else
			cout << "NULL";
	}
};

int main() {
	CoSoVatChat C;
	C.Nhap();
	C.TimPhong();
	return 0;
}