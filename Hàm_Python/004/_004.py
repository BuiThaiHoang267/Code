def Nhap():
	r = float(input('Ban kinh: '))
	return r

def DienTichXungQuanh(r):
	return 4 * 3.14 * r * r

def main():
	r = Nhap()
	print('Dien tich xung quanh la: ', DienTichXungQuanh(r))

if __name__ == "__main__":
    main()