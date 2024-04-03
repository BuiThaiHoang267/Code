s = 0
e = 0.5
i = 2
while(e >= 0.000001):
    e = 1/i
    s = s + e
    i = i + 2
print("s = ",s)