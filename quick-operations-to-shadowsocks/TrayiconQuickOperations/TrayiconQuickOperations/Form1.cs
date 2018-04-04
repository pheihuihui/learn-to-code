using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TrayiconQuickOperations
{
    public partial class Form1 : Form
    {
        PopWindow pop = new PopWindow();

        public Form1()
        {
            InitializeComponent();
        }

        private void notifyIcon1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            pop.Activate();
        }

        private void notifyIcon1_MouseClick(object sender, MouseEventArgs e)
        {

        }

    }
}
