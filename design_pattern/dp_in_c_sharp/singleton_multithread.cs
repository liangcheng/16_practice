class Singleton
{
	private static volatile Singleton instance =null;
	private static object lockHelper = new Object();

	private Singleton(){}

	public static Singleton Instance()
	{
		if (instance ==null)
		{
			lock (lockHelper)
			{
				if (instance ==null)
				{
					instance = new Singleton();
				}
			}
		}
		return instance;
	}
}


