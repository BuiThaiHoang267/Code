#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int dem = 0;
	for (int i = 0; i < n; i++) {
		int demsopt = 1 ;
		for (int j =i+ 1; j < n; j++) {
			if (a[j] < a[j - 1])
				break;
			demsopt++;
		}
		if (demsopt >= 2) {
			dem = dem+((demsopt) * (demsopt - 1)) / 2;
			i = i+demsopt-1;
		}

	}
	cout << dem;
	return 0;
}