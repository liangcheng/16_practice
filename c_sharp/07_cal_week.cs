using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cal_week
{
    class Program
    {
        static void Main(string[] args)
        {
            int y, m, d;
Console.WriteLine("Input year, month, and day:");
y = Convert.ToInt32(Console.ReadLine());
m = Convert.ToInt32(Console.ReadLine());
d = Convert.ToInt32(Console.ReadLine());

if(m==1||m==2)
{
m +=12;
y--;
}

int week = (d+2*m+3*(m+1)/5 +y+y/4-y/100);
string weekstring ="";

switch(week)
{
  case 0: weekstring = "sunday";break;
  case 1: weekstring = "monday";break;
  case 2: weekstring = "tuesday";break;
  case 3: weekstring = "wednesday";break;
  case 4: weekstring = "thursday";break;
  case 5: weekstring = "friday";break;
  case 6: weekstring = "satarday";break;
    default: break;
}

Console.WriteLine(weekstring);


        }

    }
}
