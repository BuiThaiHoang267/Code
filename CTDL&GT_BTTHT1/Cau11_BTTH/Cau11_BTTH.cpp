#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

struct Sinhvien {
	int id=0;
	string ho;
	string ten;
	int gioitinh=-1;
	string ngaysinh;
	float dtb=0;
};

void Nhap(Sinhvien a[], int n);
void Nhap(Sinhvien& a);
int Docfile(Sinhvien a[], string filename);
int Xuat(Sinhvien a[], int n,string filename);
void InterchangeSortId(Sinhvien a[], int n);
void UninterchangeSortDtb(Sinhvien a[], int n);
void Xuat(Sinhvien a[], int n);

int main() {
	int n;
	cout << "Nhap n:";
	cin >> n;
	string filename = "Sinhvien.dat";
	Sinhvien* a = new Sinhvien[100];
	Nhap(a, n);
	Xuat(a, n, filename);// xuat du lieu vao file
	InterchangeSortId(a, n);
	Xuat(a, n);
	Docfile(a, filename);// doc lai file de thuc hien so sanh dtb
	UninterchangeSortDtb(a, n);
	Xuat(a, n);
	delete[] a;
	return 0;
}
void Xuat(Sinhvien a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Id: ";
		cout << a[i].id << endl;
		cout << "Ho: ";
		cout << a[i].ho << endl;
		cout << "Ten: ";
		cout << a[i].ten << endl;
		cout << "Gioi tinh: ";
		cout << a[i].gioitinh << endl;
		cout << "Ngay sinh: ";
		cout << a[i].ngaysinh << endl;
		cout << "Diem trung binh: ";
		cout << a[i].dtb << endl;
	}
}
void Nhap(Sinhvien a[], int n) {
	for (int i = 0; i < n; i++)
		Nhap(a[i]);
}

void Nhap(Sinhvien& a) {
	cout << "Nhap id: ";
	cin >> a.id;
	cout << "Nhap ho: ";
	cin >> a.ho;
	cout << "Nhap ten: ";
	cin >> a.ten;
	cout << "Nhap gioi tinh: ";
	cin >> a.gioitinh;
	cout << "Nhap ngay sinh: ";
	cin.ignore();
	getline(cin, a.ngaysinh);
	cout << "Nhap diem trung binh: ";
	cin >> a.dtb;
}
int Xuat(Sinhvien a[], int n, string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++) {
		fo << a[i].id << "  ";
		fo << a[i].ho << "  ";
		fo << a[i].ten << "  ";
		fo << a[i].gioitinh << "  ";
		fo << a[i].ngaysinh << "  ";
		fo << a[i].dtb << "  ";
		fo << endl;
	}
	return 1;
}

int Docfile(Sinhvien a[], string filename) {
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	int m;
	fi >> m;
	for (int i = 0; i < m; i++)
		fi >> a[i].id >> a[i].ho >> a[i].ten >> a[i].gioitinh >> a[i].ngaysinh >> a[i].dtb;
	return 1;
}
void InterchangeSortId(Sinhvien a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].id > a[j].id)
				swap(a[i], a[j]);
}
void UninterchangeSortDtb(Sinhvien a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].dtb < a[j].dtb)
				swap(a[i], a[j]);
}