using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Shapes;

namespace cube
{
    class Utility
    {
        private List<Rectangle> RectangleList = new List<Rectangle>();

        public static void SwapRectangleColor(Rectangle rec1, Rectangle rec2, Rectangle rec3, Rectangle rec4, Direction dr)
        {
            if(dr == Direction.left)
            {
                Brush tmp = rec1.Fill;
                rec1.Fill = rec2.Fill;
                rec2.Fill = rec3.Fill;
                rec3.Fill = rec4.Fill;
                rec4.Fill = tmp;
            }
            else
            {
                Brush tmp = rec4.Fill;
                rec4.Fill = rec3.Fill;
                rec3.Fill = rec2.Fill;
                rec2.Fill = rec1.Fill;
                rec1.Fill = tmp;
            }
        }

        public static void SwapRectangleColor(Rectangle rec1, Rectangle rec2)
        {
            Brush tmp = rec1.Fill;
            rec1.Fill = rec2.Fill;
            rec2.Fill = tmp;
        }

        public static void ChangeRectangleColor()
        {


        }
    }

    enum Direction
    {
        left,
        right
    }
}
