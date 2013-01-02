internal class Wheel{ // not exposed to external
	public void WAction1() {}
	public void WAction2(){}
}
internal class Engine{
	public void EAction1(){}
	public void EAction2(){}
}

internal class Bodywork{
	public void BAction1(){}
	public void BAction2(){}
}
internal class Controller{
	public void CAction1(){}
	public void CAction2(){}
}

public class TankFacade{
	Wheel[] wheels = new Wheel[4];
	Engine[] engines = new Engine[4];
	Bodywork bodywork = new Bodywork();
	Controller controller = new Controller();

	public void Start(){}
	public void Stop(){}
	public void Run(){}
	public void Shot(){}
}







