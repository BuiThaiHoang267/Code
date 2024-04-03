#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class SoPhuc {
public:
	float thuc;
	float ao;
	SoPhuc() {
		thuc = ao = 0;
	}
	void Nhapsp() {
		cin >> thuc;
		cin >> ao;
	}
	SoPhuc operator+(SoPhuc b) {
		SoPhuc temp;
		temp.thuc = thuc + b.thuc;
		temp.ao = ao + b.ao;
		return temp;
	}
	SoPhuc operator*(SoPhuc b) {
		SoPhuc temp;
		temp.thuc = thuc * b.thuc - ao * b.ao;
		temp.ao = ao * b.thuc + thuc * b.ao;
		return temp;
	}
	void Xuatsp() {
		cout << thuc << " " << ao<<" ";
	}
};

class MaTran {
public:
	int type;
	SoPhuc A[10][10];
	int m, n;
	MaTran() {
		type = 0;
		m = n = 1;
	}
	void Nhap();
	MaTran ChuyenVi();
	MaTran ChuyenViBra();
	MaTran Scalar_x_Matrix(MaTran);
	MaTran Matrix_x_Scalar(MaTran);
	MaTran Matrix_x_Matrix(MaTran);
	MaTran Ket_x_Bra(MaTran);
	MaTran Ket_x_Ket(MaTran);
	MaTran Bra_x_Bra(MaTran);
	void Xuat() {
		if (n == 1&& m>1)
			*this = ChuyenViBra();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				A[i][j].Xuatsp();
			cout << endl;
		}
	}
};
MaTran TinhBT(string, MaTran[]);

int main() {
	int N;
	cin >> N;
	MaTran* a = new MaTran[N];
	for (int i = 0; i < N; i++) {
		a[i].Nhap();
	}
	string expression;
	cin.ignore();
	cin >> expression;
	MaTran temp = TinhBT(expression, a);
	temp.Xuat();
	return 0;
}
void MaTran::Nhap() {
	cin >> type;
	if (type == 1) {	
		m = n = 1;
		A[0][0].Nhapsp();
	}
	if (type == 2) {
		cin >> n;
		m = 1;
		for (int i = 0; i < n; i++)
			A[0][i].Nhapsp();
	}
	if (type == 3) {
		cin >> n;
		m = n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				A[i][j].Nhapsp();
	}
}
MaTran MaTran::ChuyenViBra() {
	MaTran temp;
	temp.m = 1;
	temp.n = m;
	for (int i = 0; i < m; i++) {
		temp.A[0][i] = A[i][0];
		temp.A[0][i].ao = -temp.A[0][i].ao;
	}
	return temp;
}
MaTran MaTran::ChuyenVi() {
	MaTran temp;
	temp.n = 1;
	temp.m = n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			temp.A[j][i] = A[i][j];
			temp.A[j][i].ao = -temp.A[j][i].ao;
		}
	return temp;
}
MaTran MaTran::Scalar_x_Matrix(MaTran s) {
	MaTran temp;
	temp.m = s.m;
	temp.n = s.n;
	for (int i = 0; i < s.m; i++)
		for (int j = 0; j < s.n; j++)
			temp.A[i][j] = A[0][0] * s.A[i][j];
	return temp;
}
MaTran MaTran::Matrix_x_Scalar(MaTran s) {
	MaTran temp;
	temp.m = m;
	temp.n = n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			temp.A[i][j] = A[i][j] * s.A[0][0];
	return temp;
}
MaTran MaTran::Matrix_x_Matrix(MaTran s) {
	MaTran temp;
	temp.m = m;
	temp.n = s.n;
	for(int i=0;i<m;i++)
		for (int j = 0; j < s.n; j++)
			for (int z = 0; z < n; z++) 
				temp.A[i][j] = temp.A[i][j] + A[i][z] * s.A[z][j];
	return temp;
}
MaTran MaTran::Ket_x_Bra(MaTran s) {
	MaTran temp;
	temp.m = m;
	temp.n = s.n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < s.n; j++)
			temp.A[i][j] = A[i][0] * s.A[0][j];
	return temp;
}
MaTran MaTran::Ket_x_Ket(MaTran s) {
	MaTran temp;
	temp.m = m * s.m;
	temp.n = 1;
	int t = 0;
	for (int z = 0; z < m; z++)
		for (int i = 0; i < s.m; i++)
			temp.A[t++][0] = A[z][0] * s.A[i][0];
	return temp;
}
MaTran MaTran::Bra_x_Bra(MaTran s) {
	MaTran temp;
	temp.m = 1;
	temp.n = n*s.n;
	int t = 0;
	for (int z = 0; z < n; z++)
		for (int i = 0; i < s.n; i++)
			temp.A[0][t++] = A[0][z] * s.A[0][i];
	return temp;
}
MaTran TinhBT(string s, MaTran a[]) {
	vector<MaTran> kq;
	int Size = s.size();
	for (int i = 0; i < Size; i++) {
		if (s[i] == '|' && s[i + 2] == '>') {
			kq.push_back(a[s[i + 1] - 'a'].ChuyenVi());
			i = i + 2;
		}
		else if (i>0 && s[i - 1] == '|' && s[i + 1] == '>') {
			kq.push_back(a[s[i] - 'a'].ChuyenVi());
			i = i + 1;
		}
		else if (s[i] == '<') {
			kq.push_back(a[s[i + 1] - 'a']);
			i = i + 2;
		}
		else if (s[i] == '|' && s[i + 2] == '|') {
			kq.push_back(a[s[i + 1] - 'a']);
			i = i + 2;
		}
		else if (i>0 && s[i-1] == '|' && s[i + 1] == '|') {
			kq.push_back(a[s[i ] - 'a']);
			i = i + 1;
		}
		else
			kq.push_back(a[s[i] - 'a']);
	}
	MaTran KQ = kq[0];
	int sizekq = kq.size();
	for (int i = 1; i < sizekq; i++) {
		if (KQ.m == 1 && KQ.n == 1) {
			KQ = KQ.Scalar_x_Matrix(kq[i]);
		}
		else if (kq[i].m == 1 && kq[i].n == 1) {
			KQ = KQ.Matrix_x_Scalar(kq[i]);
		}
		else if (KQ.m > 1 && KQ.n == 1 && kq[i].m > 1 && kq[i].n == 1) {
			KQ = KQ.Ket_x_Ket(kq[i]);
		}
		else if (KQ.n == kq[i].m && KQ.n > 1) {
			KQ = KQ.Matrix_x_Matrix(kq[i]);
		}
		else if (KQ.m > 1 && KQ.n == 1 && kq[i].m == 1 && kq[i].n > 1) {
			KQ = KQ.Ket_x_Bra(kq[i]);
		}
		else if (KQ.m == 1 && KQ.n > 1 && kq[i].m == 1 && kq[i].n > 1) {
			KQ = KQ.Bra_x_Bra(kq[i]);
		}
	}
	return KQ;
}