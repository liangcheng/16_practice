class Singleton
{
	public static readonly Singleton Instance = new Singleton();
	private Singleton() {}
	public void Init(FileStream fs)
	{
		// configure something like database;
	}

	public int x
	{
		get
		{
			return this.x;
		}
		set
		{
			this.x = x;
		}
	}
	
}

/**
class Singleton
{
	public static readonly Singleton Instance;

	static Singleton()
	{
		Instance = new Singleton();
	}
	private Singleton(){}
}

**/


class Test
{
	public static void Main()
	{
		Singleton instance = Singleton.Instance;
		instance.Init(new FileStream("...");
		instance.x = X;
		
		Console.WriteLine(instance);
		
		myClass c1 = new MyClass();
		myClass c2 = new MyClass();

		Type t1 = c1.GetType();
		Type t2 = c2.GetType();

		//t1 ==t2
		//HttpContext.Current
		}
		}

