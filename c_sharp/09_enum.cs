using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ExampleEnum
{
    //enum WeekDays { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday}
    enum WeekDays
    {
        Sunday = 5,
        Monday,
        Tuesday,
        Wednesday =100,
        Thursday,
        Firday,
        Saturday
    }

    class Program
    {
        static void Main(string[] args)
        {
            WeekDays today = WeekDays.Sunday;

            if ((today == WeekDays.Saturday) || (today == WeekDays.Sunday))
                Console.WriteLine("I love the weekends.");
            else
                Console.WriteLine("Back to work!");

            for(today=WeekDays.Sunday; today<=WeekDays.Saturday;++today)
                Console.WriteLine(today);
            
        }
    }
}
