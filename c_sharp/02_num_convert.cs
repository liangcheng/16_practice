using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace convert_num
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Convert.ToInt32("110011",2));
            Console.WriteLine(Convert.ToInt32("567", 8));
            Console.WriteLine(Convert.ToInt32("6F", 16));

            Console.WriteLine(Convert.ToString(89,2));
            Console.WriteLine(Convert.ToString(89, 8));
            Console.WriteLine(Convert.ToString(89, 16));
        }
    }
}
