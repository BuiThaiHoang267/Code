#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
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
void Input(TREE& t);
void Output(TREE t);
int DemNode(TREE t);

int main() {
	TREE t;
	Input(t);
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
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int InsertNode(TREE& t, int x) {
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
int DemNode(TREE t) {
	if (t == NULL)
		return 0;
	int a = DemNode(t->pLeft);
	int b = DemNode(t->pRight);
	return a + b + 1;
}
void Output(TREE t) {
	if (t == NULL)
		return;
	Output(t->pLeft);
	cout << t->info << " ";
	Output(t->pRight);
}