using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CalculatorMachine;


namespace CalculatorConsoleTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Demo Unit Menggunakan App Console";
            Calculator cal = new Calculator();

            Console.WriteLine("Hasil penambahan 2 + 3 ={0}", cal.Penambahan(2, 3));
            Console.WriteLine("Hasil pengurangan 7 - 3 ={0}", cal.Pengurangan(7, 3));
            Console.WriteLine("Hasil perkalian 5 x 2 ={0}", cal.Perkalian(5, 2));
            Console.WriteLine("Hasil pembagian 6 : 2 ={0}", cal.Pembagian(6, 2));

            Console.ReadKey();
        }
    }
}