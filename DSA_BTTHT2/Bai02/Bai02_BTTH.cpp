#include<iostream>
using namespace std;

int dem = 0;
int prodem = 0;

bool LinearSearch(int[], int, int);
bool ProLinearSearch(int[], int, int);

int main() {
	int a[11] = { 1,2,3,4,5,6,7,8,9,10 };
	a[10] = 11;
	int x;
	cout << "Nhap gia tri muon tim kiem: ";
	cin >> x;
	LinearSearch(a, 10, x);
	ProLinearSearch(a, 10, x);
	cout << "So luong phep so sanh chua cai tien: " << dem;
	cout << "\nSo luong phep so sanh da cai tien: " << prodem;
	return 0;
}
bool LinearSearch(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		dem++;
		dem++;
		if (x == a[i])
			return true;
	}
	dem++;
	return false;
}
bool ProLinearSearch(int a[], int n, int x) {
	a[n] = x;
	int i = 0;
	while (a[i] != x) {
		prodem++;
		i++;
	}
	prodem++;
	prodem++;
	if (i == n) {
		return false;
	}
	return true;
}