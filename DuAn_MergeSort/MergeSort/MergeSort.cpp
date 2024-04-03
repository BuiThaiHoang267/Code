#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;


int Nhap(int a[], int& n, string filename);
void Merge(int[], int, int, int);
void MergeSort(int[], int, int);
int Xuat(int a[], int n, string filename);

int main() {
	int n;
	int* a = new int[100000];
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intdata";
		if (i <= 9)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename + ".inp";
		if (Nhap(a, n, filenameinp) == 1) {
			MergeSort(a, 0, n-1);
			string filenameout = filename + ".out";
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
	for (int i = 0; i < n; i++)
		fi >> a[i];
	return 1;
}
int Xuat(int a[], int n, string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++) {
		fo << setw(5) << a[i];
	}
	return 1;
}
void Merge(int a[], int l, int r, int m) {
	int* temp = new int[r - l + 2];
	int k = 0;
	int i = l;
	int j = m + 1;
	while (!(i > m && j > r)) 
	{
		if ((a[i] < a[j] && i <= m && j <= r) || j > r)
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	for (int i = 0; i < k; i++)
		a[l + i] = temp[i];
	delete[] temp;
}
void MergeSort(int a[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		MergeSort(a, l, m);
		MergeSort(a,m + 1, r);
		Merge(a, l, r, m);
	}
}