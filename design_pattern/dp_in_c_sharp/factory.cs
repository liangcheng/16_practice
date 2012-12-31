//auto testing program
abstract class AbstractCar
{
	public abstract void Startup();
	public abstract void Run() ;
	public abstract void Turn(Direction dir) ;
	public abstract void Stop() ;
}


public class HongqiCar:AbstractCar
{
	Engine engine1;
	Engine engine1;
	Engine engine1;
	Engine engine1;
	public override Startup(){}
	public override Run() {}
	public override Turn(Direction dir) {}
	public override Stop() {}
}


abstract class CarFactory
{
	public abstract Car CreateCar();
}


public class HongqiCarFactory : CarFactory
{
	public override Car CreateCar()
	{
		return new HongqiCar();
	}
}


class CarTestFramework
{
	public void BuildTestContext(CarFactory cf)
	{
		AbstractCar c1 = cf.CreateCar();
		AbstractCar c2 = cf.CreateCar();
		AbstractCar c3 = cf.CreateCar();
		AbstractCar c4 = cf.CreateCar();
	}

	public void DoTest(AbstractCar car)
       	{
		car.run();
	}

	public TestData GetTestData(AbstractCar car)
	{
		car.getdata();
	}
}


class App
{
	public static void Main()
	{
		CarTestFramework carTestFramework = new CarTestFramework();

		carTestFramework.BuildTestContext(new HongqiCarFactory);
		carTestFramework.BuildTestContext(new DongfengCarFactory);

		//Activator.CreateInstance(string TypeName);
		// using template may work for this also
	}
}



