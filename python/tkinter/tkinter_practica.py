# Author: José Rodolfo (jric2002)
import tkinter as tk
from tkinter import ttk
root = tk.Tk()
root.title("Saludo")
root_width = 600
root_height = 400
root_x = int((root.winfo_screenwidth() - root_width)/2)
root_y = int((root.winfo_screenheight() - root_height)/2)
root.geometry(f"{root_width}x{root_height}+{root_x}+{root_y}")
root.mainloop()