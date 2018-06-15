using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using Windows.UI;
using Windows.UI.Xaml.Shapes;
using System.Threading;
using System.Threading.Tasks;

// https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x804 上介绍了“空白页”项模板

namespace cube
{
    /// <summary>
    /// 可用于自身或导航至 Frame 内部的空白页。
    /// </summary>
    public sealed partial class MainPage : Page
    {
        delegate void Click();

        public MainPage()
        {
            this.InitializeComponent();
        }


        #region Clicks
        private void L_left_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Up01, Front01, Down01, Back08, Direction.left);
            Utility.SwapRectangleColor(Up04, Front04, Down04, Back05, Direction.left);
            Utility.SwapRectangleColor(Up06, Front06, Down06, Back03, Direction.left);
            Utility.SwapRectangleColor(Left01, Left03, Left08, Left06, Direction.left);
            Utility.SwapRectangleColor(Left02, Left05, Left07, Left04, Direction.left);
        }

        public void L_left_Click()
        {
            Utility.SwapRectangleColor(Up01, Front01, Down01, Back08, Direction.left);
            Utility.SwapRectangleColor(Up04, Front04, Down04, Back05, Direction.left);
            Utility.SwapRectangleColor(Up06, Front06, Down06, Back03, Direction.left);
            Utility.SwapRectangleColor(Left01, Left03, Left08, Left06, Direction.left);
            Utility.SwapRectangleColor(Left02, Left05, Left07, Left04, Direction.left);
        } 

        private void L_right_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Up01, Front01, Down01, Back08, Direction.right);
            Utility.SwapRectangleColor(Up04, Front04, Down04, Back05, Direction.right);
            Utility.SwapRectangleColor(Up06, Front06, Down06, Back03, Direction.right);
            Utility.SwapRectangleColor(Left01, Left03, Left08, Left06, Direction.right);
            Utility.SwapRectangleColor(Left02, Left05, Left07, Left04, Direction.right);
        }

        public void L_right_Click()
        {
            Utility.SwapRectangleColor(Up01, Front01, Down01, Back08, Direction.right);
            Utility.SwapRectangleColor(Up04, Front04, Down04, Back05, Direction.right);
            Utility.SwapRectangleColor(Up06, Front06, Down06, Back03, Direction.right);
            Utility.SwapRectangleColor(Left01, Left03, Left08, Left06, Direction.right);
            Utility.SwapRectangleColor(Left02, Left05, Left07, Left04, Direction.right);
        }

        private void R_right_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Up03, Front03, Down03, Back06, Direction.left);
            Utility.SwapRectangleColor(Up05, Front05, Down05, Back04, Direction.left);
            Utility.SwapRectangleColor(Up08, Front08, Down08, Back01, Direction.left);
            Utility.SwapRectangleColor(Right01, Right03, Right08, Right06, Direction.left);
            Utility.SwapRectangleColor(Right02, Right05, Right07, Right04, Direction.left);
        }

        public void R_right_Click()
        {
            Utility.SwapRectangleColor(Up03, Front03, Down03, Back06, Direction.left);
            Utility.SwapRectangleColor(Up05, Front05, Down05, Back04, Direction.left);
            Utility.SwapRectangleColor(Up08, Front08, Down08, Back01, Direction.left);
            Utility.SwapRectangleColor(Right01, Right03, Right08, Right06, Direction.left);
            Utility.SwapRectangleColor(Right02, Right05, Right07, Right04, Direction.left);
        }

        private void R_left_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Up03, Front03, Down03, Back06, Direction.right);
            Utility.SwapRectangleColor(Up05, Front05, Down05, Back04, Direction.right);
            Utility.SwapRectangleColor(Up08, Front08, Down08, Back01, Direction.right);
            Utility.SwapRectangleColor(Right01, Right03, Right08, Right06, Direction.right);
            Utility.SwapRectangleColor(Right02, Right05, Right07, Right04, Direction.right);
        }

        public void R_left_Click()
        {
            Utility.SwapRectangleColor(Up03, Front03, Down03, Back06, Direction.right);
            Utility.SwapRectangleColor(Up05, Front05, Down05, Back04, Direction.right);
            Utility.SwapRectangleColor(Up08, Front08, Down08, Back01, Direction.right);
            Utility.SwapRectangleColor(Right01, Right03, Right08, Right06, Direction.right);
            Utility.SwapRectangleColor(Right02, Right05, Right07, Right04, Direction.right);
        }

        private void F_right_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Right01, Up06, Left08, Down03, Direction.left);
            Utility.SwapRectangleColor(Right04, Up07, Left05, Down02, Direction.left);
            Utility.SwapRectangleColor(Right06, Up08, Left03, Down01, Direction.left);
            Utility.SwapRectangleColor(Front01, Front03, Front08, Front06, Direction.left);
            Utility.SwapRectangleColor(Front02, Front05, Front07, Front04, Direction.left);
        }

        public void F_right_Click()
        {
            Utility.SwapRectangleColor(Right01, Up06, Left08, Down03, Direction.left);
            Utility.SwapRectangleColor(Right04, Up07, Left05, Down02, Direction.left);
            Utility.SwapRectangleColor(Right06, Up08, Left03, Down01, Direction.left);
            Utility.SwapRectangleColor(Front01, Front03, Front08, Front06, Direction.left);
            Utility.SwapRectangleColor(Front02, Front05, Front07, Front04, Direction.left);
        }

        private void F_left_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Right01, Up06, Left08, Down03, Direction.right);
            Utility.SwapRectangleColor(Right04, Up07, Left05, Down02, Direction.right);
            Utility.SwapRectangleColor(Right06, Up08, Left03, Down01, Direction.right);
            Utility.SwapRectangleColor(Front01, Front03, Front08, Front06, Direction.right);
            Utility.SwapRectangleColor(Front02, Front05, Front07, Front04, Direction.right);
        }

        public void F_left_Click()
        {
            Utility.SwapRectangleColor(Right01, Up06, Left08, Down03, Direction.right);
            Utility.SwapRectangleColor(Right04, Up07, Left05, Down02, Direction.right);
            Utility.SwapRectangleColor(Right06, Up08, Left03, Down01, Direction.right);
            Utility.SwapRectangleColor(Front01, Front03, Front08, Front06, Direction.right);
            Utility.SwapRectangleColor(Front02, Front05, Front07, Front04, Direction.right);
        }

        private void B_right_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Right03, Down08, Left06, Up01, Direction.left);
            Utility.SwapRectangleColor(Right05, Down07, Left04, Up02, Direction.left);
            Utility.SwapRectangleColor(Right08, Down06, Left01, Up03, Direction.left);
            Utility.SwapRectangleColor(Back01, Back03, Back08, Back06, Direction.right);
            Utility.SwapRectangleColor(Back02, Back05, Back07, Back04, Direction.right);
        }

        public void B_right_Click()
        {
            Utility.SwapRectangleColor(Right03, Down08, Left06, Up01, Direction.left);
            Utility.SwapRectangleColor(Right05, Down07, Left04, Up02, Direction.left);
            Utility.SwapRectangleColor(Right08, Down06, Left01, Up03, Direction.left);
            Utility.SwapRectangleColor(Back01, Back03, Back08, Back06, Direction.right);
            Utility.SwapRectangleColor(Back02, Back05, Back07, Back04, Direction.right);
        }

        private void B_left_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Right03, Down08, Left06, Up01, Direction.right);
            Utility.SwapRectangleColor(Right05, Down07, Left04, Up02, Direction.right);
            Utility.SwapRectangleColor(Right08, Down06, Left01, Up03, Direction.right);
            Utility.SwapRectangleColor(Back01, Back03, Back08, Back06, Direction.left);
            Utility.SwapRectangleColor(Back02, Back05, Back07, Back04, Direction.left);
        }

        public void B_left_Click()
        {
            Utility.SwapRectangleColor(Right03, Down08, Left06, Up01, Direction.right);
            Utility.SwapRectangleColor(Right05, Down07, Left04, Up02, Direction.right);
            Utility.SwapRectangleColor(Right08, Down06, Left01, Up03, Direction.right);
            Utility.SwapRectangleColor(Back01, Back03, Back08, Back06, Direction.left);
            Utility.SwapRectangleColor(Back02, Back05, Back07, Back04, Direction.left);
        }

        private void U_right_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Left01, Front01, Right01, Back01, Direction.left);
            Utility.SwapRectangleColor(Left02, Front02, Right02, Back02, Direction.left);
            Utility.SwapRectangleColor(Left03, Front03, Right03, Back03, Direction.left);
            Utility.SwapRectangleColor(Up01, Up03, Up08, Up06, Direction.right);
            Utility.SwapRectangleColor(Up02, Up05, Up07, Up04, Direction.right);
        }

        public void U_right_Click()
        {
            Utility.SwapRectangleColor(Left01, Front01, Right01, Back01, Direction.left);
            Utility.SwapRectangleColor(Left02, Front02, Right02, Back02, Direction.left);
            Utility.SwapRectangleColor(Left03, Front03, Right03, Back03, Direction.left);
            Utility.SwapRectangleColor(Up01, Up03, Up08, Up06, Direction.right);
            Utility.SwapRectangleColor(Up02, Up05, Up07, Up04, Direction.right);
        }

        private void U_left_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Left01, Front01, Right01, Back01, Direction.right);
            Utility.SwapRectangleColor(Left02, Front02, Right02, Back02, Direction.right);
            Utility.SwapRectangleColor(Left03, Front03, Right03, Back03, Direction.right);
            Utility.SwapRectangleColor(Up01, Up03, Up08, Up06, Direction.left);
            Utility.SwapRectangleColor(Up02, Up05, Up07, Up04, Direction.left);
        }

        public void U_left_Click()
        {
            Utility.SwapRectangleColor(Left01, Front01, Right01, Back01, Direction.right);
            Utility.SwapRectangleColor(Left02, Front02, Right02, Back02, Direction.right);
            Utility.SwapRectangleColor(Left03, Front03, Right03, Back03, Direction.right);
            Utility.SwapRectangleColor(Up01, Up03, Up08, Up06, Direction.left);
            Utility.SwapRectangleColor(Up02, Up05, Up07, Up04, Direction.left);
        }

        private void D_left_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Left06, Front06, Right06, Back06, Direction.left);
            Utility.SwapRectangleColor(Left07, Front07, Right07, Back07, Direction.left);
            Utility.SwapRectangleColor(Left08, Front08, Right08, Back08, Direction.left);
            Utility.SwapRectangleColor(Down01, Down03, Down08, Down06, Direction.left);
            Utility.SwapRectangleColor(Down02, Down05, Down07, Down04, Direction.left);
        }

        public void D_left_Click()
        {
            Utility.SwapRectangleColor(Left06, Front06, Right06, Back06, Direction.left);
            Utility.SwapRectangleColor(Left07, Front07, Right07, Back07, Direction.left);
            Utility.SwapRectangleColor(Left08, Front08, Right08, Back08, Direction.left);
            Utility.SwapRectangleColor(Down01, Down03, Down08, Down06, Direction.left);
            Utility.SwapRectangleColor(Down02, Down05, Down07, Down04, Direction.left);
        }

        private void D_right_Click(object sender, RoutedEventArgs e)
        {
            Utility.SwapRectangleColor(Left06, Front06, Right06, Back06, Direction.right);
            Utility.SwapRectangleColor(Left07, Front07, Right07, Back07, Direction.right);
            Utility.SwapRectangleColor(Left08, Front08, Right08, Back08, Direction.right);
            Utility.SwapRectangleColor(Down01, Down03, Down08, Down06, Direction.right);
            Utility.SwapRectangleColor(Down02, Down05, Down07, Down04, Direction.right);
        }

        public void D_right_Click()
        {
            Utility.SwapRectangleColor(Left06, Front06, Right06, Back06, Direction.right);
            Utility.SwapRectangleColor(Left07, Front07, Right07, Back07, Direction.right);
            Utility.SwapRectangleColor(Left08, Front08, Right08, Back08, Direction.right);
            Utility.SwapRectangleColor(Down01, Down03, Down08, Down06, Direction.right);
            Utility.SwapRectangleColor(Down02, Down05, Down07, Down04, Direction.right);
        }
        #endregion

        private void MouseLeftClick(object sender, PointerRoutedEventArgs e)
        {
            var tmp = e.GetCurrentPoint(sender as Button);
            if (tmp.Properties.IsLeftButtonPressed)
            {
                Utility.SwapRectangleColor(test1, test2);
            }
        }

        private void SolveCube(object sender, RoutedEventArgs e)
        {
            FixFirstLayer();
        }

        private void RandomClick(object sender, RoutedEventArgs e)
        {
            Random random = new Random();
            List<Click> Clicks = new List<Click>
            {
                L_left_Click,
                L_right_Click,
                R_left_Click,
                R_right_Click,
                U_left_Click,
                U_right_Click,
                D_left_Click,
                D_right_Click,
                F_left_Click,
                F_right_Click,
                B_left_Click,
                B_right_Click
            };
            for(int i = 0; i <= 100; i++)
            {
                int num = random.Next(Clicks.Count);
                var rdclick = Clicks[num];
                rdclick();
                //TODO: update UI in each loop.
            }
        }


        private void RandomRotate()
        {
            Random random = new Random();
            List<Click> Clicks = new List<Click>
            {
                L_left_Click,
                L_right_Click,
                R_left_Click,
                R_right_Click,
                U_left_Click,
                U_right_Click,
                D_left_Click,
                D_right_Click,
                F_left_Click,
                F_right_Click,
                B_left_Click,
                B_right_Click
            };
            int num = random.Next(Clicks.Count);
            var rdclick = Clicks[num];
            rdclick();
        }


        private void Grid_KeyDown(object sender, KeyRoutedEventArgs e)
        {

        }

        private void Grid_RightTapped(object sender, RightTappedRoutedEventArgs e)
        {
            MenuFlyout menuFlyout = new MenuFlyout();
            MenuFlyoutItem BlueItem = new MenuFlyoutItem()
            {
                Icon = new BitmapIcon() { UriSource = new Uri("ms-appx:///Assets/Icons/blue.ico") },
                Text = "Blue"
            };
            MenuFlyoutItem GreenItem = new MenuFlyoutItem()
            {
                Icon = new BitmapIcon() { UriSource = new Uri("ms-appx:///Assets/Icons/green.ico")},
                Text = "Green"
            };
            MenuFlyoutItem OrangeItem = new MenuFlyoutItem()
            {
                Icon = new BitmapIcon() { UriSource = new Uri("ms-appx:///Assets/Icons/orange.ico") },
                Text = "Orange"
            };
            MenuFlyoutItem RedItem = new MenuFlyoutItem()
            {
                Icon = new BitmapIcon() { UriSource = new Uri("ms-appx:///Assets/Icons/red.ico") },
                Text = "Red"
            };
            MenuFlyoutItem WhiteItem = new MenuFlyoutItem()
            {
                Icon = new BitmapIcon() { UriSource = new Uri("ms-appx:///Assets/Icons/white.ico") },
                Text = "White"
            };
            MenuFlyoutItem YellowItem = new MenuFlyoutItem()
            {
                Icon = new BitmapIcon() { UriSource = new Uri("ms-appx:///Assets/Icons/yellow.ico") },
                Text = "Yellow"
            };
            menuFlyout.Items.Add(BlueItem);
            menuFlyout.Items.Add(GreenItem);
            menuFlyout.Items.Add(OrangeItem);
            menuFlyout.Items.Add(RedItem);
            menuFlyout.Items.Add(WhiteItem);
            menuFlyout.Items.Add(YellowItem);
            FrameworkElement frameworkElement = sender as FrameworkElement;
            menuFlyout.ShowAt(sender as UIElement, e.GetPosition(sender as UIElement));
            

        
        }
        public void FixFirstLayer()
        {
            while (Back02.Fill == Front00.Fill || Back04.Fill == Front00.Fill || Back05.Fill == Front00.Fill || Back07.Fill == Front00.Fill)
            {
                RandomRotate();
            }
        }
    }
}
