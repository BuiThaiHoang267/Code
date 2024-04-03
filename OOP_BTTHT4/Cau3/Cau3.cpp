#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int Money = 0;
static int Power = 0;
static int Wisdom = 0;
static bool pass = true;

class Gate {
public:
    virtual void Nhap() = 0;
    virtual void Moneyy() = 0;
    virtual void Powerr() = 0;
    virtual void Wisdomm() = 0;
};
class BusinessGate :public Gate {
private:
    int Bill;
    int Quanity;
public:
    void Nhap() {
        cin >> Bill;
        cin >> Quanity;
    }
    void Moneyy() {
        Money -= Bill * Quanity;
        if (Money < 0)
            pass = false;
    }
    void Powerr() {
        return;
    }
    void Wisdomm() {
        return;
    }
};
class AcademicGate :public Gate {
private:
    int IQ;
public:
    void Nhap() {
        cin >> IQ;
    }
    void Moneyy() {
        return;
    }
    void Powerr() {
        return;
    }
    void Wisdomm() {
        if (Power <= IQ)
            pass = false;
    }
};
class PowerGate :public Gate {
private:
    int StrengthIndex;
public:
    void Nhap() {
        cin >> StrengthIndex;
    }
    void Moneyy() {
        return;
    }
    void Powerr() {
        Power -= StrengthIndex;
        if (Power < 0)
            pass = false;
    }
    void Wisdomm() {
        return;
    }
};

int main() {
    int n;
    cin >> n;
    int m, p, w;
    Gate** gate = new Gate * [n];
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            gate[i] = new BusinessGate();
        }
        if (x == 2) {
            gate[i] = new AcademicGate();
        }
        if (x == 3) {
            gate[i] = new PowerGate();
        }
        gate[i]->Nhap();
    }
    cin >> m >> w >> p;
    Money = m;
    Wisdom = w;
    Power = p;
    for (int i = 0; i < n; i++) {
        gate[i]->Moneyy();
        gate[i]->Powerr();
        gate[i]->Wisdomm();
    }
    if (pass == false)
        cout << -1;
    else
        cout << Money << " " << Wisdom << " " << Power;
    return 0;
}