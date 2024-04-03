#include<iostream>
using namespace std;

struct node {
	int info;
	struct node* pRight;
	struct node* pLeft;
};
typedef struct node NODE;
typedef NODE* TREE;

void Init(TREE& t);
int IsEmpty(TREE t);
NODE* GetNode(int x);
int InsertNode(TREE& t, int x);
NODE* SearchNode(TREE t, int x);
void DeleteNode(TREE& t, int x);
void Replace(TREE& p, TREE& t);
void Input(TREE& t);
void Output(TREE t);

int main() {
	TREE t;
	Init(t);
	while (true) {
		int x;
		cin >> x;
		if (x == 0)
			break;
		InsertNode(t, x);
	}
	DeleteNode(t, 18);
	Output(t);
	return 0;
}
void Init(TREE& t) {
	t = NULL;
}
int IsEmpty(TREE t) {
	if (t == NULL)
		return 1;
	return 0;
}
NODE* GetNode(int x) {
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pRight = NULL;
	p->pLeft = NULL;
	return p;
}
int InsertNode(TREE& t, int x) {
	if (t != NULL) {
		if (t->info == x)
			return 0;
		if (t->info > x)
			return InsertNode(t->pLeft, x);
		else
			return InsertNode(t->pRight, x);
	}
	t = GetNode(x);
	if (t == NULL)
		return -1;
	return 1;
}
NODE* SearchNode(TREE t, int x) {
	if (t != NULL) 
	{
		if (t->info == x)
			return t;
		else if (t->info > x)
			return SearchNode(t->pLeft, x);
		else
			return SearchNode(t->pLeft, x);
	}
	return NULL;
}
void DeleteNode(TREE& t, int x) {
	if (t != NULL) {
		if (t->info < x)
			DeleteNode(t->pRight, x);
		else if (t->info > x)
			DeleteNode(t->pRight, x);
		else
		{
			NODE* p = t;
			if (t->pLeft == NULL)
				t = t->pRight;
			else if (t->pRight == NULL)
				t = t->pLeft;
			else
				Replace(p, t->pRight);
			delete p;
		}
	}
	else
		cout << "Khong tim thay" << endl;
}
void Replace(TREE& p,TREE& t) {
	if (t->pLeft != NULL)
		Replace(p, t->pLeft);
	else
	{
		p->info = t->info;
		p = t;
		t = t->pRight;
	}
}
void Input(TREE& t) {
	int n;
	int x;
	cin >> n;
	Init(t);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		InsertNode(t, x);
	}
}
void Output(TREE t) {
	if (t == NULL)
		return;
	Output(t->pLeft);
	Output(t->pRight);
	cout << t->info << " ";
}
