#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int KiemTraTDTN = 0;
static int DienDu = 0;

class DKThoiTiet {
public:
    int Gio;
    int TocDoGio;
    int May;
    int TongCongSuat;
    DKThoiTiet() {
        Gio = TocDoGio = May = TongCongSuat = 0;
    }
    void Nhap() {
        cin >> Gio;
        cin >> TocDoGio;
        cin >> May;
        cin >> TongCongSuat;
    }
};

class NhaMayDien {
public:
    int HieuSuat;
    int loai;
    NhaMayDien() {
        HieuSuat = 0;
        loai = 0;
    }
    void virtual Nhap() = 0;
    int virtual CongSuat(int gioht,int may,int gio) = 0;
};
class ThuyDien: public NhaMayDien{
public:
    int SoToMay;
    int TinhNang;
    int SoDien;
    ThuyDien() {
        SoDien = SoToMay = TinhNang = 0;
        loai = 1;
    }
    void Nhap() {
        cin >> HieuSuat;
        cin >> SoToMay;
        cin >> TinhNang;
        if (TinhNang == 1) {
            KiemTraTDTN = 1;
        }
    }
    int CongSuat(int gioht, int may, int gio) {
        return HieuSuat * SoToMay;
    }
};
class NhietDien :public NhaMayDien {
public:
    int SoLuongThan;
    NhietDien() {
        SoLuongThan = 0;
        loai = 2;
    }
    void Nhap() {
        cin >> HieuSuat;
        cin >> SoLuongThan;
    }
    int CongSuat(int gioht, int may, int gio) {
        return HieuSuat * SoLuongThan;
    }
};
class DienGio :public NhaMayDien {
public:
    int SoTuaPin;
    int TocDoGioToiDa;
    int TocDoGioHienTai;
    int HieuSuatThuc;
    DienGio() {
        SoTuaPin = 0;
        TocDoGioHienTai = 0;
        TocDoGioToiDa = 0;
        HieuSuatThuc = 0;
        loai = 3;
    }
    void Nhap() {
        cin >> HieuSuat;
        cin >> SoTuaPin;
        cin >> TocDoGioToiDa;
    }
    int CongSuat(int gioht, int may, int gio) {
        HieuSuatThuc = HieuSuat * gioht / TocDoGioToiDa;
        return HieuSuatThuc * SoTuaPin;
    }
};
class DienMatTroi :public NhaMayDien {
public:
    double DienTichPin;
    double HieuSuatToiDa;
    DienMatTroi() {
        loai = 4;
        DienTichPin = 0;
        HieuSuatToiDa = 0;
    }
    void Nhap() {
        cin >> HieuSuat;
        cin >> DienTichPin;
        HieuSuatToiDa = HieuSuat;
    }
    int CongSuat(int gioht, int may, int gio) {
        if (may == 1) {
            HieuSuat = 0;
        }
        else if (gio >= 18 && gio >= 0 && gio <= 6) {
            HieuSuat = 0;
        }
        else if (gio >= 11 && gio <= 13) {
            HieuSuat = HieuSuatToiDa;
        }
        else if (gio >= 7 && gio <= 10) {
            HieuSuat = HieuSuatToiDa * (gio - 6) / 5;
        }
        else if (gio > 13 && gio < 18) {
            HieuSuat = HieuSuatToiDa * (gio - 13) / 5;
        }
        return int(HieuSuat * DienTichPin + 0.999);
    }
};

class EVN {
public:
    int n;
    vector<NhaMayDien*> D;
    int m;
    vector<DKThoiTiet> T;
    EVN() {
        n = m = 0;
    }
    void Nhap() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            NhaMayDien* temp;
            int x;
            cin >> x;
            switch (x)
            {
            case 1: temp = new ThuyDien;
                break;
            case 2: temp = new NhietDien;
                break;
            case 3: temp = new DienGio;
                break;
            case 4: temp = new DienMatTroi;
                break;
            default: temp = NULL;
                break;
            }
            if (temp != NULL) {
                temp->Nhap();
                D.push_back(temp);
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            DKThoiTiet temp;
            temp.Nhap();
            T.push_back(temp);
        }
    }
    double TongCongSuat(DKThoiTiet t) {
        double Tongcs = 0;
        for (int i = 0; i < n; i++) {
            Tongcs += D[i]->CongSuat(t.TocDoGio,t.May,t.Gio);
        }
        if (Tongcs >= t.TongCongSuat) {
            if (KiemTraTDTN == 1) {
                DienDu = Tongcs - t.TongCongSuat;
            }
            return t.TongCongSuat;
        }
        else if (Tongcs < t.TongCongSuat) {
            if (KiemTraTDTN == 1) {
                if ((Tongcs + DienDu) >= t.TongCongSuat) {
                    DienDu = Tongcs+ DienDu - t.TongCongSuat;
                    return t.TongCongSuat;
                }
                else {
                    DienDu = 0;
                    return Tongcs + DienDu;
                }
            }
        }
    }
    double TongCongSuatTan(DKThoiTiet t) {
        int Tongcs = 0;
        for (int i = 0; i < n; i++) {
            if (D[i]->loai == 1 || D[i]->loai == 2) {
                if (DienDu > 0) {
                    Tongcs += D[i]->CongSuat(t.TocDoGio, t.May, t.Gio) + DienDu;
                    break;
                }
                Tongcs += D[i]->CongSuat(t.TocDoGio, t.May, t.Gio);
            }
        }
        return Tongcs;
    }
    void TongThu() {
        if (m == 0 || n == 0) {
            cout << 0;
            return;
        }
        int ThoiDiemTan = 0;
        int TCSTruocDo = 0;
        long long TienDien = 0;
        for (int i = 0; i < m; i++) {
            if (i >= 1+ThoiDiemTan) {
                if (TCSTruocDo >= 1.2 * TongCongSuat(T[i])) {
                    ThoiDiemTan += i;
                    TienDien += TongCongSuat(T[i])*3000;
                }
            }
            if (ThoiDiemTan != 0) {
                if (i >= ThoiDiemTan + 1 && i <= ThoiDiemTan + 2) {
                    TienDien += (TongCongSuatTan(T[i])*3000);
                }
            }
            else {
                if (TongCongSuat(T[i]) / T[i].TongCongSuat <= 0.50) {
                    TienDien += (TongCongSuat(T[i])*2000);
                }
                else if (TongCongSuat(T[i]) / T[i].TongCongSuat <= 0.80 && TongCongSuat(T[i]) / T[i].TongCongSuat > 0.50) {
                    TienDien += (TongCongSuat(T[i]) * 2500);
                }
                else {
                    TienDien += (TongCongSuat(T[i])*3000);
                }
            }
        }
        cout << TienDien*1000;
    }
};

int main() {
    EVN E;
    E.Nhap();
    E.TongThu();
    return 0;
}
