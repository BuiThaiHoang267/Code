#include<iostream>
#include<string>
using namespace std;

class SinhVien {
private:
	int Id=0;
	float DiemTrungBinh=0.0;
	string Name;
	int NamSinh = 0;
	int GioiTinh=1;

public:
	friend istream& operator >> (istream& in, SinhVien& a);
	friend ostream& operator << (ostream& out, SinhVien a);
	float getDiemTrungBinh() {
		return this->DiemTrungBinh;
	}
	int getId() {
		return this->Id;
	}
};



istream& operator >> (istream& in, SinhVien& a) {
	cout << "Id co dang 2252xxxx va moi sinh vien co 1 Id duy nhat" << endl;
	cout << "Nhap Id: ";
	in >> a.Id;
	if (a.Id > 22529999 || a.Id < 22520001) {
		do {
			cout << "Nhap Id sai vui long nhap lai ID: ";
			in >> a.Id;
		} while (a.Id > 22529999 || a.Id < 22520001);
	}

	cout << "Nhap ho va ten: ";
	in.ignore();
	getline(cin, a.Name);

	cout << "Nhap nam sinh: ";
	in >> a.NamSinh;
	if (a.NamSinh < 1) {
		do {
			cout << "Nam khong thoa man vui long nhap lai: ";
			in >> a.NamSinh;
		} while (a.NamSinh < 1);
	}

	cout << "1 la nam, 0 la nu!";
	cout << "\nNhap gioi tinh: ";
	in >> a.GioiTinh;
	
	cout << "Nhap diem trung binh: ";
	in >> a.DiemTrungBinh;
	if (a.DiemTrungBinh < 0.0 || a.DiemTrungBinh>10.0) {
		do {
			cout << "Nhap sai vui long nhap lai diem trung binh: ";
			in >> a.DiemTrungBinh;
		} while (a.DiemTrungBinh < 0.0 || a.DiemTrungBinh>10.0);
	}
	return in;
}
ostream& operator << (ostream& out, SinhVien a) {
	out << "Name: " << a.Name << endl;
	out << "ID: " << a.Id << endl;
	out << "Nam sinh: " << a.NamSinh << endl;
	out << "Gioi tinh: ";
	if (a.GioiTinh == 0)
		cout << "Nu" << endl;
	else
		cout << "Nam" << endl;
	out << "Diem trung binh: " << a.DiemTrungBinh << endl;
	return out;
}

void Nhap(SinhVien[], int);
void SortDiemTrungBinh(SinhVien [],int );
void SortID(SinhVien[], int);
void Xuat(SinhVien[], int);

int main() {
	int n;
	cout << "So luong sinh vien: ";
	cin >> n;
	SinhVien* a = new SinhVien[n];
	Nhap(a, n);
	cout << "\nSap xep theo ID!" << endl;
	SortID(a, n);
	Xuat(a, n);
	cout << "Sap xep theo diem trung binh!" << endl;
	Xuat(a, n);
	delete[] a;
	return 0;
}

void Nhap(SinhVien a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap SV" << i + 1 << endl;
		cin >> a[i];
	}
}
void Xuat(SinhVien a[], int n) {
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	cout << endl;
}

void SortDiemTrungBinh(SinhVien a[],int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j].getDiemTrungBinh() > a[i].getDiemTrungBinh())
				swap(a[j], a[i]);
}
void SortID(SinhVien a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j].getId() < a[i].getId())
				swap(a[j], a[i]);
}

