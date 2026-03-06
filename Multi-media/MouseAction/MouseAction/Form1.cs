using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MouseAction
{
    public partial class Form1 : Form
    {
        int xOld = -1;
        int yOld = -1;
        bool isDrag = false;
        List<Form> moves = new List<Form>();
        public Form1()
        {
            InitializeComponent();
            this.MouseDown += Form1_MouseDown;
            this.MouseMove += Form1_MouseMove;
            this.MouseUp += Form1_MouseUp;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            xOld = -1;
            yOld = -1;
            isDrag = false;
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDrag)
            {
                int dx = e.X - xOld;
                int dy = e.Y - yOld;
                // xOld = e.X; yOld = e.Y;
                this.Text = "Amount: " + dx + " : " + dy;
                if (dy >= 0 && dy < 256 && dx >= 0 && dx < 256)
                {
                    this.BackColor = Color.FromArgb(dx, dy, 0);
                }
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            xOld = e.X;
            yOld = e.Y;
            isDrag = true;
        }
    }
}
