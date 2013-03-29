using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using class_creation;


namespace class_creation
{
    class Program
    {
        static void Main(string[] args)
        {
            Cat kitty = new Cat();
            kitty.name = "Kitty";
            //kitty.age = 3;
            kitty.Age = 3;
            Console.WriteLine("I am "+kitty.Age);

            //kitty.Meow();
            //kitty.ChaseMice();
            //kitty.ChaseMice();

        }
    }
}
