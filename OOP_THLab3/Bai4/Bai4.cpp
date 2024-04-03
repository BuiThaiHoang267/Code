#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DaThuc {
private:
    int bac;
    int* heso;
public:
    DaThuc(){
        heso = 0;
        bac = 0;
    }
    DaThuc(int n){
        bac = n;
        heso = new int[bac + 1];
    }
    void Nhap();
    void Xuat();
    DaThuc operator+(DaThuc);
    DaThuc operator-(DaThuc);
    DaThuc operator*(DaThuc);
    ~DaThuc(){}
};

int main() {
    DaThuc A,B;
    A.Nhap();
    B.Nhap();
    string pheptinh;
    cin >> pheptinh;
    if (pheptinh == "+")
        (A + B).Xuat();
    if (pheptinh == "-")
        (A - B).Xuat();
    if (pheptinh == "*")
        (A * B).Xuat();
    return 0;
}
void DaThuc::Nhap() {
    cin >> bac;
    heso = new int[bac + 1];
    for (int i = 0; i <= bac; i++)
        cin >> heso[i];
}
void DaThuc::Xuat() {
    int i = 0;
    while (heso[i] == 0) {
        i++;
    }
    cout << heso[i] << "x^" << i;
    i++;
    while (i <= bac) {
        if (heso[i] > 0)
            cout << "+" << heso[i] << "x^" << i;
        if (heso[i] < 0)
            cout << heso[i] << "x^" << i;
        i++;
    }
}
DaThuc DaThuc::operator+(DaThuc a) {
    DaThuc T = DaThuc(max(bac, a.bac));
    int i = 0, j = 0, k = 0;
    while (i <= bac && j <= a.bac) {
        T.heso[k++] = heso[i++] + a.heso[j++];
    }
    while (i <= bac) {
        T.heso[k++] = heso[i++];
    }
    while (j <= a.bac) {
        T.heso[k++] = a.heso[j++];
    }
    return T;
}
DaThuc DaThuc::operator-(DaThuc a) {
    DaThuc T = DaThuc(max(bac, a.bac));
    int i = 0, j = 0, k = 0;
    while (i <= bac && j <= a.bac) {
        T.heso[k++] = heso[i++] - a.heso[j++];
    }
    while (i <= bac) {
        T.heso[k++] = heso[i++];
    }
    while (j <= a.bac) {
        T.heso[k++] = -a.heso[j++];
    }
    return T;
}
DaThuc DaThuc::operator*(DaThuc a) {
    DaThuc T = DaThuc(bac + a.bac );
    int k = 0;
    int** t = new int* [bac + 1];
    for (int i = 0; i <= bac; i++)
        t[i] = new int[a.bac + 1];
    for (int z = 0; z <= a.bac; z++) {
        int j = z;
        int i = 0;
        while (j >= 0) {
            T.heso[k] += heso[i] * a.heso[j];
            i++;
            j--;
        }
        k++;
    }
    for (int z = 1; z <= a.bac; z++) {
        int j = z;
        int i = bac;
        while (j <= a.bac ) {
            T.heso[k] += heso[i] * a.heso[j];
            i--;
            j++;
        }
        k++;
    }
    for (int i = 0; i <= bac; i++)
        delete[] t[i];
    delete[] t;
    return T;
}