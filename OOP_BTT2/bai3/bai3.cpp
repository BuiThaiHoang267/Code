#include<iostream>
#include<string>
using namespace std;
struct BirthDay
{
	int Ngay;
	int Thang;
	int Nam;
};
struct Candidate
{
	int Ma;
	string strName;
	BirthDay birthday;
	float DiemToan;
	float DiemVan;
	float DiemAnh;
};
struct TestCandidate
{
	Candidate A;
};

void Nhap(TestCandidate[], int);
void Nhap(TestCandidate&);
bool TestSumPoint(TestCandidate);
void Xuat(TestCandidate);
int main()
{
	int n;
	cout << "Nhap so luong thi sinh: ";
	cin >> n;
	TestCandidate Arr[50];
	Nhap(Arr, n);
	for (int i = 0; i < n; i++)
		if (TestSumPoint(Arr[i]) == true)
		{
			Xuat(Arr[i]);
			cout << "\n";
		}
	return 0;
}
void Xuat(TestCandidate a)
{
	cout << "\nMa thi sinh: " << a.A.Ma;
	cout << "\nTen thi sinh: " << a.A.strName;
	cout << "\nNgay sinh: " << a.A.birthday.Ngay << "/" << a.A.birthday.Thang << "/" << a.A.birthday.Nam;
	cout << "\nDiem Toan: " << a.A.DiemToan;
	cout << "\nDiem Van: " << a.A.DiemVan;
	cout << "\nDiem Anh: " << a.A.DiemAnh;
}
bool TestSumPoint(TestCandidate a)
{
	if (a.A.DiemToan + a.A.DiemAnh + a.A.DiemVan > 15)
		return true;
	else
		return false;
}
void Nhap(TestCandidate a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nThi sinh " << i+1;
		Nhap(a[i]);
	}
}
void Nhap(TestCandidate& a)
{
	cout << "\nNhap ma thi sinh: ";
	cin >> a.A.Ma;
	cout << "Nhap ten thi sinh: ";
	cin.ignore();
	getline(cin, a.A.strName);
	cout << "Nhap ngay thang nam sinh";
	cout << "\nNgay ";
	cin >> a.A.birthday.Ngay;
	cout << "Thang ";
	cin >> a.A.birthday.Thang;
	cout << "Nam ";
	cin >> a.A.birthday.Nam;
	cout << "Nhap diem toan: ";
	cin >> a.A.DiemToan;
	cout << "Nhap Diem van: ";
	cin >> a.A.DiemVan;
	cout << "Nhap Diem anh: ";
	cin >> a.A.DiemAnh;
}