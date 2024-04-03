import math
x = float(input("Nhap x: "))
n = int(input("Nhap n: "))
s = 0
t = x
i = 1
while(i <= n):
    t = math.sin(t)
    s = s + t
    i = i + 1
print("s = ",s)