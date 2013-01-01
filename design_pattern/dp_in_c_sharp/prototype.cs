//Prototype
public abstract class NormalActor
{
	public abstract NormalActor Clone();
}
public abstract class FlyActor
{
	public abstract FlyActor Clone();
}
public abstract class WaterActor
{
	public abstract WaterActor Clone();
}

//MemberwiseClone() -- shallow copy, instance type and string type can be copied. int[] a, only address is copied. 
//ConcretePrototype1
public class NormalActorA:NormalActor
{
	public override NormalActor Clone()
	{
		return (NormalActor) this.MemberwiseClone();
	}
}
//ConcreteProtytype2
public class NormalActorB:NormalActor
			  {
	public override NormalActor Clone()
	{
		return (NormalActor) this.MemberwiseClone();
	}
}
public class FlyActorA:FlyActor
{
	public override FlyActor Clone()
	{
		return (FlyActor) this.MemberwiseClone();
	}
}
public class FlyActorB:FlyActor
{
	public override FlyActor Clone()
	{
		return (FlyActor) this.MemberwiseClone();
	}
}
public class WaterActorA:WaterActor
{
	public override WaterActor Clone()
	{
		return (WaterActor) this.MemberwiseClone();
	}
}
public class WaterActorB:WaterActor
{
	public override WaterActor Clone()
	{
		return (WaterActor) this.MemberwiseClone();
	}
}


//original
public class GameSystem
{
	
	public void Run()
	{
		NormalActor na1 = new NormalActorA();
		NormalActor na2 = new NormalActorA();
		NormalActor na3 = new NormalActorA();
		NormalActor na4 = new NormalActorA();
		NormalActor na5 = new NormalActorA();
		FlyActor fa1 = new FlyActorA();
		FlyActor fa2 = new FlyActorA();
		WaterActor wa1 = new WaterActorA();
		WaterActor wa2 = new WaterActorA();
	}
}



//refactor to prototype pattern
//Client
public class GameSystem
{
	NormalActor na;
	FlyActor fa;
	WaterActor wa;

	//operation()
	public void Run()
	{
		NormalActor na1 = na.Clone();
		NormalActor na2 =na.Clone();
		NormalActor na3 = na.Clone();
		NormalActor na4 = na.Clone();
		NormalActor na5 = na.Clone();
		FlyActor fa1 = fa.Clone();
		FlyActor fa2 = fa.Clone();
		WaterActor wa1 = wa.Clone();
		WaterActor wa2 =wa.Clone();
	}
}


Class App
{
	public static void Main()
	{
		GameSystem gs = new GameSystem;
		gm.Run(new NormalActorA(), 
			new FlyActorB(),
			new WaterActorA());
	}
}








