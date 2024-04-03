#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> DotConTruongThanh;
	int SoLuong;
	int SoConTruongThanh;
	int Luot;
	cin >> SoLuong;
	cin >> Luot;
	int Sua = 0;
	SoConTruongThanh = SoLuong;
	for (int i = 1; i <= Luot; i++) {
		if (i >= 5) {
			SoConTruongThanh = SoConTruongThanh + DotConTruongThanh.front();
			DotConTruongThanh.pop();
		}
		DotConTruongThanh.push(SoConTruongThanh / 2);
		Sua = Sua + SoConTruongThanh * 10;
	}
	cout << Sua;
	return 0;
}