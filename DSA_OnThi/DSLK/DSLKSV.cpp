#include<iostream>
#include<string>
using namespace std;

struct sinhvien {
	int ID;
	string name;
	string lop;
	float dtb;
	int hanhkiem;
};
typedef struct sinhvien SINHVIEN;
struct node {
	SINHVIEN sv;
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
NODE* GetNode(SINHVIEN x);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void Nhap(SINHVIEN& x);
void Nhap(LIST& l);


int main()
{
	LIST l;
	Nhap(l);
	return 0;
}
void Init(LIST& l)
{
	l.pHead = l.pTail = NULL;
}
int IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}
NODE* GetNode(SINHVIEN x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->sv = x;
	p->pNext = NULL;
	return p;
}
void AddHead(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Nhap(SINHVIEN& x)
{
	cout << "Nhap ID(2252XXXX): ";
	cin >> x.ID;
	cout << "Nhap name: ";
	cin.ignore();
	getline(cin, x.name);
	cout << "Nhap lop: ";
	cin >> x.lop;
	cout << "Nhap diem tong ket: ";
	cin >> x.dtb;
	cout << "Nhap hanh kiem (1. Y, 2.TB, 3. K,4. T): ";
	cin >> x.hanhkiem;
}
void Nhap(LIST& l)
{
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		SINHVIEN x;
		Nhap(x);
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l,p);
	}
}