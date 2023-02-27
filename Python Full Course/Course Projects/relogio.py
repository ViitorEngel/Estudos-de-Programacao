from tkinter import *
from time import *

def update():
    time_string=strftime("%I:%M:%S %p")
    time_label.config(text=time_string)

    day_string=strftime("%A")
    day_label.config(text=day_string)

    time_label.after(1000,update)

window = Tk()
window.config(background="black")

time_label = Label(window, font=("System",70),foreground="green",bg="black")
time_label.pack()

day_label = Label(window, font=("System",70),foreground="green",bg="black")
day_label.pack()

update()

window.mainloop()