#include<iostream>
#include<fstream>
#include<iomanip>
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
NODE* GetNode(int);
void AddTail(LIST&, NODE*);
int Nhap(LIST&,string);
void Xuat(LIST);

int main(){
	LIST l;
	string filename = "intdata01.inp";
	Nhap(l, filename);
	Xuat(l);
	return 0;
}

void Init(LIST& l) {
	l.pHead = NULL;
	l.pTail = NULL;
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
	l.pTail->pNext = p;
	l.pTail = p;
}
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

void Xuat(LIST l) {
	NODE* p = l.pHead;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->pNext;
	}
}
