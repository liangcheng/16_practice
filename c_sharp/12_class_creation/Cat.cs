using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace class_creation
{
    class Cat
    {
        public string name;
        public int age;
        private int miceCount = 0;

        public Cat(string nameValue, int ageValue)
        {
            name = nameValue;
            age = ageValue;

        }
        public Cat()
        {
            name = "";
            age = 0;
        }

        public int Age // attribute defintion
        {
            get 
            {
                return age;
            }
            set
            {
                if (value <= 0) age = 0;
                else age = value;
            }
        }

        private void Hello()
        {
            Console.WriteLine("hi, I am" + name);
        }
        public void Meow()
        {
            Hello();
            Console.WriteLine("meow,meow...");
        }

        public void ChaseMice()
        {
            miceCount++;
            Hello();
            Console.WriteLine("I got{0} mice.", miceCount);

        }
    }
}
