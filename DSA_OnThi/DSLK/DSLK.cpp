#include<iostream>
using namespace std;

struct node {
	int data;
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
void addTail(LIST& l,NODE* p);
void addHead(LIST& l, NODE* p);
void Nhap(LIST& l);
void Xuat(LIST& l);
void DeleteHead(LIST& l);
void DeleteTail(LIST& l);
void RemoveList(LIST& l);
void XuatDaoNguoc(LIST l);
void Thempt_x_VaoVT_n(LIST& l);
int DemNode(LIST l);
bool KiemTra_khoaX(LIST l);
void Xoa_PT_X(LIST& l);
void Insertion_x(LIST& l);
LIST C(LIST l, LIST t);


int main() 
{
	LIST l,t;
	Nhap(l);
	Nhap(t);
	LIST kq = C(l, t);
	Xuat(kq);
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
NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void addTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void addHead(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void Nhap(LIST& l)
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			addTail(l, p);
	}
}
void Xuat(LIST& l)
{
	if (IsEmpty(l) == 1)
	{
		cout << "DSLK rong!";
		return;
	}
	NODE* p = l.pHead;
	while (p != NULL)
	{
		cout << p->data <<" ";
		p = p->pNext;
	}
}
void DeleteHead(LIST& l)
{
	if (l.pHead == NULL)
	{
		cout << "DSLK rong!";
		return;
	}
	NODE* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
	if (l.pHead == NULL)
		l.pTail == NULL;
}
void DeleteTail(LIST& l)
{
	if (l.pHead == NULL)
	{
		cout << "DSLK rong!";
		return;
	}
	NODE* p = l.pHead;
	if (l.pHead == l.pTail)
	{
		l.pHead = l.pTail = NULL;
		delete p;
	}
	else
	{
		while (p->pNext->pNext != NULL)
			p = p->pNext;
		NODE* q = l.pTail;
		l.pTail = p;
		l.pTail->pNext = NULL;
		delete q;
	}
}
void RemoveList(LIST& l)
{
	NODE* p = l.pHead;
	while (p != NULL)
	{
		NODE* q = p;
		p = p->pNext;
		delete q;
	}
	l.pHead = l.pTail = NULL;
}
void XuatDaoNguoc(LIST l)
{
	LIST temp;
	Init(temp);
	NODE* p = l.pHead;
	while (p != NULL)
	{
		NODE* q = GetNode(p->data);
		if (q != NULL)
			addHead(temp, q);
		p = p->pNext;
	}
	NODE* q= temp.pHead;
	while (q != NULL)
	{
		cout << q->data << " ";
		q = q->pNext;
	}
}
void Thempt_x_VaoVT_n(LIST& l)
{
	int x;
	int n;
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap n: ";
	cin >> n;
	if (n < 1 || DemNode(l)+1 < n) {
		cout << "n khong thoa voi so luong node!";
		return;
	}
	NODE* p = l.pHead;
	if (n == 1) {
		NODE* p = GetNode(x);
		if (p != NULL)
			addHead(l, p);
	}
	else
	{
		int dem = 0;
		while (p != NULL)
		{
			dem++;
			if (dem == n - 1)
			{
				NODE* q = GetNode(x);
				if (q != NULL)
				{
					q->pNext = p->pNext;
					p->pNext = q;
					return;
				}
			}
			p = p->pNext;
		}
	}
}
int DemNode(LIST l)
{
	NODE* p = l.pHead;
	int dem = 0;
	while (p != NULL)
	{
		dem++;
		p = p->pNext;
	}
	return dem;
}
bool KiemTra_khoaX(LIST l)
{
	int x;
	cout << "Nhap phan tu muon tim kiem x: ";
	cin >> x;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		if (p->data == x)
			return true;
		p = p->pNext;

	}
	return false;
}
void Xoa_PT_X(LIST& l)
{
	int x;
	cout << "Nhap node muon xoa x: ";
	cin >> x;
	if (KiemTra_khoaX(l) == false)
		return;
	if (l.pHead->data == x)
		DeleteHead(l);
	else
	{
		NODE* p = l.pHead;
		while (p != NULL)
		{
			if (p->pNext->data == x)
			{
				NODE* q = p->pNext;
				p->pNext = q->pNext;
				delete q;
				return;
			}
			p = p->pNext;
		}
	}
}
void Insertion_x(LIST& l)
{
	int x;
	cout << "Nhap x: ";
	cin >> x;
	NODE* p = l.pHead;
	if (l.pHead != NULL)
	{
		if (x <= l.pHead->data)
		{
			NODE* q = GetNode(x);
			if (q != NULL)
				addHead(l, q);
		}
		else if (x >= l.pTail->data)
		{
			NODE* q = GetNode(x);
			if (q != NULL)
				addTail(l, q);
		}
		else
		{
			while (p->pNext != NULL)
			{
				if (p->pNext->data >= x)
				{
					NODE* q = GetNode(x);
					if (q != NULL)
					{
						q->pNext = p->pNext;
						p->pNext = q;
						return;
					}
				}
				p = p->pNext;
			}
		}
	}
}
LIST C(LIST l, LIST t)
{
	LIST c;
	Init(c);
	NODE* p = l.pHead;
	NODE* q = t.pHead;
	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			NODE* temp = GetNode(p->data);
			if (temp != NULL)
				addTail(c, temp);
			p = p->pNext;
		}
		else
		{
			NODE* temp = GetNode(q->data);
			if (temp != NULL)
				addTail(c, temp);
			q = q->pNext;
		}
	}
	while (p != NULL)
	{
		NODE* temp = GetNode(p->data);
		if (temp != NULL)
			addTail(c, temp);
		p = p->pNext;
	}
	while (q != NULL)
	{
		NODE* temp = GetNode(q->data);
		if (temp != NULL)
			addTail(c, temp);
		q = q->pNext;
	}
	return c;
}

