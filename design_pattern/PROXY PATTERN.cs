/**
PROXY PATTERN
BY LI JIANZHONG
2/23/2013
**/

using System;
//Version 1.0
class Employee{
  public void GetSalary(){...}
  public void Report(){...}
  public void ApplyVacation() {...}
  
}

class HrSystem{
  public void Process(Employee employee){
    employee.Report();
    //...
    
    employee.ApplyVacation();
    //
    
  }
}


//Version 2.0
interface IEmployee
{
  public void GetSalary();
  public void Report();
  public void ApplyVacation();
}

//run in remote computer internet
class Employee : IEmployee  //real subject
{
  public void GetSalary(){...}
  public void Report(){...}
  public void ApplyVacation() {...}
}


// run local winForms
class EmployeeProxy : IEmployee // Proxy
{
  public EmployeeProxy()
  {
    //build object 
  }
  
  public void GetSalary()
  {
    //build the object, a soap encapulation     
    //send soap data     
    //if has return value, accept soap, decrypher,return raw C# data 
    }
    
  public void Report() {...}
  public void ApplyVacation() {...}     
}


class HrSystem //Subject
{
  public void Process()
  {
    IEmployee employee = new EmployeeProxy();
    employee.Report();
    //...                           
    employee.ApplyVacation();
}


// example 2, copy on write
using System;
/// Copy-On-Write
///

public class App
{
  public static void Main() 
  {
    string s = "hello";
    string s1 = "hello";
    string s2 = s1.ToUpper();
    
    StringBuilder sb = new StringBuilder("hello");
    StringBuilder sb2 = new StringBuilder("hello");
    StringBuilder sb3 = new StringBuilder("hello");
    
    
  }
  
}