/*
 * Created by SharpDevelop.
 * User: liang
 * Date: 12/15/2012
 * Time: 3:08 PM
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;

namespace ascii
{
	class Program
	{
		public static void Main(string[] args)
		{
			Console.WriteLine("Hello World!");
			
			// TODO: Implement Functionality Here
			char ch = (char)65;
			Console.WriteLine("65->{0}", ch);
			
			//output in hex
			Console.WriteLine("\u0047\u006f\u006f\u0064\u0021\n");

			Console.WriteLine("c:\\windows\\fonts");
			Console.WriteLine(@"c:\\windows\\fonts");
			Console.WriteLine("ming saied:\"I am his friend\".");
			Console.WriteLine("make a beep. \a");
			
			
			
			Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);
		}
	}
}