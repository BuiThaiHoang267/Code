#include<iostream>
#include<vector>
using namespace std;



int main()
{
	vector<vector<int>> l;

	for (int i = 0; i <= 3; i++) {
		vector<int> temp;
		temp.push_back(i);
		l.push_back(temp);
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			l[i].push_back(j);
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cout << l[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}