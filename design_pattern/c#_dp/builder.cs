public abstract class Door{}
public abstract class Windows{}
public abstract class Floor{}
public abstract class HouseCeiling{}
public abstract class Wall{}
public abstract class House{}

public class RomanDoor:Door{}
public class RomanWindows:Windows{}
public class RomanFloor:Floor{}
public class RomanHouseCeiling:HouseCeiling{}
public class RomanWall:Wall{}
public class RomanHouse:House{}

//Builder
public abstract class Builder
{
	public abstract void BuildDoor();
	public abstract void BuildWindows();
	public abstract void BuildWall();
	public abstract void BuildFloor();
	public abstract void BuildHouseCeiling();
	public abstract House GetHouse();
}

//ConcreteBuilder
public class RomanHouseBuilder:Buidler
{
	public override void BuildDoor(){}
	public override void BuildWall(){}
	public override void BuildWindows(){}
	public override void BuildFloor(){}
	public override void BuildHouseCeiling(){}
	public override House GetHouse(){}
}

//Director
//no need change in later use
public class GameManager
{
	public static House CreateHouse(Builder builder) //static method
	{
		builder.BuildDoor();
		builder.BuildDoor();

		builder.BuildWindows();
		builder.BuildWindows();

		builder.BuildWall();
		builder.BuildWall();
		builder.BuildWall();
		builder.BuildWall();

		builder.BuildFloor();

		builder.BuildHouseCeiling();

		return builder.GetHouse();	
	}
}


class App
{
	public static void Main()
	{
		//House house = GameManager.CreateHouse(new RomanHouseBuilder());

		string assemblyName = ConfiguratonSettings["BuilderAssembly"];
		string builderName = ConfigurationSettings["Builder"];
		Assembly assembly = Assembly.Load(assemblyName);
		Type t = assembly.GetType(builderName);
		Builder builder = Activator.CreateInstance(t);
		House house = GameManager.CreateHouse(builder);
	}
}
