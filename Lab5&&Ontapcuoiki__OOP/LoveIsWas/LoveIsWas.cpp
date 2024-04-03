#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int TongSoBan = 0;
static float TongThoiGianChoBanTraiKhac = 0;
static float TongThoiGianChoBanTrai = 0;
static float TongThoiGianChoBanThan = 0;
static float TimeMax = 0;

class Friend {
public:
    string name;
    int age;
    Friend() {
        name = '\0';
        age = 0;
    }
    virtual void Nhap() {
        cin >> name;
        cin >> age;
    }
    virtual float ThoiGian() = 0;
    virtual void XuatThanNhat() = 0;
    
};
class BestFriend : public Friend{
public:
    string sdt;
    BestFriend() {
        sdt = '\0';
    }
    void Nhap() {
        Friend::Nhap();
        cin >> sdt;
    }
    float ThoiGian() {
        TongThoiGianChoBanThan += 5;
        if (TimeMax < 5)
            TimeMax = 5;
        return 5;
    }
    void XuatThanNhat() {
        cout << "Ten: " << name << ", tuoi: " <<age<< ", so dien thoai: " << sdt << endl;
    }
};
class BoyFriend : public Friend {
public:
    long long income;
    BoyFriend() {
        income = '\0';
    }
    void Nhap() {
        Friend::Nhap();
        cin >> income;
    }
    float ThoiGian() {
        TongThoiGianChoBanTrai += 5 * income / 10000000.0;
        if (5 * income / 10000000.0 > TimeMax)
            TimeMax = 5 * income / 10000000.0;
        return 5*income/10000000.0;
    }
    void XuatThanNhat() {
        cout << "Ten: " << name << ", tuoi: " << age << ", thu nhap: " << income << "d" << endl;
    }
};
class OtherBoy : public Friend {
public:
    float attractiveness;
    OtherBoy() {
        attractiveness = 0;
    }
    void Nhap() {
        Friend::Nhap();
        cin >> attractiveness;
    }
    float ThoiGian() {
        TongThoiGianChoBanTraiKhac += attractiveness * 20 / TongSoBan;
        if (attractiveness * 20 / TongSoBan > TimeMax)
            TimeMax = attractiveness * 20 / TongSoBan;
        return attractiveness*20/TongSoBan;
    }
    void XuatThanNhat() {
        cout << "Ten: " << name << ", tuoi: "<<age << ", do thu hut: ";
        if (attractiveness < 0.4)
            cout << "thap" << endl;
        else if (attractiveness >= 0.7)
            cout << "cao" << endl;
        else
            cout << "trung binh" << endl;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Friend*> F;
    // Nhap 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Friend* temp;
        switch (x)
        {
        case 1:
            temp = new BestFriend;
            break;
        case 2:
            temp = new BoyFriend;
            break;
        case 3:
            temp = new OtherBoy;
            break;
        default:
            temp = NULL;
            break;
        }
        if (temp != NULL) {
            temp->Nhap();
            F.push_back(temp);
            TongSoBan++;
        }
    }
    for (int i = 0; i < n; i++) {
        F[i]->ThoiGian();
    }
    // Xuat 
    cout << "Thong ke:" << endl;
    if (TongThoiGianChoBanThan > 0)
        cout << "-Thoi gian cho ban than: " << TongThoiGianChoBanThan << " h" << endl;
    if (TongThoiGianChoBanTrai > 0)
        cout << "-Thoi gian cho ban trai: " << TongThoiGianChoBanTrai << " h" << endl;
    if (TongThoiGianChoBanTraiKhac > 0)
        cout << "-Thoi gian cho ban trai khac: " << TongThoiGianChoBanTraiKhac << " h" << endl;
    cout << "Nguoi ban quan trong nhat:" << endl;
    // Xu ly
    for (int i = 0; i < n; i++) {
        if (F[i]->ThoiGian() == TimeMax)
            F[i]->XuatThanNhat();
    }
    return 0;
}
