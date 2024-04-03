#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

struct phanso {
	int tu;
	int mau;
};
typedef struct phanso PHANSO;

int Nhap(PHANSO a[], int& n, string filename);
int Xuat(PHANSO a[], int n, string filename);
void BubbleSort(PHANSO a[], int n);
int SoSanh(PHANSO a);

int main() {
	int n;
	PHANSO* a = new PHANSO[1000000];
	for (int i = 1; i <= 13; i++)
	{
		string filename = "phansodata";
		if (i < 10)
			filename += '0';//intdata0 vs 1<=i<=9
		filename += to_string(i);//intdata01....intdata0i...intdata12
		string filenameinp = filename;
		filenameinp += ".inp";// vd intdata01.inp
		if (Nhap(a, n, filenameinp) == 1)
		{
			BubbleSort(a, n);
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
	return 0;
}
int Nhap(PHANSO a[], int& n, string filename) {
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	fi >> n;
	for (int i = 0; i < n; i++) {
		fi >> a[i].tu >> a[i].mau;
	}
	return 1;
}
int Xuat(PHANSO a[], int n, string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << setw(5) << a[i].tu << setw(5) << a[i].mau << endl;
	return 1;
}
int SoSanh(PHANSO a, PHANSO b) {
	PHANSO c;
	c.tu = a.tu * b.mau - a.mau * b.tu;
	c.mau = a.mau * b.mau;
	float i = (float)c.tu / c.mau;
	if (i < 0)
		return 1;
	return 0;
}
void BubbleSort(PHANSO a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n-1; j >=i+1 ; j--)
			if (SoSanh(a[j], a[j-1]) == 1)
				swap(a[j-1], a[j]);
}