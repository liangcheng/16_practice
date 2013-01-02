public abstract class Tank{
	public abstract void Shot();
	public abstract void Run();
}

public class T50: Tank{
	public override void Shot(){}
	public override void Run(){}
}

public class T75 : Tank{
	public override void Shot(){}
	public override void Run(){}
}

public class T90 : Tank{
	public override void Shot(){}
	public override void Run(){}
}

public interface IA
{
	void ShotA();
	void RunA();
}

public class T50 : Tank,IA
{
	void ShotA(){}//private?
	void RunA(){}

	public override void Shot(){
		this.ShotA();//function expanded
		// do shot ...
		base.Shot();
	}
	public override void Run(){
		this.RunA();
		// do run ...
		base.Run();
	}
}

// -------------------------------
// refactor to decorator pattern
public abstract class Tank{ //Component
	public abstract void Shot();
	public abstract void Run();
}

public class T50: Tank{ //ConcreteComponent
	public override void Shot(){}
	public override void Run(){}
}

public class T75 : Tank{//ConcreteComponent
	public override void Shot(){}
	public override void Run(){}
}

public class T90 : Tank{//ConcreteComponent
	public override void Shot(){}
	public override void Run(){}
}

//Decorator
public abstract class Decorator: Tank{// not "is a" but "do as", it is interface inheritance, not class inheritance. 
	private Tank tank; // "has a" combination
	public Dectorator(Tank tank){
		this.tank = tank;}
	public override void Shot(){
		this.tank.Shot();}
	public override void Run(){
		this.tank.Run();}
}

// function A extended
public class DecoratorA : Decorator{ //ConcreteDecoratorA
	public DecoratorA(Tank tank):base(tank){}

	public override void Shot(){
		//Do some extension, infract light
		//do shot....
		base.Shot();
	}
	public override void Run(){
		//do some extension
		//do run...
		base.Run();
	}
}

public class DectoratorB:Dectorator{//ConcreteDecoratorB
	public DecoratorB(Tank tank):base(tank){}

	public override void Shot(){
		//Do some extension, satalite positioning
		//do shot....
		base.Shot();
	}
	public override void Run(){
		//do some extension
		//do run...
		base.Run();
	}
} 


public class DectoratorC:Dectorator{
	public DecoratorC(Tank tank):base(tank){}

	public override void Shot(){
		//Do some extension, water-land bibattle
		//do shot....
		base.Shot();
	}
	public override void Run(){
		//do some extension
		//do run...
		base.Run();
	}
} 

public class App{
	public static void Main(){
		Tank tank = new T50();
		DecoratorA da = new DecoratorA(tank);
		da.Shot();
		DacoratorB db = new DecoratorB(da);
		db.Run();
		DacoratorC dc = new Decorator(dc);
		dc.Run();
	}
}



