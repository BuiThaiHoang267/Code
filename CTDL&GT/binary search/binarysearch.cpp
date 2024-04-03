//#include<iostream>
//using namespace std;
//
//int binarySearch(int a[], int l, int h, int x) {
//	if (l > h)
//		return false;
//	int m = (l + h) / 2;
//	if (a[m] == x) return true;
//	else if (a[m] > x)
//		return binarySearch(a, l, m - 1, x);
//	else
//		return binarySearch(a, m + 1, h, x);
//}
//
//int main() {
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int x; cin >> x;
//	if (binarySearch(a, 0, 9, x))
//		cout << "succeed!";
//	else cout << "false";
//	return 0;
//}

#include<iostream>
using namespace std;

bool binarySearch(int a[], int l, int r, int x) {
	if (l > r) return false;
	int m = (l + r) / 2;
	if (a[m] == x)
		return true;
	else if (a[m] > x)
		return binarySearch(a, l, m - 1, x);
	else
		return binarySearch(a, m + 1, r, x);
}

int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
		int x; cin >> x;
		if (binarySearch(a, 0, 9, x))
			cout << "succeed!";
		else cout << "false";
	return 0;
}