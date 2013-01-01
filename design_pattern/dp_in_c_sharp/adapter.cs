using System.Collections;
using System;

interface IStack //client expected interface
{
	void Push (object item);
	object Pop();
	object Peek();
}

//Object Adapter
class MyStack:IStack 
{
	ArrayList list; // adaptee and Target
	AnotherType adaptee2;// adaptee

	public MyStack()
	{
		list = new ArrayList();
	}

	public void Push(object item)
	{
		list.Add(item);
	}

	public object Pop()
	{
		list.RemoveAt(list.Count - 1);
	}

	public object Peek()
	{
		return list.RemoveAt(list.Count -1);
	}
}

//Class adapter
class Adapter:ArrayList, IStack //adaptee
{
	public void Push(ojbect item)
	{
		this.Add(item);
	}
	//...
}





// -----------------explain why adapter ----------------------------
class ExisitingClass // existing system
{
	public void SpecificRequest1(){}
	public void SpecificRequest2(){}
}

Interface ITarget() //interface used by new evironment
{
	void Request() // no public?
}

class MySystem // another new system
{
	public void Process(ITarget target){}
	public void Process(MyTarget target){} //not good
}

class Adapter: ITarget
{
	ExistingClass adaptee;
	public void Request() //override the old Request()? can be virtual method.
	{
		adaptee.SpecificRequest1();
		adaptee.SpecificRequest2();
	}
}




// another example of adapter
class EmployeeDA()
{
	public DataSet GetAllEmployee()
	{
		SqlDataAdapter dataAdapter = new SqlDataAdapter();
		//...
		DataSet ds = new DataSet();
		dataAdapter.Fill(ds);
	}
}

class DataSet
{
	DbDataAdapter dataAdatper;
	public DataSet(DbDataAdapter dataAdapter)
	{
		this.DataTable = dataAdapter.Fill();
	}
}

DataSet dataSet = new DataSet(new SqlDataAdapter(...));



//another adapter
class Employee
{
	int age;
	public int Age
	{
		get{return this.age;}
		set{this.age=value;}
	}
	//...
}

class EmpolyeeSortAdapter:IComparer
{
	public int Compare(object obj1, object obj2)
	{
		if(obj1.GetType()!=typeof(Employee)
				||obj2.GetType() != typeof(Employee))
		{
			throw new Exception();
		}
		Employee e1 = (Employee) obj1;
		Employee e2 = (Employee) obj2;

		if(e1.Age == e2.Age) {return 0;}
		elseif(e1.Age>e2.Age){return 1;}
		elseif(e1.Age < e2.Age){return -1;}
	}
}



class App
{
	public static void Main()
	{
		Empolyee[] employees = new Employee[100];

		//...
		
		Array.Sort(employees); // not work, how to do w/o changing Employee class
		Array.Sort(employees, new EmployeeSortAdapter());

	}
}

