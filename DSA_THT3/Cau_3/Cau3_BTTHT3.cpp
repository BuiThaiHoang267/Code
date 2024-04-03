#include<iostream>
using namespace std;

struct DonThuc {
	float heso;
	int somu;
};
struct node {
	DonThuc info;
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
NODE* GetNode(DonThuc x);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void Nhap(LIST& l);
void Xuat(LIST l);
int DemNode(LIST l);
void InterchangeSort(LIST l);
void Cong(LIST& a, LIST b, LIST c);

int main() {
	LIST l;
	LIST B;
	LIST C;
	Nhap(B);
	Nhap(C);
	InterchangeSort(B);
	InterchangeSort(C);
	Cong(l, B, C);
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
NODE* GetNode(DonThuc x) {
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
	DonThuc x;
	Init(l);
	for (int i = 0; i < n; i++) {
		cout << "Nhap he so: ";
		cin >> x.heso;
		cout << "Nhap so mu: ";
		cin >> x.somu;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
}
void Xuat(LIST l) {
	NODE* p = l.pHead;
	while (p != NULL) {
		cout << p->info.heso << "x^" << p->info.somu << " ";
		p = p->pNext;
	}
}
void InterchangeSort(LIST l) {
	for (NODE* p = l.pHead; p->pNext != NULL; p = p->pNext)
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
			if (q->info.somu < p->info.somu)
				swap(q->info, p->info);
}
void Cong(LIST& a, LIST b, LIST c) {
	Init(a);
	DonThuc x;
	NODE* p = b.pHead;
	NODE* q = c.pHead;
	while (p != NULL && q != NULL) {
		NODE* t;
		if (p->info.somu == q->info.somu) {
			x.heso = p->info.heso + q->info.heso;
			x.somu = p->info.somu;
			t = GetNode(x);
			if (t != NULL)
				AddTail(a, t);
			p = p->pNext;
			q = q->pNext;
		}
		else if (p->info.somu < q->info.somu) {
			x.heso = p->info.heso;
			x.somu = p->info.somu;
			NODE* t = GetNode(x);
			if (t != NULL)
				AddTail(a, t);
			p = p->pNext;
		}
		else if (p->info.somu > q->info.somu) {
			x.heso = q->info.heso;
			x.somu = q->info.somu;
			NODE* t = GetNode(x);
			if (t != NULL)
				AddTail(a, t);
			q = q->pNext;
		}
	}
	while (p != NULL) {
		x.heso = p->info.heso;
		x.somu = p->info.somu;
		NODE* t = GetNode(x);
		if (t != NULL)
			AddTail(a, t);
		p = p->pNext;
	}
	while (q != NULL) {
		x.heso = q->info.heso;
		x.somu = q->info.somu;
		NODE* t = GetNode(x);
		if (t != NULL)
			AddTail(a, t);
		q = q->pNext;
	}
}