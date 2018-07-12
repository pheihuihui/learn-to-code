using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace csplot
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            InitChart();
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }

        private void InitChart()
        {
            chart1.ChartAreas[0].Axes[0].Title = "N";
            chart1.ChartAreas[0].Axes[1].Title = "FIB(N)";
            chart1.Series[0].ChartType = SeriesChartType.Line;
            chart1.Series[0].MarkerStyle = MarkerStyle.Circle;
            chart1.Series[0].LegendText = "Fibonacci numbers";
            Tuple<int, int> t = Tuple.Create(0, 1);

            for (int i = 1; i <= 30; i++)
            {
                chart1.Series[0].Points.Add(new DataPoint(i, t.Item1));
                t = Tuple.Create(t.Item2, t.Item1 + t.Item2);
            }
        }
    }
}
