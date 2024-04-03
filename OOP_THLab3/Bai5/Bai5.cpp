#include <cmath>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

class HocSinh {
private:
    string name;
    string NgaySinh;
    float a[6];
public:
    void Nhap();
    bool KiemTraNgaySinh();
    float DiemTB();
    float DiemTBmonToan();
    float DiemTBmonVan();
    float DiemTBmonTA();
    bool KtDoTuoi();
    bool KtDkThiHSG() {
        if (KtDoTuoi() == false)
            return false;
        for (int i = 0; i < 6; i++)
            if (a[i] < 5)
                return false;
        if (DiemTBmonToan() < 7 || DiemTBmonTA() < 7 || DiemTBmonVan() < 7)
            return false;
        if (DiemTB() <= 8)
            return false;
        return true;
    }
    void Xuat();
};
bool KtNamNhuan(int);

int main() {
    int n,k;
    cin >> n >> k;
    HocSinh* A = new HocSinh[n];
    for (int i = 0; i < n; i++) {
        cin.ignore();
        A[i].Nhap();
    }
    vector<HocSinh> B;
    for (int i = 0; i < n; i++) {
        if (A[i].KtDkThiHSG())
            B.push_back(A[i]);
    }
    if (B.size() <= k)
        for (int i = 0; i < B.size(); i++)
            B[i].Xuat();
    if (B.size() > k) {
        for (int j = 0; j < k; j++) {
            int lc = 0;
            for (int i = 1; i < B.size(); i++) {
                if (B[lc].DiemTB() < B[i].DiemTB())
                    lc = i;
            }
            B[lc].Xuat();
            B.erase(B.begin()+lc);
        }

    }
    return 0;
}

void HocSinh::Nhap() {
    getline(cin, name);
    do {
        cin >> NgaySinh;
    } while (KiemTraNgaySinh() != true);
    int flag;
    do {
        flag = 0;
        for (int i = 0; i < 6; i++) {
            cin >> a[i];
            if (a[i] < 0 || a[i]>10)
                flag++;
        }
    } while (flag != 0);
}
void HocSinh::Xuat() {
    cout << "Ho ten: " << name << " - Diem trung binh: " <<setprecision(3)<< DiemTB() << endl;
}
bool HocSinh::KiemTraNgaySinh() {
    int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int day = 0;
    int month = 0;
    int year = 0;
    int dem = 0;
    for (int i = 0; i < NgaySinh.size(); i++) {
        if (dem == 0 && NgaySinh[i] != '/')
            day = day*10 + (NgaySinh[i]-'0');
        if (dem == 1 && NgaySinh[i] != '/')
            month = month * 10 + (NgaySinh[i] - '0');
        if (dem == 2)
            year = year * 10 + (NgaySinh[i] - '0');
        if (NgaySinh[i] == '/')
            dem++;
    }
    if (KtNamNhuan(year))
        a[2] = 29;
    if (day > a[month] || day == 0)
        return false;
    return true;
}
bool KtNamNhuan(int a) {
    if (a % 4 == 0 && a % 100 != 0)
        return true;
    if (a % 400 == 0)
        return true;
    return false;
}
float HocSinh::DiemTB() {
    float s = (DiemTBmonToan() + DiemTBmonVan() + DiemTBmonTA())/3.0;
    return s;
}
float HocSinh::DiemTBmonToan() {
    return a[0] * 0.3 + a[1] * 0.7;
}
float HocSinh::DiemTBmonVan() {
    return a[2] * 0.3 + a[3] * 0.7;
}
float HocSinh::DiemTBmonTA() {
    return a[4] * 0.3 + a[5] * 0.7;
}
bool HocSinh::KtDoTuoi() {
    int day = 0;
    int month = 0;
    int year = 0;
    int dem = 0;
    for (int i = 0; i < NgaySinh.size(); i++) {
        if (dem == 0 && NgaySinh[i] != '/')
            day = day * 10 + (NgaySinh[i] - '0');
        if (dem == 1 && NgaySinh[i] != '/')
            month = month * 10 + (NgaySinh[i] - '0');
        if (dem == 2)
            year = year * 10 + (NgaySinh[i] - '0');
        if (NgaySinh[i] == '/')
            dem++;
    }
    if (year < 2006)
        return true;
    if (year == 2006 && month == 1 && day == 1)
        return true;
    return false;
}