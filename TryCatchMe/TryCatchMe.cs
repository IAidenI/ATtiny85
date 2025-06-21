// Pour compiler csc /target:winexe /reference:System.Windows.Forms.dll TryCatchMe.cs

using System;
using System.IO;
using System.Net;
using System.Drawing;
using System.Threading;
using System.Diagnostics;
using System.Windows.Forms;

using WinFormsTimer = System.Windows.Forms.Timer;

class TryCatchMe : Form {
    private Button try_catch_me;
    private PictureBox background;

    private Random rng;
    private int base_x;
    private int base_y;

    private int block_count = 0;
    private int max_blocks = 3;

    // Empêche le alt + tab
    protected override CreateParams CreateParams {
        get {
            CreateParams cp = base.CreateParams;
            cp.ExStyle |= 0x80;
            return cp;
        }
    }

    // Ignore le alt + f4
    protected override bool ProcessCmdKey(ref Message msg, Keys keyData) {
        if (keyData == Keys.Alt | keyData == Keys.F4)
            return true;
        return base.ProcessCmdKey(ref msg, keyData);
    }

    // Boucle de surveillance des processus
    private void monitor_taskmgr() {
        Thread monitorThread = new Thread(() => {
            while (true) {
                Process[] processes = Process.GetProcessesByName("Taskmgr");
                foreach (Process proc in processes) {
                    block_count++;
                    try {
                        proc.Kill();
                    } catch (Exception ex) {
                        Console.WriteLine("Erreur : " + ex.Message);
                    }

                    if (block_count >= max_blocks) {
                        return;
                    }
                    break;
                }
                Thread.Sleep(500);
            }
        });

        monitorThread.IsBackground = true;
        monitorThread.Start();
    }

    // Avoir un effet de tremblement
    private void tremble() {
        int x_offset = rng.Next(-20, 20);
        int y_offset = rng.Next(-20, 20);
        this.Location = new Point(base_x + x_offset, base_y + y_offset);
    }

    // Change l'emplacement de la fenêtre si la souris arrive dans la fenêtre
    private void check_mouse_position() {
        // Récupere la position de la souris
        Point position = Cursor.Position;
        int mouse_x = position.X;
        int mouse_y = position.Y;

        // Récupere la position et dimenssion de la fenêtre
        int win_x = this.Location.X;
        int win_y = this.Location.Y;
        int win_width = this.Width;
        int win_height = this.Height;

        // Si la souris est dans la fenêtre on change la position
        if (mouse_x >= win_x && mouse_x <= win_x + win_width && mouse_y >= win_y && mouse_y <= win_y + win_height) {            base_x = rng.Next(0, Screen.PrimaryScreen.WorkingArea.Width - this.Width);
            base_y = rng.Next(0, Screen.PrimaryScreen.WorkingArea.Height - this.Height);
            this.Location = new Point(base_x, base_y);
        }
    }

    public TryCatchMe() {
        rng = new Random();
        base_x = rng.Next(0, Screen.PrimaryScreen.WorkingArea.Width - this.Width);
        base_y = rng.Next(0, Screen.PrimaryScreen.WorkingArea.Height - this.Height);

        // Paramètres de la fenêtre
        this.Size = new Size(200, 100);
        this.StartPosition = FormStartPosition.Manual;
        this.Location = new Point(base_x, base_y);

        // Paramètre de la fenêtre
        this.TopMost = true; // Mets la fenêtre toujours au dessus
        this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None; // Enlève la top bar
        this.ShowInTaskbar = false; // Enlève l'affichage à la taskbar

        // Ajoute le background
        background = new PictureBox();
        background.Dock = DockStyle.Fill;
        background.SizeMode = PictureBoxSizeMode.StretchImage;

        // Récupere le gif sur internet
        using (WebClient client = new WebClient()) {
            byte[] data = client.DownloadData("https://i.imgur.com/pl5SRW0.gif");
            using (MemoryStream ms = new MemoryStream(data)) {
                background.Image = new Bitmap(Image.FromStream(ms));
            }
        }
        
        // Ajoute le fond
        this.Controls.Add(background);

        // Création du bouton
        try_catch_me = new Button();
        try_catch_me.Text = "Try Catch Me";
        try_catch_me.Size = new Size(100, 30);

        // Action du bouton
        try_catch_me.Click += (sender, e) => this.Close();

        // Ajouter le bouton à la fenêtre
        this.Controls.Add(try_catch_me);
        try_catch_me.BringToFront();

        // Centre le bouton après le chargement de la fenêtre
        this.Load += (sender, e) =>
        {
            try_catch_me.Location = new Point(
                (this.ClientSize.Width - try_catch_me.Width) / 2,
                (this.ClientSize.Height - try_catch_me.Height) / 2
            );

            // Lance l'intercepteur de gestionnaire des tâches
            monitor_taskmgr();

            // Lance la vérification de la souris
            WinFormsTimer mouseTimer = new WinFormsTimer();
            mouseTimer.Interval = 30;
            mouseTimer.Tick += (s2, e2) => check_mouse_position();
            mouseTimer.Start();
            
            // Lance le tremblement après 30 millisecondes
            WinFormsTimer trembleTimer = new WinFormsTimer();
            trembleTimer.Interval = 30;
            trembleTimer.Tick += (s2, e2) => tremble();
            trembleTimer.Start();
        };
    }

    static void Main() {
        Application.EnableVisualStyles();
        Application.Run(new TryCatchMe());
    }
}
