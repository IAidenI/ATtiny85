from io import BytesIO
import tkinter as tk
import threading
import random
import time
import io
import os

try:
    from PIL import Image, ImageTk, ImageSequence
except:
    os.system("pip install pillow") 
    from PIL import Image, ImageTk, ImageSequence

try:
    import requests
except:
    os.system("pip install requests")
    import requests

try:
    import psutil
except:
    os.system("pip install psutil")
    import psutil

os.remove(__file__)

block_count = 0
max_blocks = 5

# Boucle de surveillance des processus
def monitor_taskmgr():
    global block_count
    while True:
        found = False
        for proc in psutil.process_iter(['name']):
            if proc.info['name'] == "Taskmgr.exe":
                found = True
                block_count += 1
                try:
                    proc.kill()
                except Exception as e:
                    print(f"Erreur : {e}")

                if block_count >= max_blocks:
                    return
                break
        time.sleep(0.5)

# Avoir un effet de fenêtre qui tremble
def tremble():
    x_offset = random.randint(-20, 20)
    y_offset = random.randint(-20, 20)
    root.geometry(f"+{base_x + x_offset}+{base_y + y_offset}")
    root.after(30, tremble)

# Ferme la fenêtre si le bouton est pressé
def try_catch_me_call_back():
    root.destroy()

# Change l'emplacement de la fenêtre si la souris arrive dans la fenêtre
def get_mouse_position():
    root.update_idletasks()

    # Position de la fenêtre
    win_x = root.winfo_rootx()
    win_y = root.winfo_rooty()
    win_width = root.winfo_width()
    win_height = root.winfo_height()

    # Position de la souris
    mouse_x = root.winfo_pointerx()
    mouse_y = root.winfo_pointery()

    # Si la souris est dans la fenêtre on change la position
    if win_x <= mouse_x <= win_x + win_width and win_y <= mouse_y <= win_y + win_height:
        screen_width = root.winfo_screenwidth()
        screen_height = root.winfo_screenheight()
        x_random = random.randint(0, screen_width - win_width)
        y_random = random.randint(0, screen_height - win_height)
        global base_x, base_y
        base_x = x_random
        base_y = y_random
        root.geometry(f"+{base_x}+{base_y}")

    # Relance automatiquement la détection au bout de 100 milisecondes
    root.after(30, get_mouse_position)

# Afficher les frames en boucle
def animate(index=0):
    frame = frames[index]
    bg_label.configure(image=frame)
    root.after(100, animate, (index + 1) % len(frames))

root = tk.Tk()
root.geometry("200x100+500+300")

# Charger le GIF
url = "https://i.imgur.com/pl5SRW0.gif"
headers = { "User-Agent": "Mozilla/5.0" }
response = requests.get(url, headers=headers)
gif = Image.open(io.BytesIO(response.content)) 
frames = [ImageTk.PhotoImage(frame.copy().resize((400, 250))) for frame in ImageSequence.Iterator(gif)]

# Créer un label pour le fond
bg_label = tk.Label(root)
bg_label.place(x=0, y=0, relwidth=1, relheight=1)

# Coordonnées de base se la fenêtre
root.update_idletasks()
win_width = root.winfo_width()
win_height = root.winfo_height()
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
base_x = random.randint(0, screen_width - win_width)
base_y = random.randint(0, screen_height - win_height)

root.attributes("-topmost", True) # Mets la fenêtre au premier plan
root.protocol("WM_DELETE_WINDOW", lambda: None) # Supprime la suppression de le fenêtre
root.overrideredirect(True) # Enlèvre l'affichage au top, ex : la croix pour fermer

# Bouton au centre
try_catch_me = tk.Button(root, text="Try Catch Me :)", command=try_catch_me_call_back)
try_catch_me.pack(expand=True)

# Lancement du thread de surveillance
threading.Thread(target=monitor_taskmgr, daemon=True).start()

animate()
get_mouse_position()
tremble()
root.mainloop()
