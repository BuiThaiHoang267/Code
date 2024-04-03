#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Clock {
private:
    int second;
    int minute;
    int hour;
public:
    void Nhap() {
        cin >> hour;
        cin >> minute;
        cin >> second;
        second = abs(second)%60;
        minute = abs(minute)%60;
        hour = abs(hour)%24;
    }
    void operator ++ (int);
    void operator -- (int);
    Clock operator + (int);
    Clock operator - (int);
    void Xuat() {
        cout << hour << " "<< minute << " " << second;
    }
};

int main() {
    Clock C;
    C.Nhap();
    int n;
    cin >> n;
    string pheptinh;
    for (int i = 1; i <= n; i++) {
        cin >> pheptinh;
        if (pheptinh == "++")
            C++;
        else if (pheptinh == "--")
            C--;
        else if (pheptinh == "-") {
            int x;
            cin >> x;
            C=C - x;
        }
        else if (pheptinh == "+") {
            int x;
            cin >> x;
            C=C + x;
        }
    }
    C.Xuat();
    return 0;
}
void Clock::operator ++ (int) {
    second++;
    if (second > 59) {
        minute++;
        if (minute > 59) {
            hour++;
            if (hour > 23)
                hour = 0;
            minute = 0;
        }
        second = 0;
    }
}
void Clock::operator -- (int) {
    second--;
    if (second < 0) {
        minute--;
        if (minute < 0) {
            hour--;
            if (hour < 0)
                hour = 23;
            minute = 59;
        }
        second = 59;
    }
}
Clock Clock::operator + (int s)
{
    int lc = hour * 3600 + minute * 60 + second + s;
    hour = lc / 3600;
    hour = hour % 24;
    lc = lc % 3600;
    minute = lc / 60;
    second = lc % 60;
    return *this;
}
Clock Clock::operator - (int s)
{
    int lc = hour * 3600 + minute * 60 + second - s;
    hour = lc / 3600;
    hour = hour % 24;
    lc = lc % 3600;
    minute = lc / 60;
    second = lc % 60;
    return *this;
}