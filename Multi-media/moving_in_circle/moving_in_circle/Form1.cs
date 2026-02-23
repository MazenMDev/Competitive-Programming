using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace moving_in_circle
{
    public partial class Form1 : Form
    {
        List<Form1> blocks = new List<Form1>();
        int wd = 150; int ht = 100;
        int vx = 0; 
        int vy = 0;
        public Form1()
        {
            InitializeComponent();
            this.KeyDown += Form1_KeyDown;
            this.MouseDown += Form1_MouseDown;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            Form1 pnn = new Form1();
            pnn.Show();
            pnn.Size = new Size(wd, ht);
            pnn.BackColor = Color.FromArgb(255, 0, 0);
            pnn.Opacity = 0.5f;

            int i = blocks.Count;
            if(i == 0)
            {
                pnn.Location = new Point(
                        this.Location.X + this.Width,
                        this.Location.Y - pnn.Height
                    );
                pnn.vx = -1;
                pnn.vy = 0;
            }
            if (i == 1)
            {
                pnn.Location = new Point(
                        this.Location.X - pnn.Width,
                        this.Location.Y - pnn.Height
                    );
                pnn.vx = 0;
                pnn.vy = 1;
            }
            if (i == 2)
            {
                pnn.Location = new Point(
                        this.Location.X - pnn.Width,
                        this.Location.Y + this.Height
                    );
                pnn.vx = 1;
                pnn.vy = 0;
            }
            if(i == 3)
            {
                pnn.Location = new Point(
                        this.Location.X + this.Width,
                        this.Location.Y + this.Height
                    );
                pnn.vx = 0;
                pnn.vy = -1;
            }

            blocks.Add(pnn);
            this.Activate();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Space)
            {
                for (int i = 0; i < blocks.Count; i++)
                {
                    Form1 ptrav = blocks[i];
                    ptrav.Location = new Point(
                            ptrav.Location.X + ptrav.vx*10,
                            ptrav.Location.Y + ptrav.vy*10
                        );
                    if (ptrav.vx == -1)
                    {
                        if((ptrav.Location.X + ptrav.Width) < this.Location.X)
                        {
                            ptrav.vx = 0;
                            ptrav.vy = 1;
                        }
                    }
                    else if(ptrav.vx == 1)
                    {
                        if (ptrav.Location.X > this.Location.X + this.Width)
                        {
                            ptrav.vx = 0;
                            ptrav.vy = -1;
                        }
                    }
                    else if (ptrav.vy == 1)
                    {
                        if (ptrav.Location.Y > this.Location.Y + this.Height)
                        {
                            ptrav.vx = 1;
                            ptrav.vy = 0;
                        }
                    }
                    else if (ptrav.vy == -1)
                    {
                        if (ptrav.Location.Y + ptrav.Height < this.Location.Y)
                        {
                            ptrav.vx = -1;
                            ptrav.vy = 0;
                        }
                    }
                }
            }
        }

    }
}
