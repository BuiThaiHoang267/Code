#include<iostream>
#include<string>
using namespace std;

struct stack {
	int n;
	int a[100];
};
typedef struct stack STACK;

void Init(STACK& s) {
	s.n = 0;
}
int IsEmpty(STACK s) {
	if (s.n == 0)
		return 1;
	return 0;
}
int IsFull(STACK s) {
	if (s.n == 100)
		return 1;
	return 0;
}
void push(STACK& s, int x) {
	s.n++;
	s.a[s.n - 1] = x;
}
int pop(STACK& s) {
	char x = s.a[s.n - 1];
	s.n--;
	return x;
}
int top(STACK s) {
	return s.a[s.n - 1];
}

string ThapPhanSangNhiPhan(int so) {
	STACK s;
	// khoi tao stack
	Init(s); 
	string kq = "";
	while (so != 0)
	{
		int tam = so % 2;
		push(s,tam);
		so = so / 2;
	}
	while (!IsEmpty(s)) {
		int num = pop(s);
		kq = kq + to_string(num);
	}
	return kq;
}
string ThapPhanSangHeThapLucPhan(int n) {
	STACK s;
	Init(s);
	string kq="";
	while (n != 0) {
		int dv = n % 16;
		push(s, dv);
		n = n / 16;
	}
	while (!IsEmpty(s)) {
		int num = pop(s);
		if (num <= 9) {
			kq = kq + to_string(num);
		}
		switch (num)
		{
		case(15):
			kq = kq + 'F';
			break;
		case(14):
			kq = kq + 'E';
			break;
		case(13):
			kq = kq + 'D';
			break;
		case(12):
			kq = kq + 'C';
			break;
		case(11):
			kq = kq + 'B';
			break;
		case(10):
			kq = kq + 'A';
			break;
		}
	}
	return kq;
}

int main() {
	int n;
	cout << "Nhap So thap phan: ";
	cin >> n;
	cout << "\nHe nhi phan: ";
	cout<<ThapPhanSangNhiPhan(n);
	cout << "\nHe Thap luc phan: ";
	cout << ThapPhanSangHeThapLucPhan(n);

	return 0;
}