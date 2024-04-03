#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) { //day phan tu nho len dau .
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}

void output(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	int arr[] = { 1,2,4,7,8,5,3,7,89,4,6,8,5,3,6,9,8,6,5,4 };
	int lenght = sizeof(arr)/sizeof(int);
	bubbleSort(arr, lenght);
	output(arr, lenght);
	return 0;
}