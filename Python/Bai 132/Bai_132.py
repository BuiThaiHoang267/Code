import cmath
xA = float(input("Nhap xA: "))
yA = float(input("Nhap yA: "))
xB = float(input("Nhap xB: "))
yB = float(input("Nhap yB: "))
xC = float(input("Nhap xC: "))
yC = float(input("Nhap xC: "))
xM = float(input("Nhap xM: "))
yM = float(input("Nhap xM: "))
SABC = abs(xA*yB + xB*yC + xC*yA - xB*yA - xC*yB - xA*yC) / 2
SMAB = abs(xA*yB + xB*yM + xM*yA - xB*yA - xM*yB - xA*yM) / 2 
SMBC = abs(xM*yB + xB*yC + xC*yM - xB*yM - xC*yB - xM*yC) / 2 
SMAC = abs(xA*yM + xM*yC + xC*yA - xM*yA - xC*yM - xA*yC) / 2 
S = SABC + SMAC + SMBC + SMAB
if(S == SABC):
    print("M nam tron tam giac ABC")
print("M nam ngoai tam giac ABC")