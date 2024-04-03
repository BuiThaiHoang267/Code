from CMachDien import CMachDien

class CDienTro(CMachDien):
    def __init__(self):
        self._MaSo = 0
        self._R = 0.0

    def Nhap(self):
        self._MaSo = input("Nhap ma so: ")
        self._R = float(input("Nhap R: "))

    def Xuat(self):
        print("Ma so:",self._MaSo)
        print("R = ",self._R)

    def Tinh_R(self):
        return self._R
