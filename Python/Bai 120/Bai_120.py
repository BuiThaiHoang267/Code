import cmath
n = int(input("Nhap n: "))
at = 2
i = 2
ahh = 2
while(i <= n):
    ahh = 5 * at + cmath.sqrt(24 * at * at - 8)
    i = i + 1
    at = ahh
print("ahh = ",ahh)