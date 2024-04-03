#include<iostream>
using namespace std;

bool LinearSearch(int[], int, int);
bool LinearSearchlc(int[], int, int);

int main() {
	for (int j = 0; j < 100; j++) {
		int n;
		//cout << "Nhap so phan tu: ";
		n = 989974;
		int* a = new int[n+1];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			a[i] = rand();
		int x;
		x = rand();
		clock_t time_LS;
		time_LS = clock();
		LinearSearch(a, n, x);
		time_LS = clock() - time_LS;
		cout << "LinearSearch xu ly mat " << fixed << (double)time_LS / CLOCKS_PER_SEC << " giay";

		time_LS = clock();
		LinearSearchlc(a, n, x);
		time_LS = clock() - time_LS;
		cout << "    LinearSearchlc xu ly mat " << fixed << (double)time_LS / CLOCKS_PER_SEC << " giay";
		cout << endl;
	}
	return 0;
}

bool LinearSearch(int a[], int n, int x) {
	int lc = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x)
			return true;
	}
	return false;
}
bool LinearSearchlc(int a[], int n, int x) {
	a[n] = x;
	int i = 0;
	while (a[i] != x)
		i++;
	if (i == n)
		return false;
	return true;
}
