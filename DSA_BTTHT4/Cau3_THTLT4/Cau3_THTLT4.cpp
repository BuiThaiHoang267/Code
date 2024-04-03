#include<iostream>
using namespace std;

struct stack {
	int n;
	int a[100];
};
typedef struct stack STACK;
void Init(STACK& st) {
	st.n = 0;
}
int IsEmpty(STACK st) {
	if (st.n == 0)
		return 1;
	return 0;
}
int IsFull(STACK st) {
	if (st.n == 100)
		return 1;
	return 0;
}
void Push(STACK& st, int x) {
	st.a[st.n] = x;
	st.n++;
}
int Pop(STACK& st) {
	int x = st.a[st.n - 1];
	st.n--;
	return x;
}
int Top(STACK& st) {
	return st.a[st.n - 1];
}
void DaoNguoc(int& n) {
	STACK st;
	Init(st);
	while (n != 0) {
		int dv = n % 10;
		Push(st, dv);
		n = n / 10;
	}
	n = 0;
	int i = 0;
	while (IsEmpty(st) == 0) {
		n = n + Pop(st)*pow(10,i);
		i++;
	}
}

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	DaoNguoc(n);
	cout << n;
	return 0;
}