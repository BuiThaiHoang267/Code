#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void Nhap(int** a, int m, int n) {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
}
void Xuat(int** a, int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int Kt8oXungQuanh(int** a, int m, int n,int i,int j);
void Sau1VongDoi(int** a, int m, int n);

int main() {
    int m, n, k;
    cin >> m >> n;
    //cap phat
    int** a = new int* [m + 2];
    for (int i = 0; i < m + 2; i++)
        a[i] = new int[n + 2];

    for (int i = 0; i < m + 2; i++){
        for (int j = 0; j < n + 2; j++) {
            if (i != 0 || i != m + 1) {
                a[i][0] = a[i][n + 1] = 0;
                break;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        a[0][i] = a[m + 1][i] = 0;
    }

    Nhap(a, m, n);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        Sau1VongDoi(a, m, n);
    }
    Xuat(a, m, n);
    for (int i = 0; i < m + 2; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

int Kt8oXungQuanh(int** a, int m, int n, int i,int j) {
    int dem = 0;
    if (a[i - 1][j - 1] == 1)
        dem++;
    if (a[i - 1][j] == 1)
        dem++;
    if (a[i - 1][j + 1] == 1)
        dem++;
    if (a[i][j - 1] == 1)
        dem++;
    if (a[i][j + 1] == 1)
        dem++;
    if (a[i + 1][j - 1] == 1)
        dem++;
    if (a[i + 1][j] == 1)
        dem++;
    if (a[i + 1][j + 1] ==1 )
        dem++;
    if (dem == 2)
        return 2;
    if (dem == 3)
        return 3;
    return 0;
}
void Sau1VongDoi(int** a, int m, int n) {
    stack<int> stack_i_die;
    stack<int> stack_j_die;
    stack<int> stack_i_add;
    stack<int> stack_j_add;
    for(int i=1;i<=m;i++)
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0 && Kt8oXungQuanh(a,m,n,i,j) == 3) {
                stack_i_add.push(i);
                stack_j_add.push(j);
            }
            if (a[i][j] == 1 && Kt8oXungQuanh(a, m, n, i, j) == 0) {
                stack_i_die.push(i);
                stack_j_die.push(j);
            }
        }
    while (!stack_i_add.empty()) {
        a[stack_i_add.top()][stack_j_add.top()] = 1;
        stack_i_add.pop();
        stack_j_add.pop();
    }
    while (!stack_i_die.empty()) {
        a[stack_i_die.top()][stack_j_die.top()] = 0;
        stack_i_die.pop();
        stack_j_die.pop();
    }
}