
def Nhap():
    x = int(input("Nhap x: "))
    y = int(input("Nhap y: "))
    z = int(input("Nhap z: "))
    return x, y, z

def KiemTra_TamGiac(x, y, z):
    if ( x+ y > z and x + z > y and y + z > x):
        return True
    return False

def main():
    print("Bai 130")
    x, y, z = Nhap()
    if (KiemTra_TamGiac(x, y, z) == True):
        print("La tam giac")
    else:
        print("Ko la tam giac")

if __name__ == "__main__":
    main()

