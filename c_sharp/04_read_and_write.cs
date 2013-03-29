using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace console_write
{
    class Program
    {
        static void Main(string[] args)
        {
            int bal = 100000;
            Console.WriteLine("bal");
            Console.WriteLine(bal);

            // print string
            Console.WriteLine('a');
            Console.WriteLine("a");
            Console.WriteLine("I love you.");

            // character
            char mys = 'x';
            Console.WriteLine(mys);

            // string
            string str1 = "How are you doing?";
            Console.WriteLine(str1);


            //Console.Write()
            Console.Write("line 1. ");
            Console.Write("line 2. \n");

            //read() read one character, readline() read string
            Console.WriteLine("Please input your name:");
            string name = Console.ReadLine();
            Console.WriteLine("Your name is " + name);

            // area of circle
            double r, s;
            Console.Write("r=");
            r = Convert.ToDouble(Console.ReadLine() );
            s = 3.14 * r * r;
            Console.WriteLine("s=" + s);
        }
    }
}
