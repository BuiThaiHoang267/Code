#include<iostream>
using namespace std;

bool TimKiem(int a) {
	int i = 1;
	int dem = 0;
	while (i <= sqrt(a)) {
		if (a % i == 0)
			dem++;
		i++;
	}
	if (dem == 1)
		return true;
	return false;
}
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	srand(10);
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 500;
	}
	InterchangeSort(a, n);
	int lc = 1;
	for (int i = 0; i < n; i++)
	{
		if (TimKiem(a[i]) == true) {
			if (a[i] != lc)
			{
				cout << a[i] << " ";
				lc = a[i];
			}
		}
	}
	delete[] a;
	return 0;
}