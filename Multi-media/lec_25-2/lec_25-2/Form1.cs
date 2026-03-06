using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace lec_25_2
{
    public partial class Form1 : Form
    {
        List<Color> lc = new List<Color>();
        List<Form1> forms = new List<Form1>();
        List<string> textlines = new List<string>();
        int counter = 0;
        int ischild = 0;
        string myname = "mazen";
        string mytext;
        public Form1()
        {
            InitializeComponent();
            this.KeyDown += press_key;
            lc.Add(Color.Yellow);
            lc.Add(Color.Red);
            lc.Add(Color.Blue);
        }

        private void press_key(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Space)
            {
                if(ischild == 0)
                {
                    if(counter < 3)
                    {
                        Form1 pnn = new Form1();
                        StreamReader sr = new StreamReader("test"+(counter+1).ToString()+".txt");
                        while (!sr.EndOfStream)
                        {
                            string line = sr.ReadLine();
                            pnn.textlines.Add(line);
                            pnn.mytext += line;
                            pnn.mytext += "\n";
                        }

                        sr.Close();
                        pnn.Size = new Size(300, 300);
                        pnn.BackColor = lc[counter];
                        pnn.ischild = 1;
                        pnn.Show();
                        counter++;
                        forms.Add(pnn);
                    }
                }
                else
                {
                    MessageBox.Show(mytext);
                }
            }
            else
            {
                if (e.KeyCode == Keys.A)
                {
                    if(ischild == 1)
                    {
                        int half = textlines.Count / 2;
                        string text = "";
                        for (int i = 0; i < half; i++)
                        {
                            text += textlines[i];
                            text += '\n';
                        }
                        MessageBox.Show(text);
                    }
                }
            }
        }
    }
}
