
def Nhap():
	n = int(input('Nhap n: '))
	return n

def Tong(n):
	s = 0
	for i in range(1, n + 1):
		s = s + i
	return s

def main():
	n = Nhap()
	print('Tong la: ', Tong(n))

if __name__ == "__main__":
    main()