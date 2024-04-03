#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int sodinh, socanh;
vector<char> adj[100];
vector<bool> visited(100, false);

void Nhap() {
	cin >> sodinh >> socanh;
	for (int i = 0; i < socanh; i++)
	{
		char dinh1, dinh2;
		cin >> dinh1 >> dinh2;
		adj[dinh1 - 'A'].push_back(dinh2);
		adj[dinh2 - 'A'].push_back(dinh1);
	}
}

void dfs(char a)
{
	cout << a << " ";
	visited[a - 'A'] = true;
	for (char x : adj[a - 'A'])
	{
		if (visited[x - 'A'] == false)
			dfs(x);
	}
}

void bfs(char a)
{
	queue<char> q;
	q.push(a);
	visited[a - 'A'] = true;
	while (!q.empty())
	{
		char v = q.front();
		q.pop();
		cout << v << " ";
		for (char x : adj[v - 'A'])
		{
			if (visited[x - 'A'] == false)
			{
				q.push(x);
				visited[x - 'A'] = true;
			}
		}
	}
}

int main()
{
	Nhap();
	char x = 'A';
	bfs(x);
	return 0;
}