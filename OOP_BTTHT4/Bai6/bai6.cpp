#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int TongGiaNhap = 0;

class LinhKien {
protected:
    string Id;
    string Hang;
    int GiaNhap;
public:
    LinhKien() {
        Id = Hang = '\0';
        GiaNhap = 0;
    }
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
};

class CPU:public LinhKien {
private:
    string Loai;
    int SoCore;
    float XungNhip;
public:
    CPU() {
        Loai= '0';
        SoCore = XungNhip = 0;
    }
    void Nhap() {
        int x;
        cin >> x;
        if (x == 1) {
            Loai = "Alpha";
            Hang = "Black";
            SoCore = 2;
            XungNhip = 1.8;
            GiaNhap = 200;
            TongGiaNhap += GiaNhap;
        }
        if (x == 2) {
            Loai = "Beta";
            Hang = "Black";
            SoCore = 4;
            XungNhip = 2.46;
            GiaNhap = 400;
            TongGiaNhap += GiaNhap;
        }
        if (x == 3) {
            Loai = "Gamma";
            Hang = "White";
            SoCore = 4;
            XungNhip = 2.6;
            GiaNhap = 600;
            TongGiaNhap += GiaNhap;
        }
        cin >> Id;
    }
    void Xuat() {
        cout << "CPU: " << Id << " " << Loai << " " << Hang << " " << SoCore << " " << XungNhip << " " << GiaNhap;
        cout << endl;
    }
};

class ManHinh: public LinhKien {
private:
    string DoPhanGiai;
    float KichThuoc;
    int ChongLoa;
public:
    ManHinh() {
        DoPhanGiai = '\0';
        KichThuoc = 4.7;
        ChongLoa = -1;
    }
    void Nhap() {
        int x;
        cin >> Id;
        cin >> Hang;
        cin >> x;
        if (x == 1) {
            DoPhanGiai = "HD";
            GiaNhap = 200;
            TongGiaNhap += GiaNhap;
        }
        if (x == 2) {
            DoPhanGiai = "FullHD";
            cin >> ChongLoa;
            if (ChongLoa = 1)
                GiaNhap = 500;
            else
                GiaNhap = 300;
            TongGiaNhap += GiaNhap;
        }
    }
    void Xuat() {
        cout << "Man hinh: " << Id << " " << Hang << " " << DoPhanGiai << " " << GiaNhap;
        if (ChongLoa == 1)
            cout << " Chong loa";
        cout << endl;
    }
};
class Vo:public LinhKien {
private:
    string Loai;
    string MauSac;
public:
    Vo() {
        Loai = MauSac = '\0';
    }
    void Nhap() {
        int x;
        cin >> x;
        if (x == 1) {
            Loai = "Nhom";
            Hang = "Black";
            GiaNhap = 400;
            TongGiaNhap += GiaNhap;
        }
        if (x == 2) {
            Loai = "Nhua";
            Hang = "White";
            GiaNhap = 200;
            TongGiaNhap += GiaNhap;
        }
        cin >> Id;
        cin >> x;
        if (x == 1)
            MauSac = "Do";
        if (x == 2)
            MauSac = "Den";
        if (x == 3)
            MauSac = "Xanh";
    }
    void Xuat() {
        cout << "Vo smartphone: " << Id << " " << Loai << " " << Hang << " " << MauSac << " " << GiaNhap;
        cout << endl;
    }
};
class Smartphone {
private:
    LinhKien** lk;
    string ID;
    string DongSmartphone;
    float GiaBan;
public:
    Smartphone() {
        lk = NULL;
        ID = DongSmartphone = '\0';
        GiaBan = 0;
    }
    void Nhap() {
        int x;
        cin >> x;
        if (x == 1) {
            DongSmartphone = "Venus";
        }
        if (x == 2) {
            DongSmartphone = "Mars";
        }
        if (x == 3) {
            DongSmartphone = "Jupiter";
        }
        cin >> ID;
        lk = new LinhKien * [3];
        lk[0] = new CPU();
        lk[1] = new ManHinh();
        lk[2] = new Vo();
        for (int i = 0; i < 3; i++) {
            lk[i]->Nhap();
        }
        if (x == 1) {
            GiaBan = TongGiaNhap * 1.3;
        }
        if (x == 2) {
            GiaBan = TongGiaNhap * 1.5;
        }
        if (x == 3) {
            GiaBan = TongGiaNhap * 1.8;
        }
    }
    void Xuat() {
        cout << "Smartphone: " << ID << " " << DongSmartphone << " " << GiaBan;
        cout << endl;
        for (int i = 0; i < 3; i++) {
            lk[i]->Xuat();
        }
    }
};
class CompanySmartphone {
private:
    int SoLuong;
    Smartphone* a;
public:
    CompanySmartphone() {
        SoLuong = 0;
        a = NULL;
    }
    void Nhap() {
        cin >> SoLuong;
        a = new Smartphone[SoLuong];
        for (int i = 0; i < SoLuong; i++) {
            a[i].Nhap();
        }
    }
    void Xuat() {
        for (int i = 0; i < SoLuong; i++) {
            a[i].Xuat();
        }
    }
};

int main() {
    CompanySmartphone C;
    C.Nhap();
    C.Xuat();
    cout << TongGiaNhap;
    return 0;
}
