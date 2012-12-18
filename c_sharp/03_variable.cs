using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace variable
{
    class Program
    {
        static void Main(string[] args)
        {
            // a, b sum, sub, multiplication, and divided
            int a = 7;
            int b = 2;
            int sum, dif, pro, quo;

            sum = a + b;
            dif = a - b;
            pro = a * b;
            quo = a / b;

            Console.WriteLine("{0}+{1} = {2}", a, b,sum);
            Console.WriteLine("{0}-{1} = {2}", a, b, dif);
            Console.WriteLine("{0}*{1} = {2}", a, b, pro);
            Console.WriteLine("{0}/{1} = {2}", a, b, quo);
        }
    }
}
