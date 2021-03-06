// developing a video game

//AbstractProductA
public abstract class Road{}

//AbstractProductB
public abstract class Building{}

//AbstractProdutC
public abstract class Tunnel{}

//AbstractProductD
public abstract class Jungle{}


//AbstractFactory
abstract class FacilitiesFactory
{
	public abstract Road CreateRoad();
	public abstract Building CreateBuilding();
	public abstract Tunnel CreateTunnel();
	public abstract Jungle CreateJunge();
}


//client, use only abstract classes
//do not need to change later
class GameManager
{
	private FAcilitiesFactory ff;
	private Road road;
	private Building building;
	private Tunnel tunnel;
	private Jungle jungle;

	public GameManager(FacilitiesFactory ff)
	{
		this.ff = ff;	
	}
	
	public void BuildGameFacilities()
	{
		Road road = ff.CreateRoad();
		Building building = ff.BreateBuilding();
		Tunnel tunnel = ff.CreateTunnel();
		Jungle jungle = ff.CreateJungle();
	}

	public void Play()
	{
		road.AAA();
		building.BBB(road);
		tunnel.CCC();
		jungle.DDD(tunnel);
	}
}

public class ModernRoad:Road
{
}

public class ModernBuilding:Building
{
}

public class ModernTunnel:Tunnel
{
}

public class ModernJungle:Jungle
{
}


//ConcreteFactory
public class ModernFacilitiesFactory:FacilitiesFactory
{
	public override Road CreateRoad()
	{
		return new ModernRoad();
	}

	public override Building CreateBuilding()
	{
		return new ModernBuilding();
	}

	public override Tunnel CreateTunnel()
	{
		return new ModernTunnel();
	}

	public override Jungle CreateJunge()
	{	
		return new ModernJungle();
	}
}


class App
{
	public static void Main()
	{
		GameManager gm = new GameManager(new ClassicFacilitiesFactory() );

		gm.BuildGameFacilities();
		gm.Run();
	}
}


