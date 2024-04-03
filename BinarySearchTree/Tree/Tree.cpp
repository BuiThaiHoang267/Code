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
int InsearchNode(TREE& t, int x);
NODE* SearchNode(TREE t, int x);
void Replace(TREE& t, TREE& p);
void DeleteNode(TREE& t, int x);
void Input(TREE& t);
void Output(TREE t);
int DemNode(TREE t);
int DemNodeDayDu(TREE t);
int DemNodeLa(TREE t);
int DemCanh(TREE t);

int main() {
	TREE t;
	Input(t);
	//Output(t);
	cout << DemNode(t);
	cout << endl;
	cout << DemNodeDayDu(t);
	cout << endl;
	cout << DemNodeLa(t);
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
	p->data = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int InsearchNode(TREE& t, int x) {
	if (t != NULL) {
		if (x == t->data)
			return 0;
		else if (x < t->data)
			return InsearchNode(t->pLeft, x);
		else
			return InsearchNode(t->pRight, x);
	}
	t = GetNode(x);
	if (t == NULL)
		return -1;
	return 1;
}
NODE* SearchNode(TREE t, int x) {
	if (t != NULL) {
		if (x == t->data)
			return t;
		else if (x < t->data)
			return SearchNode(t->pLeft, x);
		else
			return SearchNode(t->pRight, x);
	}
	return NULL;
}
void Replace(TREE& t, TREE& p) {
	if (t->pLeft != NULL)
		Replace(t->pLeft, p);
	else {
		p->data = t->data;
		p = t;
		t = t->pRight;
	}
}
void DeleteNode(TREE& t, int x) {
	if (t != NULL) {
		if (x < t->data)
			return DeleteNode(t->pLeft, x);
		else if (x > t->data)
			return DeleteNode(t->pRight, x);
		else {
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
int DemNode(TREE t) {
	if (t == NULL)
		return 0;
	int a = DemNode(t->pLeft);
	int b = DemNode(t->pRight);
	return a + b + 1;
}
int DemNodeDayDu(TREE t) {
	if (t == NULL)
		return 0;
	if (t->pLeft != NULL && t->pRight)
		return 1 + DemNodeDayDu(t->pLeft) + DemNodeDayDu(t->pRight);
	return DemNodeDayDu(t->pLeft) + DemNodeDayDu(t->pRight);
}
void Input(TREE& t) {
	int n;
	int x;
	cin >> n;
	Init(t);
	for (int i = 0; i < n; i++) {
		cin >> x;
		InsearchNode(t, x);
	}
}
void Output(TREE t) {
	if (t == NULL)
		return ;
	cout << t->data << " ";
	Output(t->pLeft);
	Output(t->pRight);
}
int DemNodeLa(TREE t) {
	if (t == NULL)
		return 0;
	if (t->pLeft == NULL && t->pRight == NULL)
		return 1;
	return DemNodeLa(t->pLeft) + DemNodeLa(t->pRight);
}
