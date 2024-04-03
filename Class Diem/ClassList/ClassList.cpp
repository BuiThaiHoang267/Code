#include<iostream>
#include<list>
using namespace std;

int main() {
	list<double> Numbers;
	int n;
	double x;
	while(true) {
		cin >> n;
		if (n == -1) {
			cout << "[";
			if (Numbers.size() != 0) {
				cout<< *Numbers.begin();
				for (auto it = ++Numbers.begin(); it != Numbers.end(); it++)
				{
					cout << "," << *it;
				}
			}
			cout << "]";

			return 0;
		}
		else if (n == 0) {
			cin >> x;
			Numbers.push_back(x);
		}
		else if (n == 1) {
			cin >> x;
			for (auto it = Numbers.begin(); it != Numbers.end(); it++)
			{
				if (*it == x) {
					Numbers.erase(it);
					break;
				}
			}
		}
		else if (n == 2) {
			cin >> x;
			int dem = 0;
			for (auto it = Numbers.begin(); it != Numbers.end(); it++)
			{
				if (*it == x) {
					dem++;
				}
			}
			for (int j = 0; j < dem; j++)
				for (auto it = Numbers.begin(); it != Numbers.end(); it++)
				{
					if (*it == x) {
						Numbers.erase(it);
						break;
					}
				}
		}
		else if (n == 3) {
			double y;
			cin >> x >> y;
			double dem = -1;
			for (auto it = Numbers.begin(); it != Numbers.end(); it++)
			{
				dem++;
				if (dem == x) {
					*it = y;
					break;
				}
			}
		}
	}
	return 0;
}