using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace equal
{
    class Program
    {
        static void Main(string[] args)
        {
            cde f1 = new cde(2);
            cde f2 = new cde(2);
            //cde f2 = f1;
            Console.WriteLine(ReferenceEquals(f1, f2)); //static method, object class
            Console.WriteLine(f1.Equals(f2)); //instance method
            Console.WriteLine(cde.Equals(f1,f2)); //static method
            Console.WriteLine(f1 == f2); // yun suan fu method
        }
    }

    class cde
    {
        int a;
        public cde(int b) { a = b; }
        public override bool Equals(object obj)
        {
            //return base.Equals(obj);
            if ((obj == null) || obj.GetType() != typeof(cde)) return false;
            cde f3 = (cde)obj;
            if (f3.a == this.a) return true;
            else return false;
        }
    }
}
