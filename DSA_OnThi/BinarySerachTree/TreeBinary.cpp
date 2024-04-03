#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* pLeft;
	struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

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
NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;

	p->data = x;
	p->pLeft = p->pRight = NULL;
	return p;
}
int InsearchNode(TREE& t, int x)
{
	if (t != NULL)
	{
		if (t->data == x)
			return 0;
		else if (t->data > x)
			return InsearchNode(t->pLeft, x);
		else
			return InsearchNode(t->pRight, x);
	}
	t = GetNode(x);
	if (t == NULL)
		return -1;
	return 1;
}
void Nhap(TREE& t)
{
	int n;
	cin >> n;
	int x;
	Init(t);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		InsearchNode(t,x);
	}
}

void Xuat(TREE t)
{
	if (t == NULL)
		return;
	Xuat(t->pLeft);
	cout << t->data << endl;
	Xuat(t->pRight);
}


int main()
{
	TREE T;
	Nhap(T);
	Xuat(T);
	return 0;
}