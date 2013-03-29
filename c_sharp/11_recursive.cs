using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace recursive
{
    class Program
    {
        static int Fac(int n)
        {
            if (n <= 1) return 1; // initial value
            else return n * Fac(n - 1);

        }

        static int Fibonacci(int n)
        {
            if ((n == 1) || (n == 2)) return 1; // initial
            else return (Fibonacci(n - 1) + Fibonacci(n - 2));
        }



        static void Main(string[] args)
        {
            int result = Fac(5);
            Console.WriteLine(result);

            result = Fibonacci(20);
            Console.WriteLine(result);

        }
    }
}
