//version 1.0
class App{// backbone/high level abstract of application program
	public void Show(){
		Document doc = new Document();
		doc.ShowText(); //depends directly on instance
	
		Graphics = graph = nwe Graphics();
		graph.ShowGraphics(); //directly depends on instance

	}
}

class Document{
	public void ShowText(){
		//...
	}
}

class Graphics{
	public void ShowGraphics(){
		//....
	}
}




//version 2.0
public interface Command{ //can be abstract class or interface.
	public void Show();
	public void Undo();
	public void Redo();
}

class Document : Command{
	public virtual void Show(){
		//...
	}
}

class Graphics : Command{
	public virtual void Show(){
		//....
	}
}


class App{
	//ArrayList<Command> list;
	Stack<Command> stack;

	public void Show(){
		foreach(Command s in stack){
			s.Show();
		}
	}

	public void Undo(){
		if(canUndo){
			Command command = s.Pop();
			command.Undo();
			undoList.Add(command);
		}
	}

	public void Redo(){
		if(canRedo){
			Command command = uodoList.Pop();
			command.Redo();
		}
	}
}


//version 3.0
//Receiver, can be any type/object
class Document{} //existed, implementation details, low level 
class Graphics{} //existed, implementation details, low level

public interface Command{// implement Command design pattern, abstract body
	public void Show();
	public void Undo();
	public void Redo();
}

//ConcreteCommand
class DocumentCommand:Command{// instanalize command object -- DocumentCommand represents a behavior.
	Document document;
	public DocumentCommand(Document doc){ //ctor
		this.document = doc;
	}
	public void Show(){
		document.ShowText();
	}
	public void Undo(){
		//...
	}
	public void Redo(){
		//...
	}
}

//ConcreteCommand
class GraphicsCommand:Command{
	// similar to the DocumentCommand;
}
