#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Day {
    int ngay;
    int thang;
    int nam;
};

bool Nhap(Day& a) {
    cin >> a.ngay;
    if (a.ngay <= 0 || a.ngay >= 32)
        return false;
    
    cin >> a.thang;
    if (a.thang >= 13|| a.thang <= 0)
        return false;
    if (a.thang == 2 && a.ngay >= 29) {
        if (!((a.nam % 4 == 0 && a.nam % 100 != 0) || a.nam % 400 == 0))
            return false;
    }
    if (a.thang == 4 || a.thang == 6 || a.thang == 9 || a.thang == 11) {
        if (a.ngay >= 31)
            return false;
    }
    
    cin >> a.nam;
    if ( a.nam <= 0)
        return false;
    return true;
}


int NgayTiepTheo(Day& a) {
    if (a.ngay == 30) {
        if (a.thang == 4 || a.thang == 6 || a.thang == 9 || a.thang == 11) {
            a.ngay = 1;
            a.thang++;
            return 0;
        }
    }
    else if (a.ngay == 31) {
        if (a.thang == 1 || a.thang == 3 || a.thang == 5 || a.thang == 7 || a.thang == 8 || a.thang == 10) {
            a.ngay = 1;
            a.thang++;
            return 0;
        }
        if (a.thang == 12) {
            a.ngay = 1;
            a.thang = 1;
            a.nam++;
            return 0;
        }
    }
    else if ((a.nam % 4 == 0 && a.nam % 100 != 0) || a.nam % 400 == 0) {
        if (a.ngay == 29 && a.thang == 2)
        {
            a.ngay = 1;
            a.thang = 3;
            return 0;
        }
    }
    else if (a.ngay == 28 && a.thang == 2) {
        a.ngay = 1;
        a.thang = 3;
        return 0;
    }
    else
        a.ngay++;
    return 0;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Day a;
    if (!Nhap(a)) {
        cout << "ERROR";
        return 0;
    }
    NgayTiepTheo(a);
    cout << a.ngay << "/" << a.thang << "/" << a.nam;
    return 0;
}
