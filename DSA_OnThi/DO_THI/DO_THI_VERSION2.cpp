#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

vector<pair<char, int>> adj[100];
void Nhap(int&,int&,char&,char&);
void Dijkstra(int sodinh,int socanh,char dinhbatdau);
void Dijkstra_2_dinh(int sodinh, int socanh, char dinhbatdau, char dinhketthuc);
int main()
{
	int SoDinh, SoCanh;
	char DinhBatDau, DinhKetThuc;
	Nhap(SoDinh, SoCanh, DinhBatDau, DinhKetThuc);
	Dijkstra(SoDinh, SoCanh, DinhBatDau);
	return 0;
}
void Nhap(int& sodinh, int& socanh, char& dinhbatdau, char&dinhketthuc)
{
	cin >> sodinh >> socanh >> dinhbatdau >> dinhketthuc;
	for (int i = 1; i <= socanh; i++)
	{
		char dinh1, dinh2;
		int trongso;
		cin >> dinh1 >> dinh2 >> trongso;
		adj[dinh1-'A'].push_back({dinh2,trongso});
		adj[dinh2-'A'].push_back({dinh1,trongso});
	}
}
void Dijkstra(int sodinh, int socanh, char dinhbatdau)
{
	vector<long long> d(sodinh , 1e9);
	d[dinhbatdau - 'A'] = 0;
	priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> Q;
	Q.push({ 0,dinhbatdau });
	while (!Q.empty())
	{
		pair<int, char> top = Q.top();
		Q.pop();
		char dinh_dang_xet = top.second;
		int trongso_duongdi_dinh_dangxet = top.first;
		if (trongso_duongdi_dinh_dangxet > d[dinh_dang_xet - 'A'])
			continue;
		for (auto it : adj[dinh_dang_xet - 'A'])
		{
			char dinh_ke = it.first;
			int trongso_ke = it.second;
			if (d[dinh_ke - 'A'] > d[dinh_dang_xet - 'A'] + trongso_ke)
			{
				d[dinh_ke - 'A'] = d[dinh_dang_xet - 'A'] + trongso_ke;
				Q.push({ d[dinh_ke - 'A'],dinh_ke });
			}
		}
	}
	for (auto it : d)
		cout << it << " ";
}
void Dijkstra_2_dinh(int sodinh, int socanh, char dinhbatdau,char dinhketthuc)
{
	vector<long long> d(sodinh, 1e9);
	d[dinhbatdau - 'A'] = 0;
	priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> Q;
	Q.push({ 0,dinhbatdau });
	char pre[100];
	pre[dinhbatdau - 'A'] = dinhbatdau;
	while (!Q.empty())
	{
		pair<int, char> top = Q.top();
		Q.pop();
		char dinh_dang_xet = top.second;
		int trongso_duongdi_dinh_dangxet = top.first;
		if (trongso_duongdi_dinh_dangxet > d[dinh_dang_xet - 'A'])
			continue;
		for (auto it : adj[dinh_dang_xet - 'A'])
		{
			char dinh_ke = it.first;
			int trongso_ke = it.second;
			if (d[dinh_ke - 'A'] > d[dinh_dang_xet - 'A'] + trongso_ke)
			{
				d[dinh_ke - 'A'] = d[dinh_dang_xet - 'A'] + trongso_ke;
				Q.push({ d[dinh_ke - 'A'],dinh_ke });
				pre[dinh_ke - 'A'] = dinh_dang_xet;
			}
		}
	}
	cout << d[dinhketthuc - 'A'] << endl;
	vector<char> DuongDi;
	while (true)
	{
		DuongDi.push_back(dinhketthuc);
		if (dinhketthuc == 'A')
			break;
		dinhketthuc = pre[dinhketthuc - 'A'];
	}
	reverse(begin(DuongDi), end(DuongDi));
	for (char x : DuongDi)
		cout << x << " ";
}
