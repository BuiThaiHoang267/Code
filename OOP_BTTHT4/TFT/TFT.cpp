#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

static int CountShaco = 0;
static int CountZed = 0;

class Tuong {
protected:
    string Name;
    string ClanName;
    string Skill;
    int Attack;
    int Sao;
public:
    Tuong() {
        Name = '\0';
        ClanName = '\0';
        Skill = '\0';
        Attack = 0;
        Sao = 1;
    }
    void Nhap() {
        cin >> Attack;
    }
    string getName() {
        return Name;
    }
    int getSao() {
        return Sao;
    }
    void setSao(int k) {
        Sao = k;
    }
    int getAttack() {
        return Attack;
    }
    void setAttack(int k) {
        Attack = k;
    }
    virtual int Damage(int m) = 0;
};
class Shaco :public Tuong {
public:
    Shaco() {
        Name = "Shaco";
        ClanName = "Mat tham";
        Skill = "Dam len: Sat thuong hay ra x2 so voi binh thuong.";
        Attack = 0;
    }
    int Damage(int m) {
        return Attack * m * 2;
    }
};
class Zed :public Tuong {
public:
    Zed() {
        Name = "Zed";
        ClanName = "Mat tham";
        Skill = "Khing thuong ke yeu: sau moi 2 luot, luot thu 3 gay sat thuong x3";
        Attack = 0;
    }
    int Damage(int m) {
        int CountSkil = 0;
        CountSkil = m / 3;
        return m * Attack + 2 * Attack * CountSkil;
    }
};
class TFT {
private:
    Tuong** T;
    int SoLuong;
public:
    int m;
    list<int> vtXuat;
    TFT() {
        T = NULL;
        SoLuong = 0;
    }
    void Nhap() {
        cin >> SoLuong;
        cin >> m;
        int x;
        T = new Tuong * [SoLuong];
        for (int i = 0; i < SoLuong; i++) {
            cin >> x;
            if (x == 1) {
                T[i] = new Shaco();
                T[i]->Nhap();
                CountShaco++;
            }
            if (x == 2) {
                T[i] = new Zed();
                T[i]->Nhap();
                CountZed++;
            }
        }
    }
    bool KiemTraHeToc() {
        if (CountZed > 0 && CountShaco > 0)
            return true;
        return false;
    }
    void KichHe() {
        if (KiemTraHeToc() == true) {
            for (int i = 0; i < SoLuong; i++) {
                T[i]->setAttack(T[i]->getAttack() + 10);
            }
        }
    }
    void NangSao() {
        int j = 0;
        int k = 0;
        for (int i = 0; i < CountShaco / 9; i++) {
            int dem = 0;
            while (j < SoLuong) {
                if (dem <= 8) {
                    if (T[j]->getName() == "Shaco") {
                        dem++;
                        if (dem == 1) {
                            vtXuat.push_back(j);
                            T[vtXuat.back()]->setAttack(T[vtXuat.back()]->getAttack() * 6);
                        }
                        if (dem >= 2) {
                            T[vtXuat.back()]->setAttack(T[vtXuat.back()]->getAttack() + T[j]->getAttack() * 6);
                        }
                    }
                }
                else break;
                j++;
            }
        }
        for (int i = 0; i < CountZed / 9; i++) {
            int dem = 0;
            while (k < SoLuong) {
                if (dem <= 8) {
                    if (T[k]->getName() == "Zed") {
                        dem++;
                        if (dem == 1) {
                            vtXuat.push_back(k);
                            T[vtXuat.back()]->setAttack(T[vtXuat.back()]->getAttack() * 6);
                        }
                        if (dem >= 2) {
                            T[vtXuat.back()]->setAttack(T[vtXuat.back()]->getAttack() + T[k]->getAttack() * 6);
                        }
                    }
                }
                else break;
                k++;
            }
        }
        for (int i = 0; i < CountShaco % 9 / 3; i++) {
            int dem = 0;
            while (j < SoLuong) {
                if (dem <= 2) {
                    if (T[j]->getName() == "Shaco") {
                        dem++;
                        if (dem == 1) {
                            vtXuat.push_back(j);
                            T[vtXuat.back()]->setAttack(T[vtXuat.back()]->getAttack() * 2);
                        }
                        if (dem >= 2) {
                            T[vtXuat.back()]->setAttack(T[vtXuat.back()]->getAttack() + T[j]->getAttack() * 2);
                        }
                    }
                }
                else break;
                j++;
            }
        }
        for (int i = 0; i < CountZed % 9 / 3; i++) {
            int dem = 0;
            while (k < SoLuong) {
                if (dem <= 2) {
                    if (T[k]->getName() == "Zed") {
                        dem++;
                        if (dem == 1) {
                            vtXuat.push_back(k);
                            cout << k;
                            T[vtXuat.back()]->setAttack(T[vtXuat.back()]->getAttack() * 2);
                        }
                        if (dem >= 2) {
                            T[vtXuat.back()]->setAttack(T[vtXuat.back()]->getAttack() + T[k]->getAttack() * 2);
                        }
                    }
                }
                else break;
                k++;
            }
        }
        while (j < SoLuong) {
            if (T[j]->getName() == "Shaco")
                vtXuat.push_back(j);
            j++;
        }
        while (k < SoLuong) {
            if (T[k]->getName() == "Zed")
                vtXuat.push_back(k);
            k++;
        }
    }
    void Xuat() {
        vtXuat.sort();
        KichHe();
        for (auto it = vtXuat.begin(); it != vtXuat.end(); ++it) {
            cout << T[*it]->getName() << " - " << T[*it]->Damage(m) << endl;
        }
    }
};

int main() {
    TFT DTCL;
    DTCL.Nhap();
    DTCL.NangSao();
    DTCL.Xuat();
    return 0;
}
