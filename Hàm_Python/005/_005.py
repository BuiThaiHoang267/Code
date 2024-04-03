def Nhap():
	r = float(input('Ban kinh: '))
	return r

def TheTich(r):
	return 4 * 3.14 * r * r * r / 3

def main():
	r = Nhap()
	print('Dien tich xung quanh la: ', TheTich(r))

if __name__ == "__main__":
    main()