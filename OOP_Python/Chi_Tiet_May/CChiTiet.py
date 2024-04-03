class CChiTiet:
    def __init__(self):
        self._Maso = 0

    def Nhap(self):
        self._Maso = int(input("Nhap ma so: "))

    def Xuat(self):
        print("Ma so:",self._Maso)

    def TinhTien(self):
        return 0

    def TimKiem(self, ms):
        if(self._Maso == ms):
            return self
        else:
            return None