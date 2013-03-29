using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace math
{
    class Program
    {
        static void Main(string[] args)
        {
            double x, y;
            Console.Write("input x please \n");
            x = Convert.ToDouble( Console.ReadLine());
            y = x*x*x+3*x*x + 24*x +10;
            Console.WriteLine(y);


            //sqrt
            Console.WriteLine("sqrt(9) = "+ Math.Sqrt(9));
        }
    }
}
