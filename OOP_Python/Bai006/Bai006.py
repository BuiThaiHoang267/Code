class CHocSinh:
    def __init__(self):
        self.HoTen = ""
        self.Toan = 0
        self.Van = 0
        self.DiemTrungBinh = 0
    def Nhap(self):
        self.HoTen = input("Nhap ho ten: ")
        self.Toan = float(input("Nhap toan: "))
        self.Van = float(input("Nhap van: "))
    def Xuly(self):
        self.DiemTrungBinh = (self.Toan+self.Van)/2
    def Xuat(self):
        print("Ho ten: ",self.HoTen)
        print("Toan: ",self.Toan)
        print("Van: ",self.Van)
        print("Diem trung binh: ",self.DiemTrungBinh)

def main():
    hs = CHocSinh()
    hs.Nhap()
    hs.Xuly()

if __name__ == "__main__":
    main()