// stream in .net system
using System.Security.Cryptography;
using System.IO;

class App{
	public static void Main(){
		MemoryStream ms = 
			new MemoryStream(new byte[] {100,203,456,777,921,345});
		BufferedStream buff = new BufferedStream(ms);
		CryptoStream crypto = new CryptoStream(buff);
	}
}
