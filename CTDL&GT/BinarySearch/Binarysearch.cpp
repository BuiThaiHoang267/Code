#include<iostream>
using namespace std;

bool BinarySearch(int a[], int l, int r, int x) {
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x)
			return true;
		else if (a[m] > x)
			r = m - 1;
		else
			l = m + 1;
	}
	return false;
}

int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int x;
	cin >> x;
	if (BinarySearch(a, 0, 9,x))
		cout << "Succeed!";
	else
		cout << "false!";
	return 0;
}