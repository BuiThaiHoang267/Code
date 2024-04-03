n = int(input("Nhap n: "))
flag = 0
t = n
while (t != 0):
    dv = t % 10
    if (dv % 2 == 0):
        flag = 1
    t = int(t / 10)
if (flag == 1):
    print("TT")
else:
    print("Ko TT")