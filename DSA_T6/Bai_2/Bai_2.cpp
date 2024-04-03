#include<iostream>
using namespace std;

bool BinarySearch(int a[], int l, int r, int x) {
	if (l <= r) {
		int m = (l + r) / 2;
		if (m == x)
			return true;
		if (m < x)
			return BinarySearch(a, m + 1, r, x);
		if (m > x)
			return BinarySearch(a, l, m - 1, x);
	}
	return false;
}


int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand()%(50000+1);
	int x;
	cin >> x;
	if (BinarySearch(a, 0, n - 1, x))
		cout << "true";
	else
		cout << "false";

	return 0;
}