from CChiTiet import CChiTiet
from CChiTietDon import CChiTietDon
from CChiTietPhuc import CChiTietPhuc
class CMay:
    def __init__(self):
        self._n = 0
        self._ds = []

    def Nhap(self):
        self._n = int(input("Nhap so luong chi tiet: "))
        for i in range(self._n):
            type = int(input("Nhap loai (0. Don, 1. Phuc): "))
            if type == 0:
                temp = CChiTietDon()
            else:
                temp = CChiTietPhuc()
            temp.Nhap()
            self._ds.append(temp)

    def Xuat(self):
        print("So luong chi tiet:", self._n)
        for x in self._ds:
            x.Xuat()

    def TinhTien(self):
        s = 0
        for x in self._ds:
            s += x.TinhTien()
        return s

    def TimKiem(self, ms):
        for x in self._ds:
            if(x.TimKiem(ms) != None):
                return x.TimKiem(ms)
        return None
