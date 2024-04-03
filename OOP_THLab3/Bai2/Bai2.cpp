#include<iostream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	void Nhap();
	bool KtNamNhuan();
	int KtNamNhuan(int);
	void AddDay(int);
	void SubDay(int);
	int KhoangCach(Date T) {
		int d = 0, t = 0;
		int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int dem = 0;
		dem = 365 * (abs(year - T.year) - 1);
		if (T.KtNamNhuan() == true)
			a[2] = 29;
		for (int i = 1; i < T.month; i++)
			t = t + a[i];
		t = t + T.day;
		a[2] = 28;

		if (KtNamNhuan() == true)
			a[2] = 29;
		for (int i = 1; i < month; i++)
			d = d + a[i];
		d = d + day;
		if (year > T.year)
			dem = dem + d + (365 + KtNamNhuan(T.year) - t);
		else if (year < T.year)
			dem = dem + t + (365 + KtNamNhuan(year) - d);
		else
			dem = abs(d - t);
		int i = min(year, T.year) + 1;
		while (KtNamNhuan(i) == false) {
			i++;
		}
		while (i < max(year, T.year)) {
			if (KtNamNhuan(i) == true)
				dem++;
			i = i + 4;
		}
		return dem;
	}
};

int main() {
	Date D;
	D.Nhap();
	int n, x;
	while (true) {
		cin >> n;
		if (n == 1) {
			cin >> x;
			if (x < 0)
				D.SubDay(abs(x));
			else
				D.AddDay(x);
		}
		else if (n == 2) {
			cin >> x;
			if (x < 0)
				D.AddDay(abs(x));
			else
				D.SubDay(x);
		}
		else if (n == 3) {
			Date T;
			T.Nhap();
			cout << D.KhoangCach(T);
			return 0;
		}
	}
}

void Date::Nhap() {
	cin >> day;
	cin >> month;
	cin >> year;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (KtNamNhuan() == 1)
		a[2] = 29;
	day = abs(day);
	month = abs(month);
	year = abs(year);
	this->month = (this->month) % 12; if (this->month == 0) this->month = 12;
	if (this->day > a[month])
	{
		this->day = 1;
	}
}
int Date::KtNamNhuan(int x) {
	if (x % 400 == 0)
		return 1;
	if (x % 4 == 0 && x % 100 != 0)
		return 1;
	return 0;
}
bool Date::KtNamNhuan() {
	if (year % 400 == 0)
		return true;
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	return false;
}
void Date::AddDay(int x) {
	for (int i = 1; i <= x; i++) {
		int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (KtNamNhuan() == 1)
			a[2] = 29;
		day++;
		if (day > a[month]) {
			month++;
			if (month > 12) {
				year++;
				month = 1;
			}
			day = 1;
		}
	}
}
void Date::SubDay(int x) {
	for (int i = 1; i <= x; i++) {
		int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (KtNamNhuan() == 1)
			a[2] = 29;
		day--;
		if (day < 1) {
			month--;
			if (month < 1) {
				year--;
				month = 12;
			}
			day = a[month];
		}
	}
}