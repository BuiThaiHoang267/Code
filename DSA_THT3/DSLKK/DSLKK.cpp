#include<iostream>
using namespace std;

struct node {
	int data;
	node* pNext;
	node* pPre;
};
typedef struct node NODE;
struct list {
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void Init(LIST& l) {
	l.pHead = l.pTail = NULL;
}
bool IsEmpty(LIST l) {
	if (l.pHead == NULL)
		return true;
	return false;
}
NODE* GetNode(int x) {
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	p->pPre = NULL;
	return p;
}
void AddTail(LIST& l, NODE* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		p->pPre = l.pTail;
		l.pTail = p;
	}
}
void Nhap(LIST& l) {
	int n;
	cout << "Nhap so luong node: ";
	cin >> n;
	int x;
	Init(l);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
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
void Xuat(LIST l) {
	NODE* p = l.pHead;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->pNext;
	}
}

void Cau1(LIST& l);
int main() {
	LIST l;
	Cau1(l);
	return 0;
}
void Cau1(LIST & l) {
	int x;
	Init(l);
	while(true) {
		cin >> x;
		if (x == 0)
			return;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
}