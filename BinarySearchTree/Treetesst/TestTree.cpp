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
void OutputLNR(TREE t);
void OutputNLR(TREE t);
void OutputRNL(TREE t);
int DemNodeLa(TREE t);
int DemNode(TREE t);
void XuatNodeMucThu_K(TREE t, int k);
int DemNodeCoDu2CayCon(TREE t);
int DemCacNodeChiCoCayConTrai(TREE t);
void XuatCayTheoTungMuc(TREE t);
int ChieuCaoCay(TREE t);
int DemCacNodeChiCo1CayCon(TREE t);
void XuatNodeChiCo1Con(TREE t);

int main() {
	TREE t;
	cout << "Nhap so luong node: ";
	Input(t);
	cout << "Xuat cay theo LNR: ";
	OutputLNR(t);
	cout << "\nXuat cay theo NLR: ";
	OutputNLR(t);
	cout << "\nXuat cay theo RNL: ";
	OutputRNL(t);
	cout << endl;
	cout << "So luong cac node La: " << DemNodeLa(t) << endl;
	cout << "So luong cac node co du 2 cay con: " << DemNodeCoDu2CayCon(t) << endl;
	cout << "So luong node chi co cay con trai: " << DemCacNodeChiCoCayConTrai(t) << endl;
	cout << "So luong node chi co mot cay con: " << DemCacNodeChiCo1CayCon(t) << endl;
	int x;
	cout << "Nhap gia tri node muon xoa: ";
	cin >> x;
	DeleteNode(t, x);
	cout << endl;
	cout << "Chieu cao cay: " << ChieuCaoCay(t) << endl;
	cout << "\nXuat cay theo tung muc: " << endl;
	XuatCayTheoTungMuc(t);
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
			return SearchNode(t->pRight, x);
	}
	return NULL;
}
void DeleteNode(TREE& t, int x) {
	if (t != NULL) {
		if (t->info < x)
			DeleteNode(t->pRight, x);
		else if (t->info > x)
			DeleteNode(t->pLeft, x);
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
void Replace(TREE& p, TREE& t) {
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
		cout << "Nhap x: ";
		cin >> x;
		InsertNode(t, x);
	}
}
void OutputLNR(TREE t) {
	if (t == NULL)
		return;
	OutputLNR(t->pLeft);
	cout << t->info << " ";
	OutputLNR(t->pRight);
}
void OutputNLR(TREE t) {
	if (t == NULL)
		return;
	cout << t->info << " ";
	OutputNLR(t->pLeft);
	OutputNLR(t->pRight);
}
void OutputRNL(TREE t) {
	if (t == NULL)
		return;
	OutputRNL(t->pRight);
	cout << t->info << " ";
	OutputRNL(t->pLeft);
}
int DemNodeLa(TREE t) {
	if (t == NULL)
		return 0;
	if (t->pLeft == NULL && t->pRight == NULL)
		return 1;
	return DemNodeLa(t->pLeft) + DemNodeLa(t->pRight);
}
int DemNode(TREE t) {
	if (t == NULL)
		return 0;
	return DemNode(t->pLeft) + DemNode(t->pRight) + 1;
}
void XuatNodeMucThu_K(TREE t, int k) {
	if (t != NULL) {
		k--;
		if (t->pLeft != NULL)
			XuatNodeMucThu_K(t->pLeft,k);
		if (t->pRight != NULL)
			XuatNodeMucThu_K(t->pRight, k);
		if (k == 0)
			cout << t->info << " ";
	}
}
int DemNodeCoDu2CayCon(TREE t) {
	if (t == NULL)
		return 0;
	if (t->pLeft != NULL && t->pRight != NULL)
		return 1;
	return DemNodeCoDu2CayCon(t->pLeft) + DemNodeCoDu2CayCon(t->pRight);
}
int DemCacNodeChiCoCayConTrai(TREE t) {
	if (t == NULL)
		return 0;
	if (t->pLeft != NULL && t->pRight == NULL)
		return 1;
	return DemCacNodeChiCoCayConTrai(t->pLeft) + DemCacNodeChiCoCayConTrai(t->pRight);
}
int DemCacNodeChiCo1CayCon(TREE t) {
	if (t == NULL)
		return 0;
	if (t->pLeft != NULL && t->pRight == NULL)
		return 1;
	if (t->pLeft == NULL && t->pRight != NULL)
		return 1;
	return DemCacNodeChiCo1CayCon(t->pLeft) + DemCacNodeChiCo1CayCon(t->pRight);
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
void XuatNodeChiCo1Con(TREE t) {
	if (t == NULL)
		return;
	if (t->pLeft != NULL && t->pRight == NULL)
		cout << t->info << " ";
	if (t->pLeft == NULL && t->pRight != NULL)
		cout << t->info << " ";
	XuatNodeChiCo1Con(t->pLeft);
	XuatNodeChiCo1Con(t->pRight);
}
void XuatCayTheoTungMuc(TREE t) {
	int h = ChieuCaoCay(t);
	for (int i = 1; i <= h; i++) {
		cout << "Xuat node o muc " << i << ": ";
		XuatNodeMucThu_K(t, i);
		cout << endl;
	}
}