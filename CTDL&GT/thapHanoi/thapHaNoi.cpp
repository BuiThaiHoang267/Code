#include<iostream>
using namespace std;

void thapHaNoi(int n, char a, char b, char c);

void chuyen(int, char, char);
int main() {
	int n; cin >> n;
	char a = 'A', b = 'B', c = 'C';
	thapHaNoi(n, a, b, c);

}
void thapHaNoi(int n, char a, char b, char c) {
	if (n == 1)
		chuyen(n, a, c);
	else {
		int i = 1;
		while (i <= n) {
			chuyen(i, a, b);
			i++;
		}
		i--;
		while (i >= 1) {
			chuyen(i, b, c);
			i--;
		}
	}
}
void chuyen(int n, char a, char b) {
	cout << "chuyen " << n << " tu " << a << " sang " << b<<endl;
}