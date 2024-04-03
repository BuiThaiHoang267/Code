#include<iostream>
#include<iomanip>
#include<fstream>
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
int IsEmpty(LIST);
NODE* GetNode(int);
void AddTail(LIST&, NODE*);
int Nhap(LIST&, string);
int Xuat(LIST, string);
int DemNode(LIST);
void InterchangeSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int vt;
		for (vt = i - 1; vt >= 0 && a[vt] > x; vt--) {
			a[vt + 1] = a[vt];
		}
		a[vt+1] = x;
	}
}

int main() {
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
void AddTail(LIST& l, NODE* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
int Nhap(LIST& l, string filename) {
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	int n;
	int x;
	fi >> n;
	Init(l);
	for (int i = 0; i < n; i++) {
		fi >> x;
		NODE* p = new NODE;
		if (p != NULL)
			AddTail(l, p);
	}
	return 1;
}
int Nhap(LIST l, string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << DemNode(l) << endl;
	NODE* p = l.pHead;
	while (p != NULL) {
		fo << p->info;
		p = p->pNext;
	}
	return 1;
}

