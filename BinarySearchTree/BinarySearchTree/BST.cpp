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
int Nhap(TREE& t, string filename);
void Xuat(TREE t);
int DemNode(TREE t);
int Xuat(TREE t, ofstream& fo);
int Xuat(TREE t, string filename);




int main() {
	TREE t;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intbst";
		if (i <= 9)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename + ".inp";
		if (Nhap(t, filenameinp) == 1)
		{
			cout << "\n So luong node: " << DemNode(t);
			string filenameout = filename + ".out";
			Xuat(t, filenameout);
			cout << "\n" << filenameinp << "\n" << filenameout;
		}
		else
			cout << "\n Khong mo duoc file " << filename << "\n";
	}
	cout << "\n\n\n";
	return 0;
}
void Init(TREE& t) {
	t = NULL;
}
int IsEmpty(TREE t) {
	if (t == NULL)
		return 0;
	return 1;
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
		if (x > t->info)
			return InsertNode(t->pRight, x);
		if (x < t->info)
			return InsertNode(t->pLeft, x);
		return 0;
	}
	t = GetNode(x);
	if (t == NULL)
		return -1;
	return 1;
}
int Nhap(TREE& t, string filename) {
	ifstream fi(filename);
	if (fi.fail() == true)
		return 0;
	int n, x;
	fi >> n;
	Init(t);
	for (int i = 1; i <= n; i++) {
		fi >> x;
		InsertNode(t, x);
	}
	return 1;
}
void Xuat(TREE t) {
	if (t == NULL)
		return;
	Xuat(t->pLeft);
	cout << setw(6) << t->info;
	Xuat(t->pRight);
}
int DemNode(TREE t) {
	if (t == NULL)
		return 0;
	int a = DemNode(t->pLeft);
	int b = DemNode(t->pRight);
	return a + b + 1;
}
int Xuat(TREE t, ofstream& fo) {
	if (t == NULL)
		return 0;
	Xuat(t->pLeft, fo);
	fo << setw(6) << t->info;
	Xuat(t->pRight, fo);
}
int Xuat(TREE t, string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	fo << setw(6) << DemNode(t) << endl;
	return Xuat(t, fo);
}