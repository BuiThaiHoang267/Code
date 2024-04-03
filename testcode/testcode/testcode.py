
def Nhap():
    m, n = map(int, input().split())
    a = []
    temp = [-1e9]*n
    a.append(temp)
    for _ in range(1, m+1):
        row = list(map(int, input().split()))
        a.append(row)
    a.append(temp)
    return m, n, a

def Dath(a,i,j,n):

    if(j == n-1):
        return a[i][n-1]
    d = a[i][j]

    max_values = max(a[i][j+1], a[i-1][j+1], a[i+1][j+1])

    x = y = z = -1
    if(max_values == a[i][j+1]):
        x = Dath(a,i,j+1,n)
    if(max_values == a[i-1][j+1]):
        y = Dath(a,i-1,j+1,n)
    if(max_values == a[i+1][j+1]):
        z = Dath(a,i+1,j+1,n)
    temp = max(x,y,z)
    return d + temp

def MaxDath(m,n,a):
    d = -1e9
    for i in range(1,m+1):
        temp = Dath(a,i,0,n)
        if temp > d:
            d = temp
    return d
        

def main():
    m, n, a = Nhap()
    kq = MaxDath(m,n,a)
    print(int(kq))
    return

if __name__ == "__main__":
    main()