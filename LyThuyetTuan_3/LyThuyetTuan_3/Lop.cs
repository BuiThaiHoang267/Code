using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LopHoc
{
    public class Lop
    {
        public string TenLop { get; set; }
        public int SiSo { get; set; }
        public string CVHT { get; set; }
        public Lop()
        {
            TenLop = string.Empty;
            SiSo = 0;
            CVHT = string.Empty;
        }
        public void Nhap()
        {
            TenLop = Console.ReadLine();
            SiSo = int.Parse(Console.ReadLine());
            CVHT = Console.ReadLine();
        }
        public void Xuat()
        {
            Console.WriteLine($"Lop: {TenLop}");
            Console.WriteLine($"Si so: {SiSo}");
            Console.WriteLine($"Co van hoc tap: {CVHT}");
        }
    }
}
