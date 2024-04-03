#include<iostream>
using namespace std;

struct node {
	int info;
	struct node* pNext;
};
typedef struct node NODE;
struct list {
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void Init(LIST& l);
int IsEmpty(LIST l);
NODE* GetNode(int x);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void Nhap(LIST& l);
void Xuat(LIST l);
int DemNode(LIST l);
void InsertAfterQ(LIST& l, NODE* p, NODE* q);
void RemoveList(LIST& l);
void InterchangeSort(LIST l);

int main() {
	LIST l;
	Nhap(l);
	InterchangeSort(l);
	Xuat(l);
	return 0;
}
void Init(LIST& l) {
	l.pHead = l.pTail = NULL;
}
int IsEmpty(LIST l) {
	if (l.pHead == NULL)
		return 1;
	return 0;
}
NODE* GetNode(int x) {
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddHead(LIST& l, NODE* p) {
	if (p == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(LIST& l, NODE* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
int DemNode(LIST l) {
	int dem = 0;
	NODE* p = l.pHead;
	while (p != NULL) {
		dem++;
		p = p->pNext;
	}
	return dem;
}
void Nhap(LIST& l) {
	int x;
	Init(l);
	while (true) {
		cin >> x;
		if (x == 0)
			return;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
}
void Xuat(LIST l) {
	NODE* p = l.pHead;
	while (p != NULL) {
		cout << p->info << ' ';
		p = p->pNext;
	}
}
void InsertAfterQ(LIST& l, NODE* p, NODE* q) {
	if (q != NULL) {
		if (l.pTail == q)
			AddTail(l, p);
		else {
			p->pNext = q->pNext;
			q->pNext = p;
		}
	}
	else
		AddHead(l, p);
}
void RemoveList(LIST& l) {
	NODE* p;
	while (l.pHead != NULL) {
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
void InterchangeSort(LIST l) {
	for (NODE* p = l.pHead; p->pNext != NULL; p = p->pNext)
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
			if (p->info > q->info)
				swap(q->info, p->info);
}