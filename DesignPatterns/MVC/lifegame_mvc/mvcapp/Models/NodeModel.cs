using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace mvcapp.Models
{
    public enum State : int
    {
        Gray = 0,
        Green = 1
    }

    public static class NodeModel
    {
        public static int HorizonNumber { get; set; }
        public static int VerticalNumber { get; set; }
        public static State[,] Face { get; set; }
        static NodeModel()
        {
            HorizonNumber = 16;
            VerticalNumber = 9;
            Face = new State[HorizonNumber, VerticalNumber];
        }

        public static void InitGame()
        {
            Random rd = new Random();
            for (int i = 0; i < HorizonNumber; i++)
            {
                for(int j = 0; j < VerticalNumber; j++)
                {
                    if(rd.Next(1) == 0)
                    {
                        Face[i, j] = State.Gray;
                    }
                    else
                    {
                        Face[i, j] = State.Green;
                    }
                }
            }
        }

        public static void ChangeState(uint i, uint j)
        {
            if(i < HorizonNumber && j < VerticalNumber)
            {
                State state = Face[i, j];
                if(state == State.Gray)
                {
                    Face[i, j] = State.Green;
                }
                else
                {
                    Face[i, j] = State.Gray;
                }
            }
            else
            {
                throw new IndexOutOfRangeException("Out of range");
            }
        }
    }
}
