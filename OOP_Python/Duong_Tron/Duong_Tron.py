class Diem:
    def __init__(self):
        self.x = 0
        self.y = 0
    def Nhap(self):
        self.x = float(input("Nhap hoanh do x: "))
        self.y = float(input("Nhap tung do y: "))
    def Xuat(self):
        print("I(",self.x," ; ",self.y,")",sep = "")
    
class Circle:
    def __init__(self):
        self.I = Diem()
        self.R = 0
        self.S = 0
    def Nhap(self):
        print("Nhap tam duong tron I:")
        self.I.Nhap()
        self.R = float(input("Nhap ban kinh R: "))
    def DienTich(self):
        self.S = 3.14*self.R*self.R
    def __gt__(self, x):
        return (self.S > x.S)
    def __lt__(self, x):
        return (self.S < x.S)
    def __eq__(self, x):
        return (self.S == x.S)
    def __ne__(self, x):
        return (self.S != x.S)
    def __ge__(self, x):
        return (self.S >= x.S)
    def __le__(self, x):
        return (self.S <= x.S)

def main():
    dt1 = Circle()
    dt1.Nhap()
    dt2 = Circle()
    dt2.Nhap()
    dt1.DienTich()
    dt2.DienTich()
    if(dt1 > dt2):
        print("dt1 > dt2")
    if(dt1 < dt2):
        print("dt1 < dt2")
    if(dt1 == dt2):
        print("dt1  == dt2")
    if(dt1 != dt2):
        print("dt1 != dt2")
    if(dt1 >= dt2):
        print("dt1 >= dt2")
    if(dt1 <= dt2):
        print("dt1 <= dt2")

    return

if __name__ == "__main__":
    main()