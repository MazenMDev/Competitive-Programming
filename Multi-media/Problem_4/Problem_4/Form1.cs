using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Problem_4
{
    public partial class Form1 : Form
    {
        List<Form> blocks = new List<Form>();
        int counter = 0;
        int i = 0;
        public Form1()
        {
            InitializeComponent();
            this.MouseDown += Form1_MouseDown;
            this.KeyDown += Form1_KeyDown;
        }

        void clearAll()
        {
            for (int k = 0; k < blocks.Count; k++)
            {
                Form ptrav = blocks[k];
                ptrav.BackColor = Color.White;
                ptrav.Opacity = 1;
            }
        }
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            this.Text = "Here";
            if (e.KeyCode == Keys.Right)
            {
                if (i + 1 <= blocks.Count - 1)
                    i++;
            }
            else if (e.KeyCode == Keys.Left)
            {
                if (i - 1 >= 0)
                    i--;
            }
            clearAll();
            blocks[i].BackColor = Color.Red;
            if (i - 1 >= 0)
            {
                blocks[i - 1].BackColor = Color.Red;
                blocks[i - 1].Opacity = 0.5;
            }
            if (i + 1 <= blocks.Count - 1)
            {
                blocks[i + 1].BackColor = Color.Red;
                blocks[i + 1].Opacity = 0.5;
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            Form pnn = new Form();
            pnn.Size = new Size(150, 100);
            pnn.Show();
            pnn.Location = new Point(this.Location.X + pnn.Width * counter, this.Location.Y - pnn.Height);
            blocks.Add(pnn);
            counter++;
        }
    }
}
