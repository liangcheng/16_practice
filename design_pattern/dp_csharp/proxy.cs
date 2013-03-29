using System;

//version 1.0
class Empolyee{
	public void GetSalary(){}
	public void ReportTo(){}
	public void ApplyVacation(){}
}

class HrSystem{
	public void Process()
	{
		Employee employee = new Employee();
		employee.Report();
		//...
		employee.ApplyVacation();
		//...
	}
}



//version 2.0
interface IEmployee{
	public void GetSalary();
	public void Report();
	public void ApplyVacation();
}

class Employee : IEmployee{ // run remotely, really working actor
	public void GetSalary(){}
	public void Report(){}
	public void ApplyVacation(){}
}

class EmployeeProxy : IEmployee{ // run locally
	public EmployeeProxy(){
		//sort of encapulation for object creation
	}
	public void GetSalary(){
		// object creation / SOAP encapulation(visit)
		
		// send SOAP data / call
		
		// if return value, receive return value and decipher the data, return raw C# data.
	}
	public void Report(){
		//...
	}
	public void ApplyVacation(){
		//...
	}
}

class HrSystem{ //Subject
	public void Process()
	{
		Employee employee = new Employee();
		employee.Report();
		//...
		employee.ApplyVacation();
		//...
	}
}

class App{ // Client
	public static void Main(){
		HrSystem hs = new HrSystem();
		hs.Process();
		//...
		}
}

