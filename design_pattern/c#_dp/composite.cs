public interface IBox{
	void Process();
}

public class SingleBox: IBox{
	public void Process(){}
}

public class ContainerBox:IBox{
	public void Process(){}
	public ArrayList getBoxes(){}
}


class App //client
{
	public static void Main()
	{
		IBox box = Factory.GetBox();

		//client couples with inner structure of object
		if(box is ContainerBox){
			box.Process();
			ArrayList list = ((ContainerBox) box).GetBoxes();
			//... face up complicated recursion
		}else if(box is SingleBox){
			box.Process();
		}
	}
}


// -----------------------
// refined version
public interface IBox{//Component
	void Process();
	void Add(IBox box); //tradeoff
	void Remove(IBox box); //tradeoff
}

public class SingleBox:IBox// leaf in tree model
{
	public void Process(){}
	public void Add(IBox box){ 
		throw UnsupportedException();
	}
	public void Remove(IBox box){
		throw UnsupportedException();
	}
}

public class ContainerBox:IBox //subtree of tree model,Composite
{
	ArrayList list = null;

	public void Add(IBox box)
	{
		if(list==null)
		{
			list = new ArrayList();
		}
		list.Add(box);
	}
	public void Remove(IBox box)
	{
		if(list ==null)
		{
			throw XXXException();
		}
		list.Remove(box);
	}
	public void Process() {
		//Do process for myself
		//....
		//Do process for the box in the list
		if(list!=null){
			foreach (IBox box in list){
				box.Process();
			}
		}
	}
}


class App//client
{
	public static void Main()
	{
		IBox box = Factory.GetBox(); //relation between Client and Component

		//client code couples with abstract interface
		box.Process();
		box.Add(Factory.GetBox());
		box.Remove();
	}
}



// another exmple
Button b = new Button();
Panel p = new Panel();
p.Control.Add(d);

TextBox t = new TextBox();
Panel p2 = new Panel();
p2.Controls.Add(t);
p2.Controls.Add(p);




