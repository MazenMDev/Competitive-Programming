using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bouncing_Balls
{
    public partial class Form1 : Form
    {
        List<Panel> sqaurs = new List<Panel>();
        public Form1()
        {
            InitializeComponent();
        
            this.KeyDown += Form1_KeyDown;
            this.MouseDown += Form1_MouseDown;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            Panel newSquare = new Panel();
            Random rand = new Random();
            Color randomColor = Color.FromArgb(rand.Next(256), rand.Next(256), rand.Next(256));
            newSquare.Size = new Size(50, 50);
            newSquare.BackColor = randomColor;
            newSquare.Location = e.Location;
            this.Controls.Add(newSquare);
            sqaurs.Add(newSquare);
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            int step = 10;
            for(int i=0; i<sqaurs.Count; i++)
            {
                Panel square = sqaurs[i];
                if (e.KeyCode == Keys.Up)
                    square.Top -= step;
                else if (e.KeyCode == Keys.Down)
                    square.Top += step;
                else if (e.KeyCode == Keys.Right)
                    square.Left += step;
                else if (e.KeyCode == Keys.Left)
                    square.Left -= step;

                if (square.Left < 0) square.Left = 0;
                if (square.Top < 0) square.Top = 0;
                if (square.Right > this.ClientSize.Width) square.Left = this.ClientSize.Width - square.Width;
                if (square.Bottom > this.ClientSize.Height) square.Top = this.ClientSize.Height - square.Height;
            }
        }
    }
}
