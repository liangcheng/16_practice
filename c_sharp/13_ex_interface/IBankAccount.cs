using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ex_interface
{
    interface IBankAccount
    {
        void PayIn(decimal amount);
        bool WithShowMyself(decimal amount);
        decimal Balance { get; }
    }
}
