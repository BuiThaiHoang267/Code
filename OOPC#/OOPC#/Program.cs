using System;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using static Program;

class Program
{
    static int KiemTraTichNang = 0;
    public abstract class NguonDien
    {
        public int HieuSuat;
        public string Loai;
        public abstract void Nhap(string[] a);
        public abstract int CongSuat(int Gio, int TocDoGio,int May,int TongCongSuatTieuThu);
        public void XuatCongSuat(int Gio, int TocDoGio, int May, int TongCongSuatTieuThu)
        {
            Console.WriteLine(CongSuat(Gio, TocDoGio, May, TongCongSuatTieuThu));
        }
    }
    public class ThuyDien : NguonDien
    {
        public int SoToMay;
        public int TichNang;
        public ThuyDien()
        {
            Loai = "ThuyDien";
        }
        public override void Nhap(string[] a)
        {
            HieuSuat = int.Parse(a[1]);
            SoToMay = int.Parse(a[2]);
            TichNang = int.Parse(a[3]);
            if(TichNang == 1)
            {
                KiemTraTichNang++;
            }
        }
        public override int CongSuat(int Gio, int TocDoGio, int May, int TongCongSuatTieuThu)
        {
            return HieuSuat * SoToMay;
        }
    }
    public class NhietDien : NguonDien
    {
        public int SoLuongThan;
        public NhietDien()
        {
            Loai = "NhietDien";
        }
        public override void Nhap(string[] a)
        {
            HieuSuat = int.Parse(a[1]);
            SoLuongThan = int.Parse(a[2]);
        }
        public override int CongSuat(int Gio, int TocDoGio, int May, int TongCongSuatTieuThu)
        {
            return HieuSuat * SoLuongThan;
        }
    }
    public class DienGio : NguonDien
    {
        public int SoTuaBin;
        public int TocDoGioTD;
        public DienGio()
        {
            Loai = "DienGio";
        }
        public override void Nhap(string[] a)
        {
            HieuSuat = int.Parse(a[1]);
            SoTuaBin = int.Parse(a[2]);
            TocDoGioTD = int.Parse(a[3]);
        }
        public override int CongSuat(int Gio, int TocDoGio, int May, int TongCongSuatTieuThu)
        {
            float HieuSuatThuc = (float)HieuSuat * SoTuaBin * TocDoGio / TocDoGioTD;
            int temp = (int)Math.Round(HieuSuatThuc + 0.5f);
            return temp;
        }
    }
    public class DienMatTroi : NguonDien
    {
        public int DienTichPin;
        public DienMatTroi()
        {
            Loai = "DienMatTroi";
        }
        public override void Nhap(string[] a)
        {
            HieuSuat = int.Parse(a[1]);
            DienTichPin = int.Parse(a[2]);
        }
        public override int CongSuat(int Gio, int TocDoGio, int May, int TongCongSuatTieuThu)
        {
            int HieuSuatTD = HieuSuat * DienTichPin;
            float HieuSuatThuc = 0;
            if (May == 1 || Gio >= 18 || Gio <= 6)
                HieuSuatThuc = 0;
            else if (Gio >= 11 && Gio <= 13)
                HieuSuatThuc = HieuSuatTD;
            else if (Gio>=7 && Gio <= 10)
            {
                HieuSuatThuc = (float)HieuSuatTD * (Gio - 6) / 5.0f;
            }
            else
            {
                HieuSuatThuc = (float)HieuSuatTD - HieuSuatTD * (Gio - 13) / 5.0f;
            }
            int temp = (int)Math.Round(HieuSuatThuc);
            return temp;
        }
    }
    public class NgoaiCanh
    {
        public int Gio;
        public int TocDoGio;
        public int May;
        public int TongCongSuatTieuThu;
        public void Nhap()
        {
            string[] a = Console.ReadLine().Split(' ');
            Gio = int.Parse(a[0]);
            TocDoGio = int.Parse(a[1]);
            May = int.Parse(a[2]);
            TongCongSuatTieuThu = int.Parse(a[3]);
        }
        public void Xuat()
        {
            Console.WriteLine($"{Gio} {TocDoGio} {May} {TongCongSuatTieuThu}");
        }
    }
    public static void Main()
    {
        int SoNguonDien;
        int SoGio;
        SoNguonDien = int.Parse(Console.ReadLine());
        NguonDien[] D = new NguonDien[SoNguonDien];
        // Nhap du lieu
        int LoaiNguonDien;
        for (int i = 0; i < SoNguonDien; i++)
        {
            string[] a = Console.ReadLine().Split(' ');
            LoaiNguonDien = int.Parse(a[0]);
            if (LoaiNguonDien == 1)
                D[i] = new ThuyDien();
            if (LoaiNguonDien == 2)
                D[i] = new NhietDien();
            if (LoaiNguonDien == 3)
                D[i] = new DienGio();
            if (LoaiNguonDien == 4)
                D[i] = new DienMatTroi();
            D[i].Nhap(a);
        }
        SoGio = int.Parse(Console.ReadLine());
        NgoaiCanh[] N =new NgoaiCanh[SoGio];
        for(int i = 0;i < SoGio; i++)
        {
            N[i]= new NgoaiCanh();
            N[i].Nhap();
        }
        // Xu ly
        double TongThu = 0;
        int TongCongSuatPhatDien = 0;
        int DienDuTru = 0;
        int TongCongSuatPhatDienTruocDo = 0;
        // Gio Dau Tien
        TongCongSuatPhatDien = TongCongSuatPhatDien1(D, N, SoNguonDien, 0);
        if(TongCongSuatPhatDien > N[0].TongCongSuatTieuThu)
        {
            TongThu += (double)N[0].TongCongSuatTieuThu * 1000 * 3000;
            if(KiemTraTichNang != 0)
            {
                DienDuTru += TongCongSuatPhatDien - N[0].TongCongSuatTieuThu;
            }
        }
        else
        {
            float HieuSuatCungCap = (float)TongCongSuatPhatDien / N[0].TongCongSuatTieuThu;
            if (HieuSuatCungCap >= 0.8f)
                TongThu += TongCongSuatPhatDien * 1000 * 3000;
            else if (HieuSuatCungCap <= 0.5f)
                TongThu += TongCongSuatPhatDien * 1000 * 2000;
            else
                TongThu += TongCongSuatPhatDien * 1000 * 2500;
        }
        TongCongSuatPhatDienTruocDo = TongCongSuatPhatDien;
        // Cac gio tiep theo
        int ThoiGianQuaTai = 0;
        for(int i = 1; i < SoGio; i++)
        {
            if (ThoiGianQuaTai <= 0)
            {
                TongCongSuatPhatDien = TongCongSuatPhatDien1(D, N, SoNguonDien, i);
            }
            else
            {
                TongCongSuatPhatDien = TongCongSuatPhatDien2(D, N, SoNguonDien, i);
            }
            float temp = (float)TongCongSuatPhatDien / TongCongSuatPhatDienTruocDo;
            TongCongSuatPhatDien += DienDuTru;
            if (temp < 0.8f || temp > 1.2f)
                ThoiGianQuaTai = 2;
            else
                ThoiGianQuaTai--;
            if(TongCongSuatPhatDien > N[i].TongCongSuatTieuThu)
            {
                TongThu += N[i].TongCongSuatTieuThu * 1000 * 3000;
                if (KiemTraTichNang != 0)
                {
                    DienDuTru = TongCongSuatPhatDien - N[i].TongCongSuatTieuThu;
                }
            }
            else
            {
                float HieuSuatCungCap = (float)TongCongSuatPhatDien / N[i].TongCongSuatTieuThu;
                if (HieuSuatCungCap >= 0.8f)
                    TongThu += TongCongSuatPhatDien * 1000 * 3000;
                else if (HieuSuatCungCap <= 0.5f)
                    TongThu += TongCongSuatPhatDien * 1000 * 2000;
                else
                    TongThu += TongCongSuatPhatDien * 1000 * 2500;
            }
            TongCongSuatPhatDienTruocDo = TongCongSuatPhatDien;
        }
        Console.WriteLine(TongThu);
    }
    public static int TongCongSuatPhatDien1(NguonDien[] D, NgoaiCanh[] N, int SoNguonDien, int k)
    {
        int TongCongSuatPhatDien = 0;
        for (int i = 0; i < SoNguonDien; i++)
        {
            TongCongSuatPhatDien += D[i].CongSuat(N[k].Gio, N[k].TocDoGio, N[k].May, N[k].TongCongSuatTieuThu);
        }
        return TongCongSuatPhatDien;
    }
    public static int TongCongSuatPhatDien2(NguonDien[] D, NgoaiCanh[] N, int SoNguonDien, int k)
    {
        int TongCongSuatPhatDien = 0;
        for (int i = 0; i < SoNguonDien; i++)
        {
            if (D[i].Loai == "ThuyDien" || D[i].Loai == "NhietDien")
                TongCongSuatPhatDien += D[i].CongSuat(N[k].Gio, N[k].TocDoGio, N[k].May, N[k].TongCongSuatTieuThu);
        }
        return TongCongSuatPhatDien;
    }
}