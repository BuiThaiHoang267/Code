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
int InSearchNode(TREE& t, int x);
void DeleteNode(TREE& t, int x);
void Replace(TREE& t, TREE& p);
void Input(TREE& t);
int DemNodeLa(TREE t);
int DemNodeCo1CayCon(TREE t);
int DemNodeChiCo1CayConPhai(TREE t);
int DemNodeCoCayConTrai(TREE t);
int DemNodeCo2CayCon(TREE t);
void XuatNodeOMuc_K(TREE t, int k);
void XuatNodeTheoTungMuc(TREE t);
int ChieuCaoCay(TREE t);
int DoDaiDuongDiTuGocToiNode(TREE t, int x);
NODE* SearchNode(TREE t, int x) {
	if (t != NULL)
	{
		if (t->data == x)
			return t;
		else if (t->data > x)
			return SearchNode(t->pLeft, x);
		else
			return SearchNode(t->pRight, x);
	}
	return NULL;
}

int main() {
	TREE t;
	Input(t);
	cout << endl;
	cout << "So luong node la: " << DemNodeLa(t) << endl;
	cout << "So luong node co 1 cay con: " << DemNodeCo1CayCon(t) << endl;
	cout << "So luong node chi co 1 cay con phai: " << DemNodeChiCo1CayConPhai(t) << endl;
	cout << "So luong node co 1 cay con trai: " << DemNodeCoCayConTrai(t) << endl;
	cout << "So luong node co 2 cay con: " << DemNodeCo2CayCon(t) << endl;
	cout << "Xuat cac node theo tung muc: " << endl;
	XuatNodeTheoTungMuc(t);
	cout << endl;
	cout << "Nhap node co gia tri muon tinh do dai di tu goc: ";
	int x;
	cin >> x;
	cout << "Do dai tu goc toi node: " << DoDaiDuongDiTuGocToiNode(t, x);
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
	p->pLeft = p->pRight = NULL;
	return p;
}
int InSearchNode(TREE& t, int x){
	if (t != NULL) {
		if (t->data == x)
			return 0;
		else if (t->data > x)
			return InSearchNode(t->pLeft, x);
		else
			return InSearchNode(t->pRight, x);
	}
	t = GetNode(x);
	if (t == NULL)
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
			else
				Replace(t->pRight, p);
			delete p;
		}
	}
	else {
		cout << "Khong co node nao co gia tri can xoa!" << endl;
	}
}
void Replace(TREE& t, TREE& p) {
	if (t->pLeft != NULL) {
		t = t->pLeft;
	}
	else {
		p->data = t->data;
		p = t;
		t = t->pRight;
	}
}
void Input(TREE& t) {
	int n;
	cout << "Nhap so luong node: ";
	cin >> n;
	Init(t);
	for (int i = 0; i < n; i++) {
		cout << "Nhap x: ";
		int x;
		cin >> x;
		InSearchNode(t, x);
	}
}
int DemNodeLa(TREE t) {
	if (t == NULL)
		return 0;
	if (t->pLeft == NULL && t->pRight == NULL)
		return 1;
	return DemNodeLa(t->pLeft) + DemNodeLa(t->pRight);
}
int DemNodeCo1CayCon(TREE t) {
	if (t == NULL)
		return 0;
	int count = 0;
	if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
		count = 1;
	count += DemNodeCo1CayCon(t->pLeft);
	count += DemNodeCo1CayCon(t->pRight);
	return count;
}
int DemNodeChiCo1CayConPhai(TREE t) {
	if (t == NULL)
		return 0;
	int count = 0;
	if (t->pRight != NULL && t->pLeft == NULL)
		count=1;
	count += DemNodeChiCo1CayConPhai(t->pLeft);
	count += DemNodeChiCo1CayConPhai(t->pRight);
	return count;
}
int DemNodeCoCayConTrai(TREE t) {
	if (t == NULL)
		return 0;
	int count = 0;
	if (t->pLeft != NULL)
		count++;
	count += DemNodeCoCayConTrai(t->pLeft);
	count += DemNodeCoCayConTrai(t->pRight);
	return count;
}
void XuatNodeOMuc_K(TREE t, int k) {
	if (t != NULL) {
		k--;
		if (t->pLeft != NULL)
			XuatNodeOMuc_K(t->pLeft, k);
		if (t->pRight != NULL)
			XuatNodeOMuc_K(t->pRight, k);
		if (k == 0)
			cout << t->data << " ";
	}
}
void XuatNodeTheoTungMuc(TREE t) {
	int h = ChieuCaoCay(t);
	for (int i = 1; i <= h; i++) {
		cout << "Xuat node o muc " << i << ": ";
		XuatNodeOMuc_K(t, i);
		cout << endl;
	}
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
int DoDaiDuongDiTuGocToiNode(TREE t, int x) {
	if (t == NULL)
		return 0;
	int length = 0;
	if (SearchNode(t, x) != NULL) {
		while (t != NULL) {
			if (t->data == x)
				break;
			else if (t->data > x)
				t = t->pLeft;
			else
				t = t->pRight;
			length++;
		}
	}
	return length;
}
int DemNodeCo2CayCon(TREE t) {
	if (t == NULL)
		return 0;
	int count = 0;
	if(t->pLeft!=NULL&& t->pRight!=NULL)
		count=1;
	count += DemNodeCo2CayCon(t->pLeft);
	count += DemNodeCo2CayCon(t->pRight);
	return count;
}
