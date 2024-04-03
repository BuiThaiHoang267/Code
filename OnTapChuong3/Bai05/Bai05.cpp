#include<iostream>
using namespace std;

class CSoPhuc {
private:
	float thuc;
	float ao;
public:
	friend istream& operator >> (istream&, CSoPhuc&);
	friend ostream& operator << (ostream&, CSoPhuc&);
	CSoPhuc operator+(CSoPhuc);
	CSoPhuc operator-(CSoPhuc);
	CSoPhuc operator*(CSoPhuc);
};


int main() {
	CSoPhuc A, B, kq;
	cout << "Nhap so phuc A" << endl;
	cin >> A;
	cout << "Nhap so phuc B" << endl;
	cin >> B;
	cout << "\nTong 2 phan so\n";
	kq = A=B;
	cout << kq;
	cout << "\nHieu 2 phan so\n";
	kq=A-B;
	cout << kq;
	cout << "\nTich 2 phan so\n";
	kq=A*B;
	cout << kq;
	return 0;
}

istream& operator >> (istream& in, CSoPhuc& a) {
	cout << "Nhap thuc: ";
	cin >> a.thuc;
	cout << "Nhap ao: ";
	cin >> a.ao;
	return in;
}
ostream& operator << (ostream& out, CSoPhuc& a) {
	out << a.thuc << " ";
	if (a.ao > 0)
		out << "+ " << a.ao << "i" << endl;
	else if (a.ao < 0)
		out << a.ao << "i" << endl;
	return out;
}
CSoPhuc CSoPhuc::operator+(CSoPhuc b)
{
	CSoPhuc temp;
	temp.thuc = thuc + b.thuc;
	temp.ao = ao + b.ao;
	return temp;
}
CSoPhuc CSoPhuc::operator-(CSoPhuc b)
{
	CSoPhuc temp;
	temp.thuc = thuc - b.thuc;
	temp.ao = ao - b.ao;
	return temp;
}
CSoPhuc CSoPhuc::operator*(CSoPhuc b) {
	CSoPhuc temp;
	temp.thuc = thuc * b.thuc - ao * b.ao;
	temp.ao = ao * b.thuc + thuc * b.ao;
	return temp;
}
