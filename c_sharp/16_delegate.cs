using System;

namespace ex_delegate
{

  delegate void AnimalPlay(string name);

  class Program
  {

    static void RunCircus(AnimalPlay animalPlay, string name)
    {
      animalPlay(name);
     }


    static void Main(String[] args)
    {
       //AnimalPlay deleDogPlay = new AnimalPlay(DogAct);
       AnimalPlay deleDogPlay = DogAct;
       deleteDogPlay("xx");

       //deleDogPlay += new AnimalPlay(CatPlay);

       RunCircus(deleDogPlay, "Snoopy");
     }
    
    static void DogAct(string name)
    {
       Console.WriteLine("Hello, I am dog "+name+"!");
    
    static void LionAct(string name)
    {
       Console.WriteLine("Hello, I am lion "+name+"!");
    }



   }
}