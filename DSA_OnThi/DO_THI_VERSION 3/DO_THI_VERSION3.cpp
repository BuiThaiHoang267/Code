#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<set>
using namespace std;

map < string, set<pair<string, int>>> adj;
void Nhap(int&, int&, string&, string&);
void Dijkstra_2_dinh(int sodinh, int socanh, string dinhbatdau, string dinhketthuc);

int main()
{
	int SoDinh, SoCanh;
	string DinhBatDau, DinhKetThuc;
	Nhap(SoDinh, SoCanh, DinhBatDau, DinhKetThuc);
	Dijkstra_2_dinh(SoDinh, SoCanh, DinhBatDau, DinhKetThuc);
	return 0;
}
void Nhap(int& sodinh, int& socanh, string& dinhbatdau, string& dinhketthuc)
{
	cin >> sodinh >> socanh >> dinhbatdau >> dinhketthuc;
	//cout << sodinh << " " << socanh << " " << dinhbatdau << " " << dinhketthuc;
	for (int i = 1; i <= socanh; i++)
	{
		string dinh1, dinh2;
		int trongso;
		cin >> dinh1 >> dinh2 >> trongso;
		adj[dinh1].insert({ dinh2,trongso });
		adj[dinh2].insert({ dinh1,trongso });
	}
}
void Dijkstra_2_dinh(int sodinh, int socanh, string dinhbatdau, string dinhketthuc)
{
	map < string, int> d;
	for (auto x : adj)
		d[x.first] = 1e9;
	d[dinhbatdau] = 0;
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> Q;
	Q.push({ 0,dinhbatdau });
	while (!Q.empty())
	{
		pair<int,string> top = Q.top();
		Q.pop();
		string dinhxet = top.second;
		int trongsoduong = top.first;
		if (trongsoduong > d[dinhxet])
			continue;
		for (auto x : adj[dinhxet])
		{
			string dinhke = x.first;
			int trongso = x.second;
			if (d[dinhke] > d[dinhxet] + trongso)
			{
				d[dinhke] = d[dinhxet] + trongso;
				Q.push({ d[dinhke],dinhke });
			}
		}
	}
	for (auto x : d)
		cout << x.second << " ";
}