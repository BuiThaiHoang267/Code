#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

int Nhap(int a[], int& n, string filename);
void SelectionSort1(int a[], int n);
void SelectionSort2(int a[], int n);
void SelectionSort3(int a[], int n);
int Xuat(int a[], int n, string filename);


int main() {
	int n;
	int* a = new int[200000];
	for (int i = 1; i <= 13; i++) {
		string filename = "intdata";
		if (i <= 9)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename + ".inp";
		if (Nhap(a, n, filenameinp) == 1) {
			SelectionSort1(a, n);
			//SelectionSort2(a, n);
			//SelectionSort3(a, n);
			string filenameout = filename + ".out";
			Xuat(a, n, filenameout);
			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;
		}
		else
			cout << "\nKhong mo duoc file " << filename << "\n";
	}
	cout << "\n\n\n";
	delete[] a;
	return 1;
}
int Nhap(int a[], int& n, string filename) {
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
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
void SelectionSort1(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int lc = i;
		for (int j = n - 1; j >= i + 1; j--)
			if (a[j] < a[lc])
				lc = j;
		swap(a[i], a[lc]);
	}
}
void SelectionSort2(int a[], int n) {
	for (int i = n - 1; i >= 1; i--) {
		int lc = i;
		for (int j = 0; j <= i - 1; j++)
			if (a[j] > a[lc])
				lc = j;
		swap(a[i], a[lc]);
	}
}
void SelectionSort3(int a[], int n) {
	for (int i = n - 1; i >= 1; i--) {
		int lc = i;
		for (int j = i - 1; j >= 0; j--)
			if (a[j] > a[lc])
				lc = j;
		swap(a[i], a[lc]);
	}
}