#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef string BigNum;

BigNum Sum(long long);
char toChar(int);
int toNumber(char);
int compareBigNum(BigNum, BigNum);
BigNum addBigNum(BigNum, BigNum);
BigNum subBigNum(BigNum, BigNum);
BigNum mulBigNum(BigNum, long);
BigNum mulBigNum(BigNum, BigNum);
BigNum divBigNum(BigNum, long);
BigNum divBigNum(BigNum, BigNum);
long modBigNum(BigNum, long);
BigNum modBigNum(BigNum, BigNum);
BigNum toBigNum(unsigned long long);

int main()
{
	long long n;
	cout << "Nhap n: ";
	cin >> n;
	cout << endl;
	cout << "Tong uoc sp cua " << n << "! la: " << Sum(n);
	return 0;
}
BigNum toBigNum(unsigned long long n)
{
	BigNum temp = "";
	while (n > 0) {
		int dv = n % 10;
		temp = toChar(dv) + temp;
		n = n / 10;
	}
	return temp;
}
BigNum Sum(long long n)
{
	vector<long long> minprime(n + 1);
	for (long long p = 0; p <= n; p++)
		minprime[p] = p;
	for (long long p = 2; p * p <= n; p++)
		if (minprime[p] == p)
			for (long long i = p * p; i <= n; i += p)
				if (minprime[i] == i)
					minprime[i] = p;

	vector<long long> factoriprime;
	for (long long i = 2; i <= n; i++) {
		long long n = i;
		while (n > 1)
		{
			factoriprime.push_back(minprime[n]);
			n /= minprime[n];
		}
	}
	sort(factoriprime.begin(), factoriprime.end());

	BigNum T = "1";
	for (long long i = 0; i < factoriprime.size(); i++) {
		long long count = 0;
		for (int j = i; j < factoriprime.size(); j++) {
			if (factoriprime[i] == factoriprime[j]) {
				count++;
			}
			else {
				break;
			}
		}
		unsigned long long x= (pow(factoriprime[i], count + 1) - 1) / (factoriprime[i] - 1);
		BigNum temp = toBigNum(x);
		T = mulBigNum(T, temp);
		i = i + count - 1;
	}
	return T;
}


char toChar(int n)
{
	char l[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	return l[n];
}
int toNumber(char n)
{
	if (n == '0')
		return 0;
	if (n == '1')
		return 1;
	if (n == '2')
		return 2;
	if (n == '3')
		return 3;
	if (n == '4')
		return 4;
	if (n == '5')
		return 5;
	if (n == '6')
		return 6;
	if (n == '7')
		return 7;
	if (n == '8')
		return 8;
	if (n == '9')
		return 9;
	if (n == 'A')
		return 10;
	if (n == 'B')
		return 11;
	if (n == 'C')
		return 12;
	if (n == 'D')
		return 13;
	if (n == 'E')
		return 14;
	if (n == 'F')
		return 15;
}
int compareBigNum(BigNum  x, BigNum y)
{
	while (x.size() < y.size())
		x = '0' + x;
	while (x.size() > y.size())
		y = '0' + y;
	if (x > y)
		return 1;
	if (y > x)
		return -1;
	return 0;
}
BigNum addBigNum(BigNum x, BigNum y)
{
	while (x.size() < y.size())
		x = '0' + x;
	while (x.size() > y.size())
		y = '0' + y;

	int carry = 0;
	BigNum temp = "";
	for (int i = x.size() - 1; i >= 0; i--)
	{
		int xx = toNumber(x[i]);
		int yy = toNumber(y[i]);
		int ss = xx + yy + carry;

		temp = toChar(ss % 10) + temp; // chuyen hang don vi vao ben trai chuoi kq
		carry = ss / 10;
	}
	if (carry > 0)
		temp = '1' + temp;
	return temp;
}
BigNum subBigNum(BigNum x, BigNum y)
{
	while (x.size() < y.size())
		x = '0' + x;
	while (x.size() > y.size())
		y = '0' + y;

	int borrow = 0;
	BigNum temp = "";
	for (int i = x.size() - 1; i >= 0; i--)
	{
		int xx = toNumber(x[i]);
		int yy = toNumber(y[i]);
		int ss = xx - yy - borrow;
		if (ss < 0)
		{
			ss = ss + 10;
			borrow = 1;
		}
		else
			borrow = 0;
		temp = toChar(ss % 10) + temp;
	}
	while (temp.size() > 1 && temp[0] == '0')
		temp.erase(0, 1);
	return temp;
}
BigNum mulBigNum(BigNum x, long y)
{
	long carry = 0;
	BigNum temp = "";
	for (int i = x.size() - 1; i >= 0; i--)
	{
		int xx = toNumber(x[i]);
		long ss = xx * y + carry;

		temp = toChar(ss % 10) + temp;
		carry = ss / 10;
	}
	if (carry > 0)
		temp = to_string(carry) + temp;
	return temp;
}
BigNum mulBigNum(BigNum x, BigNum y)
{
	BigNum temp = "";
	BigNum zero = "";
	for (int i = x.size() - 1; i >= 0; i--) // lay ra tung so x nhan vs y
	{
		long xx = toNumber(x[i]);
		BigNum ss = mulBigNum(y, xx);
		ss = ss + zero;
		temp = addBigNum(temp, ss);
		zero = zero + '0';
	}
	return temp;
}
BigNum divBigNum(BigNum x, long y)
{
	BigNum temp = "";
	long hold = 0;
	long ss = 0;
	for (int i = 0; i < x.size(); i++)
	{
		hold = hold * 10 + toNumber(x[i]);
		ss = hold / y;
		temp = temp + toChar(ss);
		hold = hold % y;
	}
	while (temp.size() > 1 && temp[0] == '0')
		temp.erase(0, 1);
	return temp;
}
BigNum divBigNum(BigNum x, BigNum y)
{
	BigNum ky[11];
	ky[0] = "0";
	for (int i = 1; i <= 10; i++)
		ky[i] = addBigNum(ky[i - 1], y);

	BigNum temp = "";
	BigNum hold = "";
	for (int i = 0; i < x.size(); i++)
	{
		hold = hold + x[i];
		int k = 0;
		while (compareBigNum(hold, ky[k + 1]) != -1)
			k++;
		temp = temp + toChar(k);
		hold = subBigNum(hold, ky[k]);
	}
	while (temp.size() > 1 && temp[0] == '0')
		temp.erase(0, 1);
	return temp;
}
long modBigNum(BigNum x, long y)
{
	long hold = 0;
	for (int i = 0; i < x.size(); i++)
		hold = (hold * 10 + toNumber(x[i])) % y;
	return hold;
}
BigNum modBigNum(BigNum x, BigNum y)
{
	BigNum kY[11];
	kY[0] = "0";
	for (int i = 1; i <= 10; i++)
		kY[i] = addBigNum(kY[i - 1], y);

	BigNum hold = "";
	for (int i = 0; i < x.size(); i++)
	{
		hold = hold + x[i];
		int k = 0;
		while (compareBigNum(hold, kY[k + 1]) != -1)
			k++;
		hold = subBigNum(hold, kY[k]);
	}
	return hold;
}