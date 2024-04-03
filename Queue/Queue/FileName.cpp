#include<iostream>
using namespace std;

struct queue {
	int n;
	int a[100];
};
typedef struct queue QUEUE;
void Init(QUEUE& que) {
	que.n = 0;
}
int IsEmpty(QUEUE que) {
	if (que.n == 0)
		return 1;
	return 0;
}
int IsFull(QUEUE que) {
	if (que.n == 100)
		return 1;
	return 0;
}
void EnQueue(QUEUE& que, int x) {
	que.a[que.n] = x;
	que.n++;
}
int DeQueue(QUEUE& que) {
	int x = que.a[0];
	for (int i = 0; i < que.n - 1; i++)
		que.a[i] = que.a[i + 1];
	que.n--;
	return x;
}
int BotQueue(QUEUE que) {
	return que.a[0];
}

int main() {
	QUEUE Q;
	Init(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	cout << DeQueue(Q);
	cout << "\n" << BotQueue(Q);
	return 0;
}