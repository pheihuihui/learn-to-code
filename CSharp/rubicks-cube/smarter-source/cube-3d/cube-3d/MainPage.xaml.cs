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
using Windows.UI.Xaml.Media.Media3D;
using Windows.UI.Xaml.Navigation;

// https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x804 上介绍了“空白页”项模板

namespace cube_3d
{
    /// <summary>
    /// 可用于自身或导航至 Frame 内部的空白页。
    /// </summary>
    public sealed partial class MainPage : Page
    {
        double centePos;
        private double WidthGrid;

        public MainPage()
        {
            this.InitializeComponent();

            centePos = (this.ActualWidth / 2) / 2;
            WidthGrid = this.ActualWidth / 2;
            this.SizeChanged += (s, e) =>
            {
                centePos = (e.NewSize.Width / 2) / 2;
                WidthGrid = e.NewSize.Width / 2;
            };
        }

        private void LeftGrid_Loaded(object sender, RoutedEventArgs e)
        {
            var temp = LeftGrid.Transform3D as CompositeTransform3D;
            temp.CenterZ = -centePos;
            temp.CenterX = centePos;
        }

        private void Border_Loaded(object sender, RoutedEventArgs e)
        {
            (sender as Border).Width = WidthGrid;
            var temp = (sender as Border).Transform3D as CompositeTransform3D;
            temp.TranslateX = WidthGrid;
            temp.RotationY = -90;
        }
    }
}
