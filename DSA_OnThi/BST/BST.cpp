#include<iostream>
using namespace std;

struct node {
	int data;
	struct node* pLeft;
	struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void Init(TREE& t);
int IsEmpty(TREE t);
NODE* GetNode(int x);
int InsertNode(TREE& t, int x);
NODE* SearchNode(TREE t, int x);
void Replace(TREE& t, TREE& p);
void DeleteNode(TREE& t, int x);
void Nhap(TREE& t);
void Xuat(TREE& t);
int DemNode(TREE t);
int DemNodeLa(TREE t);
int DemNodeDayDu(TREE t);
int DemNode1con(TREE t);
int DemNodeChiCoCayConTrai(TREE t);
int DemNodeChiCoCayConPhai(TREE t);
int DemCanh(TREE t);
int ChieuCaoCay(TREE t);
void XuatNODE_MucK(TREE t, int k);
void XuatNodeTheoTungMuc(TREE t);


int main()
{
	TREE t;
	Nhap(t);
	XuatNODE_MucK(t,3);
	return 0;
}

void Init(TREE& t)
{
	t = NULL;
}
int IsEmpty(TREE t)
{
	if (t == NULL)
		return 1;
	return 0;
}
NODE* GetNode( int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pLeft = p->pRight = NULL;
	return p;
}
int InsertNode(TREE& t, int x)
{
	if (t != NULL)
	{
		if (x == t->data)
			return 0;
		else if (x < t->data)
			return InsertNode(t->pLeft, x);
		else
			return InsertNode(t->pRight, x);
	}
	t = GetNode(x);
	if (t == NULL)
		return -1;
	return 1;
}
NODE* SearchNode(TREE t, int x)
{
	if (t != NULL)
	{
		if (x == t->data)
			return t;
		else if (x < t->data)
			return SearchNode(t->pLeft, x);
		else
			return SearchNode(t->pRight, x);
	}
	else
	{
		cout << "Khong tim thay!";
		return NULL;
	}
}
void Replace(TREE& t, TREE& p)
{
	if (t->pLeft != NULL)
		Replace(t->pLeft, p);
	else
	{
		p->data = t->data;
		p = t;
		t = t->pRight;
	}
}
void DeleteNode(TREE& t, int x)
{
	if (t != NULL) 
	{
		if (x < t->data)
			DeleteNode(t->pLeft, x);
		else if (x > t->data)
			DeleteNode(t->pRight, x);
		else
		{
			NODE* p = t;
			if (t->pLeft == NULL)
				t = t->pRight;
			else if (t->pRight == NULL)
				t = t->pLeft;
			else
				Replace(t->pRight, p);
			delete p;
		}
	}
}
void Nhap(TREE& t)
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	Init(t);
	for (int i = 0; i<n; i++)
	{
		int x;
		cin >> x;
		InsertNode(t, x);
	}
}
void Xuat(TREE& t)
{
	if (t == NULL)
		return;
	Xuat(t->pLeft);
	cout << t->data << " ";
	Xuat(t->pRight);
}
int DemNode(TREE t)
{
	if (t == NULL)
		return 0;
	int a = DemNode(t->pLeft);
	int  b = DemNode(t->pRight);
	return a + b + 1;
}
int DemNodeLa(TREE t)
{
	if (t == NULL)
		return 0;
	int count = 0;
	if (t->pLeft == NULL && t->pRight == NULL)
		count++;
	return count+DemNodeLa(t->pLeft) + DemNodeLa(t->pRight);
}
int DemNodeDayDu(TREE t)
{
	if (t == NULL)
		return 0;
	int count = 0;
	if (t->pLeft != NULL && t->pRight != NULL)
		count++;
	return count + DemNodeDayDu(t->pLeft) + DemNodeDayDu(t->pRight);
}
int DemNode1con(TREE t)
{
	if (t == NULL)
		return 0;
	int count = 0;
	if ((t->pLeft == NULL && t->pRight != NULL) || (t->pLeft != NULL && t->pRight == NULL))
		count++;
	return count + DemNode1con(t->pLeft) + DemNode1con(t->pRight);
}
int DemNodeChiCoCayConTrai(TREE t)
{
	if (t == NULL)
		return 0;
	int count = 0;
	if (t->pLeft != NULL && t->pRight == NULL)
		count++;
	return count + DemNodeChiCoCayConTrai(t->pLeft) + DemNodeChiCoCayConTrai(t->pRight);
}
int DemNodeChiCoCayConPhai(TREE t)
{
	if (t == NULL)
		return 0;
	int count = 0;
	if (t->pLeft == NULL && t->pRight != NULL)
		count++;
	return count + DemNodeChiCoCayConPhai(t->pLeft) + DemNodeChiCoCayConPhai(t->pRight);
}
int DemCanh(TREE t)
{
	return DemNode(t) - 1;
}
int ChieuCaoCay(TREE t)
{
	if (t == NULL)
		return 0;
	int a = ChieuCaoCay(t->pLeft);
	int b = ChieuCaoCay(t->pRight);
	if (a>b)
		return a + 1;
	return b + 1;
}
void XuatNODE_MucK(TREE t, int k)
{
	if (t == NULL)
		return;
	if (t != NULL) {
		if (k == 0)
			cout << t->data << " ";
		k--;
		XuatNODE_MucK(t->pLeft, k);
		XuatNODE_MucK(t->pRight, k);
	}
}
void XuatNodeTheoTungMuc(TREE t)
{
	for (int i = 1; i <= ChieuCaoCay(t); i++)
	{
		cout << "Muc " << i << ":";
		XuatNODE_MucK(t, i);
		cout << endl;
	}
}
