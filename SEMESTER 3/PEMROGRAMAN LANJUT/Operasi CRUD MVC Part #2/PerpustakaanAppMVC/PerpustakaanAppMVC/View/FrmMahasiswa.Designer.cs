namespace PerpustakaanAppMVC.View
{
    partial class FrmMahasiswa
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Text = new System.Windows.Forms.Label();
            this.NameText = new System.Windows.Forms.Button();
            this.ivwMahasiswa = new System.Windows.Forms.ListView();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.txtnama = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Text
            // 
            this.Text.AutoSize = true;
            this.Text.Location = new System.Drawing.Point(16, 18);
            this.Text.Name = "Text";
            this.Text.Size = new System.Drawing.Size(164, 20);
            this.Text.TabIndex = 0;
            this.Text.Text = "Cari nama mahasiswa";
            // 
            // NameText
            // 
            this.NameText.Location = new System.Drawing.Point(566, 18);
            this.NameText.Name = "NameText";
            this.NameText.Size = new System.Drawing.Size(79, 27);
            this.NameText.TabIndex = 2;
            this.NameText.Text = "Cari";
            this.NameText.UseVisualStyleBackColor = false;
            this.NameText.Click += new System.EventHandler(this.button1_Click);
            // 
            // ivwMahasiswa
            // 
            this.ivwMahasiswa.HideSelection = false;
            this.ivwMahasiswa.Location = new System.Drawing.Point(21, 59);
            this.ivwMahasiswa.Name = "ivwMahasiswa";
            this.ivwMahasiswa.Size = new System.Drawing.Size(623, 225);
            this.ivwMahasiswa.TabIndex = 3;
            this.ivwMahasiswa.UseCompatibleStateImageBehavior = false;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(21, 306);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(83, 27);
            this.button2.TabIndex = 4;
            this.button2.Text = "Tambah";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(128, 306);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(99, 27);
            this.button3.TabIndex = 5;
            this.button3.Text = "Perbaiki";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(245, 306);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(116, 32);
            this.button4.TabIndex = 6;
            this.button4.Text = "Hapus";
            this.button4.UseVisualStyleBackColor = true;
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(560, 306);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(85, 29);
            this.button5.TabIndex = 7;
            this.button5.Text = "Selesai";
            this.button5.UseVisualStyleBackColor = true;
            // 
            // txtnama
            // 
            this.txtnama.Location = new System.Drawing.Point(193, 21);
            this.txtnama.Name = "txtnama";
            this.txtnama.Size = new System.Drawing.Size(367, 26);
            this.txtnama.TabIndex = 8;
            // 
            // FrmMahasiswa
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(657, 338);
            this.Controls.Add(this.txtnama);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.ivwMahasiswa);
            this.Controls.Add(this.NameText);
            this.Controls.Add(this.Text);
            this.Name = "FrmMahasiswa";
            this.Text = "FrmMahasiswa";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Text;
        private System.Windows.Forms.Button NameText;
        private System.Windows.Forms.ListView ivwMahasiswa;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.TextBox txtnama;
    }
}