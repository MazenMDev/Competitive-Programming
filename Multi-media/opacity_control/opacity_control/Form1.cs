using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace First_multi_media
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
			this.BackColor = Color.FromArgb(255, 0, 0);
			this.Text = "Here we go";
			KeyDown += test_key;
		}

		private void test_key(object sender, KeyEventArgs e)
		{
			int block_move = 20;
			if (e.KeyCode == Keys.Right)
			{
				this.Left += block_move;
				this.Opacity -= 0.05;
			}
			else if(e.KeyCode == Keys.Left)
			{
				this.Left -= block_move;
				this.Opacity += 0.05;
			}
			if (e.KeyCode == Keys.Up) this.Top -= block_move;
			else if (e.KeyCode == Keys.Down) this.Top += block_move;
		}
	}
}
