using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Problem_3
{
    public partial class Form1 : Form
    {
        List<Form> blocks = new List<Form>();
        bool direction = false;
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
            for(int k = 0; k < blocks.Count; k++)
            {
                Form ptrav = blocks[k];
                ptrav.BackColor = Color.White;
            }
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Down)
            {
                if (i + 2 <= blocks.Count - 1)
                    i += 2;
                clearAll();
                blocks[i].BackColor = Color.Red;
                blocks[i + 1].BackColor = Color.Red;
                this.Text = "i: " + i;
            }
            else if (e.KeyCode == Keys.Up)
            {
                if (i - 2 >= 0)
                    i -= 2;
                clearAll();
                blocks[i].BackColor = Color.Red;
                blocks[i + 1].BackColor = Color.Red;
                this.Text = "i: " + i;
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            Form pnn = new Form();
            pnn.Size = new Size(100, 100);
            pnn.Show();
            blocks.Add(pnn);
            if (!direction) {
                pnn.Location = new Point(this.Location.X - pnn.Width, this.Location.Y + pnn.Height * counter);
                direction = !direction;
            } 
            else {
                pnn.Location = new Point(this.Location.X + this.Width, this.Location.Y + pnn.Height * counter);
                direction = !direction;
                counter++;
            }
        }
    }
}
