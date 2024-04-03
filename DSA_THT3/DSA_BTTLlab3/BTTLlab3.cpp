#include<iostream>
using namespace std;

struct node {
	int data;
	node* pNext;
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
NODE* GetNode(int x) {
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void AddHead(LIST& l, NODE* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
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
int IsEmpty(LIST l) {
	if (l.pHead == NULL)
		return 1;
	return 0;
}

void Cau1(LIST& l);

void Cau2(LIST& l);
void Cau3(LIST l);
void Cau4(LIST l);
int Cau5(LIST l);
void Cau6(LIST& l);
void Cau7(LIST& l);
void Cau8(LIST l);
int Cau9(LIST& l);
void Cau10(LIST& l);
void Cau11(LIST& l);
void Cau12(LIST& l);
void Cau13(LIST& l);

int main() {
	LIST l;
	Cau1(l);
	cout << endl;
	//Cau2(l);
	//Cau3(l);
	cout << endl;
	//Cau4(l);
	cout << endl;
	if (Cau5(l) == 1)
		cout << "Tim thay phan tu x";
	else
		cout << "Khon tim thay phan tu x";
	cout << endl;
	//Cau6(l);
	cout << endl;
	//Cau7(l);
	cout << endl;
	//Cau8(l);
	//Cau9(l);
	//Cau10(l);
	//Cau11(l);
	//Cau12(l);
	//Cau13(l);
	return 0;
}
void Cau1(LIST& l) {
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
void Cau2(LIST& l) {
	Xuat(l);
}
void Cau3(LIST l) {
	cout << "So luong node la: " << DemNode(l);
}
void Cau4(LIST l) {
	int n;
	cout << "Nhap phan tu thu n: ";
	cin >> n;
	NODE* p = l.pHead;
	for (int i = 1; i <=n ; i++) {
		p = p->pNext;
	}
	cout << "Gia tri tai not n: " << p->data;
}
int  Cau5(LIST l) {
	int x;
	cout << "Nhap phan tu muon tim kiem ";
	cin >> x;
	NODE* p = l.pHead;
	while (p != NULL) {
		if (p->data == x)
			return 1;
		p = p->pNext;
	}
	return 0;
}
void Cau6(LIST& l) {
	int k;
	cout << "Nhap k: ";
	cin >> k;
	NODE* p = l.pHead;
	while (p != NULL) {
		if (p->data == k)
			break;
		p = p->pNext;
	}
	int x;
	cout << "Nhap x: ";
	cin >> x;
	NODE* q = GetNode(x);
	if(p!=NULL)
	{
		q->pNext = p->pNext;
		p->pNext = q;
	}
	Xuat(l);
}
void Cau7(LIST& l) {
	int n;
	cout << "Nhap vi tri muon them node: ";
	cin >> n;
	NODE* p = l.pHead;
	for (int i = 1; i < n; i++) {
		p = p->pNext;
	}
	int x;
	cout << "Nhap x: ";
	cin >> x;
	NODE* q = GetNode(x);
	if (p != NULL)
	{
		q->pNext = p->pNext;
		p->pNext = q;
	}
	Xuat(l);
}
void Cau8(LIST l) {
	NODE* p = l.pHead;
	LIST T;
	Init(T);
	while (p != NULL) {
		NODE* q = GetNode(p->data);
		if(q != NULL)
		{
			AddHead(T, q);
		}
		p = p->pNext;
	}
	Xuat(T);
}
int Cau9(LIST& l) {
	int x;
	cout << "Nhap gia tri phan tu muon xoa: ";
	cin >> x;
	NODE* p = l.pHead;
	if (l.pHead->data == x)
	{
		l.pHead = l.pHead->pNext;
		delete p;
		return 1;
	}
	while (p->pNext != NULL) {
		if (p->pNext->data == x)
		{
			NODE* q = p->pNext;
			p->pNext = p->pNext->pNext;
			delete q;
			return 1;
		}
		p = p->pNext;
	}
	return 0;
}
void Cau10(LIST& l) {
	NODE* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void Cau11(LIST& l) {
	NODE* p = l.pHead;
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	NODE* q = l.pTail;
	l.pTail = p;
	delete q;
}
void Cau12(LIST& l) {
	while (l.pHead != NULL) {
		NODE* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
void Cau13(LIST& l) {
	int x;
	cout << "Nhap x: ";
	cin >> x;
	NODE* p = l.pHead;
	if (l.pHead->data > x) {
		NODE* q = GetNode(x);
		if (q != NULL)
			AddHead(l, q);
		return;
	}
	if (l.pTail->data <= x) {
		NODE* q = GetNode(x);
		if (q != NULL)
			AddTail(l, q);
		return;
	}
		
	NODE* q = l.pHead;
	while (p->pNext != NULL) {
		if (p->pNext->data > x) {
			NODE* q = GetNode(x);
			q->pNext = p->pNext;
			p->pNext = q;
			return;
		}
		p = p->pNext;
	}
}