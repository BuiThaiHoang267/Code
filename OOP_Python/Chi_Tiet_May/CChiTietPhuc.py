from CChiTiet import CChiTiet
from CChiTietDon import CChiTietDon
class CChiTietPhuc(CChiTiet):
    def __init__(self):
        super().__init__()
        self._n = 0
        self._ds = []

    def Nhap(self):
        super().Nhap()
        self._n = int(input("Nhap so luong thnah phan: "))
        for i in range(self._n):
            type = int(input("Nhap loai (0. Don, 1. Phuc): "))
            if type == 0:
                temp = CChiTietDon()
            else:
                temp = CChiTietPhuc()
            temp.Nhap()
            self._ds.append(temp)

    def Xuat(self):
        super().Xuat()
        print("So luong thanh phan chi tiet phuc:",self._n)
        for x in self._ds:
            x.Xuat()

    def TinhTien(self):
        s = 0
        for x in self._ds:
            s = x.TinhTien()
        return s

    def TimKiem(self, ms):
        if self._Maso == ms:
            return self
        for x in self._ds:
            if x.TimKiem(ms) != None:
                return x.TimKiem(ms)
        return None
