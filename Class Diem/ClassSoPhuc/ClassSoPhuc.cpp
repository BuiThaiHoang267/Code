#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class SoPhuc {
private:
	float thuc;
	float ao;
public:
	void Nhap() {
		cin >> thuc;
		cin >> ao;
	}
	void CanN(int n) {
		float k = 0;
		float d = 0;
		if (thuc == 0 && ao == 0) {
			for (int i = 0; i < n; i++)
				cout << 0 << " " << 0 << endl;
		}
		else {
			d = (float)sqrt(thuc * thuc + ao * ao);
			d = (float)pow(d, 1.0 / n);
			k = atan(ao / thuc);
			for (int i = 0; i < n; i++) {
				thuc = d * cos((k + i * 2 * 3.14159) / n);
				ao = d * sin((k + i * 2 * 3.14159) / n);
				if (abs(thuc) < 0.001) {
					thuc = 0;
					cout << thuc << " " << fixed << setprecision(2) << ao << endl;
				}
				else {
					thuc = round((thuc * 100)) / 100.0;
					ao = round((ao * 100)) / 100.0;
					cout << thuc << " " << ao << endl;
				}

			}
		}
	}
};

int main() {
	int n;
	SoPhuc A;
	A.Nhap();
	cin >> n;
	A.CanN(n);
	return 0;
}
