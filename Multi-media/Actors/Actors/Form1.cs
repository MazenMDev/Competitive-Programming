using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Actors
{
    public class CActor
    {
        public int x, y;
        public int wd, ht;
    }
    public partial class Form1 : Form
    {
        List<CActor> actors = new List<CActor>();
        public Form1()
        {
            InitializeComponent();
            this.WindowState = FormWindowState.Maximized;
            this.MouseDown += Form1_MouseDown;
            this.Paint += Form1_Paint;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            DrawScence();
        }

        void DrawScence()
        {
            Graphics g = this.CreateGraphics();
            Pen pn = new Pen(Color.Green, 5);
            for(int i=0; i<actors.Count; i++)
            {
                CActor ptrav = actors[i];
                g.DrawRectangle(pn, ptrav.x, ptrav.y, ptrav.wd, ptrav.ht);
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            CActor pnn = new CActor();
            pnn.x = e.X;
            pnn.y = e.Y;
            pnn.wd = 150;
            pnn.ht = 100;

            actors.Add(pnn);
            DrawScence();
        }
    }
}
