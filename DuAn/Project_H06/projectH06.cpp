#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

struct node {
	int info;
	struct node* pNext;
	struct node* pPrev;
};
typedef struct node NODE;
struct list {
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void Init(LIST&);
NODE* GetNode(int);
int IsEmpty(LIST);
void AddTail(LIST&, NODE*);
int Nhap(LIST&);
int Nhap(LIST&, string);
void BubbleSort(LIST);
int DemNode(LIST);
void Xuat(LIST);
int Xuat(LIST, string);

int main() {
	LIST l;
	for (int i = 1; i <= 13; i++) {
		string filename = "intdata";
		if (i <= 9)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename;
		filenameinp += ".inp";
		if (Nhap(l, filenameinp) == 1) {
			BubbleSort(l);
			string filenameout = filename;
			filenameout += ".out";
			Xuat(l, filenameout);
			cout << "\n" << filenameinp;
			cout << "\n" << filenameout;
		}
		else
			cout << "\nKhong mo duoc file!" << filename << "\n";
	}
	cout << "\n\n\n";
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
	p->pPrev = NULL;
	return p;
}
void AddTail(LIST& l, NODE* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}
int Nhap(LIST& l) {
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	int x;
	Init(l);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
	return 1;
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
int DemNode(LIST l) {
	NODE* p = l.pHead;
	int dem = 0;
	while (p != NULL) {
		dem++;
		p = p->pNext;
	}
	return dem;
}
int Xuat(LIST l, string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(5) << DemNode(l) << endl;
	NODE* p = l.pHead;
	while (p != NULL) {
		fo << setw(5) << p->info;
		p = p->pNext;
	}
	return 1;
}
void BubbleSort(LIST l) {
	for (NODE* p = l.pHead; p->pNext != NULL; p = p->pNext)
		for (NODE* q = l.pTail; q != p; q = q->pPrev)
			if (q->pPrev->info > q->info)
				swap(q->pPrev->info, q->info);
}