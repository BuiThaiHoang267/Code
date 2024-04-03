using LopHoc;
using SinhVienSinhVienTN;
using System;
using TruongHoc;

namespace Quanly
{
    public class Program
    {
        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            SinhVien[] sv = new SinhVien[n];
            for(int i = 0; i < n; i++)
            {
                int loai = int.Parse(Console.ReadLine());
                if (loai == 1)
                    sv[i] = new SinhVienTN();
                else
                    sv[i] = new SinhVien();
                sv[i].Nhap();
            }
            for(int i = 0;i < n; i++)
            {
                sv[i].Xuat();
            }
        }
    }
}

