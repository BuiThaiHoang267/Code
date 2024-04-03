def Nhap():
	r = float(input('Ban kinh: '))
	return r

def ChuVi(r):
	return 2 * 3.14 * r

def main():
	r = Nhap()
	print('Chu vi duong tron la: ', ChuVi(r))

if __name__ == "__main__":
    main()