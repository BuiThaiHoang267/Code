#include<iostream>
using namespace std;

void Nhap(int**, int, int);
bool LinearSearch(int**, int,int, int);
bool LinearSearchlc(int**, int,int, int);

int main() {
	for (int j = 0; j < 100; j++) {
		int m, n, x;
		cout << "Nhap m va n: ";
		cin >> m >> n;
		cout << "Nhap phan tu can tim kiem: ";
		cin >> x;
		int** a = new int* [m + 1];
		for (int i = 0; i < m+1; i++)
			a[i] = new int[n];
		Nhap(a, m, n);

		clock_t time_LS;
		time_LS = clock();
		LinearSearch(a, m, n, x);
		time_LS = clock() - time_LS;
		cout << "LinearSearch xu ly mat " << fixed << (double)time_LS / CLOCKS_PER_SEC << " giay";

		time_LS = clock();
		LinearSearchlc(a, m, n, x);
		time_LS = clock() - time_LS;
		cout << "    LinearSearchlc xu ly mat " << fixed << (double)time_LS / CLOCKS_PER_SEC << " giay";
		cout << endl;
		for (int i = 0; i < m + 1; i++)
			delete[] a[i];
		delete[] a;
	}
	return 0;
}
void Nhap(int** a, int m, int n) {
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (100000 + 1);
}
bool LinearSearch(int** a,int m, int n, int x) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == x)
				return true;
	return false;
}
bool LinearSearchlc(int** a,int m, int n, int x) {
	a[m][0] = x;
	int i = 0;
	while (a[i / n][i % n] != x)
		i++;
	if (i == m * n)
		return false;
	return true;
}
