using System;
using System.Text;

// Copy-On-Write
// 
// Copy-On-Change

public class App{
	public static void Main(){
		string s = "hello";
		string s1 = "hello";
		string s1 = s1.ToUpper();

		StringBuilder sb = new StringBuilder("hello");
		StringBuilder sb2 = new StringBuilder("hello");
		StringBuilder sb3 = new StringBuilder("hello");

		sb.Replace('l','q');
	}
}

