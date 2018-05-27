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
        public CellController()
        {

        }

        public void RunGame()
        {
            CellsModel.InitGame();
            ChangeAllCells();
        }

        public void ChangeCell(ref bool state)
        {
            Random rd = new Random();
            while (true)
            {
                state = !state;
                Thread.Sleep(rd.Next(500, 2000));
                Debug.WriteLine(CellsModel.Face[0, 0].ToString() + "  " + Thread.CurrentThread.ManagedThreadId);
            }
        }

        public void ChangeAllCells()
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
