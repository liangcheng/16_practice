using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace three_elem_condition
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("please input a letter");
            char ch = Convert.ToChar(Console.ReadLine());

            ch = (char.IsUpper(ch)) ? char.ToLower(ch) : ch;

            Console.WriteLine(ch);

            
        }
    }
}
