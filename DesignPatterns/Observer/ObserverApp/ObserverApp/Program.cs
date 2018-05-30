using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObserverApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Subject subject = new Subject();
            BinaryObserver bb = new BinaryObserver(subject);
            OctalObserver oo = new OctalObserver(subject);
            subject.state = 10;
            subject.state = 20;
        }
    }
}
