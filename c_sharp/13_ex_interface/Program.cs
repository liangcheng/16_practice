using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ex_interface
{
    class Program
    {
        static void Main(string[] args)
        {
            IBankAccount myAccount = new SaverAccount();
            ITransferBankAccount yourAccount = new TransferAccount();
            myAccount.PayIn(10000);
            yourAccount.PayIn(30000);
            yourAccount.TransferTo(myAccount, 5000);
            Console.WriteLine("my balance is " + myAccount.Balance);
            Console.WriteLine("your balance is " + yourAccount.Balance);
        }
    }

    class SaverAccount : IBankAccount
    {
        private decimal balance;
        public void PayIn(decimal amount)
        {
            balance += amount;
        }
        public bool WithShowMyself(decimal amount)
        {
            if (balance >= amount) {balance -= amount; return true;}
            else
            {
                Console.WriteLine("insufficient balance, withdrew is failed.");
                return false;
            }
        }
        public decimal Balance { get { return balance; } }
    }




    class TransferAccount : ITransferBankAccount
    {
        private decimal balance;
        public void PayIn(decimal amount)
        {
            balance += amount;
        }

        public bool WithShowMyself(decimal amount)
        {
            if (balance >= amount) { balance -= amount; return true; }
            else
            {
                Console.WriteLine("no sufficient amount, withdrew failed");
                return false;
            }
        }

        public decimal Balance
        { get { return balance; } }

        public bool TransferTo(IBankAccount destination, decimal amount)
        {
            bool result = WithShowMyself(amount);
            if (result == true) destination.PayIn(amount);
            return result;
        }

    }
}
