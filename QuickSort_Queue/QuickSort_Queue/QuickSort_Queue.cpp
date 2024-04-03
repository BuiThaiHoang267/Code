#include<iostream>
using namespace std;

struct segment {
	int left;
	int right;
};
typedef struct segment SEGMENT;

struct Queue {
	int n;
	SEGMENT a[10000];
};
typedef struct Queue QUEUE;

void Init(QUEUE&);
int IsEmpty(QUEUE);
int IsFull(QUEUE);
void EnQueue(QUEUE&, SEGMENT);
SEGMENT DeQueue(QUEUE&);
int partition(int arr[], int l, int r);
void QuickSort(int arr[], int n);

int main()
{
	int arr[10] = { 9,3,7,2,8,6,5,1,0,4 };
	QuickSort(arr, 10);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
	return 0;
}
void Init(QUEUE& que)
{
	que.n = 0;
}
int IsEmpty(QUEUE que)
{
	if (que.n == 0)
		return 1;
	return 0;
}
int IsFull(QUEUE que)
{
	if (que.n == 10000)
		return 1;
	return 0;
}
void EnQueue(QUEUE& que, SEGMENT d)
{
	que.a[que.n] = d;
	que.n++;
}
SEGMENT DeQueue(QUEUE& que)
{
	SEGMENT temp = que.a[0];
	for (int i = 0; i < que.n - 1; i++)
		que.a[i] = que.a[i + 1];
	que.n--;
	return temp;
}
int partition(int arr[], int l, int r)
{
	int x = arr[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (arr[j] < x) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	i++;
	swap(arr[i], arr[r]);
	return i;
}
void QuickSort(int arr[], int n) {
	if (n <= 1)
		return;
	QUEUE que;
	Init(que);
	SEGMENT dd = { 0,n - 1 };
	EnQueue(que, dd);
	while (IsEmpty(que) != 1) {
		dd = DeQueue(que);
		int vt = partition(arr, dd.left, dd.right);
		if (dd.left < vt)
			EnQueue(que, { dd.left,vt - 1 });
		if (dd.right > vt) {
			EnQueue(que, { vt + 1,dd.right });
		}
	}
}
