from CChiTiet import CChiTiet

class CChiTietDon(CChiTiet):
    def __init__(self):
        super().__init__()
        self._GiaTien = 0

    def Nhap(self):
        super().Nhap()
        self._GiaTien = int(input("Nhap gia: "))

    def Xuat(self):
        super().Xuat()
        print("Gia:", self._GiaTien)

    def TinhTien(self):
        return self._GiaTien

    def TimKiem(self, ms):
        return super().TimKiem(ms)

