from CMachDien import CMachDien
from CDienTro import CDienTro
class CMachSongSong(CMachDien):
    def __init__(self):
        self._n = 0
        self._ds = []

    def Nhap(self):
        self._n = int(input("Nhap so luong thanh phan mach song song: "))
        for i in range(self._n):
            print("Nhap thanh phan thu: ",i+1)
            type = int(input("Nhap loai(0. NoiTiep, 1. SongSong, 2. DienTro): "))
            if(type == 0):
                from CMachNoiTiep import CMachNoiTiep
                temp = CMachNoiTiep()
            elif(type == 1):
                temp = CMachSongSong()
            else:
                temp = CDienTro()
            temp.Nhap()
            self._ds.append(temp)

    def Xuat(self):
        print("So chi tiet thanh phan:",self._n)
        for x in self._ds:
            x.Xuat()

    def Tinh_R(self):
        s = 0
        for x in self._ds:
            s += 1/x.Tinh_R()
        return 1/s