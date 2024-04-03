#include<iostream>
#include<vector>
using namespace std;

class CDonThuc {
private:
	float heso;
	int somu;
public:
	void Nhap();
	void Xuat();
	float getHeSo() { return heso; }
	int getSoMu() { return somu; }
	CDonThuc Cong(CDonThuc d) {
		CDonThuc temp;
		temp.heso = heso + d.heso;
		temp.somu = somu;
		return temp;
	}
	CDonThuc Tru(CDonThuc d) {
		CDonThuc temp;
		temp.heso = heso - d.heso;
		temp.somu = somu;
		return temp;
	}
};
class CDaThuc {
private:
	int n;
	vector<CDonThuc> A;
public:
	CDaThuc() {
		n = 0;
	}
	void Nhap();
	void Xuat();
	void SapXep();
	CDaThuc Cong(CDaThuc);
	CDaThuc Tru(CDaThuc);
	~CDaThuc() {}
};

int main() {
	CDaThuc H = CDaThuc();
	CDaThuc K = CDaThuc();
	H.Nhap();
	K.Nhap();
	H.SapXep();
	K.SapXep();
	H.Tru(K).Xuat();
	return 1;
}
void CDonThuc::Nhap() {
	cout << "Nhap he so: ";
	cin >> heso;
	cout << "Nhap so mu: ";
	cin >> somu;
}
void CDonThuc::Xuat() {
	if (heso > 0)
		cout << "+ " << heso << "x^" << somu << " ";
	else if (heso < 0)
		cout << "- " << abs(heso) << "x^" << somu << " ";
}
void CDaThuc::Nhap() {
	cout << "Nhap so luong don thuc trong da thuc n = ";
	cin >> n;
	A.resize(n);
	for (int i = 0; i < n; i++) {
		A[i].Nhap();
	}
}
void CDaThuc::Xuat() {
	if (A[0].getHeSo() != 0)
		cout << A[0].getHeSo() << "x^" << A[0].getSoMu() << " ";
	for (int i = 1; i < n; i++)
		A[i].Xuat();
}
void CDaThuc::SapXep(){
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (A[i].getSoMu() < A[j].getSoMu())
				swap(A[i], A[j]);
}
CDaThuc CDaThuc::Cong(CDaThuc a) {
	CDaThuc B;
	B.A.resize(n + a.n);
	int i = 0, j = 0, z = 0;
	while (i < n && j < a.n) {
		if (A[i].getSoMu() > a.A[i].getSoMu())
		{
			B.A[z++] = A[i++];
		}
		else if(A[i].getSoMu() < a.A[j].getSoMu()){
			B.A[z++] = a.A[j++];
		}
		else {
			B.A[z++] = A[i].Cong(a.A[j]);
			i++;
			j++;
		}
	}
	while (i < n)
	{
		B.A[z++] = A[i++];
	}
	while (j < a.n)
	{
		B.A[z++] = a.A[j++];
	}
	B.n = z--;
	B.A.resize(B.n);
	return B;
}
CDaThuc CDaThuc::Tru(CDaThuc a) {
	CDaThuc B;
	B.A.resize(n+a.n);
	int i = 0, j = 0, z = 0;
	while (i < n && j < a.n) {
		if (A[i].getSoMu() > a.A[i].getSoMu())
		{
			B.A[z++] = A[i++];
		}
		else if (A[i].getSoMu() < a.A[j].getSoMu()) {
			B.A[z++] = a.A[j].Tru(a.A[j]).Tru(a.A[j]);
			j++;
		}
		else {
			B.A[z++] = A[i].Tru(a.A[j]);
			i++;
			j++;
		}
	}
	while (i < n)
	{
		B.A[z++] = A[i++];
	}
	while (j < a.n)
	{
		B.A[z++] = a.A[j].Tru(a.A[j]).Tru(a.A[j]);
		j++;
	}
	B.n = z--;
	B.A.resize(B.n);
	return B;
}
