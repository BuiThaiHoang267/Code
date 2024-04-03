class CPhanSo:
    def __init__(self):
        self.Tu = 0
        self.Mau = 0
    def Nhap(self):
        self.Tu = int(input("Nhap tu: "))
        self.Mau = int(input("Nhap mau: "))
    def RutGon(self):
        a = int(abs(self.Tu))
        b = int(abs(self .Mau))
        while(a!=b):
            if(a > b):
                a = a - b
            else:
                b = b - a
        self.Tu = int(self.Tu / a)
        self.Mau = int(self.Mau / a)
        if(self.Tu*self.Mau < 0):
            self.Tu = -abs(self.Tu)
            self.Mau = abs(self.Mau)
    def Xuat(self):
        print(self.Tu,"/",self.Mau,sep="")

def main():
    ps = CPhanSo()
    ps.Nhap()
    print("Phan so truoc khi rut gon: ",end = ' ')
    ps.Xuat()
    ps.RutGon()
    print("Phan so sau khi rut gon: ", end = ' ')
    ps.Xuat()

if __name__ == "__main__":
    main()