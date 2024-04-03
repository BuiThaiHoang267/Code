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
	int sizemc = 1;
	int vt = 0;
	for (int i = 0; i < n; i++) {
		int dem = 1; int lc = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[j - 1])
				break;
			dem++;
		}
		if (dem > sizemc)
		{
			sizemc = dem;
			vt = lc;
		}
	}
	for (int i = vt; i <= vt + sizemc - 1; i++)
		cout << a[i] << " ";
	return 0;
}