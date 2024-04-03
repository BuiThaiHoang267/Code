#include<iostream>
using namespace std;

struct segment {
	int left;
	int right;
};
typedef struct segment SEGMENT;


struct stack {
	int n;
	SEGMENT a[1000];
};
typedef struct stack STACK;
void Init(STACK& st) {
	st.n = 0;
}
int IsEmpty(STACK st) {
	if (st.n == 0)
		return 1;
	return 0;
}
int IsFull(STACK st) {
	if (st.n == 1000)
		return 1;
	return 0;
}
void Push(STACK& st, SEGMENT x) {
	st.a[st.n] = x;
	st.n++;
}
SEGMENT Pop(STACK& st) {
	SEGMENT x = st.a[st.n-1];
	st.n--;
	return x;
}
int partition(int arr[], int l, int r) {
	int temp = arr[r];
	int j = l - 1;
	for (int i = l; i < r; i++)
	{
		if (arr[i] < temp) {
			j++;
			swap(arr[i], arr[j]);
		}
	}
	j++;
	swap(arr[r], arr[j]);
	return j;
}
void QuickSort(int arr[], int n) {
	if (n <= 1)
		return;
	STACK s;
	Init(s);
	SEGMENT dd = { 0,n - 1 };
	Push(s, dd);
	while (IsEmpty(s)==0) {
		dd = Pop(s);
		int pi = partition(arr, dd.left, dd.right);
		if (dd.left < pi - 1)
			Push(s, { dd.left,pi - 1 });
		if (dd.right > pi + 1)
			Push(s, { pi + 1,dd.right });
	}
}
int main() {
	STACK s;
	Init(s);
	int arr[10] = { 9,3,7,2,8,6,5,1,0,4 };
	QuickSort(arr ,10);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
}