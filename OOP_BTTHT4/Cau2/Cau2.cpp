#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static float TongDienTich = 0;
static float TongTheTichNuocTrenDat = 0;

class Chai {
public:
    virtual void Nhap() = 0;
    virtual float DienTich() = 0;
    virtual float TheTich() = 0;
    float TheTichNuocTrenMatDat() {
        TongTheTichNuocTrenDat += TheTich() * 0.1;
        return TheTich() * 0.1;
    }
};
class TruTron:public Chai {
private:
    float h;
    float R;
public:
    TruTron() {
        R = h = 0;
    }
    void Nhap() {
        cin >> h;
        cin >> R;
    }
    float DienTich() {
        TongDienTich+= h * 2 * R * 3.14;
        return h * 2 * R * 3.14;
    }
    float TheTich() {
        return h * R * R * 3.14;
    }
    ~TruTron() {}
};
class HopChuNhat:public Chai {
private:
    float h;
    float a;
    float b;
public:
    HopChuNhat() {
        a = b = h = 0;
    }
    void Nhap() {
        cin >> h;
        cin >> a;
        cin >> b;
    }
    float DienTich() {
        TongDienTich += 2 * (a * b + a * h + b * h);
        return 2 * (a * b + a * h + b * h);
    }
    float TheTich() {
        return a * b * h;
    }
    ~HopChuNhat() {}
};
class LapPhuong: public Chai {
private:
    float a;
public:
    LapPhuong() {
        a = 0;
    }
    void Nhap() {
        cin >> a;
    }
    float DienTich() {
        TongDienTich+= 6 * a * a;
        return 6 * a * a;
    }
    float TheTich() {
        return a * a * a;
    }
    ~LapPhuong() {}
};

int main() {
    int n;
    cin >> n;
    Chai** chai = new Chai * [n];
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            chai[i] = new TruTron();
        }
        if (x == 2) {
            chai[i] = new HopChuNhat();
        }
        if (x == 3) {
            chai[i] = new LapPhuong();
        }
        chai[i]->Nhap();
        chai[i]->DienTich();
        chai[i]->TheTichNuocTrenMatDat();
    }
    cout << "Dien tich chai vo: " << TongDienTich << endl;
    cout << "Luong nuoc tren mat dat: " << TongTheTichNuocTrenDat << endl;
    return 0;
}
