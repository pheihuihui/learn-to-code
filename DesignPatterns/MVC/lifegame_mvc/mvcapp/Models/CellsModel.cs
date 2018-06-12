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
        public static int LimitNumber { get; set; } = 4;
        public static bool IsRunning { get; set; } = false;
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
            IsRunning = true;
            for (int i = 0; i < HorizonNumber; i++)
            {
                for(int j = 0; j < VerticalNumber; j++)
                {
                    Face[i, j] = (rd.Next(2) == 0 ? false : true);
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

        public static int GetAliveCellsNumber(int i, int j)
        {
            int res = 0;
            if (IsCellExit(i - 1, j - 1))
                res += (Face[i - 1, j - 1] ? 1 : 0);
            if (IsCellExit(i - 1, j))
                res += (Face[i - 1, j] ? 1 : 0);
            if (IsCellExit(i - 1, j + 1))
                res += (Face[i - 1, j + 1] ? 1 : 0);
            if (IsCellExit(i, j - 1))
                res += (Face[i, j - 1] ? 1 : 0);
            if (IsCellExit(i, j + 1))
                res += (Face[i, j + 1] ? 1 : 0);
            if (IsCellExit(i + 1, j - 1))
                res += (Face[i + 1, j - 1] ? 1 : 0);
            if (IsCellExit(i + 1, j))
                res += (Face[i + 1, j] ? 1 : 0);
            if (IsCellExit(i + 1, j + 1))
                res += (Face[i + 1, j + 1] ? 1 : 0);
            return res;
        }

        private static bool IsCellExit(int i, int j)
        {
            if(i < 0 || i >= HorizonNumber || j < 0 || j >= VerticalNumber )
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}
