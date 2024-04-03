#include<iostream>
using namespace std;


struct Move {
	int SoDia;
	char a;
	char b;
	char c;
	Move() {}
	Move(int SoDiaa, char aa, char bb, char cc) {
		SoDia = SoDiaa;
		a = aa;
		b = bb;
		c = cc;
	}
};

struct stack {
	int n ;
	Move st[1000];
};
typedef struct stack STACK;

void Init(STACK& st) {
	st.n = 0;
}
int IsEmpty(STACK& st) {
	if (st.n == 0)
		return 1;
	return 0;
}
int IsFull(STACK& st) {
	if (st.n == 1000)
		return 1;
	return 0;
}
void push(STACK& st, Move x) {
	st.st[st.n] = x;
	st.n++;
}
Move pop(STACK& st) {
	Move x = st.st[st.n - 1];
	st.n--;
	return x;
}

void ThapHaNoi(int n, char a, char b, char c) {
	STACK s;
	Init(s);
	push(s, Move(n, a, b, c));
	while (IsEmpty(s) == 0) {
		Move current = pop(s);

		int SoDia = current.SoDia;
		char a = current.a;
		char b = current.b;
		char c = current.c;

		if (SoDia == 1) {
			cout << "Chuyen 1 dia tu cot " << a << " sang cot " << c << endl;
		}
		else {
			push(s, Move(SoDia - 1, b, a, c)); // chuyen n-1 dia tu cot b sang c
			push(s, Move(1, a, b, c)); // chuyen dia con lai tu cot a sang cot c
			push(s, Move(SoDia - 1, a, c, b)); // chuyen n-1 dai tu cot a sang b
		}
	}
	
}

int main() {
	int n;
	cout << "Nhap so luong dia dang o cot A";
	cin >> n;
	char a = 'A';
	char b = 'B';
	char c = 'C';
	ThapHaNoi(n, a, b, c);
	return 0;
}