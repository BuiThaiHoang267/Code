from CMay import CMay

def main():
    M = CMay()
    M.Nhap()
    M.Xuat()
    ms = int(input("Nhap ma so muon tim kiem: "))
    if(M.TimKiem(ms) != None):
        print("Chi tiet duoc tim kiem la:")
        M.TimKiem(ms).Xuat()
    else:
        print("Khong tim thay chi tiet may tuong ung!")
    print("Gia tri cua may:", M.TinhTien())
    return

if __name__ == "__main__":
    main()