#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

struct node {
	int info;
	struct node* pLeft;
	struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void Init(TREE&);
int IsEmpty(TREE);
NODE* GetNode(int);
int InsertNode(TREE&, int);
int Nhap(TREE&, string);
int DemNode(TREE);
void Xuat(TREE);
int Xuat(TREE, string);
int Xuat(TREE, ofstream&);

int main() 
{
	TREE t;
	string filenameinp = "intdata01.inp";
	Nhap(t, filenameinp);
	Xuat(t);
	return 1;
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
NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pLeft = p->pRight = NULL;
	return p;
}
int InsertNode(TREE& t, int x)
{
	if (t != NULL) {
		int rValue = rand();
		if (rValue % 2 == 0)
			return InsertNode(t->pRight, x);
		return InsertNode(t->pLeft, x);
	}
	t = GetNode(x);
	if (t == NULL)
		return -1;
	return 1;
}
int Nhap(TREE& t, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	int n, x;
	fi >> n;
	Init(t);
	for (int i = 1; i <= n; i++)
	{
		fi >> x;
		InsertNode(t, x);
	}
	return 1;
}
int DemNode(TREE t)
{
	if (t == NULL)
		return 0;
	int a = DemNode(t->pLeft);
	int b = DemNode(t->pRight);
	return a + b + 1;
}
void Xuat(TREE t)
{
	if (t == NULL)
		return;
	Xuat(t->pRight);
	Xuat(t->pLeft);
	cout << t->info << " ";
}
int Xuat(TREE t, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(6) << DemNode(t) << endl;
	Xuat(t, fo);
}
int Xuat(TREE t, ofstream& fo)
{
	if (t == NULL)
		return 0;
	Xuat(t->pLeft, fo);
	fo << setw(6) << t->info;
	Xuat(t->pRight, fo);
}