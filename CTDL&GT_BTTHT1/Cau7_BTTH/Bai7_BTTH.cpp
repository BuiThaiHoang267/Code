#include<iostream>
using namespace std;

void output(int a[], int n);
void Sort(int a[], int n);

int main(){
	int a[9] = { 12, 8, 2, 14, 3, 5, 10, 15, 36 };
	Sort(a, 9);
	output(a, 9);
	return 0;
}
void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void Sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 == 0)
			for (int j = i + 1; j < n; j++)
				if (a[j] % 2 == 0)
					if (a[i] > a[j])
						swap(a[i], a[j]);
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 != 0)
			for (int j = i + 1; j < n; j++)
				if (a[j] % 2 != 0)
					if (a[i] < a[j])
						swap(a[i], a[j]);
}