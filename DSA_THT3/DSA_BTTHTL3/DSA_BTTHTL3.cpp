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

void Cau1(LIST& l);
void Cau2(LIST l);
void Cau3(LIST l);
int Cau4(LIST l);
int Cau5(LIST l);
void Cau6(LIST& l);
void Cau7(LIST& l);
void Cau8(LIST l);
int Cau9(LIST& l);
int Cau10(LIST& l);
int Cau11(LIST& l);
void Cau12(LIST& l);
void Cau13(LIST& l);
void Cau14(LIST& l,LIST L);
void Cau15(LIST l, LIST& A, LIST& B);
void Cau16(LIST l, LIST& A, LIST& B);
void Cau17(LIST& l, LIST& A, LIST& B);

int main() {
	LIST l;
	LIST L;
	LIST T;
	//Cau1(l);
	//Cau2(l);
	/*Cau3(l);
	cout << "Gia tri phan tu tai vi tri tim kiem la: " << Cau4(l);
	if (Cau5(l) == 1)
		cout << "Tim thay x";
	else
		cout << "Khong tim thay x";
	cout << endl;*/
	//Cau6(l);
	//Cau7(l);
	//Cau8(l);
	//Cau9(l);
	//Cau10(l);
	//Cau11(l);
	//Cau12(l);
	//Cau13(l);
	//Cau14(l, L);
	//Cau15(l, L, T);
	//Cau16(l,L,T);
	//Cau17(l, L, T);
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
void Cau1(LIST& l) {
	Nhap(l);
}
void Cau2(LIST l) {
	Xuat(l);
}
void Cau3(LIST l) {
	cout << "\nSo luong node la: " << DemNode(l);
}
int Cau4(LIST l) {
	int n;
	cout << "\nNhap vi tri can tim kiem: ";
	cin >> n;
	NODE* p = l.pHead;
	for (int i = 0; i < n; i++) {
		p = p->pNext;
	}
	return p->info;
}
int Cau5(LIST l) {
	int x;
	cout << "\nNhap gia tri muon tim kiem: ";
	cin >> x;
	NODE* p = l.pHead;
	while (p != NULL) {
		if (p->info == x)
			return 1;
		p = p->pNext;
	}
	return 0;
}
void Cau6(LIST& l) {
	int k,x;
	cout << "\nNhap gia tri cua phan tu tai do ta muon them node p vao sau: ";
	cin >> k;
	cout << "Nhap gia tri cua node p: ";
	cin >> x;
	NODE* q = l.pHead;
	NODE* p = GetNode(x);
	while (q != NULL) {
		if (q->info == k)
			InsertAfterQ(l, p, q);
		q = q->pNext;
	}
}
void Cau7(LIST& l) {
	int n,x;
	cout << "Nhap vi tri muon them node p: ";
	cin >> n;
	NODE* q = l.pHead;
	for (int i = 0; i < n - 1; i++)
		q = q->pNext;
	cout << "Nhap gia tri cua node p: ";
	cin >> x;
	NODE* p = GetNode(x);
	if (q == l.pHead)
		AddHead(l, p);
	else
		InsertAfterQ(l, p, q);
}
void Cau8(LIST l) {
	LIST T;
	Init(T);
	NODE* p = l.pHead;
	while (p != NULL) {
		NODE* q = GetNode(p->info);
		if (q != NULL)
		{
			AddHead(T, q);
		}
		p = p->pNext;
	}
	Xuat(T);
}
int Cau9(LIST& l) {
	int x;
	cout << "\nNhap gia tri node muon xoa: ";
	cin >> x;
	NODE* p = l.pHead;
	if (l.pHead->info == x) {
		l.pHead = l.pHead->pNext;
		delete p;
		return 1;
	}
	while (p->pNext != NULL) {
		if (p->pNext->info == x) {
			NODE* q = p->pNext;
			p->pNext = q->pNext;
			delete q;
			return 1;
		}
		p = p->pNext;
	}
	return 0;
}
int Cau10(LIST& l) {
	if (l.pHead != NULL) {
		NODE* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
		return 1;
	}
	return 0;
}
int Cau11(LIST& l) {
	if (l.pTail != NULL) {
		NODE* p = l.pHead;
		while (p->pNext->pNext != NULL)
			p = p->pNext;
		NODE* q = l.pTail;
		l.pTail = p;
		l.pTail->pNext = NULL;
		delete q;
		return 1;
	}
	return 0;
}
void Cau12(LIST& l) {
	RemoveList(l);
}
void Cau13(LIST& l) {
	int x;
	cout << "Nhap x: ";
	cin >> x;
	NODE* p = l.pHead;
	if (l.pHead->info > x) {
		NODE* q = GetNode(x);
		if (q != NULL)
			AddHead(l, q);
		return;
	}
	if (l.pTail->info <= x) {
		NODE* q = GetNode(x);
		if (q != NULL)
			AddTail(l, q);
		return;
	}

	NODE* q = l.pHead;
	while (p->pNext != NULL) {
		if (p->pNext->info > x) {
			NODE* q = GetNode(x);
			q->pNext = p->pNext;
			p->pNext = q;
			return;
		}
		p = p->pNext;
	}
}
void Cau14(LIST& l,LIST L) {
	l.pTail->pNext = L.pHead;
	l.pTail = L.pTail;
}
void Cau15(LIST l, LIST& A, LIST& B) {
	A.pHead = l.pHead;
	B.pTail = l.pTail;
	int n = DemNode(l);
	n = (n+1) / 2;
	NODE* p = l.pHead;
	for (int i = 0; i < n-1; i++)
		p=p->pNext;
	A.pTail = p;
	B.pHead = p->pNext;
	A.pTail->pNext = NULL;
	Xuat(A);
	cout << endl;
	Xuat(B);
}
void Cau16(LIST l, LIST& A, LIST& B) {
	Init(A);
	Init(B);
	NODE* p = l.pHead;
	while (p != NULL) {
		NODE* q = GetNode(p->info);
		if ((p->info % 2 == 0) && q != NULL)
			AddTail(B, q);
		if ((p->info % 2 != 0) && q != NULL)
			AddTail(A, q);
		p = p->pNext;
	}
	Xuat(A);
	cout << endl;
	Xuat(B);
}
void Cau17(LIST& l, LIST& A, LIST& B) {
	Nhap(A);
	Nhap(B);
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
	Xuat(l);
}