2#include<iostream>
using namespace std;

struct node {
	int data;
	struct node* pRight;
	struct node* pLeft;
};
typedef struct node NODE;
typedef NODE* TREE;

void Init(TREE& t);
int IsEmpty(TREE t);
NODE* GetNode(int x);
int InSearchNode(TREE& t, int x);
void DeleteNode(TREE& t, int x);
void Replace(TREE& t, TREE& p);
void Input(TREE& t);
int DemNode(TREE t);
void XuatCacNodeChan(TREE t);
void XuatCacNodeCoGiaTriLonHon_x(TREE t,int x);
int ChieuCaoCay(TREE t);
NODE* SearchNode(TREE t, int x);
NODE* TimNodeMax(TREE t);
NODE* TimNodeMinCuaCayConPhai(TREE t);

int main() {
	TREE t;
	Input(t);
	cout << endl;
	cout << "\nCac node co gia tri chan: ";
	XuatCacNodeChan(t);
	int x;
	cout << "\nNhap x: ";
	cin >> x;
	cout << "\nCac node co gia tri lon hon x: ";
	XuatCacNodeCoGiaTriLonHon_x(t, x);
	cout << "\nSo luong node cua cay la: " << DemNode(t);
	cout << "\nChieu cao cay: " << ChieuCaoCay(t);
	cout << "\nNhap x: ";
	cin >> x;
	if (SearchNode(t, x) != NULL) {
		cout << "\nTim thay node x!";
	}
	cout << "\nNode co gia tri cao nhat: " << TimNodeMax(t);
	cout << "\nNode co gia tri nho nhat cua cay con phai: " << TimNodeMinCuaCayConPhai(t);
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
int InSearchNode(TREE& t, int x) {
	if (t != NULL) {
		if (t->data == x)
			return 0;
		else if (x < t->data)
			return InSearchNode(t->pLeft, x);
		else
			return InSearchNode(t->pRight, x);
	}
	t = GetNode(x);
	if (t != NULL)
		return 1;
	return -1;
}
void DeleteNode(TREE& t, int x) {
	if (t != NULL) {
		if (t->data > x)
			DeleteNode(t->pLeft, x);
		else if (t->data < x)
			DeleteNode(t->pRight, x);
		else {
			NODE* p = t;
			if (t->pLeft == NULL)
				t = t->pRight;
			else if (t->pRight == NULL)
				t = t->pLeft;
			else {
				Replace(t->pRight, p);
			}
			delete p;
		}
	}
	else {
		cout << "\nKhong tim thay node can xoa!" << endl;
	}
}
void Replace(TREE& t, TREE& p) {
	if (t->pLeft != NULL) {
		Replace(t->pLeft, p);
	}
	else {
		p->data = t->data;
		p = t;
		t = t->pRight;
	}
}
void Input(TREE& t) {
	int n;
	Init(t);
	cout << "Nhap so luong Node: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cout << "Nhap x: ";
		cin >> x;
		InSearchNode(t, x);
	}
}
int DemNode(TREE t) {
	if (t == NULL)
		return 0;
	return DemNode(t->pLeft) + DemNode(t->pRight) + 1;
}
void XuatCacNodeChan(TREE t) {
	if (t == NULL)
		return;
	if (t->data % 2 == 0)
		cout << t->data << " ";
	XuatCacNodeChan(t->pLeft);
	XuatCacNodeChan(t->pRight);
}
void XuatCacNodeCoGiaTriLonHon_x(TREE t,int x) {
	if (t == NULL)
		return;
	if (t->data > x)
		cout << t->data << " ";
	XuatCacNodeCoGiaTriLonHon_x(t->pLeft, x);
	XuatCacNodeCoGiaTriLonHon_x(t->pRight, x);
}
int ChieuCaoCay(TREE t) {
	if (t == NULL)
		return 0;
	int a = ChieuCaoCay(t->pLeft);
	int b = ChieuCaoCay(t->pRight);
	if (a > b)
		return a + 1;
	return b + 1;
}
NODE* SearchNode(TREE t, int x) {
	if (t != NULL) {
		if (x == t->data)
			return t;
		else if (t->data < x)
			return SearchNode(t->pRight, x);
		else
			return SearchNode(t->pLeft, x);
	}
	else {
		cout << "khong co node co gia tri: " << x;
		return NULL;
	}
}
NODE* TimNodeMax(TREE t) {
	if (t == NULL) {
		cout << "Cay rong!";
		return NULL;
	}
	while (t->pRight != NULL) {
		t = t->pRight;
	}
	return t;
}
NODE* TimNodeMinCuaCayConPhai(TREE t) {
	if (t == NULL) {
		cout << "Cay rong!";
		return NULL;
	}
	if (t->pRight != NULL) {
		t = t->pRight;
	}
	while (t->pLeft != NULL) {
		t = t->pLeft;
	}
	return t;
}