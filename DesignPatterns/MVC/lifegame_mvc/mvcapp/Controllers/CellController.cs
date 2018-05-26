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
            Thread th = new Thread(ChangeCell);
            th.Start();
        }

        public void ChangeCell()
        {
            while (true)
            {
                CellsModel.Face[0, 0] = !CellsModel.Face[0, 0];
                Thread.Sleep(1000);
                Debug.WriteLine(CellsModel.Face[0, 0].ToString());
            }
        }



    }
}
