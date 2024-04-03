using System;

public class Program
{
    static int TongSoSP = 0;
    static int TongSoNLV = 0;

    public abstract class NhanVien
    {
        public string HoTen;

        public virtual void Nhap()
        {
            HoTen = Console.ReadLine();
        }

        public void Xuat()
        {
            //Console.WriteLine($"{HoTen}: {TinhLuong()}");
            Console.WriteLine("{0} : {1}", HoTen, TinhLuong());
        }

        public abstract float TinhLuong();
    }

    public class NVSX : NhanVien
    {
        public float LuongCB;
        public int SoSP;

        public override void Nhap()
        {
            base.Nhap();
            LuongCB = float.Parse(Console.ReadLine());
            SoSP = int.Parse(Console.ReadLine());
            TongSoSP += SoSP;
        }

        public override float TinhLuong()
        {
            return LuongCB + SoSP * 5;
        }
    }

    public class NVVP : NhanVien
    {
        public int SoNLV;

        public override void Nhap()
        {
            base.Nhap();
            SoNLV = int.Parse(Console.ReadLine());
            TongSoNLV += SoNLV;
        }

        public override float TinhLuong()
        {
            return SoNLV * 100;
        }
    }

    public class Sep : NhanVien
    {
        public override float TinhLuong()
        {
            return 100 + TongSoNLV * 40 + TongSoSP * 2;
        }
    }

    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        NhanVien[] dsNV = new NhanVien[n];

        for (int i = 0; i < n; i++)
        {
            int loai = int.Parse(Console.ReadLine());
            if (loai == 1)
            {
                dsNV[i] = new NVSX();
            }

            if (loai == 2)
            {
                dsNV[i] = new NVVP();
            }

            if (loai == 3)
            {
                dsNV[i] = new Sep();
            }

            dsNV[i].Nhap();
        }

        for (int i = 0; i < n; i++)
        {
            dsNV[i].Xuat();
        }
    }
}
