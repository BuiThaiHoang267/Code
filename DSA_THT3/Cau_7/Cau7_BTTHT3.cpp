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
void InterchangeSort(LIST l);
void Merge(LIST& l, LIST& A, LIST& B);

int main() {
	LIST l;
	LIST A, B;
	Nhap(A);
	Nhap(B);
	InterchangeSort(A);
	InterchangeSort(B);
	Merge(l, A, B);
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
	int n;
	cout << "Nhap so luong node: ";
	cin >> n;
	int x;
	Init(l);
	for(int i=0;i<n;i++) {
		cin >> x;
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
void InterchangeSort(LIST l) {
	for (NODE* p = l.pHead; p->pNext != NULL; p = p->pNext)
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
			if (p->info > q->info)
				swap(q->info, p->info);
}
void Merge(LIST& l, LIST& A, LIST& B) {
	Init(l);
	NODE* p = A.pHead;
	NODE* q = B.pHead;
	while (p != NULL && q != NULL) {
		NODE* t;
		if (p->info < q->info) {
			t = GetNode(p->info);
			p = p->pNext;
		}
		else {
			t = GetNode(q->info);
			q = q->pNext;
		}
		if (t != NULL)
			AddTail(l, t);
	}
	while (p != NULL) {
		NODE* t = GetNode(p->info);
		if (t != NULL)
			AddTail(l, t);
		p = p->pNext;
	}
	while (q != NULL) {
		NODE* t = GetNode(q->info);
		if (t != NULL)
			AddTail(l, t);
		q = q->pNext;
	}
}