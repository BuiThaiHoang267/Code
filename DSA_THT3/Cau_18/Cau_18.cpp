#include<iostream>
#include<string>
using namespace std;

struct SinhVien {
	int ID;
	string name;
	string lop;
	float DiemTK;
	string HanhKiem;
};

void Nhap(SinhVien& A);
void Xuat(SinhVien A);

int main() {
	SinhVien A;
	Nhap(A);
	Xuat(A);
	return 0;
}
void Nhap(SinhVien& A) {
	cout << "Nhap ID: ";
	cin >> A.ID;
	cout << "Nhap ten: ";
	cin.ignore();
	getline(cin, A.name);
	cout << "Nhap lop: ";
	getline(cin, A.lop);
	cout << "Nhap diem tong ket: ";
	cin >> A.DiemTK;
	cout << "Nhap hanh kiem: ";
	cin.ignore();
	cin >> A.HanhKiem;
}
void Xuat(SinhVien A) {
	cout << "\nID: " << A.ID;
	cout << "\nName: " << A.name;
	cout << "\nLop: " << A.lop;
	cout << "\nDiem tong ketP: " << A.DiemTK;
	cout << "\nHanh kiem: " << A.HanhKiem;
}