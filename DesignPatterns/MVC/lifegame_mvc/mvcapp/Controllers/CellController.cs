using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using mvcapp.Models;

namespace mvcapp.Controllers
{
    public class CellController
    {
        public CellController()
        {

        }

        public void RunGame()
        {
            CellsModel.InitGame();
        }
    }
}
