using LopHoc;
using SinhVienSinhVienTN;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TruongHoc;

namespace SinhVienSinhVienTN
{
    public class SinhVien
    {
        public string Ten { get; set; }
        public string CTDaotao {  get; set; }
        public string Mssv { get; set; }
        public Truong Truong { get; set; }
        public Lop Lop { get; set; }
        public string Khoa { get; set; }
        public string NgaySinh { get; set; }
        public string Sdt { get; set; }
        public SinhVien()
        {
            Ten = string.Empty;
            Mssv = string.Empty;
            Truong = new Truong();
            Lop = new Lop();
            Khoa = string.Empty;
            NgaySinh = string.Empty;
            Sdt = string.Empty;
            CTDaotao = "Dai tra";
        }
        public virtual void Nhap()
        {
            Ten = Console.ReadLine();
            Mssv = Console.ReadLine();
            Truong.Nhap();
            Lop.Nhap();
            Khoa = Console.ReadLine();
            NgaySinh = Console.ReadLine();
            Sdt = Console.ReadLine();
        }
        public virtual void Xuat()
        {
            Console.WriteLine($"Ten: {Ten}");
            Console.WriteLine($"Mssv: {Mssv}");
            Truong.Xuat();
            Lop.Xuat();
            Console.WriteLine($"Chuong trinh dao tao: {CTDaotao}");
            Console.WriteLine($"Khoa: {Khoa}");
            Console.WriteLine($"Ngay sinh: {NgaySinh}");
            Console.WriteLine($"So dien thoai: {Sdt}");
        }
    }
}
public class SinhVienTN : SinhVien
{
    public double TroCap;
    public SinhVienTN()
    {
        TroCap = 0;
        CTDaotao = "Tai nang";
    }
    public override void Nhap()
    {
        base.Nhap();
        TroCap = double.Parse( Console.ReadLine() );
    }
    public override void Xuat()
    {
        base.Xuat();
        Console.WriteLine($"Tro cap hang thang: {TroCap} VND");
    }
}
