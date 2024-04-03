#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Vukhi {
public:
    float ATK;
    int LuotSuDung;
    Vukhi() {
        ATK = 0;
        LuotSuDung = 0;
    }
    virtual void Nhap() {
        cin >> ATK;
        cin >> LuotSuDung;
    }
    virtual float Damage() = 0;
    virtual bool HetLuot() = 0;
};

class Dao : public Vukhi {
public:
    float ChieuDai;
    Dao() {
        ChieuDai = 0;
    }
    void Nhap() {
        Vukhi::Nhap();
        cin >> ChieuDai;
    }
    float Damage() {
        LuotSuDung--;
        return ATK * ChieuDai;
    }
    bool HetLuot() {
        if (LuotSuDung <= 0)
            return true;
        return false;
    }
};

class Cung : public Vukhi {
public:
    int slMuiTen;
    Cung() {
        slMuiTen = 0;
    }
    void Nhap() {
        Vukhi::Nhap();
        cin >> slMuiTen;
    }
    float Damage() {
        LuotSuDung = LuotSuDung - 2;
        return ATK * slMuiTen / 2;
    }
    bool HetLuot() {
        if (LuotSuDung <= 0)
            return true;
        return false;
    }
};

class TayKhong : public Vukhi {
public:
    void Nhap() {}
    float Damage() {
        return ATK;
    }
    bool HetLuot() {
        return false;
    }
};

class APhu {
public:
    float HP;
    int n;
    vector<Vukhi*> vk;
    APhu() {
        n = 0;
        HP = 0;
    }
    void Nhap() {
        cin >> HP;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            Vukhi* temp;
            switch (x) {
            case 1:
                temp = new Dao;
                break;
            case 2:
                temp = new Cung;
                break;
            default:
                temp = NULL;
                break;
            }
            if (temp != NULL) {
                temp->Nhap();
                vk.push_back(temp);
            }
        }
    }
    bool Die() {
        if (HP <= 0)
            return true;
        return false;
    }
};

class ThuDu {
public:
    float ATK;
    float HP;
    ThuDu() {
        ATK = HP = 0;
    }
    virtual void Nhap() {
        cin >> HP;
        cin >> ATK;
    }
    virtual float Damage() = 0;
    virtual bool Die() = 0;
};

class BoTot : public ThuDu {
public:
    int SoLuotChiuDanh;
    BoTot() {
        SoLuotChiuDanh = 1;
    }
    void Nhap() {
        ThuDu::Nhap();
        cin >> SoLuotChiuDanh;
    }
    float Damage() {
        return ATK;
    }
    bool Die() {
        SoLuotChiuDanh--;
        if (HP <= 0 || SoLuotChiuDanh <= 0)
            return true;
        return false;
    }
};

class Ho : public ThuDu {
public:
    void Nhap() {
        ThuDu::Nhap();
    }
    float Damage() {
        return ATK * 15 / 10;
    }
    bool Die() {
        if (HP <= 0)
            return true;
        return false;
    }
};

class TranChien {
protected:
    APhu A;
    int m;
    vector<ThuDu*> ds;
public:
    TranChien() {
        m = 0;
    }
    void Nhap() {
        A.Nhap();
        cin >> m;
        for (int i = 0; i < m; i++) {
            ThuDu* temp;
            int x;
            cin >> x;
            switch (x) {
            case 1:
                temp = new BoTot();
                break;
            case 2:
                temp = new Ho();
                break;
            default:
                temp = NULL;
                break;
            }
            if (temp != NULL) {
                temp->Nhap();
                ds.push_back(temp);
            }
        }
    }
    void Xuat() {
        if (!A.Die()) {
            cout << "A Phu chien thang, hp con lai: " << A.HP << ", so vu khi con lai: " << A.n;
        }
        else {
            cout << "A Phu that bai, so thu du con lai: " << m;
        }
    }
    int KiemTra() {
        for (int i = 0; i < A.n; i++) {
            if (A.vk[0]->HetLuot()) {
                A.vk.erase(A.vk.begin());
                A.n--;
            }
        }
        if (m == 0) {
            Xuat();
            return 1;
        }
        return 0;
    }
    void Chien() {
        float HPGoc = A.HP;
        while (!A.Die() && !ds.empty()) {
            if (!A.vk.empty()) {
                ds[0]->HP -= A.vk[0]->Damage();
                if (A.vk[0]->HetLuot()) {
                    A.vk.erase(A.vk.begin());
                    A.n--;
                }
            }
            else {
                ds[0]->HP -= HPGoc * 1 / 10;
                A.HP -= HPGoc * 1 / 10;
                if (A.Die()) {
                    Xuat();
                    return;
                }
            }
            if (!ds[0]->Die()) {
                A.HP -= ds[0]->Damage();
            }
            else {
                ds.erase(ds.begin());
                m--;
                if (ds.empty()) {
                    Xuat();
                    return;
                }
            }
            if (A.Die()) {
                Xuat();
                return;
            }
        }
        Xuat();
    }

};

int main() {
    TranChien T;
    T.Nhap();
    if (T.KiemTra() == 1) {
        return 0;
    }
    T.Chien();
    return 0;
}