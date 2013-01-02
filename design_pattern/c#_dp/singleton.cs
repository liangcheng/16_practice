public class Singleton
{
	private static Singleton instance;
	private Singleton() {}

	public static Single Instance
	{
		get
		{
			if(instance ==null)
			{
				instance = new Singleton();
			}
			return instance;
		}
	}
}

class Test
{
	public static void Main()
	{
	//	Singleton t = new Singleton();
	Singleton t1 =Singleton.Instance;
	Singleton t2 = Singleton.Instance;

	Console.WriteLine(Ojbect.ReferenceEquals(t1,t2) ==true);

	}
