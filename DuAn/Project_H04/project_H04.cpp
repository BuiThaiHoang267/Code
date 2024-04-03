#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

int Nhap(int** a, int& m, int& n, string filename);
int Xuat(int** a, int m, int n, string filename);
void BubbleSort(int** a, int m, int n);


int main() {
	int m, n;
	int** a = new int* [10000];
	for (int i = 0; i < 10000; i++) {
		a[i] = new int[10000];
	}
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intmatrandata";
		if (i < 10)
			filename += '0';//intdata0 vs 1<=i<=9
		filename += to_string(i);//intdata01....intdata0i...intdata12
		string filenameinp = filename;
		filenameinp += ".inp";// vd intdata01.inp
		if (Nhap(a, m, n, filenameinp) == 1)
		{
			BubbleSort(a, m, n);
			string filenameout = filename;
			filenameout += ".out";// vd intdata01.out
			Xuat(a, m, n, filenameout);
			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;

		}
		else
			cout << "\n Khong mo duoc file " << filename << "\n";
	}
	delete[] a;
	cout << "\n\n\n";
	return 0;
}

int Nhap(int** a, int& m, int& n, string filename) {
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			fi >> a[i][j];
		}
	return 1;
}
int Xuat(int** a, int m, int n, string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << m << n << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			fo << setw(5) << a[i][j];
		fo << endl;
	}
	return 1;
}
void BubbleSort(int** a, int m, int n) {
	for (int i = 0; i <= m * n - 2; i++)
		for (int j = m * n - 1; j >= i+1; j--)
			if (a[(j-1) / n][(j-1) % n] > a[j / n][j % n])
				swap(a[(j-1) / n][(j-1) % n], a[j / n][j % n]);
}