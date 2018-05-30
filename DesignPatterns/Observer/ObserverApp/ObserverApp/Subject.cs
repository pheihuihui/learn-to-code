using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObserverApp
{
    public class Subject
    {
        private List<Observer> observers = new List<Observer>();

        private int _state;
        public int state
        {
            get
            {
                return _state;
            }
            set
            {
                _state = value;
                NotifyObservers();
            }
        }

        public void Attach(Observer oo)
        {
            observers.Add(oo);
        }

        public void NotifyObservers()
        {
            foreach(Observer oo in observers)
            {
                oo.Update();
            }
        }
    }
}
