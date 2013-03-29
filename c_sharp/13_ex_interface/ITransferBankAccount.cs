using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ex_interface
{
    interface ITransferBankAccount : IBankAccount
    {
        bool TransferTo(IBankAccount destination, decimal amount);
    }
}
