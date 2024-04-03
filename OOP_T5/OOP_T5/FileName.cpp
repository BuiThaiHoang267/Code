#include <iostream>
using namespace std;
class Dummy {
public:
    int x;
    void Nhap();
};
void Dummy::Nhap() {
    cout << "Nhap x: ";
    cin >> x;
}

void main() {
    
    Dummy a[10];
    for (int i = 0; i < 10; i++) {
        a[i].Nhap();
    }
}
