from CMachDien import CMachDien
from CMachNoiTiep import CMachNoiTiep
from CDienTro import CDienTro
from CMachSongSong import CMachSongSong

def main():
    type = int(input("Nhap loai(0. NoiTiep, 1. SongSong, 2. DienTro): "))
    if(type == 0):
       C = CMachNoiTiep()
    elif(type == 1):
       C = CMachSongSong()
    else:
       C = CDienTro()
    C.Nhap()
    print("Mach dien: ")
    C.Xuat()
    kq = C.Tinh_R()
    print("Dien tro cua mach R =",kq)
    return

if __name__ == "__main__":
    main()