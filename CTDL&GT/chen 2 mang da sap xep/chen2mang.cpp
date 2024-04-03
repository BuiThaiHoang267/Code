#include<iostream>
using namespace std;

int main() {
	int a[] = { 1,3,5 };
	int b[] = { 2,4,6 };
	int* p = new int[20];
	int i = 0, j = 0, k = 0;
	while (i < 3 && j < 3) {
		p[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
	}
	while (i < 3) {
		p[k++] = a[i++];
	}
	while (j < 3) {
		p[k++] = b[j++];
	}
	for (int i = 0; i < 6; i++) {
		cout << *(p + i) << " ";
	}
	delete[]p;
	return 0;
}