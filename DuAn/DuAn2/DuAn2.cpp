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

void Init(LIST&);
NODE* GetNode(int x);
void AddTail(LIST&, NODE*);
int Nhap(LIST&);
void InterchangeSort(LIST&);
void Xuat(LIST);

int main() {
	LIST l;
	Nhap(l);
	InterchangeSort(l);
	Xuat(l);
	return 0;
}

// khoi tao danh sach lien ket
void Init(LIST& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

// Tao node
NODE* GetNode(int x) {
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}

// them node vao phan tu
void AddTail(LIST& l, NODE* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;//LK voi node moi them vao
		l.pTail = p;// gan node ms them vao thanh node cuoi
	}
}


// Nhap du lieu vao NODE
int Nhap(LIST& l) {
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	Init(l);
	srand(time(NULL));
	int rd;
	for (int i = 1; i <= n; i++) {
		rd = rand() % (100 + 1);
		NODE* p = GetNode(rd);
		if (p != NULL)
			AddTail(l, p);
	}
	return 1;
}

//sap xep dslk don cac so nguyen
void InterchangeSort(LIST& l) {
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
			if (q->info < p->info)
				swap(p->info, q->info);
}

void Xuat(LIST l) {
	NODE* p = l.pHead;
	while (p != NULL) {
		cout << p->info << endl;
		p = p->pNext;
	}
}