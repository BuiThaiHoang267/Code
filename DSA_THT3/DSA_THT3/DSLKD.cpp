#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

struct Node {
	int data;
	Node* pNext;
};
struct List {
	Node* pHead;
	Node* pTail;
};

void Init(List& l) {
	l.pHead = l.pTail = NULL;
}
bool IsEmpty(List l) {
	if (l.pHead == NULL)
		return true;
	return false;
}
Node* GetNode(int x) {
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void AddHead(List& l, Node* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(List& l, Node* p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Nhap(List& l) {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int x;
	Init(l);
	for (int i = 0; i < n; i++) {
		cin >> x;
		Node* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
}
int DemNode(List l) {
	int dem = 0;
	Node* p = l.pHead;
	while (p != NULL)
	{
		dem++;
		p = p->pNext;
	}
	return dem;
}
void Xuat(List l) {
	Node* p = l.pHead;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->pNext;
	}
}
int Nhap(List& l, string filename) {
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	int n;
	fi >> n;
	int x;
	Init(l);
	for (int i = 0; i < n; i++) {
		fi >> x;
		Node* p = GetNode(x);
		while (p != NULL)
			AddTail(l, p);
	}
	return 1;
}

int main() {
	return 0;
}