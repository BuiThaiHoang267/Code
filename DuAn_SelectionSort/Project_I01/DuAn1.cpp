#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;


int Nhap(int a[], int& n, string filename);
void SelectionSort(int a[], int n);
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
		if(Nhap(a,n,filenameinp)==1){
			SelectionSort(a, n);
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
	fo <<setw(5)<< n << endl;
	for (int i = 0; i < n; i++) {
		fo << setw(5) << a[i];
	}
	return 1;
}
void SelectionSort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		int lc = i;
		for (int j = i; j < n; j++)
			if (a[j] < a[lc])
				lc = j;
		swap(a[i], a[lc]);
	}
}