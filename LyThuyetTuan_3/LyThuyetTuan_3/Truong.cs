using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TruongHoc
{
    public class Truong
    {
        public string TenTruong { get; set; }
        public string DiaChi { get; set; }
        public Truong()
        {
            TenTruong = string.Empty;
            DiaChi = string.Empty;
        }
        public void Nhap()
        {
            TenTruong = Console.ReadLine();
            DiaChi = Console.ReadLine();
        }
        public void Xuat()
        {
            Console.WriteLine($"Truong: {TenTruong}");
            Console.WriteLine($"Dia chi: {DiaChi}");
        }

    }
}

