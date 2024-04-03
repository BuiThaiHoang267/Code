#include<iostream>
#include<string>
#include <fstream>
#include<iomanip>
using namespace std;

// cau truc du lieu kieu dslk don
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

// Khai Bao ham
void Init(LIST&);
int IsEmpty(LIST);
NODE* GetNode(int);
void AddTail(LIST&, NODE*);
int Nhap(LIST&);
int Nhap(LIST&, string);
int Xuat(LIST, string);
void InterchangeSort(LIST&);

int main() {

	return 0;
}

// khoi tao danh sach lien ket don
void Init(LIST& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

//Kiem tra dslk don rong
int IsEmpty(LIST l) {
	if (l.pHead == NULL)// neu node dau tien giu dia chi null thi dslk rong
		return 1;
	return 0;
}

//Tao node cho dslk don
NODE* GetNode(int x) {
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
}

//Them node vao cuoi dslk don
void AddTail(LIST& l, NODE* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;//LK voi node moi them vao
		l.pTail = p;// gan node ms them vao thanh node cuoi
	}
}

//Nhap truu tuong dslk don
int Nhap(LIST& l) {
	int  n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	Init(l);
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
	return 1;
}

//Nhap dslk don cac so nguyen tu file
int Nhap(LIST& l, string filename) {
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	int n;
	int x;
	fi >> n;
	Init(l);
	for (int i = 1; i <= n; i++) {
		fi >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
	return 1;
}

//Xuat dslk don
void Xuat(LIST l) {
	NODE* p = l.pHead;
	while (p != NULL) {
		cout << p->info;
		p = p->pNext;
	}
}

// dem node
int DemNode(LIST l) {
	int dem = 0;
	NODE* p = l.pHead;
	while (p != NULL) {
		dem++;
		p = p->pNext;
	}
	return dem;
}

//Xuat dslk don cac so nguyen ra file
int Xuat(LIST l, string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << DemNode(l) << endl;
	NODE* p = l.pHead;
	while (p != NULL) {
		fo << setw(5) << p->info;
		p = p->pNext;//giong i++ trong while
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