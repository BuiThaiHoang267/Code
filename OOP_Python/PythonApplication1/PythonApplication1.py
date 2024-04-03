
class CDate:
    def __init__(self, Day = 0,Month = 0, Year = 0):
        self.day = Day
        self.month = Month
        self.year = Year

    def Nhap(self):
        self.day = int(input("Nhap ngay: "))
        self.month = int(input("Nhap thang: "))
        self.year = int(input("Nhap nam: "))

    def KtNamNhuan(self):
        if(self.year % 100 !=0 and self.year % 4 ==0):
            return True
        if(self.year % 400 == 0):
            return True
        return False

    def Next_Day(self):
        temp = CDate(self.day,self.month,self.year)
        a = [0,31,28,31,30,31,30,31,31,30,31,30,31]
        if(temp.KtNamNhuan()==True):
            a[2] += 1
        temp.day += 1
        if(temp.day > a[temp.month]):
            temp.month +=1
            temp.day = 1
            if(temp.month > 12):
                temp.year += 1
                temp.month = 1
        return temp

    def Before_Day(self):
        temp = CDate(self.day,self.month,self.year)
        a = [0,31,28,31,30,31,30,31,31,30,31,30,31]
        if(temp.KtNamNhuan()==True):
            a[2] += 1
        temp.day -= 1
        if(temp.day == 0):
            temp.month -= 1
            if(temp.month == 0):
                temp.year -= 1
                temp.month = 12
            temp.day = a[temp.month]
        return temp

    def Xuat(self):
        print(self.day,'/',self.month,'/',self.year,sep="")
    def __str__(self):
        return f"{self.day}/{self.month}/{self.year}"
    def __del__(self):
        print("",end = "")

def main():
    D = CDate()
    D.Nhap()
    print("Ngay hien tai: ", end = "")
    D.Xuat()
    print("Ngay ke tiep:",D.Next_Day())
    print("Ngay truoc do:",D.Before_Day())
    return

if __name__ == "__main__":
    main()
