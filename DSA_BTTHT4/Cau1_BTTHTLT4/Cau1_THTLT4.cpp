#include<iostream>
using namespace std;

struct stack {
	int n;
	char a[100];
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
int main() {
	STACK s;
	Init(s);
	int m;
	cout << "Nhap so ky tu: ";
	cin >> m;
	cout << "Nhap chuoi: ";
	string chuoi;
	cin >> chuoi;
	for (int i = 0; i < m; i++) {
		if (chuoi[i] == '(' || chuoi[i] == '{' || chuoi[i] == '[')
			Push(s, chuoi[i]);
		if (chuoi[i] == ')' || chuoi[i] == '}' || chuoi[i] == ']') {
			if (IsEmpty(s) == 1) {
				cout << "flase";
				return 0;
			}
			if (chuoi[i] == ')' && Top(s) != '(')
			{
				cout << "flase";
				return 0;
			}
			if (chuoi[i] == '}' && Top(s) != '{')
			{
				cout << "flase";
				return 0;
			}
			if (chuoi[i] == ']' && Top(s) != '[')
			{
				cout << "flase";
				return 0;
			}
			Pop(s);
		}
	}
	if (IsEmpty(s) == 1)
		cout << "true";
	else 
		cout << "false";
	return 0;
}