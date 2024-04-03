#include<iostream>
#include<string>
using namespace std;

class Candidate {
private:
	int ID;
	string Ten;
	string BirthDay;
	float DiemToan, DiemVan, DiemAnh;
public:
	friend istream& operator >> (istream& in, Candidate& a);
	friend ostream& operator << (ostream& out, Candidate a);
	friend bool operator > (Candidate a,int b);
};

istream& operator >> (istream& in, Candidate& a)
{
	cout << "ID: "; in >> a.ID;
	cout << "Ho ten: "; in.ignore();
	getline(in, a.Ten);
	cout << "Ngay sinh: "; in.ignore();
	in >> a.BirthDay;
	cout << "Diem toan"; in >> a.DiemToan;
	cout << "Diem van"; in >> a.DiemVan;
	cout << "Diem anh"; in >> a.DiemAnh;
	return in;
}
ostream& operator << (ostream& out, Candidate a)
{
	out << "\nID: "; out << a.ID;
	out << "\nHo ten: "; out << a.Ten;
	out << "\nNgay sinh: "; out << a.BirthDay;
	out << "\nDiem toan: "; out << a.DiemToan;
	out << "\nDiem van: "; out << a.DiemVan;
	out << "\nDiem anh: "; out << a.DiemAnh;
	return out;
}
bool operator > (Candidate a,int b)
{
	return a.DiemToan + a.DiemVan + a.DiemAnh > 15;
}
int main()
{
	Candidate* A = new Candidate[100];
	int n;
	cout << "So luong thi sinh: "; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
	{
		if (A[i] > 15)
			cout << A[i];
	}
	return 0;
}