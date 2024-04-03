#include<iostream>
#include<iomanip>
#include<string>
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
int Nhap(LIST&);
int Nhap(LIST&, string);
int DemNode(LIST);
void InterchangeSort(LIST);
void BubbleSort(LIST);
void Xuat(LIST);
int Xuat(LIST, string);

int main() {
	LIST l;
	for (int i = 1; i <= 13; i++) {
		string filename = "intdata";
		if (i <= 9)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename + ".inp";
		if (Nhap(l, filenameinp) == 1) {
			string filenameout = filename;
			filenameout += filename + ".out";
			Xuat(l, filenameout);

		}
	}
	return 0;
}

void Init(LIST& l) {
	l.pHead = NULL;
	l.pTail == NULL;
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
int Nhap(LIST& l) {
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	int x;
	Init(l);
	for (int i = 0; i <= n; i++) {
		cin >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
	return 1;
}
int Nhap(LIST& l,string filename) {
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	int n;
	fi >> n; 
	int x;
	Init(l);
	for (int i = 1; i <= n; i++) {
		fi >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
	return 1;
}
int DemNode(LIST l)
{
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
		cout << setw(5) << p->info;
		p = p->pNext;
	}
}
int Xuat(LIST l,string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	cout << setw(5) << DemNode(l) << endl;
	NODE* p = l.pHead;
	while (p != NULL) {
		fo <<setw(5)<<p->info;
		p = p->pNext;
	}
	return 1;
}