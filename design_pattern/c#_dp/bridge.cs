public abstract class Tank
{
	public abstract void Shot();
	public abstract void Run();
	public abstract void Stop();
}



public class T50:Tank
{
	public override void Shot(){}
	public override void Run(){}
	public override void Stop(){}
}
public class PCT50:T50{}
public class MobileT50:T50{}



public class T75:Tank
{
	public override void Shot(){}
	public override void Run(){}
	public override void Stop(){}
}
public class PCT75:T750{}
public class MobileT75:T75{}


public class T90:Tank
{
	public override void Shot(){}
	public override void Run(){}
	public override void Stop(){}
}
public class PCT90:T790{}
public class MobileT90:T90{}



// ------------------------
//----- new implementation
public abstract class Tank // Abstraction
{
	protected TankPlatformImplementation tankImpl;
	public Tank(TankPlatformImplementation tankImpl)
	{
		this.tankImpl = tankImpl;
	}
	public TankImpl{
		get{return this.tankImpl;}
		set{this.tankImpl = tankImpl;}
	}

	public abstract void Shot();
	public abstract void Run();
	public abstract void Stop();
}

public class T50:Tank // RefinedAbstraction
{
	public T50(TankPlatformImplementation tankImpl) : base(tankImpl) {}

	public override void Shot()
	{
		//...
		tankImpl.DoShot();
		//...
	}
	public override void Run()
	{
		//...
		tankImpl.MoveTankTo();
		//...
	}
}
//...
//same to T75 and T90 ....
//...



public abstract class TankPlatformImplementation //Implementor
{
	public abstract void MoveTankTo(Point to);
	public abstract void DrawTank();
	public abstract void DoShot();
}

public class PCTankImpelementation:TankPlatformImplementation//ConcreteImplementorA
{
	public override void MoveTankTo(Point to){}
	public override void DrawTank(){}
	public override void DoShot(){}
}


public class MobileTankImpelementation:TankPlatformImplementation//ConcreteImplementorB
{
	public override void MoveTankTo(Point to){}
	public override void DrawTank(){}
	public override void DoShot(){}
}


public class App
{
	public static void Main()//Client
	{
		TankPlatformImplementation tankImpl = new MobileTankImplementation();
		T50 tank = new T50(tanksImpl);
	}


