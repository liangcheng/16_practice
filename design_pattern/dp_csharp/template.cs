//framework developer --develop first
public abstract class Vehical{ //abstract class
	protected abstract void startup(); // primitiveOperation1(). virtual method ->protected
	protected abstract void run();// primitiveOperation2().
	protected abstract void turn(int degree);// primitiveOperation3().
	protected abstract void stop();// primitiveOperation4().
	public void Test(){ //TemplateMethod();
		//...record test results
		startup(); // binding later, leave for application developer, extension node(virtual method)
		//...record test results
		run();  // binding later
		//...record test results
		turn(...);  // binding later
		//...record test results
		stop();  // binding later
	}
}

class VechicalTestFramework{
	public static void DoTest(Vehical vehical){
		Vehical.Test();
	}
}





//application developer -- develop later
public class HongqiCar: Vehical{ //concreteClass
	protected override void startup(){}
	protected override void run(){}
	protected override void turn(int degree){}
	protected override void stop(){}
}

class App{
	public static void Main(){
		VehicalTestFramework.DoTest(new HongqiCar()):
	}
}




