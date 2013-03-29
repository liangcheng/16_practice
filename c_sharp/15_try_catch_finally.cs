using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace try_catch_finaly
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                //Console.Write("input denominator:");
                //int denominator = Convert.ToInt32(Console.ReadLine());
                int denominator = 1;                
                double result = 100 / denominator;
                if ((result<0)||(result>10))
                {throw new IndexOutOfRangeException();}
                else
                {Console.WriteLine("result: 100/{0}={1}", denominator, result);}
            }
            catch (IndexOutOfRangeException) { Console.WriteLine("your input is out of range.\nThanks!"); }
            catch (DivideByZeroException)
            {
                Console.WriteLine("denominator can not be zero!");
            }
            catch (FormatException)
            {
                Console.WriteLine("incorrect format!");
            }
            finally { Console.WriteLine("This is finally block."); } //must execuate

        }
    }
}
