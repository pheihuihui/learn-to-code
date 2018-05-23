using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace mvcapp.Models
{
    public static class CellsModel
    {
        public static int HorizonNumber { get; set; }
        public static int VerticalNumber { get; set; }
        public static bool[,] Face { get; set; }
        static CellsModel()
        {
            HorizonNumber = 16;
            VerticalNumber = 9;
            Face = new bool[HorizonNumber, VerticalNumber];
        }

        public static void InitGame()
        {
            Random rd = new Random();
            for (int i = 0; i < HorizonNumber; i++)
            {
                for(int j = 0; j < VerticalNumber; j++)
                {
                    if (rd.Next(2) == 0)
                    {
                        Face[i, j] = false;
                    }
                    else
                    {
                        Face[i, j] = true;
                    }
                }
            }
        }

        public static void ChangeState(uint i, uint j)
        {
            if(i < HorizonNumber && j < VerticalNumber)
            {
                Face[i, j] = !Face[i, j];
            }
            else
            {
                throw new IndexOutOfRangeException("Out of range");
            }
        }
    }
}
