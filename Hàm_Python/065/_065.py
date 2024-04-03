
def Nhap():
    n = int(input("Nhap n: "))
    return n

def TimChuSoNhoNhat(t, lc):
    while (t != 0):
        dv = t % 10
        if (dv < lc):
            lc = dv
        t = int(t/10)
    return lc

def main():
    print("Bai 065")
    n = Nhap()
    lc = n % 10
    t = n
    print("Chu so nho nhat trong n la: ",TimChuSoNhoNhat(t, lc))

if __name__ == "__main__":
    main()
    
