using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using mvcapp.Models;
using System.Threading;
using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;

namespace mvcapp.Controllers
{
    public class CellController : Controller
    {
        private bool[,] TempCells;
        public CellController()
        {
            TempCells = CellsModel.Face;
        }

        public void RunGame()
        {
            CellsModel.InitGame();
            Thread th = new Thread(() => 
            {
                while (true)
                {
                    ChangeAllCells(true);
                    Thread.Sleep(100);
                }
            });
            th.Start();
        }

        private void ChangeCell(ref bool state)
        {
            Random rd = new Random();
            while (true)
            {
                if(rd.Next(2) == 1)
                    state = !state;
                Thread.Sleep(100);
                Debug.WriteLine(CellsModel.Face[0, 0].ToString() + "  " + Thread.CurrentThread.ManagedThreadId);
            }
        }

        public void ChangeAllCells(bool condition)
        {
            if (condition)
            {
                for (int i = 0; i < CellsModel.HorizonNumber; i++)
                {
                    for (int j = 0; j < CellsModel.VerticalNumber; j++)
                    {
                        int ii = i;
                        int jj = j;
                        if (CellsModel.GetAliveCellsNumber(ii, jj) == 3)
                        {
                            TempCells[ii, jj] = true;
                        }
                        else if (CellsModel.GetAliveCellsNumber(ii, jj) == 2)
                        {

                        }
                        else
                        {
                            TempCells[ii, jj] = false;
                        }
                    }
                }
                CellsModel.Face = TempCells;
            }
        }

        private void ChangeAllCells()
        {
            for (int i = 0; i < CellsModel.HorizonNumber; i++)
            {
                for (int j = 0; j < CellsModel.VerticalNumber; j++)
                {
                    //Note_1805271958: https://blogs.msdn.microsoft.com/ericlippert/2009/11/12/closing-over-the-loop-variable-considered-harmful/
                    //Note_1805271958: Closures close over variables, not over values.
                    int ii = i;
                    int jj = j;
                    new Thread(() => ChangeCell(ref CellsModel.Face[ii, jj])).Start();
                }
            }
        }

    }
}
