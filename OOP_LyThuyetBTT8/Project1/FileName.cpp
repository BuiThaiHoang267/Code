#include<iostream>
using namespace std;
bool search() {
	cout << "hiu";
	return true;
}

int main() {
	char a = 'a';
	for (int i = 0; i < 3; i++) {
		cout << (char)(++a);
	}

	return 0;
}