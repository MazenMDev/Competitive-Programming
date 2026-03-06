using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace buttons
{
    public partial class Form1 : Form
    {
        Random rnd = new Random();
        int clickCounter = 0;
        public Form1()
        {
            InitializeComponent();
            this.button1.MouseClick += button1_Click;
            this.button2.MouseClick += Button2_MouseClick;
            label2.Text = "You have clicked 0 times";
            button2.Text = "Reset";

        }

        private void Button2_MouseClick(object sender, MouseEventArgs e)
        {
            throw new NotImplementedException();
        }

        private void button1_Click(object sender, MouseEventArgs e)
        {
            clickCounter++;
            if (label1.Visible)
            {
                label1.Hide();
                button1.Text = "Press to see";
                button1.BackColor = SystemColors.Control;
            }
            else
            {
                label1.Show();
                label1.Text = "You did it";
                button1.Text = "Hide it";
                button1.BackColor = Color.FromArgb(rnd.Next(256), rnd.Next(256), rnd.Next(256));
            }
            label2.Text = $"You have click {clickCounter} times";
        }

    }
}
