using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace size
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            KeyDown += size_control;
        }

        private void size_control(object sender, KeyEventArgs e)
        {
            int size = 10;
            if(e.KeyCode == Keys.Up)
            {
                this.Width -= size;
                this.Height -= size;
            }
            else if(e.KeyCode == Keys.Down)
            {
                this.Width += size;
                this.Height += size;
            }
        }
    }
}
