#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

int Nhap(int a[], int& n, string filename);
int Xuat(int a[], int n, string filename);
void BubbleSort(int a[], int n);
void BubbleSort1(int a[], int n);

int main() {
	int n;
	int* a = new int[100000];
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intdata";
		if (i < 10)
			filename += '0';//intdata0 vs 1<=i<=9
		filename += to_string(i);//intdata01....intdata0i...intdata12
		string filenameinp = filename;
		filenameinp += ".inp";// vd intdata01.inp
		if (Nhap(a, n, filenameinp) == 1)
		{
			BubbleSort(a, n);
			//BubbleSort1(a, n);
			string filenameout = filename;
			filenameout += ".out";// vd intdata01.out
			Xuat(a, n, filenameout);
			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;
		}
		else
			cout << "\n Khong mo duoc file " << filename << "\n";
	}
	cout << "\n\n\n";
	delete[] a;
	return 0;
}

int Nhap(int a[], int& n, string filename) {
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++) {
		fi >> a[i];
	}
	return 1;
}
int Xuat(int a[], int n, string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << setw(5) << a[i];
	return 1;
}
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j >= i + 1; j--)
			if (a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
}
void BubbleSort1(int a[], int n) {
	for (int i = n-1; i>=1; i--)
		for (int j =0; j <= i - 1; j++)
			if (a[j + 1] < a[j])
				swap(a[j + 1], a[j]);
}