#include<iostream>
using namespace std;
struct Date {
	int day;
	int thang;
	int nam;
};
typedef struct Date DATE;
struct computer {
	string ID;
	string Name;
	DATE NgayXuatHang;
	int GiaXuatHang;
};
typedef struct computer COMPUTER;
struct node
{
	COMPUTER data;
	node* pNext;
};
typedef struct node NODE;
struct queue
{
	NODE* front;
	NODE* rear;
};
typedef struct queue QUEUE;

void Init(QUEUE& que);
int IsEmpty(QUEUE que);
NODE* GetNode(COMPUTER x);
void Add(QUEUE& que, NODE* p);
COMPUTER ReMove(QUEUE& que);
void Nhap(QUEUE& que, int n);
void Xuat(QUEUE que);
void NhapDate(DATE& a);
void XuatDate(DATE a);
void NhapComputer(COMPUTER& a);
void XuatComputer(COMPUTER a);
void XuatTimKiemID(QUEUE que,string id);

int main() {
	QUEUE que;
	int n;
	cout << "Nhap so luong may tinh: ";
	cin >> n;
	Nhap(que, n);
	Xuat(que);
	string id;
	cout << "Nhap ID muon tim kiem: ";
	cin.ignore();
	cin >> id;
	XuatTimKiemID(que,id);
	cout << "May tinh da boc" << endl;
	int i = 1;
	while (IsEmpty(que)==0) {
		cout << i << "." << endl;
		COMPUTER temp = ReMove(que);
		XuatComputer(temp);
		cout << endl;
		i++;
	}
	return 0;
}
void Init(QUEUE& que)
{
	que.front = NULL;
	que.rear = NULL;
}
int IsEmpty(QUEUE que)
{
	if (que.front == NULL)
		return 1;
	return 0;
}
NODE* GetNode(COMPUTER x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return p;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void Add(QUEUE& que, NODE* p)
{
	if (que.front == NULL)
		que.front = que.rear = p;
	else
	{
		que.rear->pNext = p;
		que.rear = p;
	}
}
COMPUTER ReMove(QUEUE& que)
{
	COMPUTER x;
	if (IsEmpty(que)==0) {
		NODE* q = que.front;
		x = que.front->data;
		que.front = que.front->pNext;
		delete q;
		if (que.front == NULL)
		{
			que.rear = NULL;
		}
	}
	return x;
}
void Nhap(QUEUE& que, int n)
{
	Init(que);
	for (int i = 0; i < n; i++)
	{
		COMPUTER x;
		cout << "Nhap may tinh thu " << i + 1 << endl;
		NhapComputer(x);
		NODE* p = GetNode(x);
		if (p != NULL)
		{
			Add(que, p);
		}
	}
	cout << endl;
}
void Xuat(QUEUE que) {
	NODE* p = que.front;
	while (p != NULL)
	{
		XuatComputer(p->data);
		p = p->pNext;
		cout << endl;
	}
}
void NhapDate(DATE& a) {
	cout << "Nhap ngay: ";
	cin >> a.day;
	cout << "Nhap thang: ";
	cin >> a.thang;
	cout << "Nhap nam: ";
	cin >> a.nam;
}
void NhapComputer(COMPUTER& a) {
	cout << "Nhap ma may: ";
	cin >> a.ID;
	cout << "Nhap ten may: ";
	cin >> a.Name;
	cout << "Nhap ngay xuat hang" << endl;
	NhapDate(a.NgayXuatHang);
	cout << "Nhap gia xuat hang: ";
	cin >> a.GiaXuatHang;
}
void XuatDate(DATE a) {
	cout << a.day << "/" << a.thang << "/" << a.nam << endl;
}
void XuatComputer(COMPUTER a) {
	cout << "ID: " << a.ID << endl;
	cout << "Ten may: " << a.Name << endl;
	cout << "Ngay xuat hang: ";
	XuatDate(a.NgayXuatHang);
	cout << "Gia xuat hang: " << a.GiaXuatHang << " trieu dong" << endl;
}
void XuatTimKiemID(QUEUE que,string id) {
	NODE* p = que.front;
	while (p != NULL)
	{
		if (p->data.ID == id) {
			XuatComputer(p->data);
			cout << endl;
		}
		p = p->pNext;
	}
}
