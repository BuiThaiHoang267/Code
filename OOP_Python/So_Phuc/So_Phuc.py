
class SoPhuc:
    def __init__(self, Thuc = 0, Ao = 0):
        self.thuc = Thuc
        self.ao = Ao

    def Nhap(self):
        self.thuc = float(input("Nhap phan thuc: "))
        self.ao = float(input("Nhap phan ao: "))

    def Xuat(self):
        if(self.ao >= 0):
            print(self.thuc," + ",self.ao,"i",sep = "")
        else:
            print(self.thuc," - ",abs(self.ao),"i",sep = "")

    def __add__(self, x):
        temp = SoPhuc()
        temp.thuc = self.thuc + x.thuc
        temp.ao = self.ao + x.ao
        return temp

    def __sub__(self, x):
        temp = SoPhuc()
        temp.thuc = self.thuc - x.thuc
        temp.ao = self.ao - x.ao
        return temp

    def __mul__(self, x):
        temp = SoPhuc()
        temp.thuc = self.thuc*x.thuc  - self.ao*x.ao
        temp.ao = self.thuc*x.ao + self.ao*x.thuc
        return temp

    def __truediv__(self, x):
        temp = SoPhuc()
        mau = x.thuc*x.thuc + x.ao*x.ao
        temp.thuc = (self.thuc*x.thuc  + self.ao*x.ao)/mau
        temp.ao = (self.ao*x.thuc - self.thuc*x.ao)/mau
        return temp

    def __iadd__(self, x):
        self.thuc = self.thuc + x.thuc
        self.ao = self.ao + x.ao
        return self

    def __isub__(self, x):
        self.thuc = self.thuc - x.thuc
        self.ao = self.ao - x.ao
        return self

    def __imul__(self, x):
        self.thuc = self.thuc*x.thuc  - self.ao*x.ao
        self.ao = self.thuc*x.ao + self.ao*x.thuc
        return self

    def __itruediv__(self, x):
        mau = x.thuc*x.thuc + x.ao*x.ao
        self.thuc = (self.thuc*x.thuc  + self.ao*x.ao)/mau
        self.ao = (self.ao*x.thuc - self.thuc*x.ao)/mau
        return self

def main():
    sp = SoPhuc()
    sp.Nhap()
    print("So phuc ban dau: ")
    sp.Xuat()

    x = SoPhuc(1,1)
    kq = SoPhuc()
    kq = sp + x
    print("sp1 + sp2 = ",end = "")
    kq.Xuat()

    kq = sp - x
    print("sp1 - sp2 = ",end = "")
    kq.Xuat()

    kq = sp * x
    print("sp1 * sp2 = ",end = "")
    kq.Xuat()

    kq = sp / x
    print("sp1 / sp2 = ",end = "")
    kq.Xuat()

    sp += x
    print("sp1 += x :",end = " ")
    sp.Xuat()

    sp -= x
    print("sp1 -= x :",end = " ")
    sp.Xuat()

    sp *= x
    print("sp1 *= x :",end = " ")
    sp.Xuat()

    sp /= x
    print("sp1 /= x :",end = " ")
    sp.Xuat()

    return

if __name__ == "__main__":
    main()